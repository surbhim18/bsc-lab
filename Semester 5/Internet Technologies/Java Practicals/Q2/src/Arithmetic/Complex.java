package Arithmetic;

import Exception.MyException;

/**
 *
 * @author surbhi
 */
public class Complex {

    private Rational real;
    private Rational imaginary;

    public Complex() {
        real = new Rational();
        imaginary = new Rational();
    }

    public Complex(Rational a, Rational b){
        
        real =a;
        imaginary =b;
    }
    
    public Complex(int a, int b, int c, int d) throws MyException {
        real = new Rational(a, b);
        imaginary = new Rational(c, d);
    }

    public void enter() {

        System.out.println("Enter the real part:");
        real.enter();

        System.out.println("Enter the imaginary part:");
        imaginary.enter();
    }

    private Complex conjugate(){
        
        Complex con = new Complex();
        con.real = real;
        con.imaginary = imaginary.changedSign();
        return con;
    }
    
    @Override
    public String toString() {

        String complex = "(" + real.toString() + ") +  (" + imaginary.toString() + ") i";
        return complex;
    }

    public void display() {

        String str = toString();
        System.out.print(str);
    }

    public Complex addition(Complex c) {

        Complex res = new Complex();

        res.real = real.addition(c.real);
        res.imaginary = imaginary.addition(c.imaginary);

        return res;

    }

    public Complex subtraction(Complex c) {

        Complex res = new Complex();

        res.real = real.subtraction(c.real);
        res.imaginary = imaginary.subtraction(c.imaginary);

        return res;

    }

    public Complex multiplication(Complex c) {

        Complex res = new Complex();
        Rational r1,r2;

        r1 = real.multiplication(c.real);
        r2 = imaginary.multiplication(c.imaginary);
        res.real = r1.subtraction(r2);

        r1 = real.multiplication(c.imaginary);
        r2 = imaginary.multiplication(c.real);
        res.imaginary = r1.addition(r2);

        return res;
    }

    public Complex division(Complex c) {

        Complex res = new Complex();
        
        Complex con = c.conjugate();
        Complex num = multiplication(con);
        
        Rational denom;
        denom = c.real.square().addition(c.imaginary.square());
        
        res.real = num.real.division(denom);
        res.imaginary = num.imaginary.division(denom);
        
        return res;
    }
}
