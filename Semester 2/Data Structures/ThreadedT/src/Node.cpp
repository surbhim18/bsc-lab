#include "Node.h"

Node::Node(int _data, Node* _left, Node* _right)
{
  data = _data;
  left = _left;
  right = _right;
  successor = false;
}
