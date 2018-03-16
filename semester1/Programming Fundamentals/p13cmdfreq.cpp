#include<iostream>
#include<cctype>

using namespace std;

/*
User Inputs: argc: integer: no of arguements passed as command line arguements
            argv[]: char : arguements in the form of strings
OUTPUT: no. of occurences of a particular character
PURPOSE: prints the occurences of a particular character
*/

int main(int argc,char* argv[])
{
  int i,j;
  int freq[26]={0};
  char ch2,ch1;

   for(i=1;i<argc;i++)                  //loop starts from 1 since the 0th arguement points to executable itself
  {
    for(j=0;argv[i][j]!='\0';j++)       //loop works till the last character of last string is not null
     {
        ch1= toupper(argv[i][j]);
        freq[ch1-65]++;                 //freq[0] contains frequency of A 
     }
  }

  for(i=0;i<26;i++)
  {
    if(freq[i]!=0)                     //printed only if character is present atleast one
     {
       ch2= 65+i;                      //implicitly typecasted to a character
       cout<<"  "<<ch2<<" | "<<freq[i]<<endl;
     }
  }

  return 0;

 }
