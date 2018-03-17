
package q3;

/**
 *
 * @author surbhi
 */

import java.sql.*;
import java.util.logging.Level;
import java.util.logging.Logger;

public class Q3 {

    
    public static void main(String[] args) {
        
        try {
            Connection conn= DB.getDBConnection();
            
            PreparedStatement updateTeacherNames;
            
            updateTeacherNames = conn.prepareStatement("update Teacher set tname = CONCAT('Dr. ',tname)");
            
            updateTeacherNames.executeUpdate();
            
            updateTeacherNames.close();
            conn.close();
            
        } catch (SQLException ex) {
            Logger.getLogger(Q3.class.getName()).log(Level.SEVERE, null, ex);
        }
        
        
    }
    
}
