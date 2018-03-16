#include<iostream>
#include "SLL.h"

using namespace std;

SLL::SLL()
{
    head = tail =0;
}

SLL::~SLL()
{
    Node* temp;

    while(head)
    {
        temp = head;
        head = head-> next;
        delete temp;
    }
}

bool SLL:: isEmpty() const
{
    if(head == 0 && tail == 0)
        return true;

    return false;
}

void SLL:: display() const
{
    Node* temp = head;

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

void SLL:: addToList(float _data)
{
    if(head == 0)
    {
        head = new Node(_data);
        tail = head;
    }
    else
    {
        Node* newNode = new Node(_data);
        Node *temp, *prev;

        temp=head;
        prev=0;

        while((temp->data < newNode->data) && temp!=0)
        {
            prev = temp;
            temp = temp->next;
        }

        if(prev==0)
        {
            newNode->next = head;
            head= newNode;
        }
        else if(prev==tail)
        {
            tail->next = newNode;
            newNode->next = 0;
            newNode = tail;
        }
        else
        {
            prev->next = newNode;
            newNode->next = temp;
        }
    }
}

float SLL:: deleteFromHead()
{
    float data = head->data;

    Node* temp = head;
    if(head==tail)
    {
        head=tail=0;
    }
    else
    {
        head = head->next;
    }

    delete temp;
    return data;
}
