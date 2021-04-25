package service;

import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.PrintWriter;
import java.io.UnsupportedEncodingException;
import java.sql.Date;
import java.text.SimpleDateFormat;

import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JWindow;
import javax.swing.SwingConstants;

import org.jsoup.Jsoup;
import org.jsoup.nodes.Document;

public class GetData {
	private Document document;

	public GetData(String url) throws IOException {
		document = Jsoup.connect(url).get();
	}
	
	public Document getDocument() {
		return document;
	}

	public void setDocument(Document document) {
		this.document = document;
	}
	
	public String getContentWeb() {
		String html = document.html();
		return Jsoup.parse(html).text();
	}
	
	public static void main(String[] args) throws FileNotFoundException, UnsupportedEncodingException {
		JWindow window = new JWindow();
	    window.getContentPane().add(new JLabel("Loading...", SwingConstants.CENTER));
	    window.setBounds(600, 350, 300, 200);
	    window.setVisible(true);
		
		GetData data = null;
		try {
			data = new GetData("https://dantri.com.vn/");
		} catch (IOException e) {
			JOptionPane.showMessageDialog(null, "URL không đúng!");
			return;
		}
		
		SimpleDateFormat formatter = new SimpleDateFormat("dd-MM-yyyy_HH-mm-ss");
		Date date = new Date(System.currentTimeMillis());
		
		String file_name = formatter.format(date);
		String pathFile = file_name + ".txt";
		
		PrintWriter printWriter = new PrintWriter(pathFile, "utf8");		
		printWriter.print(data.getContentWeb());
		
		printWriter.close();
		
		window.setVisible(false);
	    window.dispose();
	    JOptionPane.showMessageDialog(null, "Done!");
	    
	    System.out.println(file_name);
	}
}
