#include<iostream>
#include<cstring>
#include<cstdlib>

using namespace std;

 class strng
{
  char str[100];
  char* s;

  public:
  strng()
  {
     strcpy(str,"\0");
     s = str;
  }

  void enter();
  void print();
  void concte(strng);
  void compare(strng);
  int len();
  void uplower();
  void loupper();
  void cvowel();
  void substr();
  char* getstring()
   {  return s; }

  void point() 
  {  s = str; }
};
  

 //Enters string in str[50]
   void strng:: enter()            
 {
   point();
   cout<<"\nEnter a string:\n";
   cin.getline(s,50);
   
 }

  
//Returns length of string
  int strng:: len()                
 {
    int i;
    point();
    for(i=0;*(s+i)!='\0';i++);
    return i;
 }


//Prints the string
  void strng:: print()
 {
   point();
   cout.write(s,len());
   cout<<"\n";
   
 }


//Concatenates 2 strings and prints the concatenated string
 void strng:: concte(strng s2)
{
  strng cstr;
  point();
  s2.point();
     

  while(*s)
   {
      *(cstr.s) = *s;
        
        (cstr.s)++; 
        s++;
   }

  while(*(s2.s))
   {
      *(cstr.s) = *(s2.s);
        
        (cstr.s)++; 
        s2.s++;
    }

  *(cstr.s)= '\0';
  
    
  cout<<"\nConcatenated string\n";
  cstr.print();
}


//compares two strings and prints whether they are equal or not 
 void strng:: compare(strng s2)
{

  point();
  s2.point();
 
  int i,flag=0;

  if(len()!=s2.len())
   cout<<"\nUnequal strings!!\n"; 
  else
    {
      for(i=0;*(s+i)!='\0';i++)
       {
          if( *(s+i) != *(s2.s+i) )
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

  for(i=0;*(s+i)!='\0';i++)
  {
    if(*(s+i)>=65 && *(s+i)<=90)            //ascii values for A-Z is 65-90
    *(s+i) += 32;
  }
}


//converts lower case characters to upper case
  void strng:: loupper()
{
  int i;

  for(i=0;*(s+i)!='\0';i++)
  {
    if(*(s+i)>=97 && *(s+i)<=122)            //ascii values for a-z is 97-122
    *(s+i) -= 32;
  }
}


//count the no. of vowels in the text
 void strng:: cvowel()
{
   int i,count=0;
   
   uplower();

    for(i=0;*(s+i)!='\0';i++)
    {
      if(*(s+i)=='a'|| *(s+i)=='e'||*(s+i)=='i'|| *(s+i)=='o' || *(s+i)=='u')   
         count++;
     }

   cout<<"\nNo. of vowels: "<<count<<endl;

}


//finds the substring and prints the starting location, if present
  void strng:: substr()
{ char sub[50];
   int i,j;
 
   cout<<"\nEnter a substring\n";
   cin.getline(sub,50);

 if(len()<strlen(sub))
 {cout<<"\nLength of substring is greater than string itself!!";
   return;
 }
 else
  {
   for(i=0,j=0 ; *(s+i)!='\0' && *(sub+j)!='\0'; i++)
  {
         if(*(s+i)==*(sub+j))
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
  strng s1,s2;

do{

  cout<<"\nStrings\n";
  cout<<"1.Enter first string\n";
  cout<<"2.Enter second string\n";
  cout<<"3.Concatenate 2 strings\n";
  cout<<"4.Compare 2 strings\n";
  cout<<"(first string)\n";
  cout<<"5.Calculate length of string\n";
  cout<<"6.Convert upper case characters to lower case\n";
  cout<<"7.Convert lower case characters to upper case\n";
  cout<<"8.Calculate no. of vowels in the string\n";
  cout<<"9.Find a substring\n";
  cout<<"10.Exit\n";
  cout<<"\nEnter ur choice: ";
  cin>>ch;

  cin.ignore();
  switch(ch)
 {
   
   case 1:
   s1.enter();
   break;

   case  2:
   s2.enter();
   break;

   case 3: 
   s1.concte(s2);
   break;

  case 4:
  s1.compare(s2);
  break;

  case 5:
  len= s1.len();
  cout<<"\nLength of string \""<<s1.getstring()<<"\" = "<<len<<endl;
  break;

  case 6:
  s1.uplower();
  cout<<"\nResultant string is:\n";
  s1.print();
  break;
  
  case 7:
  s1.loupper();
  cout<<"\nResultant string is:\n";
  s1.print();
  break;

  case 8:
  s1.cvowel();
  break;

  case 9:
  s1.substr();
  cout<<endl;
  break;

  case 10:
  exit(0);
  break;

  default: cout<<"\nEnter a valid choice\n";
 }

cout<<"\nDo u wish to continue?(Y/N):";
cin>>opt;

}while(opt=='y'|| opt=='Y');
 return 0;
}
