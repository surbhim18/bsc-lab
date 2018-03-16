#include<iostream>
#include "StackSLL.h"
#include "MyException.h"

using namespace std;

StackSLL::StackSLL()
{
   top = 0;
}

StackSLL::~StackSLL()
{
    Node* temp;

    while(top)
    {
       temp = top;
       top = top-> next;
       delete temp;
    }
}

bool StackSLL:: isEmpty() const
{
    if(top == 0)
        return true;

    return false;
}

void StackSLL:: display() const
{
    Node* temp = top;

    if(temp == 0)
        cout<<"\nLink-list empty";
    else
    {
        cout<<"\nContents of link list:\n";
        while(temp!=0)
        {
            cout<<temp->data<<"  ";
            temp = temp->next;
        }
    }
}

void StackSLL:: push(int _data)
{
    if(top == 0)
    {
        top = new Node(_data);
    }
    else
    {
        Node* temp = new Node (_data,top);
        top = temp;
    }
}


int StackSLL:: pop()
{
    if(isEmpty())
        throw MyException("\nLink-list is empty.");

    int val = top->data;

    if(top->next==0)
    {
        delete top;
        top = 0;
    }
    else
    {
        Node* temp = top;
        top = top->next;
        delete temp;
    }

    return val;
}
