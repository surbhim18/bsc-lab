
package q3;

/**
 *
 * @author surbhi
 */
public class MyException extends Exception{

    private String exception;
    
    /**
     *
     * @param str
     */
    public MyException(String str){
        exception= str;
    }
    
    /**
     *
     */
    public void display(){
        System.out.println(exception);
    }    
}
