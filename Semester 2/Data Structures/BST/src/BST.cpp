#include "BST.h"
#include "SLL.h"
#include <iostream>

using namespace std;

BST:: BST()
{
    root = 0;
}

/*
BST:: ~BST()
{

}

BST:: BST(const BST& temp)
{

}
*/

bool BST:: noTree() const
{
    if(root==0)
        return true;
    else
        return false;
}



void BST:: insertI1(int ele)
{
    if(root==0)
    {
        root = new Node(ele);
        return;
    }

    Node* temp = root;

    while(temp->left!=0 || temp->right!=0)
    {
        if(temp->data >= ele)
        {
            if(temp->left==0)
                break;
            else
                temp = temp->left;
        }
        else
        {
            if(temp->right==0)
                break;
            else
                temp = temp->right;
        }
    }

    Node* newNode = new Node(ele);

    if(temp->data>=ele)
        temp->left = newNode;
    else
        temp->right = newNode;
}

void BST:: insertI2(int ele)
{
     if(root==0)
    {
        root = new Node(ele);
        return;
    }

    Node* p = root;
    Node* prev = 0;

    while(p)
    {
        prev = p;

        if(p->data >= ele)
            p = p->left;
        else
            p = p->right;

    }

    Node* newNode = new Node(ele);

    if(prev->data >= ele)
        prev->left = newNode;
    else
        prev->right = newNode;

}

void BST:: insertR1(Node* _root, int ele)
{
    if(_root==0)
        return;

    if(_root->data >= ele)
    {
        if(_root->left==0)
            _root->left = new Node(ele);
        else
            insertR1(_root->left,ele);
    }
    else
    {
        if(_root->right==0)
            _root->right = new Node(ele);
        else
            insertR1(_root->right,ele);
    }
}

void BST:: insertR2(Node* prev, Node* p, int ele)
{
    if(prev == 0 && p == 0)
        return;

    if(p==0)
    {
        if(prev->data >= ele)
            prev->left = new Node(ele);
        else
            prev->right = new Node(ele);
    }
    else
    {
        if(p->data >= ele)
            insertR2(p,p->left,ele);
        else
            insertR2(p,p->right,ele);
    }
}

void BST:: insertR3(Node* &_root , int ele)
{
    if(_root==0)
    {
        _root = new Node(ele);
        return;
    }

    if(_root->data >= ele)
        insertR3(_root->left,ele);
    else
        insertR3(_root->right,ele);
}

Node* BST:: insertR4(Node* _root, int ele)
{
    if(_root==0)
        return new Node(ele);
    else if(_root->data >= ele)
    {
        _root->left = insertR4(_root->left,ele);
        return _root;
    }
    else
    {
        _root->right = insertR4(_root->right,ele);
        return _root;

    }
}

void BST:: deletionByMergingP(Node* prev, Node* temp)
{
    if(prev==0)
        root = temp->left;
    else if(temp == prev->right)
        prev->right = temp->left;
    else
        prev->left = temp->left;


    Node* temp1 = temp->left;
    Node* temp2 = temp->right;

    delete temp;

    while(temp1->right!=0)
        temp1 = temp1->right;

    temp1->right = temp2;
}

void BST:: deletionByMergingS(Node* prev, Node* temp)
{
    Node* temp1 = temp->right;
    Node* temp2 = temp->left;

    if(prev==0)
        root = temp->right;
    else if(temp == prev->right)
        prev->right = temp->right;
    else
        prev->left = temp->right;

    delete temp;

    while(temp1->left!=0)
        temp1 = temp1->left;

    temp1->left = temp2;
}

void BST:: deletionByCopyingP(Node* temp)
{
    Node* pred = temp->left;

    while(pred->right!=0)
        pred = pred->right;

    int data = pred->data;

    deletionC1(data);

    temp->data = data;
}

void BST:: deletionByCopyingS(Node* temp)
{
    Node* succ = temp->right;

    while(succ->left!=0)
        succ = succ->left;

    int data = succ->data;

    deletionC2(data);

    temp->data = data;
}

