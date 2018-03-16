#include<iostream>
#include<cstring>
#include<cstdlib>

using namespace std;

class complex
{
  float r;
  float c;

  public:
  void enter();
  void print();
  complex add(complex);
  complex subtract(complex);
  complex multiply(complex);
  complex divide(complex);
 
}a,b,res;

 
 void complex:: enter()
{
  cout<<"\nEnter real part     : ";
  cin>>r;

  cout<<"Enter imaginary part: ";
  cin>>c;

  cout<<endl;
}

 void complex:: print()
{
  cout<<"\nThe complex no is\n";
  if(c>0)
   cout<<r<<" + "<<c<<"i\n";
  else
   cout<<r<<"  "<<c<<"i\n";
  
}

 
  complex complex:: add(complex b)
{
   res.r= r + b.r;
   res.c= c + b.c;

   return res;
}

  complex complex:: subtract(complex b)
{
   res.r= r - b.r;
   res.c= c - b.c;

   return res;
}


 complex complex:: multiply(complex b)
{
  res.r = (r * b.r) - (c * b.c);
  res.c = (r * b.c) + (b.r * c);

   return res;
}
 
 complex complex:: divide(complex b)
{
  complex res1,res2;
  int denom;

  res1.r=  b.r;
  res1.c= -b.c;
 
  res2= multiply(res1);
  
  denom= (b.r * b.r) + (b.c * b.c); 
  
  res.r = res2.r/(float)denom;
  res.c = res2.c/(float)denom;

  return res;
}
 

 int main()
{
  int ch;
  char opt;
  complex result;

 do{
  cout<<"\nComplex Numbers\n";
  cout<<"1.Enter first complex no\n";
  cout<<"2.Enter second complex no\n";
  cout<<"3.Display both complex no.s\n";
  cout<<"4.Add the complex no.s\n";
  cout<<"5.Subtract the complex no.s\n";
  cout<<"6.Multiply the complex no.s\n";
  cout<<"7.Divide the complex no.s\n";
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
 
