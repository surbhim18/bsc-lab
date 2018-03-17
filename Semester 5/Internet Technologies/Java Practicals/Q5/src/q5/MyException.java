/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package q5;

/**
 *
 * @author surbhi
 */
public class MyException extends Exception{

    private String exception;
    
    public MyException(String str){
        exception= str;
    }
    
    public void display(){
        System.out.println(exception);
    }    
}
