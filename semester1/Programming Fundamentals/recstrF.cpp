#include<iostream>
#include<cstdlib>
#include<cstring>

using namespace std;

 void print(char str[20],int len)
{
  static int i=0;
   
    if(i==len-1)
     { 
       cout<<str[i];
      // return;
     }
    else
     {
        cout<<str[i++];
        print(str,len);
     }
}


  int main()
{
  char str[20];
  cout<<"\nEnter a string:\n";
  cin.getline(str,20);
  
  cout<<"\n";
  cout<<"String:\n";
  print(str, strlen(str));
  cout<<"\n\n";
  return 0;
}
