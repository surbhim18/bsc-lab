#include<iostream>

using namespace std;

/*
INPUT PARAMETERS: n :numeric
ITERATIVE PARAMETER: i
OUTPUT: prints sum of n terms of series
*/

 int main()
{
  int sum=0,i,n,sign=1;

  cout<<"\nSeries:\n";
  cout<<"1 - 2 + 3 - 4 + ....\n";
  cout<<"Enter no of terms: ";
  cin>>n;

  for(i=1;i<=n;i++)
  {
    sum= sum + sign*i;
    sign*=-1;              //multiplied by -1 to get alternative values: 1 and -1
  }

  cout<<"\nSum of "<<n<<" terms = "<<sum<<endl;

 }
