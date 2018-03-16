#include<iostream>

using namespace std;

/*
FORMAL PARAMETERS: n: numeric
RETURN : flag: numeric
PURPOSE: returns 0 if prime no
         returns 1 if not a prime no
*/

 int fprime(int n)
{
   int i,flag=0;
   
  for(i=2;i<=n/2;i++)
  {
      if(n%i==0)
       {
         flag=1;
         break;
       }
   }
    return flag;
 
}

/*
INPUT PARAMETERS: n,ch: numeric
OUTPUT: whether a no. is prime or not
      : prime no.s less than n
*/


  int main()
{
  int flag,i,n,ch;
  
 cout<<"\nWhat do you wish to do?";
 cout<<"\n1.Calculate prime no.s less than a no";
 cout<<"\n2.Check whether a no is prime or not\n";
 cout<<"Enter choice: ";
 cin>>ch;

 cout<<"\nEnter a no: ";
 cin>>n;
 

 switch(ch)
{
 case 1:
       for(i=2;i<=n;i++)
     {
       flag=fprime(i);             //Each number less than n is passed to the function
        if(flag==0)
       cout<<i<<"    ";
     } 
     cout<<endl;
     
       break;

 case 2:
      flag=fprime(n);             //The entered no is passed to the function
 
      if(flag==0)
      cout<<" "<<n<<" is prime\n";
      else
      cout<<n<<" is not prime\n";
      break;

 default: cout<<"\nPlease enter a valid choice\n";
 }

 return 0;
}
