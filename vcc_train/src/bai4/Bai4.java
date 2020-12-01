package bai4;

import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;
import java.util.HashSet;
import java.util.List;
import java.util.Set;
import java.util.TreeSet;

public class Bai4 {
	public static void main(String[] args) throws FileNotFoundException {
		Set<Point> set1 = new HashSet<>();
		Set<Point> set2 = new HashSet<>();
		Set<Point> set3 = new HashSet<>();
		Point A = new Point(800, 800);
		Point B = new Point(4000, 8000);
		Point C = new Point(2400,2400);
		
		set1 = Point.randomPoint(A, 400, 8000);
		set2 = Point.randomPoint(B, 500, 10000);
		set3 = Point.randomPoint(C, 600, 12000);
		
		Set<Point> setShuff = new HashSet<>();
		setShuff.addAll(set1);
		setShuff.addAll(set2);
		setShuff.addAll(set3);
		
		List<Point> listPoints = new ArrayList<Point>(setShuff);
		Collections.shuffle(listPoints);
		
		PrintWriter printWriter = new PrintWriter("src/bai4/output/output.txt");
		printWriter.write(listPoints.size() + "\n");
		for(Point p : listPoints) {
			printWriter.write(p.getX() + " " + p.getY() + "\n");
		}
		
		System.out.println("hoan thanh!");
	}
}
