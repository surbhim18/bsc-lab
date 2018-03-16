#include<iostream>
#include<cstdlib>

using namespace std;

 class array
{
  int* a;
  int n;

  public:
  void enter();
  void peven();
  void podd();
  void sumavg();
  void minmax();
  void rmdup();
  void prev();
  ~array()
  {
     delete []a;                //dynamically deallocates memory
  }
}arr;


//enter elements in array
 void array:: enter()
{
  int i;

  cout<<"\nEnter no of elements in array:\n";
  cin>>n;
  
  a = new int[n];               //dynamic allocation of an array with n elements

  cout<<"\nEnter the array:\n";
   for(i=0;i<n;i++)
    cin>>a[i];
}


//even valued elements are printed
 void array:: peven()
{
 int i;
 cout<<"Even valued elements are:\n";
      for(i=0;i<n;i++)
       {
         if(a[i]%2==0)
          cout<<a[i]<<"   ";
       }

}


//odd valued elements are printed
 void array:: podd()
{

  int i;
  cout<<"Odd valued elements are:\n";
      for(i=0;i<n;i++)
       {
         if(a[i]%2!=0)
          cout<<a[i]<<"   ";
       }
}


//sum and average of elements is calculated and printed
 void array:: sumavg()
{
  int i,sum=0,avg;

     for(i=0;i<n;i++)
       sum+=a[i];
     
     avg =sum/(float)n;              //explicitly typecasted to obtain correct result

     cout<<"Sum = " <<sum;
     cout<<"\nAverage = "<<avg;

 }


//minimum and maximum element of the array calculated and printed
 void array:: minmax()
 {
   int i,min=a[0];
        for(i=0;i<n;i++)
         {
            if(a[i]<min)
              min=a[i];
         }

       int   max=a[0];
        for(i=0;i<n;i++)
         {
            if(a[i]>max)
              max=a[i];
         }
    
     cout<<"Minimum= "<<min;
     cout<<"\nMaximum= "<<max;

 }


//duplicate elements of the array are removed
 void array:: rmdup()
 {
    int i,j,k,num; 
    num=n; 

        for(i=0;i<num;i++)
         {
          for(j=i+1;j<num;j++)    
           {
              if(a[i]==a[j])
              {
                for(k=j;k<num;k++)
                 a[k]=a[k+1];

                 j--; 
                 num--;                    //as a duplicate is removed, no of elements is reduced by 1              
              }
            }
        
         }


      for(i=0;i<num;i++)
       cout<<a[i]<<"   ";
            
 }


//array is reversed
 void array:: prev()
 {
    int i,j,temp;  
      for(i=0,j=n-1;i<n/2;i++,j--)   //variables intialised with first and last elements of the array
        {
           temp=a[i];
           a[i]= a[j];               //swapping done
           a[j]=temp;
         }

    cout<<"\n";
   for(i=0;i<n;i++)
    cout<<a[i]<<"  "; 

 }



/*
INPUT PARAMETER: ch: integer
PURPOSE:
various functions are called to perform different functions
*/

int main()
{

  int i,n,ch;
  float avg;
  char opt;
    
  arr.enter();  
 
  cout<<"\n";

 do{
  cout<<"Operations on arrays\n";
  cout<<"1.Print even valued elements\n";
  cout<<"2.Print odd valued elements\n";
  cout<<"3.Calculate sum and average\n";
  cout<<"4.Calculate minimum and maximum\n";
  cout<<"5.Remove duplicates\n";
  cout<<"6.Reverse the array\n";
  cout<<"7.Exit\n";
  cout<<"\nEnter ur choice: ";
  cin>>ch;
  
 

  switch(ch)
{
  
   case 1: arr.peven();   

   break;

   case 2: arr.podd();    

   break;

   case 3: arr.sumavg();
   
   break;

   case 4: arr.minmax(); 
         
   break;

   case 5: arr.rmdup();
      
   break;

   case 6: arr.prev();

   break;

   case 7: exit(0);
  
   break;

   default: cout<<"Please enter a valid choice\n";

 }
  cout<<"\n\nDo you wish to continue(Y/N): ";
  cin>>opt;

 }while(opt=='y'|| opt=='Y'); 




return 0;

}
