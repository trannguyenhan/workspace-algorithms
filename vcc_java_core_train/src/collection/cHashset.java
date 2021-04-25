package collection;

import java.util.HashSet;
import java.util.List;
import java.util.Set;

public class cHashset extends HashSet<String>{
	@Override
	public int hashCode() {
		int sum = 0;
		String paraString = null;
		for(int i=0; i<paraString.length(); i++) {
			sum = sum +  (int)paraString.charAt(i) * (i+1);
		}
		return sum;
	}
	
	@Override
	public boolean equals(Object arg0) {
		return super.equals(arg0);
	}
	
	public static void main(String[] args) {
		Set<String> s = new cHashset();
	}
}
