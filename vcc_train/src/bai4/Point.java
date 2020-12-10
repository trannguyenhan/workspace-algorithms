package bai4;

import java.util.HashSet;
import java.util.Random;
import java.util.Set;
import java.util.TreeSet;

public class Point {
	private int x;
	private int y;
	
	public Point() {
		this(0, 0);
	}
	
	public Point(int x, int y) {
		this.x = x;
		this.y = y;
	}
	
	public int getX() {
		return x;
	}
	
	public void setX(int x) {
		this.x = x;
	}
	
	public int getY() {
		return y;
	}
	
	public void setY(int y) {
		this.y = y;
	}
	
	public static Set<Point> randomPoint(Point rootPoint, int distance, int size) {
		Random rand = new Random();
		Set<Point> setPoints = new HashSet<>();
	
		int run = 0;
		while(run < size) {
			// random number between [rootPoint.x - distance] to [rootPoint.x + distance]
			// random number between [rootPoint.y - distance] to [rootPoint.y + distance]
			int tmp_x = rand.nextInt(2 * distance) + rootPoint.getX() - distance;
			int tmp_y = rand.nextInt(2 * distance) + rootPoint.getY() - distance;
			
			Point pointTmp = new Point(tmp_x, tmp_y);
			if(!setPoints.contains(pointTmp)) {
				setPoints.add(pointTmp);
			} 
			run++;
		}
		
		System.out.println("hoan thanh tao set!");
		return setPoints;
	}
	
	public static void main(String[] args) {
		Set<Point> setPoints = new HashSet<>();
		setPoints.add(new Point(1,2));
		setPoints.add(new Point(1,2));
		
		System.out.println(setPoints.size());
		
		
	}
}
