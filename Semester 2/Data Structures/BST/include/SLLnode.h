#ifndef SLLNODE_H
#define SLLNODE_H

#include "Node.h"

class SLLnode
{
   public:
    Node* treeNode;
    SLLnode* next;
    SLLnode(Node* _treeNode = 0, SLLnode* _next = 0);
};

#endif // SLLNODE_H
