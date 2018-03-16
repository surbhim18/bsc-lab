#include<iostream>
#include "Node.h"
#include "RBtree.h"

using namespace std;

Node* nilNode = new Node(-1,black);

RBtree::RBtree()
{
    root = nilNode;
}

void RBtree::insert(int _key)
{
    insert(root,_key,nilNode);
}

void RBtree:: insert(Node*& root,int _key,Node*& p)
{
    if(root == nilNode)
    {
        root = new Node(_key,red,nilNode,nilNode,p);
        fixInsert(root);
    }
    else if(root->key >= _key)
        insert(root->left,_key,root);
    else
        insert(root->right,_key,root);
}

void RBtree:: inorder()
{
    if(root == nilNode)
        cout<<"\nThe tree is empty";
    else
        inorder(root);
}

void RBtree:: inorder(Node* root)
{
    if(root == nilNode)
        return;

    inorder(root->left);
    cout<<root->key<<":";
    if(root->nodeColor == red)
        cout<<"red    ";
    else
        cout<<"black    ";
    inorder(root->right);
}

void RBtree:: postorder()
{
    if(root == nilNode)
        cout<<"\nThe tree is empty";
    else
        postorder(root);
}

void RBtree:: postorder(Node* root)
{
    if(root == nilNode)
        return;

    postorder(root->left);
    postorder(root->right);
    cout<<root->key<<":";
    if(root->nodeColor == red)
        cout<<"red    ";
    else
        cout<<"black    ";
}

bool RBtree:: growth_in_same_direction(Node* x)
{
    Node* pX = x->p;            //parent of x
    Node* gpX = x->p->p;        // grandparent of x

    if((x == pX->left && pX == gpX->left) || (x == pX->right && pX == gpX->right))
        return true;
    else
        return false;
}

void RBtree:: fixInsert(Node* x)
{
    if(x == root)                       // color of root is always black. no fixing required. (default color of node: red)
    {
        x->nodeColor = black;
        return;
    }

    if(x->p->nodeColor == black)        // if the parent is black. no fixing required for the red node.
        return;

    Node* uncleX;                       // calculation of uncle to avoid confusion
    if(x->p == x->p->p->left)
        uncleX = x->p->p->right;
    else
        uncleX = x->p->p->left;

    if(x->p->nodeColor == red)
    {
        if(uncleX->nodeColor == red)    // when both the parent and uncle are red
        {
            x->p->nodeColor = black;
            uncleX->nodeColor = black;
            x->p->p->nodeColor = red;
            fixInsert(x->p->p);
        }
        else                            // if the parent is red but the uncle is black
        {
            if(growth_in_same_direction(x))
            {
                x->p->nodeColor = black;
                x->p->p->nodeColor = red;

                if(x == x->p->left)
                    right_rotate(x->p->p);
                else
                    left_rotate(x->p->p);
            }
            else
            {
                if(x == x->p->left)
                    right_rotate(x->p);
                else
                    left_rotate(x->p);

                x->nodeColor = black;
                x->p->nodeColor = red;

                if(x == x->p->left)
                    right_rotate(x->p);
                else
                    left_rotate(x->p);

            }
        }
    }
}


void RBtree:: right_rotate(Node* x)
{
    Node* leftX = x->left;
    Node* pX = x->p;

    if(x==root)
        root = leftX;

    if(x == pX->left)
        pX->left = leftX;
    else
        pX->right = leftX;

    leftX->p = pX;

    x->p = leftX;
    x->left = leftX->right;
    x->left->p = x;

    leftX->right = x;
}


void RBtree:: left_rotate(Node* x)
{
    Node* rightX = x->right;
    Node* pX = x->p;

    if(x==root)
        root = rightX;

    if(x == pX->left)
        pX->left = rightX;
    else
        pX->right = rightX;

    rightX->p = pX;

    x->p = rightX;
    x->right = rightX->left;
    x->right->p = x;

    rightX->left = x;
}

void RBtree:: deletionByCopying(Node* temp)
{
    Node* succ = temp->right;

    while(succ->left!=nilNode)
        succ = succ->left;

    int key = succ->key;

    deletion(key);

    temp->key = key;
}

void RBtree:: deletion(int ele)
{
    Node* temp = root;
    while(temp != nilNode && temp->key != ele)
    {
        if(temp->key >= ele)
            temp = temp->left;
        else
            temp = temp->right;
    }

    if(temp == nilNode)
    {
        cout<<"\nThe element does not exist in the tree.";
        return;
    }

    // temp holds the element to be deleted
    // x is used to hold the child of temp
    Node* x;
    Node* prev = temp->p;

    color tempColor = temp->nodeColor;

    if(temp->right == nilNode && temp->left == nilNode)
    {
        if(temp==root)
            root = nilNode;
        else if(temp==prev->right)
            prev->right = nilNode;
        else
            prev->left =  nilNode;

        if(tempColor == black)
        {
            x = nilNode;
            x->p = temp->p;
            fixDelete(x);
        }
        delete temp;
    }
    else if(temp->right == nilNode)
    {
        if(temp==root)
            root = temp->left;
        else if(temp == prev->right)
            prev->right = temp->left;
        else
            prev->left = temp->left;

       if(tempColor == black)
        {
            x = temp->left;
            x->p = temp->p;
            fixDelete(x);
        }
        delete temp;
    }
    else if(temp->left == nilNode)
    {
        if(temp==root)
            root = temp->right;
        else if(temp == prev->right)
            prev->right = temp->right;
        else
            prev->left = temp->right;

        if(tempColor == black)
        {
            x = temp->right;
            x->p = temp->p;
            fixDelete(x);
        }
        delete temp;
    }
    else
        deletionByCopying(temp);
}

void RBtree:: fixDelete(Node* x)
{
    if(x->nodeColor == red)
    {
        x->nodeColor = black;
        return;
    }

    // if the node to be fixed now is black in color

    Node* pX = x->p;
    Node* sibX;

    if(x == pX->left)
    {
        sibX = pX->right;

        if(sibX->nodeColor == red)              //case 1: the color of sibling is red
        {
            pX->nodeColor = red;
            sibX->nodeColor = black;
            left_rotate(pX);
            fixDelete(x);
        }
        else
        {
            if(sibX->left->nodeColor == black && sibX->right->nodeColor == black)
            {
                sibX->nodeColor = red;
                fixDelete(pX);
            }
            else if(sibX->left->nodeColor == red && sibX->right->nodeColor == black)
            {
                sibX->left->nodeColor = black;
                sibX->nodeColor = red;
                right_rotate(sibX);
                fixDelete(x);
            }
            else
            {
                sibX->right->nodeColor = black;
                sibX->nodeColor = pX->nodeColor;
                pX->nodeColor = black;
                left_rotate(pX);
            }
        }
    }
    else
    {
        sibX = pX->left;

        if(sibX->nodeColor == red)              //case 1: the color of sibling is red
        {
            pX->nodeColor = red;
            sibX->nodeColor = black;
            right_rotate(pX);
            fixDelete(x);
        }
        else
        {
            if(sibX->left->nodeColor == black && sibX->right->nodeColor == black)
            {
                sibX->nodeColor = red;
                fixDelete(pX);
            }
            else if(sibX->left->nodeColor == black && sibX->right->nodeColor == red)
            {
                sibX->right->nodeColor = black;
                sibX->nodeColor = red;
                left_rotate(sibX);
                fixDelete(x);
            }
            else
            {
                sibX->left->nodeColor = black;
                sibX->nodeColor = pX->nodeColor;
                pX->nodeColor = black;
                right_rotate(pX);
            }
        }
    }
}
