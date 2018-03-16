#include<iostream>

using namespace std;

/*
INPUT PARAMETER: n: numeric
ITERATIVE PARAMETER: i,j
OUTPUT: triangle of n lines
*/

int main()
{
  int n,i,j;

  cout<<"Printing triangle...\n";
  cout<<"Enter the no of lines: ";\
  cin>>n;

  for(i=0;i<n;i++)             //loop for no. of lines
 {
   for(j=0;j<n;j++)	
    {
      if(i+j>=n-1)
        cout<<"*";
      else
        cout<<" ";
     }

   for(j=0;j<i;j++)
    cout<<"*";

  cout<<"\n";
 }

  return 0;

}


  
