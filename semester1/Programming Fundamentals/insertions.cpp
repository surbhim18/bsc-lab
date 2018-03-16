#include<iostream>
#include<cstring>

using namespace std;

 void disp( int* a, int n)
{
  cout<<endl;  

  for(int i=0; i<n; i++)
   cout<<"  "<<a[i];

  cout<<endl;
}

/*
 INPUT PARAMETER: an array
 RETURN: a sorted array
 APPROACH:
 The array is considered to be divided into 2 parts- sorted & unsorted
 Elements are inserted from the unsorted part to the sorted part
 one by one
*/


 void insertionsort(int* a, int n)
{
  int i,j,pos,ele,counter=0;
 
  for(j=1;j<n;j++)
   {
     ele = a[j];
     i = j-1;
  
       while(i >= 0 && a[i] > ele)
        {
           counter++;
           a[i+1] = a[i];
           i--;
           pos = i;
        }

    a[pos+1] = ele;
   
    disp(a,n);   

   }

   cout<<"\nTotal no. of comaprisons: "<<counter<<endl;
}


 
 int main()
{

  int n;
  
  cout<<"\nEnter no. of elements: ";
  cin>>n;

  int* b= new int[n];

  for(int i=0;i<n;i++)
  cin>>b[i];

  insertionsort(b,n);
  
  cout<<"\nResultant array:";
  disp(b,n);

  delete []b;

}

