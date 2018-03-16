#ifndef SLL_H
#define SLL_H

#include "Node.h"

class SLL
{
    private:
        Node* head;
        Node* tail;

    public:
        SLL();
        bool isEmpty() const;
        void display() const;
        void addToList(float);
        float deleteFromHead();
        ~SLL();
};

#endif // SLL_H
