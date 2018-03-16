#ifndef TREENODE_H
#define TREENODE_H


class TreeNode
{
    public:
        TreeNode(char _ch='\0',int _data=0);
        char ch;
        int data;
        TreeNode *left;
        TreeNode *right;
        void print();
};

#endif // TREENODE_H
