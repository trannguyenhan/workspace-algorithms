package lamda;

import java.util.Arrays;
import java.util.List;

@FunctionalInterface
interface LambdaEx{
	public String forEach(List<String> list);
}

public class LamdaWithForEach {
	public static void main(String[] args) {
		List<String> languages = Arrays.asList("Java", "C#", "C++", "PHP", "Javascript");
		 
	    // Using Lambda expression
		LambdaEx lambdaObj = (list)->{
			String resultl = "";
			for (String string : list) {
				resultl = resultl + " " + string;
			}
			return resultl;
		};
		
		System.out.println(lambdaObj.forEach(languages));
	}
}
