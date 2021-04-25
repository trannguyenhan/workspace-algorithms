package service;

import java.io.IOException;
import java.io.InputStreamReader;
import java.net.MalformedURLException;
import java.net.URL;

import com.google.gson.Gson;

import Model.User;

public class ParseJson {
	public static User getData() {
		URL url = null;
		try {
			url = new URL("http://news.admicro.vn:10002/api/realtime?domain=kenh14.vn");
		} catch (MalformedURLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}

		InputStreamReader reader = null;
		try {
			reader = new InputStreamReader(url.openStream());
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		User user = new Gson().fromJson(reader, User.class);
		return user;
	}
}
