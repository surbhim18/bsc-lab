package q4;

import java.util.Scanner;

/**
 *
 * @author surbhi
 */
public class Q4 {

    public static void main(String[] args) {

        Scanner ob = new Scanner(System.in);
        int num, bit;

        System.out.print("Enter the number                     : ");
        num = ob.nextInt();

        do {

            System.out.print("Enter the bit to be flipped [1-32]   : ");
            bit = ob.nextInt();

        } while (bit <= 0 || bit > 32);

        int mask = 1;
        int shift = bit - 1;

        mask = mask << shift;

        int newNum = num ^ mask;

        System.out.println("The result after flipping bit " + bit + " of " + num + " : " + newNum);
    }

}