void BST:: deletionM1(int ele)
{
    Node* temp = root;
    Node* prev = 0;

    while(temp != 0 && temp->data != ele)
    {
        prev = temp;
        if(temp->data >= ele)
            temp = temp->left;
        else
            temp = temp->right;
    }

    if(temp == 0)
    {
        cout<<"\nThe element does not exist in the tree.";
        return;
    }

    if(temp->right == 0 && temp->left == 0)
    {
        if(temp==root)
            root = 0;
        else if(temp==prev->right)
            prev->right = 0;
        else
            prev->left =  0;

        delete temp;
    }
    else if(temp->right == 0)
    {
        if(temp==root)
            root = temp->left;
        else if(temp == prev->right)
            prev->right = temp->left;
        else
            prev->left = temp->left;

        delete temp;
    }
    else if(temp->left == 0)
    {
        if(temp==root)
            root = temp->right;
        else if(temp == prev->right)
            prev->right = temp->right;
        else
            prev->left = temp->right;

        delete temp;
    }
    else
        deletionByMergingP(prev,temp);

}

void BST:: deletionM2(int ele)
{
    Node* temp = root;
    Node* prev = 0;

    while(temp != 0 && temp->data != ele)
    {
        prev = temp;
        if(temp->data >= ele)
            temp = temp->left;
        else
            temp = temp->right;
    }

    if(temp == 0)
    {
        cout<<"\nThe element does not exist in the tree.";
        return;
    }

    if(temp->right == 0 && temp->left == 0)
    {
        if(temp==root)
            root = 0;
        else if(temp==prev->right)
            prev->right = 0;
        else
            prev->left =  0;

        delete temp;
    }
    else if(temp->right == 0)
    {
        if(temp==root)
            root = temp->left;
        else if(temp == prev->right)
            prev->right = temp->left;
        else
            prev->left = temp->left;

        delete temp;
    }
    else if(temp->left == 0)
    {
        if(temp==root)
            root = temp->right;
        else if(temp == prev->right)
            prev->right = temp->right;
        else
            prev->left = temp->right;

        delete temp;
    }
    else
        deletionByMergingS(prev,temp);

}


void BST:: deletionC1(int ele)
{
    Node* temp = root;
    Node* prev = 0;

    while(temp != 0 && temp->data != ele)
    {
        prev = temp;
        if(temp->data >= ele)
            temp = temp->left;
        else
            temp = temp->right;
    }

    if(temp == 0)
    {
        cout<<"\nThe element does not exist in the tree.";
        return;
    }

    if(temp->right == 0 && temp->left == 0)
    {
        if(temp==root)
            root = 0;
        else if(temp==prev->right)
            prev->right = 0;
        else
            prev->left =  0;

        delete temp;
    }
    else if(temp->right == 0)
    {
        if(temp==root)
            root = temp->left;
        else if(temp == prev->right)
            prev->right = temp->left;
        else
            prev->left = temp->left;

        delete temp;
    }
    else if(temp->left == 0)
    {
        if(temp==root)
            root = temp->right;
        else if(temp == prev->right)
            prev->right = temp->right;
        else
            prev->left = temp->right;

        delete temp;
    }
    else
        deletionByCopyingP(temp);

}


void BST:: deletionC2(int ele)
{
    Node* temp = root;
    Node* prev = 0;

    while(temp != 0 && temp->data != ele)
    {
        prev = temp;
        if(temp->data >= ele)
            temp = temp->left;
        else
            temp = temp->right;
    }

    if(temp == 0)
    {
        cout<<"\nThe element does not exist in the tree.";
        return;
    }

    if(temp->right == 0 && temp->left == 0)
    {
        if(temp==root)
            root = 0;
        else if(temp==prev->right)
            prev->right = 0;
        else
            prev->left =  0;

        delete temp;
    }
    else if(temp->right == 0)
    {
        if(temp==root)
            root = temp->left;
        else if(temp == prev->right)
            prev->right = temp->left;
        else
            prev->left = temp->left;

        delete temp;
    }
    else if(temp->left == 0)
    {
        if(temp==root)
            root = temp->right;
        else if(temp == prev->right)
            prev->right = temp->right;
        else
            prev->left = temp->right;

        delete temp;
    }
    else
        deletionByCopyingS(temp);
}


