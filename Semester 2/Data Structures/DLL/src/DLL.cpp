#include "DLL.h"
#include<iostream>
#include "MyException.h"

using namespace std;

DLL::DLL()
{
   head = tail =0;
}

DLL::~DLL()
{
    Node* temp;

    while(head)
    {
       temp = head;
       head = head-> next;
       delete temp;
    }
}

bool DLL:: isEmpty() const
{
    if(head == 0 && tail == 0)
        return true;

    return false;
}

void DLL:: display() const
{
    if(isEmpty())
        throw MyException("\nLink-list empty");
    else
    {
        Node* temp = head;
        cout<<"\nContents of link list:\n";
        while(temp)
        {
            cout<<temp->data<<"  ";
            temp = temp->next;
        }
    }
}

void DLL:: printDLL() const
{
    if(isEmpty())
        throw MyException("\nLink-list empty");
    else
    {
        cout<<"\n Previous     Current     Next\n";

        if(head->next==0)
            cout<<"   NULL  "<<"\t"<< head->data <<"\t  NULL\n";
        else
        {
            cout<<"   NULL  "<<"\t"<< head->data <<"\t    "<< head->next->data <<"  \n";
            Node* temp = head->next;
            while(temp->next)
            {
                cout<<"    "<< temp->prev->data <<"\t        "<< temp->data <<"\t    "<< temp->next->data <<endl;
                temp = temp->next;
            }
            cout<<"    "<< tail->prev->data <<"\t\t"<< tail->data <<"\t"<<"  NULL"<<"  \n";
        }
    }
}

void DLL:: addToHead(int _data)
{
    if(head == 0)
    {
        head = new Node(_data);
        head->prev = 0;
        head->next = 0;
        tail = head;
    }
    else
    {
        Node* temp = new Node (_data);
        temp->next = head;
        temp->prev = 0;
        head->prev = temp;
        head = temp;
    }
}

void DLL:: addToTail(int _data)
{
    if(tail == 0)
    {
        tail = new Node(_data);
        tail->prev = 0;
        tail->next = 0;
        head = tail;
    }
    else
    {
        tail->next  = new Node(_data);
        tail->next->prev = tail;
        tail = tail->next;
        tail->next = 0;
    }
}


int DLL:: deleteFromHead()
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
        head->prev = 0;
        delete temp;
    }

    return val;
}

int DLL:: deleteFromTail()
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
        Node* temp = tail;
        tail = tail->prev;
        tail->next = 0;
        delete temp;
    }
    return val;
}

bool DLL:: isInList(int _data) const
{
    if(isEmpty())
        throw MyException("\nLink-list is empty.");


    Node* temp = head;
    while(temp)
    {
        if(temp->data == _data)
            return true;

        temp = temp->next;
    }

    return false;
}

bool DLL:: delet(int _data)
{
    if(!isInList(_data))
        return false;

    if(head->data==_data)
        deleteFromHead();
    else if(tail->data == _data)
        deleteFromTail();
    else
    {
        Node* temp = head->next;

        while(temp->next)
        {
            if(temp->data == _data)
            {
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                delete temp;
                break;
            }
            temp = temp->next;
        }
    }
    return true;
}


bool DLL:: addBefore(int ele, int _data)
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
                Node* temp1 = new Node(_data);
                temp1->next = temp->next;
                temp1->prev = temp;
                temp->next->prev = temp1;
                temp->next = temp1;
                break;
            }

            temp = temp->next;
        }
    }

    return true;
}


bool DLL:: addAfter(int ele, int _data)
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
                Node* temp1 = new Node(_data);
                temp1->next = temp->next;
                temp1->prev = temp;
                temp->next->prev = temp1;
                temp->next = temp1;
                break;
            }

        }

        temp = temp->next;
    }

    return true;
}


bool DLL:: deleteBefore(int ele)
{
    if(!isInList(ele) || head->data==ele)
        return false;



        Node* temp= head->next;
        while(temp)
        {
            if(temp->data==ele)
            {
                if(temp==head->next)
                    deleteFromHead();
                else
                {
                    Node* t1 = temp->prev;
                    t1->prev->next = temp;
                    temp->prev = t1->prev;
                    delete t1;
                    break;
                }
            }
            temp = temp->next;
        }
    return true;
}


bool DLL:: deleteAfter(int ele)
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
                temp->next = t1->next;
                t1->next->prev = temp;
                delete t1;
                break;
            }
        }

        temp = temp->next;
    }
    return true;
}


int DLL:: deleteAtPos(int pos)
{
    int val=0,flag=0,counter=0;

    if(pos==1)
    {
        val = deleteFromHead();
        flag = 1;
    }
    else
    {
        Node* temp = head->next;
        counter = 2;

        while(temp)
        {
            if(counter==pos)
            {
                if(temp==tail)
                    val = deleteFromTail();
                else
                {
                    val = temp->data;
                    temp->prev->next = temp->next;
                    temp->next->prev = temp->prev;
                    delete temp;
                }

                flag = 1;
                break;
            }

            temp = temp->next;
            counter++;
        }
    }

    if(flag==0)
        throw MyException("\nNo such position exists. Please try again with a valid position.");
    else
        return val;

}

/*void swapPtrs(Node** x, Node** y) // fn call : swapPtrs(&head, &tail)
{
    Node temp;
    temp = *x;
    *x    = *y;
    *y    = temp;

}*/


void DLL:: reverseDLL()
{
    if(isEmpty())
        throw MyException("\nDoubly Link-list is empty.");

    if(head==tail);
    else
    {
       Node* temp = head;
       Node* swapPtr;

       while(temp)
       {
            swapPtr = temp->next;
            temp->next = temp->prev;
            temp->prev = swapPtr;

            temp = temp->prev;
       }

       swapPtr = head;
       head = tail;
       tail = swapPtr;
    }
}
