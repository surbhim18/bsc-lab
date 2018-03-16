#ifndef NODE_H
#define NODE_H


class Node
{
    public:
        int data;
        Node(int _data = 0);
        Node* next;
        Node* prev;
};

#endif // NODE_H
