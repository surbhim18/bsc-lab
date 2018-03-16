#ifndef NODE_H
#define NODE_H


class Node
{
    public:
        int data;
        Node* next;
        Node(int _data = 0, Node* _next = 0)
        {
            data = _data;
            next = _next;
        }
};

#endif // NODE_H
