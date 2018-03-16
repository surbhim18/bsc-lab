//a X b by successive addition (using recursion)

#include<iostream>
#include<cstdlib>

using namespace std;

 long calc(int x, int y)
{
   if(y==1)
    return x;
   else
    return (x + calc(x,y-1));
}

  int main()
{
  int x,y;
  long val;

  cout<<"\nEnter 2 no: ";
  cin>>x>>y;

  val = calc(x,y);

  cout<<"\nA X B = "<<val<<"\n\n";

}
