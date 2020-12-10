package bai7;

import java.util.regex.Pattern;

public class Bai7 {
	public static void main(String[] args) {
		String regexCheckDomain = "((http)|(https))(://)(www.)?[A-Za-z0-9]{1,}(.)[a-z]{2,6}[($/)[^ .]]{0,}";
		Pattern pattern = Pattern.compile(regexCheckDomain);
		
		//String domain = "https://tiki.vn/dien-thoai-may-tinh-bang/c1789?src=mega-menu";
		String domain = "https://www.tiki.vna/";
		
		if(pattern.matcher(domain).matches()) {
			System.out.println("DOMAIN!");
		} else {
			System.out.println("NOT DOMAIN!");
		}
	}
}
