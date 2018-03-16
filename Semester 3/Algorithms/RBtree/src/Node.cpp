#include "Node.h"

Node::Node(int _key, color _nodeColor, Node* _left, Node* _right, Node* _p)
{
    key = _key;
    nodeColor = _nodeColor;
    left = _left;
    right = _right;
    p = _p;
}
