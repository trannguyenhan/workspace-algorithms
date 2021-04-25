package main;

import static spark.Spark.get;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;
import java.util.List;
import java.util.stream.Collectors;

import com.google.gson.Gson;

import model.Employees;
import services.MySQLConnection;

public class Main {
	public List<Employees> getInfo() throws SQLException, ClassNotFoundException {
		Connection connection = null;
        PreparedStatement preparedStatement = null;
        ResultSet result = null;
        
        connection = new MySQLConnection().getConnection();
		String query = "select e3.*, de.dept_no, s4.salary, de.dept_no , t2.title \n"
				+ "from employees e3 inner join salaries s4 on e3.emp_no = s4.emp_no \n"
				+ "inner join dept_emp de on de.emp_no = e3.emp_no\n"
				+ "inner join titles t2 on t2.emp_no = e3.emp_no \n"
				+ "where s4.to_date = '9999-01-01' and t2.to_date = '9999-01-01'";

        preparedStatement = connection.prepareStatement(query);
        
        result =  preparedStatement.executeQuery();
        
        List<Employees> listEmployees = new ArrayList();
		while(result.next()) {
			Integer emp_no = result.getInt("emp_no");
			String birth_date = result.getString("birth_date");
			String first_name = result.getString("first_name");
			String last_name = result.getString("last_name");
			String gender = result.getString("gender");
			String hire_date = result.getString("hire_date");
			Integer salary = result.getInt("salary");
			String dept_no = result.getString("dept_no");
			String title = result.getString("title");
			
			Employees employees = new Employees(emp_no, birth_date, first_name, last_name, gender, hire_date, salary, dept_no, title);
			listEmployees.add(employees);
		}
		
		preparedStatement.close();
		connection.close();
		
		return listEmployees;
	}
	
	public static void main(String[] args) throws SQLException, ClassNotFoundException {
        get("/getinfo", (req, res) -> {
        	List<Employees> listEmployees = new Main().getInfo();
        	String hire_date_fromString = req.queryParams("hire_date");
        	String salaryString = req.queryParams("salary");
        	String dept_noString = req.queryParams("dept_no");
        	String titleString = req.queryParams("title");
        
        	if(hire_date_fromString != null) {
        		List<Employees> resutl = listEmployees.stream().filter(employee -> 
        			employee.getHire_date().toString().compareTo(hire_date_fromString) > 0
        		).collect(Collectors.toList());
        		
        		listEmployees.clear();
        		listEmployees.addAll(resutl);
        	}
        	
        	if(salaryString != null) {
        		List<Employees> resutl = listEmployees.stream().filter(employee -> 
        			employee.getSalary().toString().compareTo(salaryString) > 0
        		).collect(Collectors.toList());
        		
        		listEmployees.clear();
        		listEmployees.addAll(resutl);
        	}
        	
        	if(dept_noString != null) {
        		List<Employees> resutl = listEmployees.stream().filter(employee -> 
        			employee.getDept_no().toString().equals(dept_noString)
        		).collect(Collectors.toList());
        		
        		listEmployees.clear();
        		listEmployees.addAll(resutl);
        	}
        	
        	if(titleString != null) {
        		List<Employees> resutl = listEmployees.stream().filter(employee -> 
        			employee.getTitle().toString().equals(titleString)
        		).collect(Collectors.toList());
        		
        		listEmployees.clear();
        		listEmployees.addAll(resutl);
        	}
        	
        	String json = new Gson().toJson(listEmployees);
        	return json;
        });
	}
}
