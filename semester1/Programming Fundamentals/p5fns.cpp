#include<iostream>

using namespace std;

/*
INPUT PARAMETERS: n : numeric
OUTPUT: fibonacci series upto n terms
APPROACH:
First no and 2nd no are taken as 0 and 1 respectively
Third no is calculated by adding 1st and 2nd no. and so on..
*/

 void fibo()
{
 int n,i,third,first,second;

 cout<<"Fibonacci Series\n";
 cout<<"Enter the no of elements: ";
 cin>>n;
 
  first=0;
  second=1;

if(n>=2)                    //if more than 2 numbers of series are to be printed
{
  cout<<0<<"\t"<<1<<"\t"; 
  
  for(i=2;i<n;i++)
  {
   third= first+second;
   cout<<third<<"\t";
  
   first=second;
   second=third;
  
  }
}
else
 {
    if(n==0)
    cout<<"Zero terms\n";
    else if(n==1)
    cout<<"0";
  }
}

/*
INPUT PARAMETER: n:numeric
OUTPUT: factorial of n
APPROACH:
Starting factorial from 1 all numbers are multiplied to it, upto n
*/

  void fact()
{
  long unsigned fact;
 int n,i;

 cout<<"Enter the no whose factorial is to be calculated: ";
 cin>>n;
 
 if(n<0)                                      //if n is -ve
  cout<<"Factorial cannot be calculated!!\n";
 else
{
 fact=1;
  
 for(i=1;i<=n;i++)
 fact=fact*i;

 cout<<"\nFactorial of "<<n<<" is: "<<fact;
 }
}

/*
INPUT PARAMETERS: n1,n2 : numeric
OUPUT: greatest common divisor of the two numbers
*/

  void gcd()
 {
  int n1,n2,gcd,min,i;

 cout<<"To find Greatest Common Divisor(GCD)\n";
 cout<<"Enter 2 no.s:\n";
 cin>>n1>>n2;

 if(n1>n2)
 min=n2;
 else
 min=n1;

 for(i=1;i<=min;i++)
 {
    if(n1%i==0 && n2%i==0)
     gcd=i;
 }

 cout<<"\nGCD of "<<n1<<" and "<<n2<<" = "<<gcd<<endl;
}
 
/*
INPUT PARAMETER: ch: numeric
*/

  int main()
{
  int ch;

  cout<<"Menu\n";
  cout<<"1.Print fibonacci series\n";
  cout<<"2.Calculate factorial\n";
  cout<<"3.Calculate GCD of two no.s\n";

  cout<<"Enter choice: ";
  cin>>ch;

  switch(ch)
{
  case 1: fibo();
          break;

  case 2: fact();
          break;
  
  case 3: gcd();
          break;

  default: cout<<"Enter a valid choice\n";
}

 return 0;

}
 
