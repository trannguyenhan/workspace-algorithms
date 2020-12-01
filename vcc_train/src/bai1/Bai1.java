package bai1;

import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.Random;
import java.util.Set;
import java.util.TreeSet;

public class Bai1 {
	public static int[] allocation_fixed_values() {
		int[] fixed_values = new int[100000];
		for(int i=0; i<100000; i++)
			fixed_values[i] = i;
		return fixed_values;
	}
	
	public static int random_integer() {
		Random rand = new Random();
		int tmp = rand.nextInt(1000000000);
		
		return tmp;
	}
	
	public static void main(String[] args) throws FileNotFoundException {
		/* chuan bi du lieu */
		int[] fixed_values = new int[100000];
		fixed_values = allocation_fixed_values();
		
		Set<Integer> bucket1 = new TreeSet<>();
		Set<Integer> bucket2 = new TreeSet<>();
		
		int index = 0;
		for(int i=0; i<100000; i++) {
			bucket1.add(fixed_values[i]);
			bucket2.add(fixed_values[100000-i-1]);
			index++;
		}
		
		while(index < 2000000) {
			int tmp1 = random_integer();
			int tmp2 = random_integer();
			
			bucket1.add(tmp1);
			bucket2.add(tmp2);
			index++;
		}
		// bucket1 -> tap hop 1, bucket2 -> tap hop 2
		// cau hoi? giao va hop cua bucket1 va bucket2
		
		/* bat dau tinh toan */
		int start = (int) System.currentTimeMillis();
		
		/*hop*/
		Set<Integer> bucket_union = new TreeSet<>(bucket2);
		bucket_union.addAll(bucket1);
		
		/*giao*/
		Set<Integer> bucket_tmp = new TreeSet<>(bucket1);
		bucket_tmp.removeAll(bucket2); // giua lai cac phan tu thuoc bucket1, khong thuoc bucket2
		Set<Integer> bucket_intersec = new TreeSet<>(bucket1);
		bucket_intersec.removeAll(bucket_tmp);
		
		int end = (int) System.currentTimeMillis();
		
		// in ket qua
		System.out.println(end - start + " minisecond");
		
		
	}
}
