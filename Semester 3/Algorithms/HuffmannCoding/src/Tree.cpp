#include <iostream>
#include "Tree.h"
#include <cstring>

using namespace std;

Tree::Tree()
{

}

void Tree:: insertL(TreeNode newNode)
{
    root.left = new TreeNode(newNode);
}

void Tree:: insertR(TreeNode newNode)
{
    root.right = new TreeNode(newNode);
}

void Tree:: inorder()
{
    inorder(&root);
}

void Tree:: inorder(TreeNode* root)
{
    if(root == 0)
        return;

    inorder(root->left);
    cout<<root->ch<<":"<<root->data<<"   ";
    inorder(root->right);

}

void Tree:: postorder()
{
    postorder(&root);
}

void Tree:: postorder(TreeNode* root)
{
    if(root == 0)
        return;

    postorder(root->left);
    postorder(root->right);
    cout<<root->ch<<":"<<root->data<<"   ";
}

int findIndexOfChar(char* c, char ch,int n)
{
    for(int i=0; i<n; i++)
        if(c[i]==ch)
            return i;

    return -1;
}

//0: left 1: right
void Tree:: fillCodes(char **codes, char *c,int n)
{
    char * str = new char[10];
    strcpy(str,"\0");
    fillCodes(&root,codes,c,n,str,-1);
}



void Tree:: fillCodes(TreeNode* root,char **codes, char *c,int n,char *app, int side)
{
    if(root == 0)
        return;

    char* newApp = new char[10];
    strcpy(newApp,app);

    if(side==0)
        strcat(newApp,"0");
    else if(side==1)
        strcat(newApp,"1");

     if(root->ch!='!')
    {
        int i = findIndexOfChar(c,root->ch,n);
        strcpy(codes[i],newApp);
    }

    fillCodes(root->left,codes,c,n,newApp,0);
    fillCodes(root->right,codes,c,n,newApp,1);
}
