#include<iostream>
#include "SLL.h"

using namespace std;

SLL::SLL()
{
   head = tail =0;
}

SLL::~SLL()
{
    SLLnode* temp;

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

void SLL:: addToHead(Node* treeNode)
{
    if(treeNode==0)
        return;

    if(head == 0)
    {
        head = new SLLnode(treeNode);
        tail = head;
    }
    else
    {
        SLLnode* temp = new SLLnode (treeNode,head);
        head = temp;
    }
}

void SLL:: addToTail(Node* treeNode)
{
    if(treeNode==0)
        return;

    if(tail == 0)
    {
        tail = new SLLnode(treeNode);
        head = tail;
    }
    else
    {
        tail->next  = new SLLnode(treeNode);
        tail = tail->next;
    }
}


Node* SLL:: deleteFromHead()
{
    Node* treeNode = head->treeNode;

    if(head==tail)
    {
        delete head;
        head = tail = 0;
    }
    else
    {
        SLLnode* temp = head;
        head = head->next;
        delete temp;
    }

    return treeNode;
}
