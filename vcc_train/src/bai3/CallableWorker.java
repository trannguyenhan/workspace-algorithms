package bai3;

import java.io.BufferedReader;
import java.io.FileReader;
import java.util.Map;
import java.util.StringTokenizer;
import java.util.TreeMap;
import java.util.concurrent.Callable;

public class CallableWorker implements Callable<Map<String, Integer>> {
	private String pathFile;
	
	public CallableWorker(String pathFile) {
		this.pathFile = pathFile;
	}
	
	@Override
	public Map<String, Integer> call() throws Exception {
		BufferedReader file_reader = new BufferedReader(new FileReader(pathFile));
		Map<String, Integer> dictionary = new TreeMap<>();
		
		String str;
		while ((str = file_reader.readLine()) != null) {
			StringTokenizer tokenizer = new StringTokenizer(str, ".,!=+-—?'\"()/*][$&#_ ");
			
			while(tokenizer.hasMoreElements()) {
				String str_tmp = tokenizer.nextToken();
				if(!dictionary.containsKey(str_tmp)) {
					dictionary.put(str_tmp, 1);
				} else {
					dictionary.put(str_tmp, dictionary.get(str_tmp) + 1);
				}
			}
		}
		
		System.out.println("Xong file " + pathFile);
		return dictionary;
	}
	
}
