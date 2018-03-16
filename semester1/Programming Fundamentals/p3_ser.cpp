#include<iostream>

using namespace std;

/*
INPUT PARAMETERS: n :numeric
ITERATIVE PARAMETER: i
OUTPUT: prints sum of n terms of series
*/

 int main()
{
  float term,sum=0;
  int i,n;

  cout<<"\nSeries:\n";
  cout<<"1 + 1/2 + 1/3 + 1/4 + ....\n";
  cout<<"Enter no of terms: ";
  cin>>n;

  for(i=1;i<=n;i++)
  {                          
    term= 1/(float)i;     //explicit typecasting to convert result in float
    sum+=term;
   }

  cout<<"\nSum of "<<n<<" terms = "<<sum<<endl;

 }	
