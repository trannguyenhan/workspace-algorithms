package main;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.SQLException;

import services.MySQLConnection;

public class Main {
	public static void main(String[] args) throws SQLException {
		Connection connection = null;
		PreparedStatement preparedStatement = null;
		try {
			connection = new MySQLConnection().getConnection();
			connection.setAutoCommit(false);
			
			String query1 = "update titles \n"
					+ "set to_date = NOW()\n"
					+ "where emp_no = 10004 and to_date = '9999-01-01'";
			
			String query2 = "insert into titles(emp_no, title, from_date, to_date)\n"
					+ "value(10002, 'Senior Staff', now(), '9999-01-01')";
			
			preparedStatement = connection.prepareStatement(query1);
			preparedStatement.executeUpdate();
			
			preparedStatement = connection.prepareStatement(query2);
			preparedStatement.executeUpdate();
			
			connection.commit();
		} catch (SQLException e) {
			connection.rollback();
		} finally {
			connection.close();
			preparedStatement.close();
		}
	}
}
