#include<iostream>
#include<cstdlib>

using namespace std;


 void bsearch(int a[20], int n)
{
  int beg=0,end=0,middle,ele;

  cout<<"\nEnter element to be searched: ";
  cin>>ele;

  middle = (beg+ end)/2;

  for(beg = 0, end = n-1; beg<=end && a[middle]!=ele;)
  {
    if(a[middle] > ele)
     end = middle -1;
    else
     beg = middle +1;

    middle = (beg+end)/2;
  }

  if(a[middle]==ele)
   cout<<"\nElement found at position "<<middle+1<<endl<<endl;
  else
   cout<<"\nElement not found!!\n\n";

}

  int main()
 {
   int a[20],n,pos;

   cout<<"\nEnter no of elements in array:\n";
   cin>>n;
   

   cout<<"\nEnter the array (in ascending order):\n";
   for(int i=0;i<n;i++)
    cin>>a[i];

    pos = bsearch(a,0,n-1,ele);

    if(pos!=-1)
     cout<<"\n"<<ele<<" found at "<<pos+1<<" position\n";
    else
     cout<<"\nElement was not found!\n\n";

 }
