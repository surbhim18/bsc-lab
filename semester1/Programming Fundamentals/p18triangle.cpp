#include<iostream>
#include<cmath>
#include<cstdlib>

using namespace std;

/*
DATA MEMBERS    : a,b,c : numeric
MEMBER FUNCTIONS: enter,check,print,callarea
                  operator=, operator==
*/ 
 class triangle
{
  int a;
  int b;
  int c;

  public:
  void enter();
  bool check();
  void print();
  void callarea();
  triangle& operator = (triangle&);
  bool operator == (triangle);  
  
};


/*
FORMAL PARAMETER: NULL
PURPOSE: checks whether sides form a triangle
RETURN: true if sides form a triangle
        false if sides don't form a triangle
*/

 bool triangle:: check()
{
  return((a+b>= c && a+c>=b && b+c>=a)&&(a>0 && b>0 && c>0));
} 


/*
FORMAL PARAMETER: NULL
PURPOSE: enters values in a,b,c
       : calls function check()
RETURN: void
*/

 void triangle:: enter()
{
  cout<<"\nSide 1: ";
  cin>>a;
  cout<<"Side 2: ";
  cin>>b;
  cout<<"Side 3: ";
  cin>>c;
 
  if(!(check()))
  {
    cout<<"Values do not form a triangle!! Terminating!!\n\n";
    exit(0);
  }
}


/*
FORMAL PARAMETER: NULL
PURPOSE: displays values of a,b,c
RETURN: void
*/

 void triangle:: print()
{
  cout<<"\nSide 1: "<<a;
  cout<<"\nSide 2: "<<b;
  cout<<"\nSide 3: "<<c;
  cout<<endl;
}
 

/*
FORMAL PARAMETER: a: integer
PURPOSE: calculates area of an equilateral triangle
RETURN: area of the equilateral triangle
*/

 float area(int a)
{
  return((sqrt(3)*a*a)/4.0 );
}


/*
FORMAL PARAMETER: a,b : integer
PURPOSE: calculates area of an isosceles triangle
RETURN: area of the isosceles triangle
*/

 float area(int a, int b )
{
  float s,ar1;
   s = (a+b+b)/2.0;
   ar1 = s*(s-a)*(s-b)*(s-b);

   return (sqrt(ar1));
}


/*
FORMAL PARAMETER: a,b,c : integer
PURPOSE: calculates area of a triangle
RETURN: area of the triangle
*/

 float area(int a,int b, int c)
 {
   float s,ar1;
   s = (a+b+c)/2.0;
   ar1 = s*(s-a)*(s-b)*(s-c);

   return (sqrt(ar1));
 }


/*
FORMAL PARAMETER: NULL
PURPOSE: calls one of the overloaded functions area()
         as per the sides
       : prints the area
RETURN: void
*/

 void triangle:: callarea()
{
  float res;
 
   if(a==b && b==c)
    res= area(a);
   else if(a==b)
    res = area(c,a);
   else if(b==c)
    res =  area(a,b);
   else if(a==c)
    res = area(b,c);
   else
    res = area(a,b,c);
  
 cout<<"  "<<res<<endl;

 } 


/*
FORMAL PARAMETER: t1: reference to an object of triangle
PURPOSE: assigns value of one triangle to another
RETURN: reference to the calling object
*/
 
 triangle& triangle:: operator = (triangle& t1)
{
   a = t1.a;
   b = t1.b;
   c = t1.c;

   return (*this);
}


/*
FORMAL PARAMETER: t1: triangle
PURPOSE: checks whether two triangles are congruent
RETURN: true if triangles are congruent
        false if triangles are not congruent
*/

 bool triangle:: operator == (triangle t1) 
{
   return((a== t1.a && b== t1.b && c== t1.c)||(a== t1.b && b== t1.c && c==t1.a)||(a== t1.c && b== t1.a && c== t1.b));   
} 
  


/*
INPUT PARAMETER: ch: integer
                opt: char                 
PURPOSE: calls functions as per requirement
*/
 
 int main()
{
   int ch;
   char opt;
   triangle t1,t2,t3;

do{
   cout<<"\n------------------------------------------------------------------------\n";
   cout<<"\nMENU\n";
   cout<<"1.Enter first triangle\n";
   cout<<"2.Enter second triangle\n";
   cout<<"3.Display both triangles\n";
   cout<<"4.Calculate the area of both triangles\n";
   cout<<"5.Check if the two triangles are congruent\n";
   cout<<"6.Assign Triangle 1 to Triangle 2 (display using 3.)\n";
   cout<<"7.Exit\n";
   cout<<"------------------------------------------------------------------------\n";
   cout<<"\nEnter your choice: ";
   cin>>ch;
   cout<<"\n------------------------------------------------------------------------\n";  

   switch(ch)
   {
     case 1:
     cout<<"\nEnter triangle 1:"; 
     t1.enter();
     break;

     case 2:
     cout<<"\nEnter triangle 2:"; 
     t2.enter();
     break;
 
     case 3:
     cout<<"\nTriangle 1:";
     t1.print();
     cout<<"\nTriangle 2:";
     t2.print();
     break;

     case 4:
     cout<<"\nArea of\nTriangle 1:";
     t1.callarea();
     cout<<"\nTriangle 2:";
     t2.callarea();
     break;

     case 5:
     if(t1==t2)
      cout<<"\nThe two triangles are congruent\n";
     else 
      cout<<"\nThe two triangles are not congruent\n";
     break;

     case 6:
     t2 = t1;
     cout<<"\nTriangle 1 has been assigned to Triangle 2\n";
     break;

     case 7:
     exit(0);
     break;

     default: cout<<"\Enter a valid choice!\n";

   }
  
  cout<<"\n------------------------------------------------------------------------\n";
  cout<<"Do you wish to continue?(Y/N): ";
  cin>>opt;

 }while(opt=='y'|| opt=='Y');

return 0;
}
   
   
 

