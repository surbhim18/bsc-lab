
package q1;

/**
 *
 * @author surbhi
 */
public class Q1 {

    
    public static void main(String[] args) {
        
        Matrix a= new Matrix(2,2);
        Matrix b= new Matrix(2,3);
        
        a.enter();
        b.enter();
        
        a.display();
        b.display();
        
        Matrix res;
        try {
            res = a.multiply(b);
             System.out.print(res);
        } catch (MyException ex) {
            ex.display();
        }              
    }
    
}
