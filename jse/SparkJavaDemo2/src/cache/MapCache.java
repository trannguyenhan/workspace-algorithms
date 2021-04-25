package cache;

import java.util.Map;
import java.util.concurrent.ConcurrentHashMap;

import app.Prime;

public class MapCache {
	public static Map<Integer, String> cache;
	public static Map<Integer, Long> cachePrime10s;
	public static Map<Integer, Long> cachePrime20s;
	
	public MapCache(int expireAfterAccess, int expireAfterWrite) {
		cache = new ConcurrentHashMap<Integer, String>();
		cachePrime10s = new ConcurrentHashMap<Integer, Long>();
		cachePrime20s = new ConcurrentHashMap<Integer, Long>();
		
		new ExpireAfterAccess(cachePrime20s, cachePrime10s, cache, expireAfterAccess).start();
		new expireAfterWrite(cachePrime20s, cachePrime10s, cache, expireAfterWrite).start();
	}
	
	public void put(int n, String res) {
    	cache.put(n, res);
    	cachePrime20s.put(n, System.currentTimeMillis());
	}
	
	public String get(int key) {
		if(cache.containsKey(key)) {
			cachePrime10s.put(key, System.currentTimeMillis());
			if(cachePrime20s.containsKey(key)) {
				cachePrime20s.remove(key);
			}
			return cache.get(key);
		} else {
			String  string = new Prime(key).getSequenSePrime();
			put(key, string);
			return cache.get(key);
		}
	}
}
