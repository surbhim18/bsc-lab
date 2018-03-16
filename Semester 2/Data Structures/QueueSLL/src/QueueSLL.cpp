#include "QueueSLL.h"
#include<iostream>
#include "MyException.h"

using namespace std;

QueueSLL::QueueSLL()
{
   frontt = rear =0;
}

QueueSLL::~QueueSLL()
{
    Node* temp;

    while(frontt)
    {
       temp = frontt;
       frontt = frontt-> next;
       delete temp;
    }
}

bool QueueSLL:: isEmpty() const
{
    if(frontt == 0 && rear == 0)
        return true;

    return false;
}

void QueueSLL:: display() const
{
    Node* temp = frontt;

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

void QueueSLL:: enqueue(int _data)
{
    if(rear == 0)
    {
        rear = new Node(_data);
        frontt = rear;
    }
    else
    {
        rear->next  = new Node(_data);
        rear = rear->next;
    }
}


int QueueSLL:: dequeue()
{
    if(isEmpty())
        throw MyException("\nLink-list is empty.");

    int val = frontt->data;

    if(frontt==rear)
    {
        delete frontt;
        frontt = rear = 0;
    }
    else
    {
        Node* temp = frontt;
        frontt = frontt->next;
        delete temp;
    }

    return val;
}
