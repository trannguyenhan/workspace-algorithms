package parseweb;

import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.List;

public class PrintSynonym {
	private GetSynonym getSynonym;
	private String words;
	
	public String getWords() {
		return words;
	}

	public void setWords(String words) {
		this.words = words;
	}

	public PrintSynonym(String words) throws FileNotFoundException {
		setWords(words);
	}
	
	public void export() throws IOException {
		PrintWriter printWriter;
		printWriter = new PrintWriter("bin/result/result.txt");

		getSynonym = new GetSynonym(words);
		List<String> list = getSynonym.getListSynonym();
		
		for(String str : list) {
			printWriter.print(str + "\n");
		}
		printWriter.close();
	}
	
	public static void main(String[] args) throws IOException {
		PrintSynonym print = new PrintSynonym("good");
		print.export();
	}
}
