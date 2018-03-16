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
  void change_ele(int);
  bool operator == (const array&);
  array& operator = (const array&);
  array& operator+ (array&);
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

  
  int array:: getele( int index)
{	
   return arr[index];
}


 void array:: change_ele(int index)
{
   arr[index] = 2* arr[index];
}

  
  array& array:: operator= (const array& A)
{
   int i;   
     
   cout<<"\nASSIGNMENT OPERATOR";
   size = A.size;
   for(i=0;i<size;i++)
     arr[i] = A.arr[i];

  return(*this);
}   

  array& array:: operator+ (array& A)
{
   int i;
  
   array* res = new array(size);   
 
    for(i=0;i<size;i++)
     res->arr[i] = arr[i] + A.arr[i];

    return (*res);
}

  bool array:: operator == (const array& A)
{
   int i;

      for(i=0;i<size;i++)
       {
          if(arr[i]!=A.arr[i])
            return false;
       }
   return true;
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

  cout<<"\nMatricies\n";
  cout<<"1.Enter first matrix\n";
  cout<<"2.Enter second matrix\n";
  cout<<"3.Display both matricies\n";
  cout<<"4.Add the matricies\n";
  cout<<"5.Subtract the matricies\n";
  cout<<"6.Multiply the matricies\n";
  cout<<"7.Transpose first matrix\n";
  cout<<"8.Transpose second matrix\n";
  cout<<"9.Exit\n";
  
   cout<<"\n--------------------------------------------------------------------------"; 
   cout<<"\nEnter choice: ";
   cin>>ch;
   cout<<"\n--------------------------------------------------------------------------"; 
   switch(ch)
   {
      case 1:
      cout<<"\nArray1:";
      A.fillarray();
      break;
 
      case 2:
      cout<<"\nArray2:";
      B.fillarray();
      break;  

      case 3:
      cout<<"\nArray1:";
      A.display();
      break;

      case 4:
      cout<<"\nArray2:";
      B.display();
      break;

      case 5:
      cout<<"\nEnter index: ";
      cin>>index;
      cout<<"Element at index "<<index<<" : "<<A.getele(index)<<endl;
      break;

      case 6:
      cout<<"\nEnter index: ";
      cin>>index;
      A.change_ele(index);
      cout<<"Element at index "<<index<<" has been changed. (Display array)\n";
      break;

      case 7:
      {             
        array C(A.size);   
        cout<<"\nA + B:\n";
        C = A + B;

        C.display();
      }
      break;
      
      case 8:
      {
        cout<<"\nA + B:\n";
        array C = A + B;

        C.display();
      }
      break;

      case 9:
       cout<<"\nThe arrays are ";
        if(A==B)
          cout<<"equal.\n";
        else
          cout<<"unequal.\n";
      break;			     

      case 10:
      exit(0);
   }
   
   cout<<"\n--------------------------------------------------------------------------"; 
   cout<<"\nDo you wish to continue: ";
   cin>>opt;
 
 }while(opt=='y'||opt=='Y');
  
  cout<<"\n--------------------------------------------------------------------------\n"; 
   return 0;
}  
 

