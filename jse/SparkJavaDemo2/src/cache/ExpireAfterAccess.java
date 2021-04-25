package cache;

import java.util.Map;
import java.util.Set;

public class ExpireAfterAccess extends Thread{
	public static Map<Integer, String> cache;
	public static Map<Integer, Long> cache10s;
	public static Map<Integer, Long> cache20s;
	int TTL;
	
	public ExpireAfterAccess(Map<Integer, Long> m1, Map<Integer, Long> m2, Map<Integer, String> c, int TTL) {
		cache = c;
		cache10s = m1;
		cache20s = m2;
		this.TTL = TTL;
	}
	
	@Override
	public void run() {
		while(true) {
			Set<Integer> listKey = cache10s.keySet();
			if(listKey.size() == 0) continue;
			for(Integer integer : listKey) {
				if(System.currentTimeMillis() - cache10s.get(integer) >= TTL * 1000) {
					cache10s.remove(integer);
					System.out.println("remove : " + integer);
					cache.remove(integer);
				}
			}
		}
	}
}
