package q6;

/**
 *
 * @author surbhi
 * read: http://www.xyzws.com/javafaq/how-to-call-a-stored-procedure-by-jdbc-java-class/169
 */

import java.sql.*;
import java.util.logging.Level;
import java.util.logging.Logger;

public class Q6 {

    public static void main(String[] args) {

        try {
            Connection conn = DB.getDBConnection();

            CallableStatement callableStmt;

            callableStmt = conn.prepareCall("call noOfRows()");

            ResultSet rs = callableStmt.executeQuery();            //when one result set is returned

          //  ResultSet rs = callableStmt.getResultSet();

            int rowCount=0;
            while (rs.next()) {
                rowCount = rs.getInt(1);
            }            
            System.out.println("No. of rows in Student table: " + rowCount);
            
            rs.close();
            callableStmt.close();
            conn.close();

        } catch (SQLException ex) {
            Logger.getLogger(Q6.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
}
