package q5;

/**
 *
 * @author surbhi
 */

import java.sql.*;
import java.util.logging.Level;
import java.util.logging.Logger;

public class Q5 {

    public static void main(String[] args) {
        
        try {
            Connection conn = DB.getDBConnection();
            
            Statement stmt = conn.createStatement(ResultSet.TYPE_SCROLL_INSENSITIVE,ResultSet.CONCUR_UPDATABLE);
            
            ResultSet rs = stmt.executeQuery("select * from Student where sname = 'Ayush';");
            
            while(rs.next()){
                int rno = rs.getInt("rno");
                String name = rs.getString("sname");
                
                System.out.println("Roll No: " + rno + "  " + "Name: " + name);
            }
            
            rs.moveToInsertRow();
            rs.updateInt("rno", 12);
            rs.updateString("sname", "Ayush");
            rs.insertRow();
            
            rs.moveToInsertRow();
            rs.updateInt("rno", 14);
            rs.updateString("sname", "Ayush");
            rs.insertRow();           
            
            
            System.out.println("After insertion to resultset:");
            rs.beforeFirst();
            while(rs.next()){
                int rno = rs.getInt("rno");
                String name = rs.getString("sname");
                
                System.out.println("Roll No: " + rno + "  " + "Name: " + name);
            }          
            
            rs.close();
            stmt.close();
            conn.close();
            
        } catch (SQLException ex) {
            Logger.getLogger(Q5.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
    
}
