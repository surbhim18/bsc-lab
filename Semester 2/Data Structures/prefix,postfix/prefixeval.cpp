#include<iostream>
#include<cstring>
#include "stacks.h"

using namespace std;


 bool isOperator(char ch)
 {
   return(ch=='+'||ch=='-'||ch=='/'||ch=='*');
 }

 bool isOperand(char ch)
 {
   return((ch>='a'&& ch<='z')||(ch>='A' && ch<='Z'));
 }


 int perform(int a, char op, int b)
 {
   if(op=='+')
     return a+b;
   else if(op=='-')
     return a-b;
   else if(op=='*')
     return a*b;
   else if(op=='/')
     return a/b;
 }


 int pre_eval(char* prefix)
 {
   int length = strlen(prefix);
   Stack<int> resultSt(length/2+1);
   int res,val,a,b;

   int i;
   for(i=length-1 ;i>=0 ;i--)
   {
     if(isOperand(prefix[i]))
     {
       cout<<"Enter value of "<<prefix[i]<<": ";
       cin>>val;

       resultSt.push(val);
     }
     else if(isOperator(prefix[i]))
      {
	 a = resultSt.pop();
	 b = resultSt.pop();
         res = perform(a,prefix[i],b);
         resultSt.push(res);
      }
    }

   res = resultSt.pop();
   return res;
 }


 int main()
 {
   char* prefix= new char[20];
  // int result;

  cout<<"\n--------------------------------------------------------------------------";
  cout<<"\nPrefix : ";
  cin>>prefix;
  cout<<"--------------------------------------------------------------------------\n";
  cout<<"Result after evaluation: "<<pre_eval(prefix);

  cout<<"\n--------------------------------------------------------------------------\n";

  delete prefix;
  return 0;


 }
