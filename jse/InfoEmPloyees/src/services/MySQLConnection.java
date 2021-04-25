package services;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

public class MySQLConnection {
	public Connection getConnection() throws SQLException {
		String userName = "root";
        String password = "mysql1234";
        String connectionUrl = "jdbc:mysql://localhost:3306/employees?"
        		+ "autoReconnect=true&"
        		+ "useSSL=false&useUnicode=true&"
        		+ "useJDBCCompliantTimezoneShift=true&"
        		+ "useLegacyDatetimeCode=false&"
        		+ "serverTimezone=UTC";
        Connection connection = null;
        connection = DriverManager.getConnection(connectionUrl, userName, password);
        
        return connection;
	}
}
