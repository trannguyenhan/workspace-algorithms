package parseweb;

public class CreateUrl {
	private String url;

	public String getUrl() {
		return url;
	}

	public void setUrl(String url) {
		this.url = url;
	}
	
	public CreateUrl(String wordsString) {
		String str = "https://www.thesaurus.com/browse/" + wordsString + "?s=t";
		setUrl(str);
	}
	
	public CreateUrl() {
		this("null");
	}
}
