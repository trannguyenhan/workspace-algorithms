package regex;

import java.util.regex.Matcher;
import java.util.regex.Pattern;

import javax.swing.JOptionPane;

public class regex1 {
	public static void main(String[] args) {
		// Kiem tra ID cua ho khau
		String string = "Ngujyen";
		Pattern pattern = Pattern.compile("\\d{1,11}");
		pattern = Pattern.compile("\\w{1,50}");

		if(pattern.matcher(string).matches())
			JOptionPane.showMessageDialog(null, "DUNG");
		else JOptionPane.showMessageDialog(null, "SAI");
	}
}
