/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Exception;

/**
 *
 * @author surbhi
 */
public class MyException extends Exception{
    
    String message;
    
    public MyException(String str){
        message = str;
    }
    
    public void print(){
        System.out.println(message);
    }
}