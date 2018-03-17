package q6;

import java.sql.*;

/**
 *
 * @author surbhi
 */
public class DB {

    private static final String DB_DRIVER = "com.mysql.jdbc.Driver";
    private static final String DB_CONNECTION = "jdbc:mysql://localhost/college";
    private static final String DB_USER = "root";
    private static final String DB_PASSWORD = "root";

    public static Connection getDBConnection() {

        Connection conn = null;

        try {
            Class.forName(DB_DRIVER);
        } catch (ClassNotFoundException ex) {
            System.out.println("Error: unable to load driver class!");
            System.exit(1);
        }

        try {
            conn = DriverManager.getConnection(DB_CONNECTION, DB_USER, DB_PASSWORD);
            return conn;

        } catch (SQLException ex) {
            System.out.println("SQLException: " + ex.getMessage());
            System.out.println("SQLState: " + ex.getSQLState());
            System.out.println("VendorError: " + ex.getErrorCode());
        }
        return null;
    }
}
