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
 
   
 int post_eval(char* postfix)
 {
   int length = strlen(postfix);
   Stack<int> resultSt(length/2+1);
   int res,val,a,b;
   
   int i;
   for(i=0;i<length;i++)
   {
     if(isOperand(postfix[i]))
     {
       cout<<"Enter value of "<<postfix[i]<<": ";
       cin>>val;
       
       resultSt.push(val);
     }
     else if(isOperator(postfix[i]))
      {
	 a = resultSt.pop();
	 b = resultSt.pop();
         res = perform(b,postfix[i],a);     
         resultSt.push(res);
      }
    }
     
   res = resultSt.pop();
   return res;
 }
 
 
 int main()
 {
   char* postfix= new char[20];
  // int result;
  
  cout<<"\n--------------------------------------------------------------------------";  
  cout<<"\nPostfix : ";
  cin>>postfix;
  cout<<"--------------------------------------------------------------------------\n";  
  cout<<"Result after evaluation: "<<post_eval(postfix);
  
  cout<<"\n--------------------------------------------------------------------------\n"; 
   
  delete postfix;
  return 0;
   
   
 }