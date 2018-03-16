#ifndef NODE_H
#define NODE_H

enum color {red,black};

class Node
{
    public:
        int key;
        color nodeColor;
        Node* p;
        Node* left;
        Node* right;
        Node(int _key=0, color _nodeColor = red, Node* _left = 0, Node* _right = 0, Node* _p = 0);
};

#endif // NODE_H
