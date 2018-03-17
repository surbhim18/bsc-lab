/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package q2;

import Arithmetic.*;
import Exception.*;

/**
 *
 * @author surbhi
 */
public class Q2 {
    
    public static void main(String[] args) {
        
        try{
        
        Rational x = new Rational(3,4);
        x.enter();
        x.display();
        System.out.println("");
        
        Rational y = new Rational();
        y.enter();
        y.display();
        System.out.println("");
        
        Rational res = x.division(y);
        res.display();
        } 
        
        catch (MyException ex) {
            ex.print();
        }
           
    }
    
}
