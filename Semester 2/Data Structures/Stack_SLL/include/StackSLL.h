#ifndef STACKSLL_H
#define STACKSLL_H
#include "Node.h"

class StackSLL
{
    private:
        Node* top;
    public:
        StackSLL();
        bool isEmpty() const;
        void display() const;
        void push(int);
        int  pop();
        ~StackSLL();
};

#endif // STACKSLL_H
