package q4;

/**
 *
 * @author surbhi
 */

import java.sql.*;
import java.util.logging.Level;
import java.util.logging.Logger;

public class Q4 {

    public static void main(String[] args) {
        
        try {
            Connection conn = DB.getDBConnection();
            
            PreparedStatement deleteStudents;
            
            deleteStudents = conn.prepareStatement("delete from Student where rno = ? ");
            
            deleteStudents.setInt(1,3);
         //   deleteStudents.setString(2, null);
            
            deleteStudents.executeUpdate();
            
            deleteStudents.close();
            conn.close();
            
        } catch (SQLException ex) {
            Logger.getLogger(Q4.class.getName()).log(Level.SEVERE, null, ex);
        }
        
    }
    
}
