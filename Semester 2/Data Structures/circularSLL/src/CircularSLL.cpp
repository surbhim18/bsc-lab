#include "CircularSLL.h"
#include<iostream>
#include "MyException.h"

using namespace std;

CircularSLL::CircularSLL()
{
   head = tail =0;
}

CircularSLL::~CircularSLL()
{
    Node* temp = head->next;
    Node* temp1;

    while(temp!=head)
    {
       temp1 = temp;
       temp = temp-> next;
       delete temp1;
    }
    delete head;
}

bool CircularSLL:: isEmpty() const
{
    if(head == 0 && tail == 0)
        return true;

    return false;
}

void CircularSLL:: display() const
{

    if(head == 0)
        cout<<"\nLink-list empty";
    else
    {
        cout<<"\nContents of link list:\n";
        cout<<head->data<<"  ";
        Node* temp = head->next;
        while(temp!=head)
        {
            cout<<temp->data<<"  ";
            temp = temp->next;
        }
    }
}

void CircularSLL:: addToHead(int _data)
{
    if(head == 0)
    {
        head = new Node(_data);
        tail = head;
    }
    else
    {
        Node* temp = new Node (_data,head);
        head = temp;
    }
    tail->next = head;
}

void CircularSLL:: addToTail(int _data)
{
    if(tail == 0)
    {
        tail = new Node(_data);
        head = tail;
    }
    else
    {
        tail->next  = new Node(_data);
        tail = tail->next;
    }
    tail->next = head;
}


int CircularSLL:: deleteFromHead()
{
    if(isEmpty())
        throw MyException("\nLink-list is empty.");

    int val = head->data;

    if(head==tail)
    {
        delete head;
        head = tail = 0;
    }
    else
    {
        Node* temp = head;
        head = head->next;
        tail->next = head;
        delete temp;
    }

    return val;
}

int CircularSLL:: deleteFromTail()
{
    if(isEmpty())
        throw MyException("\nLink-list is empty.");

    int val = tail->data;

    if(head==tail)
    {
        delete head;
        head = tail = 0;
    }
    else
    {
        Node* temp = head;
        while(temp->next != tail)
        {
            temp = temp->next;
        }
        delete tail;
        tail = temp;
        tail->next = head;
    }
    return val;
}

bool CircularSLL:: isInList(int _data) const
{
    if(isEmpty())
        throw MyException("\nLink-list is empty.");

    if(head->data == _data)
        return true;

    Node* temp = head->next;
    while(temp!=head)
    {
        if(temp->data == _data)
            return true;

        temp = temp->next;
    }

    return false;
}

bool CircularSLL:: delet(int _data)
{
    if(!isInList(_data))
        return false;

    if(head->data==_data)
        deleteFromHead();
    else if(tail->data == _data)
        deleteFromTail();
    else
    {
        Node* temp = head;

        while(temp->next)
        {
            Node* temp1 = temp->next;
            if(temp1->data == _data)
            {
                temp->next = temp1->next;
                delete temp1;
                break;
            }
            temp = temp->next;
        }
    }
    return true;
}


bool CircularSLL:: addBefore(int ele, int _data)
{
    if(!isInList(ele))
        return false;

    if(head->data == ele)
        addToHead(_data);
    else
    {
        Node* temp = head;

        while(temp->next)
        {
            if(temp->next->data == ele)
            {
                Node* temp1 = new Node(_data,temp->next);
                temp->next = temp1;
                break;
            }

            temp = temp->next;
        }
    }

    return true;
}


bool CircularSLL:: addAfter(int ele, int _data)
{
    if(!isInList(ele))
        return false;

    Node* temp = head;

    while(temp)
    {
        if(temp->data == ele)
        {
            if(temp==tail)
                addToTail(_data);
            else
            {
                Node* temp1 = new Node(_data, temp->next);
                temp->next = temp1;
                break;
            }

        }

        temp = temp->next;
    }

    return true;
}


bool CircularSLL:: deleteBefore(int ele)
{
    if(!isInList(ele) || head->data==ele)
        return false;

    if(head->next->data==ele)
        deleteFromHead();
    else
    {
        Node* first = head;
        Node* second = first->next;

        while(second->next)
        {
            if(second->next->data==ele)
            {
                Node* temp = second;
                first->next = second->next;
                delete temp;
                break;
            }
          first = second;
          second = second->next;
        }
    }

    return true;
}


bool CircularSLL:: deleteAfter(int ele)
{
    if(!isInList(ele) || tail->data == ele)
        return false;

    Node* temp = head;

    while(temp->next)
    {
        if(temp->data==ele)
        {
            if(temp->next==tail)
            {
                deleteFromTail();
                break;
            }
            else
            {
                Node* t1 = temp->next;
                temp->next = temp->next->next;
                delete t1;
                break;
            }
        }

        temp = temp->next;
    }
    return true;
}

void CircularSLL:: reverseCSLL()
{
    if(isEmpty())
        throw MyException("\nLink-list is empty.");

    if(head==tail);
    else
    {
        Node* first = head;
        Node* second = first->next;
        Node* third = second->next;
        head->next = 0;

        while(third!=head)
        {
            second->next = first;

            first = second;
            second = third;
            third = third->next;
        }

        second->next = first;
        tail = head;
        head = second;
        tail->next = head;
    }
}
