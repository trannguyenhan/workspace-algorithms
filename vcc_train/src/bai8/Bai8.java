package bai8;

import java.io.IOException;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
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
		
		/* Cau 1 : In ra ten thanh pho co dan so dong nhat moi quoc gia */
//		Set<String> listCode = new HashSet<String>();
//		listCityModel.forEach(city -> {
//			listCode.add(city.getCode());
//		});
//		
//		listCode.stream().forEach(code -> {
//			Stream<CityModel> cityStream =  listCityModel.stream().filter(city -> city.getCode().equals(code));
//			String cityMax = cityStream.max(Comparator.comparingInt(CityModel::getPopulation)).get().getName();
//			System.out.println(code + " : " + cityMax);
//		});
		
		/* Cau 2 : Tim thanh pho dong danh nhat moi luc dia */
//		Set<String> listContinent = new HashSet<>();
//		Map<String, String> mapCountryontinent = new HashMap<>();
//		listCountryModel.forEach(country -> {
//			listContinent.add(country.getContinent());
//			mapCountryontinent.put(country.getCode(), country.getContinent());
//		});
//		
//		listContinent.stream().forEach(continent -> {
//			Stream<CityModel> cityStream = listCityModel.stream().filter(city -> mapCountryontinent.get(city.getCode()).equals(continent));
//			try {
//				String cityMax = cityStream.max(Comparator.comparingInt(CityModel::getPopulation)).get().getName();
//				System.out.println(continent + " : " + cityMax);
//			} catch (Exception e) {
//				System.out.println(continent + " : No Info");
//			}
//			
//		});
		
		/* Cau 3 : Tim thanh pho la thu do, dong dan nhat */
//		Set<Integer> listCapital = new HashSet<>();
//		listCountryModel.forEach(country -> {
//			listCapital.add(country.getCapital());
//		});
//		
//		Stream<CityModel> cityStream = listCityModel.stream().filter(city -> listCapital.contains(city.getId()));
//		String cityMax = cityStream.max(Comparator.comparingInt(CityModel::getPopulation)).get().getName();
//		System.out.println(cityMax);
		
		/* Cau 4 : Tim thanh pho la thu do, dong dan nhat cua moi luc dia */
//		Set<String> listContinent = new HashSet<>();
//		Map<String, String> mapCountryontinent = new HashMap<>();
//		listCountryModel.forEach(country -> {
//			listContinent.add(country.getContinent());
//			mapCountryontinent.put(country.getCode(), country.getContinent());
//		});
//		
//		Set<Integer> listCapital = new HashSet<>();
//		listCountryModel.forEach(country -> {
//			listCapital.add(country.getCapital());
//		});
//		
//		listContinent.stream().forEach(continent -> {
//			Stream<CityModel> cityStream = listCityModel.stream().filter(city -> mapCountryontinent.get(city.getCode()).equals(continent));
//			cityStream = cityStream.filter(city -> listCapital.contains(city.getId()));
//			try {
//				String cityMax = cityStream.max(Comparator.comparingInt(CityModel::getPopulation)).get().getName();
//				System.out.println(continent + " : " + cityMax);
//			} catch (Exception e) {
//				System.out.println(continent + " : No Info");
//			}
//		});
		
		/* Cau 5 : Sap xep cac quoc gia theo so luong thanh pho giam dan */
//		Set<String> listCode = new HashSet<String>();
//		listCityModel.forEach(city -> {
//			listCode.add(city.getCode());
//		});
//		
//		Map<String , Long> mapCode = new HashMap<>();
//		listCode.stream().forEach(code -> {
//			long cntCity =  listCityModel.stream().filter(city -> city.getCode().equals(code)).count();
//			mapCode.put(code, cntCity);
//		});
//		
//		List<String> listSortedCode = listCode.stream().sorted((str1, str2) -> (mapCode.get(str2).compareTo(mapCode.get(str1)))).collect(Collectors.toList());
//		listSortedCode.forEach(code -> {
//			System.out.println(code + " : " + mapCode.get(code));
//		});
		
		/* Cau 6 : Sap xep cac quoc gia theo mat do dan so giam dan ( bo qua cac quoc gia co mat do dan so == 0)*/
		Set<String> listCode = new HashSet<String>();
		Map<String , Integer> mapCode = new HashMap<>();
		listCountryModel.forEach(country -> {
			listCode.add(country.getCode());
			mapCode.put(country.getCode(), country.getPopulation());
		});
		
		List<String> listSortedCode = listCode.stream().sorted((str1, str2) -> (mapCode.get(str2).compareTo(mapCode.get(str1)))).collect(Collectors.toList());
		listSortedCode.forEach(code -> {
			System.out.println(code + " : " + mapCode.get(code));
		});
	}
}
