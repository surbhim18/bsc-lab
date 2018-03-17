package q5;

/**
 *
 * @author surbhi
 */
public class StaticStack extends Stack{
    int[] arr;
    int maxSize;
    int top;
    
    public StaticStack(int size){
        maxSize = size;
        arr = new int[maxSize];
        top=-1;
    }

    @Override
    public void push(int x) throws MyException{
    
        if(top == maxSize-1){
            throw new MyException("Stack Overflow");
        }
        else{
            top++;
            arr[top] = x;
        }
    }

    @Override
    public int pop() throws MyException {
        
        int ele;
        if(top == -1){
            throw new MyException("Stack Underflow");
        }
        else
        {
            ele = arr[top];
            top--;
        }
        return ele;
    }

    @Override
    public void display() {
        
        if(top==-1) System.out.println("Stack is empty!");
        
        for(int i=top; i>=0; i--){
            System.out.println(arr[i]+"  ");
        }
    }
    
}
