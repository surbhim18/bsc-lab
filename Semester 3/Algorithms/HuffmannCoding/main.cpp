#include <iostream>
#include "MinPQh.h"
#include <cmath>
#include <cstring>

using namespace std;

void enter_values(char *c, int *f, int n)
{
    int i;

    for(i=0; i<n; i++)
    {
        cout<<"c["<<i<<"] : ";
        cin>>c[i];
        cout<<"f["<<i<<"] : ";
        cin>>f[i];
        cout<<endl;
    }
}

void huffmann(MinPQh &hc, char *c, int *f, int n)
{
    int i;
    Tree temp;

    for(i=0; i<n; i++)
    {
        temp.root.ch = c[i];
        temp.root.data = f[i];
        hc.insertEle(temp);
    }
    //hc.printQueue();


    for(i=0; i<n-1; i++)
    {
        TreeNode newNode1 = hc.extractMin();
        TreeNode newNode2 = hc.extractMin();

        Tree insertNode;
        insertNode.root.ch ='!';

        insertNode.insertL(newNode1);
        insertNode.insertR(newNode2);

        insertNode.root.data = insertNode.root.left->data + insertNode.root.right->data;

        hc.insertEle(insertNode);
    }
}

void print_values(char **codes, char *c, int n)
{
    int i;
    for(i=0; i<n; i++)
    {
        cout<<c[i]<<":"<<codes[i];
        cout<<endl;
    }
}

int main()
{
    int i,n;
    cout<<"Enter no of characters: ";
    cin>>n;

    char *c = new char[n];
    int *f = new int[n];

    enter_values(c,f,n);

    MinPQh hc;
    huffmann(hc,c,f,n);

    TreeNode root = hc.extractMin();

    Tree myTree;
    myTree.root = root;

    myTree.postorder();

    char **codes = new char*[n];
    int size = 10;

    for(i=0; i<n; i++)
    {
        codes[i] = new char[size];
        strcpy(codes[i],"\0");
    }

    myTree.fillCodes(codes,c,n);

    cout<<"\n\nCodes:\n";
    print_values(codes,c,n);

    return 0;
}
