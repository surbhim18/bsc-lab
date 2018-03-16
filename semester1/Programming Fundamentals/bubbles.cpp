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
 adjacent elements are compared and the smaller no. is brought to the 
 beginning of the array
*/

 void bubblesort( int* a, int n)
{
  int i,j,temp,counter=0;

  for(i=0 ; i<n-1 ; i++)
  {
    for(j=0; j<n-i-1 ; j++)
     {
       if(a[j+1] < a[j])
        {
          temp = a[j];
          a[j] = a[j+1];
          a[j+1]= temp;
        }
       counter++;
     }
   
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

  bubblesort(b,n);
  
  cout<<"\nResultant array:";
  disp(b,n);

  delete []b;

}
