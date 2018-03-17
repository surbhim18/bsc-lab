/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package prime;

/**
 *
 * @author surbh
 */
public class Prime {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        
        int i=2, count=0;
        while(true)
        {
            if(isPrime(i)==true)
                count++;
            
            if(count==1000)
            {
                System.out.println("The 1000 prime no. is:" + i);
                break;
            }
            
            i++;
        }
        
    }
    
    public static boolean isPrime(int num){
        
        int i;
        for(i=2; i<=num/2; i++)
        {
            if(num%i==0)
                return false;
        }
        
        return true;
    }
    
}
