package bai8.model;

public class CountryModel {
	private String code; // ma quoc gia
	private String name;
	private String continent; // ma luc dia
	private double surfaceArea; // dien tich be mat
	private int population; // dan so
	private double gnp; // Gross national product
	private int capital; // ma thanh pho la thu do cua nuoc nay
	
	public CountryModel() {
		this("000", "noname", "000", 0, 0, 0, 0);
	}
	
	public CountryModel(String code, String name, String continent, double surfaceArea, int population, double gnp, int capital) {
		this.code = code;
		this.name = name;
		this.continent = continent;
		this.surfaceArea = surfaceArea;
		this.population = population;
		this.gnp = gnp;
		this.capital = capital;
	}
	
	public String getCode() {
		return code;
	}
	
	public void setCode(String code) {
		this.code = code;
	}
	
	public String getName() {
		return name;
	}
	
	public void setName(String name) {
		this.name = name;
	}
	
	public String getContinent() {
		return continent;
	}
	
	public void setContinent(String continent) {
		this.continent = continent;
	}
	
	public double getSurfaceArea() {
		return surfaceArea;
	}
	
	public void setSurfaceArea(double surfaceArea) {
		this.surfaceArea = surfaceArea;
	}
	
	public int getPopulation() {
		return population;
	}
	
	public void setPopulation(int population) {
		this.population = population;
	}
	
	public double getGnp() {
		return gnp;
	}
	
	public void setGnp(double gnp) {
		this.gnp = gnp;
	}
	
	public int getCapital() {
		return capital;
	}
	
	public void setCapital(int capital) {
		this.capital = capital;
	}
	
	@Override
	public String toString() {
		return code + " " + name + " " + continent + " " + gnp + " " + surfaceArea + " " + population + " " + capital;
	}
}
