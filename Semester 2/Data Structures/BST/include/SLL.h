#ifndef SLL_H
#define SLL_H

#include "SLLnode.h"

class SLL
{
    private:
        SLLnode* head;
        SLLnode* tail;

    public:
        SLL();
        bool isEmpty() const;
        void addToHead(Node*);
        void addToTail(Node*);
        Node* deleteFromHead();
        ~SLL();

};

#endif // SLL_H
