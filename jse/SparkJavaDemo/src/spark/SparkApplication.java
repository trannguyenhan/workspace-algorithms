package spark;

import static spark.Spark.*;

import java.util.Map;
import java.util.concurrent.ConcurrentHashMap;
import java.util.concurrent.TimeUnit;

import com.google.common.cache.CacheBuilder;
import com.google.common.cache.CacheLoader;
import com.google.common.cache.LoadingCache;

public class SparkApplication {
	public static Map<Integer, String> cache;
	public static Map<Integer, Long> cachePrime10s;
	public static Map<Integer, Long> cachePrime20s;
	
	public static LoadingCache<Integer, String> cacheGuava;
	
	public static void main(String[] args) {
		cache = new ConcurrentHashMap<Integer, String>();
		cachePrime10s = new ConcurrentHashMap<Integer, Long>();
		cachePrime20s = new ConcurrentHashMap<Integer, Long>();

		CacheLoader<Integer, String> loader;
	    loader = new CacheLoader<Integer, String>() {
	        @Override
	        public String load(Integer key) {
	            return new Prime(key).getSequenSePrime();
	        }
	    };
		cacheGuava = CacheBuilder.newBuilder().expireAfterAccess(10000, TimeUnit.MILLISECONDS).expireAfterWrite(20000, TimeUnit.MILLISECONDS).build(loader);
	    
        get("/hello", (req, res)->"Hello, world");
        
        get("/hello/:name", (req,res)->{
            return "Hello, "+ req.params(":name");
        });
		
        /*request from url, cache with map*/
        get("/prime4", (req, res) -> {
        	
        	String str = null;
        	str = req.queryParams("n");
        	int n = Integer.parseInt(str);
        	
        	if(cache.size() != 0) {
        		if(cache.containsKey(n)){
        			cachePrime10s.put(n, System.currentTimeMillis());
        			if(cachePrime20s.containsKey(n)) {
        				cachePrime20s.remove(n);
        			}
        			return cache.get(n);
        		}
        	}
        	
        	str = new Prime(n).getSequenSePrime();
        	cache.put(n, str);
        	cachePrime20s.put(n, System.currentTimeMillis());
        	
        	return str;
        });
        
        /*init thread*/
		Thread thread10s = new Thread10s(cachePrime10s, cachePrime20s, cache);
		thread10s.start();
	
		Thread thread20s = new Thread20s(cachePrime10s, cachePrime20s, cache);
		thread20s.start();
    	
		/*request from url, cache with guava*/
		get("/prime5", (req, res) -> {
			String str = null;
        	str = req.queryParams("n");
        	int n = Integer.parseInt(str);
        
        	return cacheGuava.get(n);
			
		});
		
    }

}