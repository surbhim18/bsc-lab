#include<iostream>
#include<cstdlib>
#include<cstring>

using namespace std;

 void print(char str[20],int len)
{
  if(len==1)
  {
    cout<<str[0];
  }
  else
  {
   cout<<str[len-1];
   print(str,len-1);
  }
}

 int main()
{
  char str[20];
  cout<<"\nEnter a string:\n";
  cin.getline(str,20);

  cout<<"\nReversed string:\n";
  print(str, strlen(str));
  cout<<"\n\n";
  return 0;
}
