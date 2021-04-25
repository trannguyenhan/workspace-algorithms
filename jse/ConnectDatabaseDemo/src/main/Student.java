package main;

public class Student {
	private int id;
	private String name;
	private String address;
	
	public int getId() {
		return id;
	}
	
	public void setId(int id) {
		this.id = id;
	}
	
	public String getName() {
		return name;
	}
	
	public void setName(String name) {
		this.name = name;
	}
	
	public String getAddress() {
		return address;
	}
	
	public void setAddress(String address) {
		this.address = address;
	}
	
	public Student(int id, String name, String address) {
		setId(id);
		setAddress(address);
		setName(name);
	}
	
	@Override
	public String toString() {
		return this.id + " " + this.name + " " + this.address;
	}
}
