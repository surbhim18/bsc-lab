package q1;

/**
 *
 * @author surbhi
 */
public class MyException extends Exception {
    
    private String exception;
    
    public MyException(String msg)
    {
        exception=msg;
    }
    
    public void display()
    {
        System.out.println(exception);
    }
}
