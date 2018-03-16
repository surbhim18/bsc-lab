//a^b using recursion

#include<iostream>
#include<cstdlib>

using namespace std;

 long calc(int num, int pow)
{
   if(pow==0)
    return 1;
   else
    return (num* calc(num,pow-1));
}

 
  int main()
{
  int num,pow;
  long val;

  cout<<"\nEnter no: ";
  cin>>num;

  cout<<"Enter power: ";
  cin>>pow;

  val = calc(num,pow);

  cout<<"\n"<<num<<"^"<<pow<<" = "<<val<<endl<<endl;

}

