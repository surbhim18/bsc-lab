package Arithmetic;

import Exception.*;
import java.util.Scanner;

/**
 *
 * @author surbhi
 */
public class Rational {

    private int numerator;
    private int denominator;

    public Rational() {

        numerator = 0;
        denominator = 1;
    }

    public Rational(int num, int denom) throws MyException {
        numerator = num;
        denominator = denom;    
        
        if(denom==0)
        {
            throw new MyException("Denominator cannot be zero.");
        }        
        simplify();
    }

    public void enter() {

        Scanner ob = new Scanner(System.in);
        int x;

        System.out.print("Enter numerator  : ");
        x = ob.nextInt();
        numerator = x;

        do {

            System.out.print("Enter denominator: ");
            x = ob.nextInt();

        } while (x == 0);
        denominator = x;

        simplify();
    }

    private void simplify() {

        if (denominator < 0) {
            denominator = denominator * -1;
            numerator = numerator * -1;
        }

        Functions f = new Functions();
        int num=numerator;
        if(numerator<0)
            num = numerator*-1;
        
        int gcd = f.gcd(num, denominator);

        if (gcd != 1) {
            numerator /= gcd;
            denominator /= gcd;
        }

    }

    @Override
    public String toString() {

        String rational = "" + numerator;
        if (denominator != 1 && numerator != 0) {
            rational = rational + "/" + denominator;
        }

        return rational;
    }

    public void display() {

        String str = toString();
        System.out.print(str);
    }

    public Rational changedSign() {
        Rational r = new Rational();
        r.numerator = (-1) * numerator;
        r.denominator = denominator;

        return r;
    }

    public Rational square() {

        Rational r = new Rational();
        r.numerator = numerator * numerator;
        r.denominator = denominator * denominator;

        return r;
    }

    public Rational addition(Rational r) {

        Rational res = new Rational();

        res.numerator = (numerator * r.denominator) + (denominator * r.numerator);
        res.denominator = denominator * r.denominator;

        res.simplify();
        return res;
    }

    public Rational subtraction(Rational r) {

        Rational res = new Rational();

        res.numerator = (numerator * r.denominator) - (denominator * r.numerator);
        res.denominator = denominator * r.denominator;

        res.simplify();
        return res;
    }

    public Rational multiplication(Rational r) {

        Rational res = new Rational();

        res.numerator = numerator * r.numerator;
        res.denominator = denominator * r.denominator;

        res.simplify();
        return res;
    }

    public Rational division(Rational r) {

        Rational res = new Rational();

        res.numerator = numerator * r.denominator;
        res.denominator = denominator * r.numerator;

        res.simplify();
        return res;
    }

}
