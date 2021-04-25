import java.util.List;
import java.util.Scanner;

public class ContestProject {
	public static int dem;
	public static int sumT;
	
	public static void Dem(int n, int S, List<Integer> totien) {
		if(n<0) return;
		
		dem++;
		sumT = sumT + totien.get(n);
		
		if(sumT > S) {
			dem--;
			sumT = sumT - totien.get(n);
			Dem(n-1, S, totien);
		} else if(sumT == S) {
			return;
		} else {
			Dem(n-1, S, totien);
		}
		
		return;
	}
	
	public static void main(String[] args) {
		int n, S;
		List<Integer> totien = null;
		
		Scanner scanner = new Scanner(System.in);
		n = scanner.nextInt();
		S = scanner.nextInt();
		
		for(int i=0; i<n; i++) {
			int temp = 0;
			temp =	scanner.nextInt();
			totien.add(temp);
		}
		
		int demMin = 31;
		for(int i=n-1; i>=0; i--) {
			dem = 0;
			sumT = 0;
			Dem(i,S,totien);
			
			if((dem<demMin) && (dem>0) && (sumT == S)) {
				demMin = dem;
			}
		}
		
		if(demMin<=30) System.out.println(demMin);
		else 
			System.out.println("-1");
	}
}
