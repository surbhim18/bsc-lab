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
abstract public class Stack {
    abstract public void push(int x) throws MyException;  //create MyException class
    abstract public int pop() throws MyException;
    abstract public void display(); 
}
