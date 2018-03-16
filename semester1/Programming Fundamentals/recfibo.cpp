#include<iostream>
#include<cstdlib>

using namespace std;

 long fibo(long num)
{
  if(num==0 || num== 1)
   return num;
  else
   return (fibo(num-1) + fibo(num-2));
}

 int main()
{
 int n;
 cout<<"\nFibonacci Series\n";
 cout<<"Enter the no of elements: ";
 cin>>n;
 
 for(int i=0; i<n ;i++)
  cout<<"  "<<fibo(i);

 cout<<"\n\n";

}
