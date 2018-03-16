#include<iostream>

using namespace std;

/*
INPUT PARAMETERS: num
OUTPUT: sum and product of the digits of num
*/



int main()
{
  int digit,num,sum,pro;

  cout<<"Enter a no sum& product of whose individual digits you wish to calculate:\n";
  cin>>num;

  sum=0;                     
  pro=1;                     
 
  while(num)                   //The loop works till number is not equal to 0
 {
   digit=num%10;               //Extracts digit at unit place of number
   num=num/10;                 //Divides number by 10

   sum+=digit;              
   pro=pro*digit;           

 }
 
 cout<<"\nSum: "<<sum;
 cout<<"\nProduct: "<<pro<<"\n";

return 0;
}