void swapp(Node** a, Node** b)
{
    Node* temp;

    temp = *a;
    *a   = *b;
    *b   = temp;
}

void BST:: mirror(Node* root)
{
    if(root == 0)
        return;

    mirror(root->left);
    mirror(root->right);

    swapp(&root->left,&root->right);
}

int BST:: calc_height(Node* root)
{
    if(root == 0)
        return 0;

    int h1 = calc_height(root->left) +1;
    int h2 = calc_height(root->right) +1;

    if(h1 > h2)
        return h1;
    else
        return h2;
}

int BST:: calc_sum(Node* root)
{
    if(root == 0)
        return 0;

    return root->data + calc_sum(root->left) + calc_sum(root->right);
}

int BST:: noOfNodes(Node* root)
{
    if(root == 0)
        return 0;

    return 1 + noOfNodes(root->left) + noOfNodes(root->right);
}


int minimum(int a, int b)
{
    if(a < b)
        return a;
    else
        return b;
}

int minimum(int a, int b, int c)
{
    if(a < b)
    {
        if(a < c)
            return a;
        else
            return b;
    }
    else
    {
        if(b < c)
            return b;
        else
            return a;
    }
}

int BST:: calcMin(Node* root)
{
    if(root->left == 0 && root->right == 0)
        return root->data;
    else if(root->left == 0)
        return minimum(calcMin(root->right),root->data);
    else if(root->right == 0)
        return minimum(calcMin(root->left),root->data);
    else
        return minimum(calcMin(root->left),calcMin(root->right),root->data);
}


int maximum(int a, int b)
{
    if(a > b)
        return a;
    else
        return b;
}

int maximum(int a, int b, int c)
{
    if(a > b)
    {
        if(a > c)
            return a;
        else
            return c;
    }
    else
    {
        if(b > c)
            return b;
        else
            return c;
    }
}

int BST:: calcMax(Node* root)
{
    if(root->left == 0 && root->right == 0)
        return root->data;
    else if(root->left == 0)
        return maximum(calcMax(root->right),root->data);
    else if(root->right == 0)
        return maximum(calcMax(root->left),root->data);
    else
        return maximum(calcMax(root->left),calcMax(root->right),root->data);
}

void BST:: preorder(Node* root) const
{
    if(root == 0)
        return;

    cout<<root->data<<"   ";
    preorder(root->left);
    preorder(root->right);

}

void BST:: inorder(Node* root) const
{
    if(root == 0)
        return;

    inorder(root->left);
    cout<<root->data<<"   ";
    inorder(root->right);

}

void BST:: postorder(Node* root) const
{
    if(root == 0)
        return;

    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<"   ";
}

void BST:: BFS() const
{
    if(root==0)
    {
        cout<<"\nThe tree does not exist.";
        return;
    }

    SLL queueObj;

    queueObj.addToTail(root);

    while(!queueObj.isEmpty())
    {
        Node* treeNode = queueObj.deleteFromHead();

        cout<<treeNode->data<<"   ";
        queueObj.addToTail(treeNode->left);
        queueObj.addToTail(treeNode->right);
    }

}

void BST:: DFS() const
{
    if(root==0)
    {
        cout<<"\nThe tree does not exist.";
        return;
    }

    SLL stackObj;

    stackObj.addToHead(root);

    while(!stackObj.isEmpty())
    {
        Node* treeNode = stackObj.deleteFromHead();

        cout<<treeNode->data<<"   ";
        stackObj.addToHead(treeNode->right);
        stackObj.addToHead(treeNode->left);
    }

}
