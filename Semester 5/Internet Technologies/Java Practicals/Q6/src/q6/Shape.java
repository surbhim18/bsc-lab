package q6;

import java.util.Scanner;

/**
 *
 * @author surbh
 */
public class Shape {

    int x;
    int y;

    public void get() {
        Scanner ob = new Scanner(System.in);

        System.out.print("Enter X : ");
        x = ob.nextInt();

        System.out.print("Enter Y : ");
        y = ob.nextInt();

    }

    public void show() {
        System.out.println("X is : " + x);
        System.out.println("Y is : " + y);
    }
}
