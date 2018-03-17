package q5;

/**
 *
 * @author surbhi
 */
public class Q5 {

    public static void main(String[] args) {
        Stack ob;
        ob = new StaticStack(5);
        //ob = new DynamicStack();

        try {
            ob.push(3); ob.display();
            ob.push(4); ob.display();
            ob.push(5); ob.display();
            ob.push(5); ob.display();
            ob.push(5); ob.display();
            ob.push(5);
            ob.display();
            System.out.println("Popped elements : " + ob.pop() + ob.pop() + ob.pop());
            ob.pop();
            
        } catch (MyException e) {
            e.display();
        }
    }

}
