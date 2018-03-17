package q5;

import java.util.ArrayList;

/**
 *
 * @author surbhi
 */
public class DynamicStack extends Stack {

    ArrayList<Integer> arr;
    int top;

    public DynamicStack() {
        this.arr = new ArrayList<>();
        top = -1;
    }

    @Override
    public void push(int x) throws MyException {
        arr.add(x);
        ++top;
    }

    @Override
    public int pop() throws MyException {

        if (arr.isEmpty()) {
            throw new MyException("Stack Underflow");
        }
        int a = arr.remove(top);
        top--;
        return a;
    }

    @Override
    public void display() {

        if(top==-1) System.out.println("Stack is empty!");
        
        for (int i = top; i >= 0; --i) {
            System.out.println(arr.get(i) + "  ");
        }
    }
}
