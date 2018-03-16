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
 One element is compared to the unsorted elements and the 
 smallest element is placed in the array
 starting from the beginning
*/

 void selectionsort(int* a, int n)
{
  int i,j,pos,min,temp,counter=0;

  for(i=0; i<n ; i++)
  {
    min = a[i];  
    pos = i;

    for(j=i+1; j<n ; j++)
     {
        if(a[j]<min)
         {
           min = a[j];
           pos = j;
         }
       counter++;
     }

  temp   = a[i];
  a[i]   = a[pos];
  a[pos] = temp;

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

  selectionsort(b,n);
  
  cout<<"\nResultant array:";
  disp(b,n);

  delete []b;

}
