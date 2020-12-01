package bai8.model;

public class CityModel {
	private int id;
	private String name;
	private int population; // dan so cua thanh pho
	private String code; // ma quoc gia
	
	public String getCode() {
		return code;
	}

	public void setCode(String code) {
		this.code = code;
	}

	public CityModel() {
		this(0, "noname", 0, "000");
	}
	
	public CityModel(int id, String name, int population, String code) {
		this.id = id;
		this.name = name;
		this.population = population;
		this.code = code;
	}
	
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
	
	public int getPopulation() {
		return population;
	}
	
	public void setPopulation(int population) {
		this.population = population;
	}
	
	@Override
	public String toString() {
		return id + " " + name + " " + population + " " + code; 
	}
}
