#include<iostream>
#include<cstdlib>
#include<cstring>

using namespace std;

class MyException
{
  string msg;

  public:
  MyException(string str)
   {
     msg = str;
   }
 
  void print() const
  {
    cout<<msg;
  }
};  


template<class T>
class Stack
{
  T* array;
  int top;     // index of topmost element
  int length;

  public:
  Stack(int length1=0);
  void push(T);
  T pop();
  bool isEmpty();
  bool isFull();
  T elementAtTop();
  void clearStack();
  void display() const;
  ~Stack()
   { delete []array; }

};

 template<class T>
 Stack<T>:: Stack(int length1)
{
   if(length1<=0)                                   
     throw MyException("\nLength cannot be negative or zero\n");
   else
    {
      length = length1;                       
         top = -1;
       array = new T[length];
    }
}


  template<class T>
  bool Stack<T>:: isEmpty()
{
  if(top==-1)
    return true;
  else
    return false;
}


  template<class T>
  bool Stack<T>:: isFull()
{
  if(top==length-1)
    return true;
  else
    return false;
}

  
 template<class T>
 void Stack<T>:: push(T element)
{
   if(isFull())                          
     throw MyException("\nStack Overflow!");
   else
    {
      top++;
      array[top] = element;
    }
}

 
 template<class T>
 T Stack<T>:: pop()
{
   if(isEmpty())
       throw MyException("\nStack Underflow!");
   else
   { 
     int rtop = top--;
     return array[rtop];
   }
}
 
 template<class T>
 T Stack<T>:: elementAtTop()
{
    if(isEmpty())
      throw MyException("\nStack Underflow!");  
   else
    return array[top];
}

 template<class T>
 void Stack<T>:: clearStack()
{
   top = -1;
}

template<class T>
  void Stack<T>:: display() const
{
  if(top==-1)
    cout<<"\nStack is empty\n";
  else
   {
     cout<<"\nCurrent stack\n"; 
     for(int i=top; i>=0; i--)
     cout<<array[i]<<"   ";
   }
}

  int main()
{
   int ch,size;
   char opt;
	Stack<int>* A;
    
    cout<<"\n--------------------------------------------------------------------------";   
    cout<<"\nEnter size of stack: "; 
      cin>>size;

     try 
    {
      A=new Stack <int>(size);
    }
    catch(MyException ex)
	{
	  ex.print();
          exit(0);
	}

   int element;

 do{
 
   cout<<"\n--------------------------------------------------------------------------\n"; 
   cout<<"1.Push element in the stack\n";
   cout<<"2.Pop an element\n";
   cout<<"3.Display the stack\n";
   cout<<"4.Exit\n";
   cout<<"\n--------------------------------------------------------------------------"; 
   cout<<"\nEnter choice: ";
   cin>>ch;
   cout<<"\n--------------------------------------------------------------------------"; 
   switch(ch)
   {
      case 1:
      cout<<"\nEnter element: ";
      cin>>element;
	try
	{
      		A->push(element);
	}
	catch(MyException ex)
	{
	  ex.print();
	}
      break;
 
      case 2:
	try
	{
         element = A->pop();
         cout<<"\nElement: "<<element;
	}
	catch(MyException ex)
	{
	  ex.print();
	}

      break;  

      case 3:
      A->display();
      break;

      case 4:
      exit(0);
   }
   
   cout<<"\n--------------------------------------------------------------------------"; 
   cout<<"\nDo you wish to continue: ";
   cin>>opt;
 
 }while(opt=='y'||opt=='Y');
  
  cout<<"\n--------------------------------------------------------------------------\n"; 
  
  delete A; 
  return 0;
}  
 

 
