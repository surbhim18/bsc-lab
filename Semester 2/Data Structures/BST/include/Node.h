#ifndef NODE_H
#define NODE_H


class Node
{
    public:
        int data;
        Node(int , Node* _left =0 , Node* _right =0);
        Node(const Node&);
        Node* left;
        Node* right;

};

#endif // NODE_H
