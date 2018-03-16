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

