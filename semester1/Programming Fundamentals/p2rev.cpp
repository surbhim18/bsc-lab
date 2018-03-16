#include<iostream>

using namespace std;

/*
INPUT PARAMETERS: num :numeric
PURPOSE: to calculate reverse of the number
OUTPUT: prints reverse of the number
*/

int main()
{
  int num,d,ori,rev;
  
  cout<<"Enter a no: ";
  cin>>num;
  
   ori=num;                  //Original no is stored in another variable
   rev=0;                    //Variable rev is initialised with 0
 
  while(num)                 //loop works while n is not equal to 0
{ 
  d=num%10;                  //extracts digit at unit place     
  num=num/10;                //number gets divided by 10
  
 rev= d + rev*10;            	
}

 cout<<"\nReverse of "<<ori<<" is "<<rev<<"\n";

 return 0;
}

 
  
