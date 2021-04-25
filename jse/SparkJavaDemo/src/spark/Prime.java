package spark;

import java.util.concurrent.Callable;

public class Prime{
	private int n;
	
	public int getN() {
		return n;
	}

	public void setN(int n) {
		this.n = n;
	}

	public Prime(int n) {
		setN(n);
	}
	
	public String print(int n) {
    	String str = "";
    	
    	for(int i=2; i<=n; i++) {
    		if(checkSNT(i)) {
    			str = str + Integer.toString(i) + " ";
    		}
    	}
    	return str;
    }
    
    public boolean checkSNT(int i) {
    	if(i<=1) return false;
    	if(i==2) return true;
    	
    	for(int j=2; j<=Math.sqrt(i); j++) {
    		if(i % j == 0) return false;
    	}
		return true;
    }

	public String getSequenSePrime(){
		String str = print(n);
		return str;
	}
}
