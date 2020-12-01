package bai2;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.List;
import java.util.Map;
import java.util.Set;
import java.util.StringTokenizer;
import java.util.TreeMap;

public class Bai2 {
	public static void main(String[] args) throws IOException {
		BufferedReader file_reader = new BufferedReader(new FileReader("resource/input_2/01.txt"));
		Map<String, Integer> dictionary = new TreeMap<>();
		
		String str;
		while ((str = file_reader.readLine()) != null) {
			StringTokenizer tokenizer = new StringTokenizer(str, ".,!=+-—?'\"()/ ");
			
			while(tokenizer.hasMoreElements()) {
				String str_tmp = tokenizer.nextToken();
				if(!dictionary.containsKey(str_tmp)) {
					dictionary.put(str_tmp, 1);
				} else {
					dictionary.put(str_tmp, dictionary.get(str_tmp) + 1);
				}
			}
		}
		
		PrintWriter printWriter = new PrintWriter("src/bai2/output/output.txt");
		Set<String> words = dictionary.keySet();
		
		for(String target : words) {
			printWriter.write(target + " : " + dictionary.get(target) + "\n");
		}
		
		System.out.println("Hoan thanh!");
	}
}
