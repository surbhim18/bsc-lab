#include<iostream>
#include<cstring>

using namespace std;

/*
FORMAL PARAMETER: str[80]: char
PURPOSE: to check whether a string is palindrome or not
RETURN: 1 if string is palindrome
        0 if not a palindrome
*/

 int cpalin( char str[80])
{
  int i,j,len,ch=1;
  
  len= strlen(str);

  for(i=0,j=len-1; i<len/2 ;i++,j--)      //intialises variables with first and last char of string
  {
     if(str[i]!=str[j])
       {
         ch=0;
         break;                          //breaks as soon as there is a mismatch
       }
   }

  return ch;
} 
   
/*
INPUT PARAMETERS: str[80]: char
OUTPUT: prints whether a string is palindrome or not
*/
  

int main()
{
  char str[80];
  int ch;

  cout<<"To check whether a string is palindrome or not: ";
  cout<<"\nEnter string: ";
  cin.getline(str,80);
  
  ch= cpalin(str);


  cout.write(str,strlen(str));
  if(ch==1)
  cout<<" is  a palindrome\n";
  else
  cout<<" is not a palindrome\n";


  return 0;
}
