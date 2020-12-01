package bai8.services;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

import bai8.model.CityModel;
import bai8.model.CountryModel;

public class CityServices {
	private List<CityModel> listCity;
	
	public CityServices() throws IOException {
		listCity = new ArrayList<>();
		
		String pathFile = "resource/input_8/cities.dat";
		BufferedReader fileReader = new BufferedReader(new FileReader(pathFile));
		
		String dataLine = fileReader.readLine();
		while(dataLine != null) {
			String tmp1 = dataLine.substring(5);
			StringTokenizer stringTokenizer = new StringTokenizer(tmp1, ",");
			
			List<String> listDataLine = new ArrayList<>();
			while(stringTokenizer.hasMoreTokens()) {
				String tmp2 = stringTokenizer.nextToken();
				listDataLine.add(tmp2);
			}
			
			int id = 0;
			String name = null;
			int population = 0; // dan so cua thanh pho
			String code = null;
			for(int i=0; i<listDataLine.size(); i++) {
				stringTokenizer = new StringTokenizer(listDataLine.get(i), "=");
				String key = stringTokenizer.nextToken();
				String value = stringTokenizer.nextToken();
				
				switch (i) {
				case 0:
					id = Integer.parseInt(value);
					break;
				case 1:
					name = value;
					break;
				case 2:
					population = Integer.parseInt(value);
					break;
				case 3:
					value = value.substring(0, value.length() - 1);
					code = value;
					break;
				default:
					break;
				}
			}
			
			CityModel cityModel = new CityModel(id, name, population,code);
			listCity.add(cityModel);
			
			dataLine = fileReader.readLine();
		}
	}
	
	public List<CityModel> getListCityModel(){
		return listCity;
	}
}
