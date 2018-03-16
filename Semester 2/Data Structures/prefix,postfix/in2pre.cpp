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
 
 
 bool checkPre(char op1, char op2)                //returns true if precedence of op1 > op2
 {
   if((op1=='+' || op1=='-') && (op2=='/'||op2=='*'))
     return false;
   else
     return true;
 }
 
 
 char* infix_to_prefix(char* infix)
 {
   int length = strlen(infix);
   
   Stack<char> operandSt(length);
   Stack<char> operatorSt(length/2);
   int i;
   
   for(i=length-1;i>=0;i--)
   {
     if(isOperand(infix[i]))
       operandSt.push(infix[i]);
     
     else if(isOperator(infix[i]))
     {
       if(operatorSt.isEmpty())
	 operatorSt.push(infix[i]);
       else if(checkPre(infix[i],operatorSt.elementAtTop()))
	 operatorSt.push(infix[i]);
       else
       {
	 do{
	   
	   operandSt.push(operatorSt.pop());
	   
	   }while(!operatorSt.isEmpty() && !checkPre(infix[i],operatorSt.elementAtTop()) );
	 
	 operatorSt.push(infix[i]);
       }
	 
     }
   }
   
   while(!operatorSt.isEmpty())
     operandSt.push(operatorSt.pop());
   
   
   char* prefix = new char[length];
   
   i=0;
   while(!operandSt.isEmpty())
     prefix[i++]= operandSt.pop();
   
   prefix[i] = '\0';
   
   return prefix;
 }
 
 
 char* prefix_to_infix(char* prefix)
 {
   int length = strlen(prefix);
   
   Stack<char> operatorSt(length/2);
   int i=0,j=0;
   
   char* infix = new char[length];
      
   for(i=0;i<length;i++)
   {
     if(isOperator(prefix[i]))
       operatorSt.push(prefix[i]);
     else if(isOperand(prefix[i]))
     {
       infix[j++]= prefix[i];
       if(!operatorSt.isEmpty())
       infix[j++]= operatorSt.pop();
     }
   }
   
    infix[j]='\0';
   
    return infix;
 }
       
       
 
 
 
 
 int main()
 {
   char* infix = new char[20];
   char* prefix= new char[20];
   char opt;
   int ch;
  
 do{
 
   cout<<"\n--------------------------------------------------------------------------\n"; 
   cout<<"1.Enter infix. View prefix.\n";
   cout<<"2.Enter prefix. View infix.\n";
   cout<<"3.Exit\n";
   cout<<"\n--------------------------------------------------------------------------"; 
   cout<<"\nEnter choice: ";
   cin>>ch;
   cout<<"\n--------------------------------------------------------------------------"; 
   switch(ch)
   {
      case 1:
      cout<<"\nInfix  : ";
      cin>>infix;
      cout<<"Prefix : "<<infix_to_prefix(infix);
      
      break;
 
      case 2:
      cout<<"\nPrefix : ";
      cin>>prefix;
      cout<<"Infix  : "<<prefix_to_infix(prefix);
      break;  

      case 3:
      exit(0);
   }
   
   cout<<"\n--------------------------------------------------------------------------"; 
   cout<<"\nDo you wish to continue: ";
   cin>>opt;
 
 }while(opt=='y'||opt=='Y');
  
  cout<<"\n--------------------------------------------------------------------------\n"; 
   return 0;
   
   
 }