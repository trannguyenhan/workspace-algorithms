package Model;

import java.util.ArrayList;
import java.util.List;

public class User {
	private long user;
	private double per_user;
	private long user_old_time;
	
	private List<Person> source;

	public User() {
		source = new ArrayList<>();
	}
	
	public long getUser() {
		return user;
	}

	public void setUserID(long user) {
		this.user = user;
	}

	public double getPer_user() {
		return per_user;
	}

	public void setPer_user(double per_user) {
		this.per_user = per_user;
	}

	public long getUser_old_time() {
		return user_old_time;
	}

	public void setUser_old_time(long user_old_time) {
		this.user_old_time = user_old_time;
	}

	public List<Person> getSource() {
		return source;
	}

	public void setSource(List<Person> source) {
		this.source = source;
	}
	
	@Override
	public String toString() {
		String string = Long.toString(this.user) + " " + Double.toString(this.per_user) + Long.toString(this.user_old_time); 
		return string;
	}
}
