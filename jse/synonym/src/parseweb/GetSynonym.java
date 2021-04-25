package parseweb;

import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

import org.jsoup.Jsoup;
import org.jsoup.nodes.Document;
import org.jsoup.nodes.Element;
import org.jsoup.select.Elements;

public class GetSynonym {
	private String words;
	private List<String> listSynonym;
	Document doc;
	
	public String getWords() {
		return words;
	}

	public void setWords(String words) {
		this.words = words;
	}
	
	public List<String> getListSynonym() {
		return listSynonym;
	}

	public void setListSynonym(List<String> listSynonym) {
		this.listSynonym = listSynonym;
	}

	public GetSynonym(String words) throws IOException {
		listSynonym = new ArrayList<String>();
		setWords(words);
		connectUrl();
		getSysnonym();
	}
	
	public GetSynonym() throws IOException {
		this("null");
	}
	
	// Ket noi toi website de phan tich
	public void connectUrl() throws IOException {
		CreateUrl cre = new CreateUrl(this.getWords());
		doc = Jsoup.connect(cre.getUrl()).get();
	}
	
	// Bat dau lay du lieu tu dong nghia
	public void getSysnonym() {
		Elements root = doc.getElementsByAttribute("class");
		Element r = null;
		for(Element foo : root) {
			if(foo.className().contains("et6tpn80")) {
				r = foo;
				break;
			}
		}
		
		String str = r.text();
		int i = 0;
		int j = 0; 
		while(i < str.length()) {
			for(j=i; j<str.length(); j++)
				if(str.charAt(j) == ' ') break;
			String temp = str.substring(i,j);
			listSynonym.add(temp);
			i = j+1;
		}
		
		printResult();
	}
	
	public void printResult() {
		for(String str : listSynonym) {
			System.out.println(str + "\n");
		}
	}
}
