#ifndef NODE_H
#define NODE_H


class Node
{
    public:
        int data;
        Node(int , Node* _left =0 , Node* _right =0);
        Node* left;
        Node* right;
        bool successor;

};

#endif // NODE_H
