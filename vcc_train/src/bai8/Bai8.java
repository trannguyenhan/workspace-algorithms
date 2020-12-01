package bai8;

import java.io.IOException;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.HashSet;
import java.util.List;
import java.util.Optional;
import java.util.Set;
import java.util.TreeSet;
import java.util.stream.Collector;
import java.util.stream.Collectors;
import java.util.stream.Stream;

import bai8.model.CityModel;
import bai8.model.CountryModel;
import bai8.services.CityServices;
import bai8.services.CountryServices;

public class Bai8 {
	private static List<CityModel> listCityModel = new ArrayList<>();
	private static List<CountryModel> listCountryModel = new ArrayList<>();
	
	public static void main(String[] args) throws IOException {
		// get data
		CountryServices countryServices = new CountryServices();
		CityServices cityServices = new CityServices();
		listCityModel = cityServices.getListCityModel();
		listCountryModel = countryServices.getListCountryModel();
		
		Set<String> listCode = new HashSet<String>();
		listCityModel.forEach(city -> {
			if(city.getCode() != null)
				listCode.add(city.getCode());
		});
		
		for(String targetCode : listCode) {
			Optional<CityModel> listTmp1 = listCityModel.stream().filter(city -> city.getCode().equals(targetCode)).findFirst();
			if(listTmp1.isPresent())
				System.out.println(listTmp1.get().getCode());
		}
		
	}
}
