#include<iostream>
#include<cstdlib>

using namespace std;

 
 class array
{
  int* arr;
  
  public:
  int size;
  array() {   };
  array(int);
  array(const array&);
  void fillarray();
  void display();
  int getele(int);
  int lsearch(int);
  int bsearch(int);
  array& sel_sort();
  ~array()
  { delete []arr; }

};

  array:: array(int n)
{
   size = n;
   arr = new int[size];
   int i;
   for(i=0;i<size;i++)
    arr[i] = -1;
}

  array:: array (const array& A)
{
   int i;
   cout<<"COPY CONSTRUCTOR\n";

   size = A.size;
   arr = new int[size];
   for(i=0;i<size;i++)
     arr[i] = A.arr[i];
}
  

  void array:: fillarray()
{
   int i;
   cout<<"\nEnter elements:\n";
  
   for(i=0 ; i<size ; i++)
    {
        cout<<"Element["<<i<<"] : ";
        cin>>arr[i];
    }

}


  void array:: display()
{
  int i;
   cout<<"\nElements:";
  
   for(i=0 ; i<size ; i++)
    {
        cout<<"\nElement["<<i<<"] : ";
        cout<<arr[i];
    }

  cout<<endl;
}


inline void swap(int &a, int &b)
 {
   int temp;
     temp = a;
        a = b;
        b = temp;
 }


 array& array:: sel_sort()
{
   array* b = new array(size);
   int i,j;

   for(i=0;i<size;i++)
    b->arr[i] = arr[i];

   for(i=0;i<size;i++)
    {
       int minLoc =i;
  
      for(j=i+1;j<size;j++)
       {
          if(b->arr[j] < b->arr[minLoc])
            minLoc = j;
        }
         
      swap(b->arr[i],b->arr[minLoc]);
    }

   return *b;
}




  int array:: lsearch(int ele)
{
   for(int i=0;i<size;i++)
   {
      if(arr[i]==ele)
        return i;
   }

   return -1;
}


 int array:: bsearch(int ele)
 {
    int beg,end,mid;

    for(beg=0,end=size-1; beg<=end && arr[mid]!=ele; )
    {
       mid = (beg+end)/2;

        if(arr[mid]>=ele)
         end = mid -1;
        else
         beg = mid +1;
    }

   if(ele==arr[mid])
    return mid;
   else
    return -1;
}
 






  int main()
{
   int ch,size,ele,index;
   char opt;
    
    cout<<"\n--------------------------------------------------------------------------";   
    cout<<"\nEnter size of array: "; 
      cin>>size;

    array A(size), B(size);

 do{
 
   cout<<"\n--------------------------------------------------------------------------\n"; 
   cout<<"1.Enter array\n";
   cout<<"2.Display array\n";
   cout<<"3.Search using linear search\n";
   cout<<"4.Search using binary search\n";
   cout<<"5.Exit\n";
   cout<<"\n--------------------------------------------------------------------------"; 
   cout<<"\nEnter choice: ";
   cin>>ch;
   cout<<"\n--------------------------------------------------------------------------"; 
   switch(ch)
   {
      case 1:
      cout<<"\nArray:";
      A.fillarray();
      break;
 
      case 2:
      cout<<"\nArray:";
      A.display();
      break;

      case 3:
      cout<<"\nEnter element to be searched: ";
      cin>>ele;
      index = A.lsearch(ele);
      if(index!=-1)
       cout<<"\nElement found.";
      else
       cout<<"\nElement not found.";
      break;

      case 4:
      cout<<"\nEnter element to be searched: ";
      cin>>ele;
      B = A.sel_sort();
      index = B.bsearch(ele);
      if(index!=-1)
       cout<<"\nElement found.";
      else
       cout<<"\nElement not found.";
      break;

      case 5:
      exit(0);
   }
   
   cout<<"\n--------------------------------------------------------------------------"; 
   cout<<"\nDo you wish to continue: ";
   cin>>opt;
 
 }while(opt=='y'||opt=='Y');
  
  cout<<"\n--------------------------------------------------------------------------\n"; 
   return 0;
}  
 

