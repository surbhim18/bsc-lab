#include<iostream>
#include<cstdlib>

using namespace std;

 
 int bsearch(int a[20], int beg,int end, int ele)
{
   int middle = (beg + end)/2;

    if(a[middle]==ele || beg >= end)
    {
       if(a[middle]==ele)
         return middle;
       else
         return -1;
    } 
    else
    {
        if(a[middle] >= ele)
          return bsearch(a ,beg ,middle-1 ,ele);
        else
          return bsearch(a,middle+1,end,ele);
    }

}
     

  int main()
{
   int a[20],n,ele,pos;

   cout<<"\nEnter no of elements in array:\n";
   cin>>n;
   
   cout<<"\nEnter the array (in ascending order):\n";
   for(int i=0;i<n;i++)
    cin>>a[i];

   cout<<"\nEnter element to be searched: ";
   cin>>ele;

   pos =  bsearch(a,0,n-1,ele);

   if(pos!=-1)
    cout<<"\nYour element ie "<<ele<<" found at position "<<pos+1<<"\n\n";
   else
    cout<<"\nElement not found!!\n\n";
}
