package thread;

import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.ScheduledExecutorService;
import java.util.concurrent.TimeUnit;

public class Lich implements Runnable {
	private String name;
	
	public Lich() {
		
	}
	
	public Lich(String name) {
		this.name = name;
	}
	
	@Override
	public void run() {
		System.out.println("Running.....");
		try {
			Thread.sleep(5000);
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	
	public static void main(String[] args) throws InterruptedException {
		ScheduledExecutorService scheduled = Executors.newSingleThreadScheduledExecutor();
		
		while(true){
			Lich l = new Lich();
			scheduled.schedule(l, 5, TimeUnit.SECONDS);
		}
	}
}
