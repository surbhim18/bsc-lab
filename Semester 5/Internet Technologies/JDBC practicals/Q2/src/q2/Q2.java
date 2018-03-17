package q2;

import java.sql.*;
import java.util.logging.Level;
import java.util.logging.Logger;
/**
 *
 * @author surbh
 */
public class Q2 {

    
    public static void main(String[] args) {
        
        try {
            Connection conn = DB.getDBConnection();
            
            Statement stmt = conn.createStatement();
            stmt.executeUpdate("update Teacher set tname = CONCAT('Dr. ',tname) where tname = 'Rita';");
            
            stmt.close();
            conn.close();
            
        } catch (SQLException ex) {
            Logger.getLogger(Q2.class.getName()).log(Level.SEVERE, null, ex);
        }        
    }    
}
