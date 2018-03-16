#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cmath>

using namespace std;

class Fraction
{
  int num;
  int den;

  public:
  void enter();
  void print();
  void check();
  Fraction add(Fraction);
  Fraction subtract(Fraction);
  Fraction multiply(Fraction);
  Fraction divide(Fraction);
}a,b,res;

 
 int fgcd(int x, int y)
 {
   if(y==0)
    return x;
   else
    return fgcd(y,x%y);
 }

  void Fraction:: check()
 {
   
  if(den==0)
  {
    cout<<"\nERROR!!! Denominator is zero....";
    exit(1);
  }

  if(den<0)
   {
     den = -den;
     num = -num;
   }
 
 int gcd = fgcd(abs(num), abs(den));

 num= num/gcd;
 den= den/gcd; 

}

 void Fraction:: enter()
{
  cout<<"\nEnter numerator  : ";
  cin>>num;

  cout<<"Enter denominator: ";
  cin>>den;
  
  check(); 

}

 void Fraction:: print()
{
  cout<<"\nThe fraction is\n";
  cout<<num<<"/"<<den<<endl;
 
} 

 Fraction Fraction:: add( Fraction b)
{
  res.num = (num * b.den) + (b.num * den);
  res.den = den * b.den;
  res.check();
  return res;
}


 Fraction Fraction:: subtract( Fraction b)
{
  res.num = (num * b.den) - (b.num * den);
  res.den = den * b.den;
  res.check();
  return res;
}


  Fraction Fraction:: multiply( Fraction b)
{
  res.den = den * b.den;
  res.num = num * b.num;
  res.check();
  return res;
}

   Fraction Fraction:: divide( Fraction b)
{
  res.num = num * b.den;
  res.den = den * b.num;
  res.check();
  return res;
}



 int main()
{
  int ch;
  char opt;
  Fraction result;

 do{
  cout<<"\nFractions\n";
  cout<<"1.Enter first fraction\n";
  cout<<"2.Enter second fraction\n";
  cout<<"3.Display both fractions\n";
  cout<<"4.Add the fractions\n";
  cout<<"5.Subtract the fractions\n";
  cout<<"6.Multiply the fractions\n";
  cout<<"7.Divide the fractions\n";
  cout<<"8.Exit\n";

  cout<<"\nEnter ur choice: ";
  cin>>ch;
  
  switch(ch)
 {

  case 1:
    cout<<"\nA";
    a.enter();
    break;
  
  case 2:
    cout<<"\nB";
    b.enter();
    break;
   
  case 3:
    cout<<"\nA:";
    a.print();
    cout<<"\nB:";
    b.print();
    break;
 
  case 4:
   
   result=a.add(b);
    cout<<"\nA + B:";                                  
   result.print();
   break;
 
  case 5:
  
   result=a.subtract(b);
   cout<<"\nA - B:";                            
   result.print();
   break;

  case 6:

   result= a.multiply(b);
   cout<<"\nA X B:";                              
   result.print();
   break;

  case 7:
  
   result= a.divide(b);
   cout<<"\nA/B:";                  
   result.print();
   break;  
 

  case 8:
  
   exit(0);
   break; 

  default: cout<<"Enter a valid choice!!\n";

 } 

 cout<<"\nDo you wish to continue?(Y/N): ";
 cin>>opt;

 }while(opt=='y'|| opt=='Y');        
 
 return 0;
}
 
