package main;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;

public class Main {
	public static void main(String[] args) throws ClassNotFoundException, SQLException {
		Connection connection = Connect.getMysqlConnection();
		List<Student> listStudent = new ArrayList<>();

		String query = "SELECT * FROM student";
		PreparedStatement preparedStatement = (PreparedStatement) connection.prepareStatement(query);
		ResultSet rs = preparedStatement.executeQuery();
		while (rs.next()) {
			Student student = new Student(rs.getInt("id"), rs.getString("name"), rs.getString("address"));
			listStudent.add(student);
			
			System.out.println(student);
		}
		preparedStatement.close();
		connection.close();
	}
}
