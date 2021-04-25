package main;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import Model.User;
import service.ParseJson;

public class Main {
	final static Logger logger = LoggerFactory.getLogger(Main.class);
	private static User lastUser = new User();
	
	public static void main(String[] args) {
		// Lay du lieu moi 2s 1 lan
		while (true) {
			User user = ParseJson.getData();
			
			if(lastUser == null) {
				logger.info("INFO : " + user.getUser(), Main.class.getSimpleName());
			} else {
				if(user.getUser() - lastUser.getUser() > user.getUser() * 0.0005) {
					logger.info("INFO : " + user.getUser(), Main.class.getSimpleName());
					lastUser = user;
				} else {
					Thread writeThread = new WriteLater12s(logger, user);
					writeThread.start();
				}
			}
			
			long timeCurrent = System.currentTimeMillis();
			long timeLater2s = timeCurrent + 2000;
			while (timeCurrent != timeLater2s) {
				timeCurrent = System.currentTimeMillis();
			}
			
		}

	}
}
