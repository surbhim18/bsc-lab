#include <iostream>
#include "TreeNode.h"

using namespace std;

TreeNode::TreeNode(char _ch, int _data)
{
    ch    = _ch;
    data  = _data;
    left  = 0;
    right = 0;
}

void TreeNode:: print()
{
    cout<<"Data: "<<data<<"  Ch: "<<ch<<endl;
}

