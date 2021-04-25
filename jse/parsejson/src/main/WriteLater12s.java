package main;

import org.slf4j.Logger;

import Model.User;

public class WriteLater12s extends Thread{
	private User user;
	private Logger logger;
	
	public WriteLater12s(Logger logger, User user) {
		this.logger = logger;
		this.user = user;
	}
	
	public User getUser() {
		return user;
	}

	public void setUser(User user) {
		this.user = user;
	}

	public Logger getLogger() {
		return logger;
	}

	public void setLogger(Logger logger) {
		this.logger = logger;
	}

	@Override
	public void run() {
		try {
			Thread.sleep(12000);
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		logger.debug("DEBUG : " + user.getUser(), Main.class.getSimpleName());
	}
}
