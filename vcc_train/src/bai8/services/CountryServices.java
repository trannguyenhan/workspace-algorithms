package bai8.services;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

import bai8.model.CountryModel;

public class CountryServices {
	private List<CountryModel> listCountry;
	
	public CountryServices() throws IOException {
		listCountry = new ArrayList<>();
		
		String pathFile = "resource/input_8/countries.dat.dat";
		BufferedReader fileReader = new BufferedReader(new FileReader(pathFile));
		
		String dataLine = fileReader.readLine();
		while(dataLine != null) {
			String tmp1 = dataLine.substring(7);
			StringTokenizer stringTokenizer = new StringTokenizer(tmp1, "{},");
			
			List<String> listDataLine = new ArrayList<>();
			while(stringTokenizer.hasMoreTokens()) {
				String tmp2 = stringTokenizer.nextToken();
				listDataLine.add(tmp2);
			}
			
			String code = null; // ma quoc gia
			String name = null;
			String continent = null; // ma luc dia
			double surfaceArea = 0; // dien tich be mat
			int population = 0; // dan so
			double gnp = 0; // Gross national product
			int capital = 0; // ma thanh pho la thu do cua nuoc nay
			for(int i=0; i<listDataLine.size(); i++) {
				stringTokenizer = new StringTokenizer(listDataLine.get(i), "=");
				String key = stringTokenizer.nextToken();
				String value = stringTokenizer.nextToken();
				
				switch (i) {
				case 0:
					code = value;
					break;
				case 1:
					name = value;
					break;
				case 2:
					continent = value;
					break;
				case 3:
					surfaceArea = Double.parseDouble(value);
					break;
				case 4:
					population = Integer.parseInt(value);
					break;
				case 5:
					gnp = Double.parseDouble(value);
					break;
				case 6:
					capital = Integer.parseInt(value);
					break;
				default:
					break;
				}
			}
			
			CountryModel countryModel = new CountryModel(code, name, continent, surfaceArea, population, gnp, capital);
			listCountry.add(countryModel);
			
			dataLine = fileReader.readLine();
		}
	}
	
	public List<CountryModel> getListCountryModel(){
		return listCountry;
	}
}
