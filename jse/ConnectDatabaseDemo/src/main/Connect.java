package main;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

public class Connect {
	public static Connection getMysqlConnection() throws SQLException, ClassNotFoundException {
		String hostName = "localhost";
		String dbName = "student";
		String userName = "root";
		String password = "mysql1234";
		return getMysqlConnection(hostName, dbName, userName, password);
	}

	public static Connection getMysqlConnection(String hostName, String dbName, String userName, String password)
			throws SQLException, ClassNotFoundException {
		// Class.forName("com.mysql.jdbc.Driver");
		String connectionUrl = "jdbc:mysql://" + hostName + ":3306/" + dbName
				+ "?useUnicode=true&characterEncoding=utf-8";
		Connection conn = DriverManager.getConnection(connectionUrl, userName, password);
		return conn;
	}
}
