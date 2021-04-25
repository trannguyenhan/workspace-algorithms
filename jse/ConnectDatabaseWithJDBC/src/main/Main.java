package main;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

public class Main {
	public void convert_department(int idEmp, String idDepar, String new_title) throws SQLException {
		String userName = "root";
        String password = "mysql1234";
        String connectionUrl = "jdbc:mysql://localhost:3306/employees?"
        		+ "autoReconnect=true&"
        		+ "useSSL=false&useUnicode=true&"
        		+ "useJDBCCompliantTimezoneShift=true&"
        		+ "useLegacyDatetimeCode=false&"
        		+ "serverTimezone=UTC";
        Connection connection = null;
        PreparedStatement preparedStatement = null;
		try {
			connection = DriverManager.getConnection(connectionUrl, userName, password);
			String query = "call convert_department(?, ?, ?)";

	        preparedStatement = connection.prepareStatement(query);
	        preparedStatement.setInt(1, idEmp);
	        preparedStatement.setString(2, idDepar);
	        preparedStatement.setString(3, new_title);
	        
	        ResultSet result =  preparedStatement.executeQuery();
			result.next(); 
			
			System.out.println("Employee Number : " + result.getInt("emp_no"));
			System.out.println("Employee First Name : " + result.getString("first_name"));
			System.out.println("Employee Last Name : " + result.getString("last_name"));
			System.out.println("Employee gender : " + result.getString("gender"));
			System.out.println("Employee title : " + result.getString("title"));
			System.out.println("Employee dept_name : " + result.getString("dept_name"));
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} finally {
			preparedStatement.close();
			connection.close();
		}
        
	}
	
	public static void main(String[] args) throws SQLException {
        new Main().convert_department(10005, "d004", "Teacher");
	}
}
