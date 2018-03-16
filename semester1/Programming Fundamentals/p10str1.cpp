#include<iostream>
#include<cstring>
#include<cstdlib>

using namespace std;

 class strng
{
  char str[50];

  public:
  void enter();
  void print();
  void concte(strng);
  void compare(strng);
  int len();
  void uplower();
  void loupper();
  void cvowel();
  void substr();
}s1,s2;
  

 //Enters string in str[50]
   void strng:: enter()            
 {
  
   cout<<"\nEnter a string:\n";
   cin.getline(str,25);
   
 }

  
//Returns length of string
  int strng:: len()                
 {
    int i;
    for(i=0;str[i]!='\0';i++);
    return i;
 }


//Prints the string
  void strng:: print()
 {
   cout.write(str,len());
   cout<<"\n";
   
 }


//Concatenates 2 strings and prints the concatenated string
 void strng:: concte(strng s2)
{
  int i,j,length,temp,temp1;
  char cstr[50];
  
    
  for(i=0;i<len();i++,temp=i)                   //copying characters from 1st string
  cstr[i]=str[i];
  for(j=0;j<s2.len();j++,temp1=j)                //copying characters from 2nd string
  cstr[temp+j]=s2.str[j];
 
  cstr[temp+temp1]='\0'; 

  length= len()+ s2.len();
 
  cout<<"\nConcatenated string\n";
  cout.write(cstr,length);
  cout<<endl; 
}


//compares two strings and prints whether they are equal or not 
 void strng:: compare(strng s2)
{

  int i,flag=0;
  if(len()!=s2.len())
   cout<<"\nUnequal strings!!\n"; 
  else
    {
      for(i=0;str[i]!='\0';i++)
       {
          if(str[i]!=s2.str[i])
           {
             flag=1;
             break;
            }
     
       }

  if(flag==1)
     cout<<"\nUnequal strings!!\n";
  else
   cout<<"\nEqual strings!!\n";
   }

}


//converts upper case characters to lower case
  void strng:: uplower()
{
  int i;

  for(i=0;str[i]!='\0';i++)
  {
    if(str[i]>=65 && str[i]<=90)            //ascii values for A-Z is 65-90
    str[i]=str[i]+32;
  }
}


//converts lower case characters to upper case
  void strng:: loupper()
{
  int i;

  for(i=0;str[i]!='\0';i++)
  {
    if(str[i]>=97 && str[i]<=122)            //ascii values for a-z is 97-122
    str[i]=str[i]-32;
  }
}


//count the no. of vowels in the text
 void strng:: cvowel()
{
   int i,count=0;
   
   uplower();

    for(i=0;str[i]!='\0';i++)
    {
      if(str[i]=='a'|| str[i]=='e'|| str[i]=='i'|| str[i]=='o' || str[i]=='u')   
         count++;
     }

   cout<<"\nNo. of vowels: "<<count<<endl;

}


//finds the substring and prints the starting location, if present
  void strng:: substr()
{ char sub[50];
   int flag=0,pos,i,j;
 
   cout<<"\nEnter a substring\n";
   cin.getline(sub,50);

 if(len()<strlen(sub))
 {cout<<"\nLength of substring is greater than string itself!!";
   return;
 }
 else
  {
   for(i=0,j=0 ; str[i]!='\0' && sub[j]!='\0'; i++)
  {
         if(str[i]==sub[j])
           j++;
         else
           j=0;
   }                
          
 
  if(j==strlen(sub))
   cout<<"\nSubstring found at position "<<i-j+1<<endl;
  else
   cout<<"\nIt is not a substring\n";
 }
}


/*
INPUT PARAMETER: ch: integer
PURPOSE: calls different functions for different options
*/

  int main()
{
  int ch,len;
  char opt; 

do{

  cout<<"\nStrings\n";
  cout<<"1.Concatenate 2 strings\n";
  cout<<"2.Compare 2 strings\n";
  cout<<"3.Calculate length of string\n";
  cout<<"4.Convert upper case characters to lower case\n";
  cout<<"5.Convert lower case characters to upper case\n";
  cout<<"6.Calculate no. of vowels in the string\n";
  cout<<"7.Find a substring\n";
  cout<<"8.Exit\n";
  cout<<"\nEnter ur choice: ";
  cin>>ch;

  cin.ignore();
  switch(ch)
 {
   
   case 1: 
   s1.enter();
   
   s2.enter();
   s1.concte(s2);
   break;

  case 2:
  s1.enter();
  s2.enter();
  s1.compare(s2);
  break;

  case 3:
  s1.enter();
  len= s1.len();
  cout<<"\nLength of string = "<<len<<endl;
  break;

  case 4:
  s1.enter();
  s1.uplower();
  cout<<"\nResultant string is:\n";
  s1.print();
  break;
  
  case 5:
  s1.enter();
  s1.loupper();
  cout<<"\nResultant string is:\n";
  s1.print();
  break;

  case 6:
  s1.enter();
  s1.cvowel();
  break;

  case 7:
  s1.enter();
  s1.substr();
  break;

  case 8:
  exit(0);
  break;

  default: cout<<"\nEnter a valid choice\n";
 }

cout<<"\nDo u wish to continue?(Y/N):";
cin>>opt;

}while(opt=='y'|| opt=='Y');
 return 0;
}
