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
  void fillarray();
  void display();
  array& bsort();
  array& sel_sort();
  array& ins_sort();
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


  array& array:: bsort()
{
   array* b = new array(size);
   int i,j,temp;

   for(i=0;i<size;i++)
    b->arr[i] = arr[i];

   for(i=0;i<size-1;i++)
    {
      for(j=0;j<size-i-1;j++)
       {
          if(b->arr[j]>=b->arr[j+1])
            swap(b->arr[j],b->arr[j+1]);
       }
    }

     return *b;
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



  array& array:: ins_sort()
{
   array* b = new array(size);
   int i,j;

   for(i=0;i<size;i++)
    b->arr[i] = arr[i];

   for(i=1;i<size;i++)
    {
      int temp = b->arr[i];
      j = i;

        while(temp < b->arr[j-1] && j>0)
         {
            b->arr[j] = b->arr[j-1];
            j--;
         }

      b->arr[j] = temp;   
   
    }

   return *b;
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
   cout<<"3.Sort by bubble sort and display\n";
   cout<<"4.Sort by selection sort and display\n";
   cout<<"5.Sort by insertion sort and display\n";
   cout<<"6.Exit\n";
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
      B = A.bsort();
      cout<<"\nSorted array:";
      B.display();
      break;

      case 4:
      B = A.sel_sort();
      cout<<"\nSorted array:";
      B.display();
      break;

      case 5:
      B = A.ins_sort();
      cout<<"\nSorted array:";
      B.display();
      break;

      case 6:
      exit(0);
   }
   
   cout<<"\n--------------------------------------------------------------------------"; 
   cout<<"\nDo you wish to continue: ";
   cin>>opt;
 
 }while(opt=='y'||opt=='Y');
  
  cout<<"\n--------------------------------------------------------------------------\n"; 
   return 0;
}  
 

