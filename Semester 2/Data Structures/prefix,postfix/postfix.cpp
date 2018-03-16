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
   if((op1=='/' || op1=='*') && (op2=='+'||op2=='-'))
     return true;
   else
     return false;
 }
 
 
 char* infix_to_postfix(char* infix)
 {
   int length = strlen(infix);
   
   Stack<char> operatorSt(length/2);
   int i,j=0;
   
   char* postfix = new char[length];
    
 
   for(i=0;i<length;i++)
   {
     if(isOperand(infix[i]))
       postfix[j++]=infix[i];
     
     else if(isOperator(infix[i]))
     {
       if(operatorSt.isEmpty())
	 operatorSt.push(infix[i]);
       else if(checkPre(infix[i],operatorSt.elementAtTop()))
	 operatorSt.push(infix[i]);
       else
       {
	 do{
	   
	   postfix[j++] = operatorSt.pop();
	   
	   }while(!operatorSt.isEmpty() && !checkPre(infix[i],operatorSt.elementAtTop()) );
	 
	 operatorSt.push(infix[i]);
       }
	 
     }
   }
   
   while(!operatorSt.isEmpty())
      postfix[j++] = operatorSt.pop();
   
   postfix[j]='\0';
   
   return postfix;
 }
 
 
 char* postfix_to_infix(char* postfix)
 {
   int length = strlen(postfix);
   
   Stack<char> operandSt(length);
   Stack<char> operatorSt(length/2);
   int i=0,j=0;
   
   
   for(i=length-1;i>=0;i--)
   {
     if(isOperator(postfix[i]))
       operatorSt.push(postfix[i]);
     else if(isOperand(postfix[i]))
     {
       operandSt.push(postfix[i]);
       
       if(!operatorSt.isEmpty())
       operandSt.push(operatorSt.pop());
     }
   }
   
    while(!operatorSt.isEmpty())
       operandSt.push(operatorSt.pop());
      
   char* infix = new char[length];
   
   i=0;
   while(!operandSt.isEmpty())
     infix[i++]= operandSt.pop();
   
   infix[i] = '\0';
   
   return infix;
 }
       
 
 
 
 
 int main()
 {
   char* infix = new char[20];
   char* postfix= new char[20];
   char opt;
   int ch;
  
 do{
 
   cout<<"\n--------------------------------------------------------------------------\n"; 
   cout<<"1.Enter infix. View postfix.\n";
   cout<<"2.Enter postfix. View infix.\n";
   cout<<"3.Exit\n";
   cout<<"\n--------------------------------------------------------------------------"; 
   cout<<"\nEnter choice: ";
   cin>>ch;
   cout<<"\n--------------------------------------------------------------------------"; 
   switch(ch)
   {
      case 1:
      cout<<"\nInfix   : ";
      cin>>infix;
      cout<<"Postfix : "<<infix_to_postfix(infix);
      
      break;
 
      case 2:
      cout<<"\nPostfix : ";
      cin>>postfix;
      cout<<"Infix   : "<<postfix_to_infix(postfix);
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