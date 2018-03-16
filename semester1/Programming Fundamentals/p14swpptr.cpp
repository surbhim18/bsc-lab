#include<iostream>
using namespace std;

/*
FORMAL PARAMETERS: a,b: pointers to integers
PURPOSE: swaps values using pointers
*/
 void swap(int* a,int* b)
{
  int temp;
  temp = *a;
  *a = *b;
  *b =temp;
 
}

/*
INPUT PARAMETER : a,b: integer
ACTUAL PARAMETER: x,y: pointers to integers
OUTPUT: prints swapped no.s
*/
 int main()
{
  int a,b;
  int *x, *y;

  cout<<"Enter 1st no: ";
  cin>>a;
  cout<<"Enter 2nd no: ";
  cin>>b;
  
  x =&a;
  y =&b;

  swap(x,y);

  cout<<"The swapped no's are "<<a<<" and "<<b<<endl;

  return 0;
}
