package Arithmetic;

/**
 *
 * @author surbhi
 */
public class Functions {

    public int gcd(int x, int y) {
        if (y == 0) {
            return x;
        } else {
            return gcd(y, x % y);
        }
    }
}
