#include<iostream>

using namespace std;

/*
INPUT PARAMETER: n: numeric
OUTPUT: factors of n
APPROACH:
The entered no. is divided by all numbers which are less than equal to half of it.
If the remainder is zero the number is a factor
*/

int main()
{
  int i,n;
 
  cout<<"\nEnter the no. whose factors u wish to calculate: ";
  cin>>n;

  cout<<"Factors of "<<n<<" are:\n";
  for(i=1;i<=n/2;i++)
 {
    if(n%i==0)
     cout<<i<<"     ";                //factors printed
 }
  cout<<n<<endl;                           //entered no. printed seperately

  return 0;

}
