#ifndef TREE_H
#define TREE_H
#include "TreeNode.h"

class Tree
{
    void postorder(TreeNode*);
    void inorder(TreeNode*);
    void fillCodes(TreeNode* root,char** codes,char* c ,int n, char* app ,int side);

public:
    TreeNode root;
    void postorder();
    void inorder();
    void fillCodes(char**,char*,int);
    void insertL(TreeNode);
    void insertR(TreeNode);
    Tree();
};

#endif // TREE_H
