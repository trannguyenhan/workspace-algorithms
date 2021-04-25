package app;

import static spark.Spark.*;

import cache.MapCache;

public class SparkApplication {
	static MapCache cacheMap = new MapCache(10, 20);
	public static void main(String[] args) {
        /*request from url, cache with map*/
        get("/prime", (req, res) -> {
        	
        	String str = null;
        	str = req.queryParams("n");
        	int n = Integer.parseInt(str);
        	
        	return cacheMap.get(n);
        });
		
    }

}