package q1;

import java.sql.*;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author surbhi
 */

public class Q1 {

    public static void main(String[] args) {
              
        try {
            Connection conn = DB.getDBConnection();
            
            Statement stmt = conn.createStatement();
            
            stmt.executeUpdate("drop table if exists college.Student");
            stmt.executeUpdate("create table college.Student ( rno int PRIMARY KEY, sname VARCHAR(50) NOT NULL);");
            
            stmt.executeUpdate("insert into college.Student values (1,'Surbhi');");
            stmt.executeUpdate("insert into college.Student values (2,'Divya');");
            
            stmt.close();
            conn.close();
            
        } catch (SQLException ex) {
            Logger.getLogger(Q1.class.getName()).log(Level.SEVERE, null, ex);
        }
        
                
    }
    
}
