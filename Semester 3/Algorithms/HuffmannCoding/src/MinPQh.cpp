#include "MinPQh.h"
#include<iostream>
#include<climits>

using namespace std;

void swapp(Tree& a, Tree& b)
{
    Tree temp = a;
                a = b;
                b = temp;
}

MinPQh:: MinPQh(int n)
{
    maxSize = n;
    heapSize = 0;

    a = new Tree[maxSize];
}

MinPQh:: ~MinPQh()
{
    delete []a;
}

int MinPQh:: retHeapSize()
{
    return heapSize;
}

void MinPQh:: minHeapify(int index)
{
    int i=index;
    int left = 2*i +1;
    int right = 2*i +2;
    int smallest;

    if(left < heapSize && a[left].root.data < a[i].root.data)
        smallest = left;
    else
        smallest = i;

    if(right < heapSize && a[right].root.data < a[smallest].root.data)
        smallest = right;

    if(smallest != i)
    {
        swapp(a[i],a[smallest]);
        minHeapify(smallest);
    }
}

Tree MinPQh:: retMax()
{
    if(heapSize==0)
        throw "\nQueue Underflow\n";

    return a[0];
}

void MinPQh:: increaseKey(int index, Tree node)
{
    a[index] = node;
    int parent = (index-1)/2;

    while(parent >= 0  && a[index].root.data < a[parent].root.data)
    {
        swapp(a[parent], a[index]);

        index = parent;
        parent = (index-1)/2;
    }
}

void MinPQh:: insertEle(Tree node)
{
    if(heapSize+1 > maxSize)
        throw "\nQueue Overflow\n";

    a[heapSize].root.data = INT_MIN;
    increaseKey(heapSize,node);
    heapSize++;
}

TreeNode MinPQh:: extractMin()
{
    if(heapSize==0)
        throw "\nQueue Underflow\n";

    Tree min = a[0];

    swapp(a[0],a[heapSize-1]);
    heapSize--;
    minHeapify(0);

    return min.root;
}

void MinPQh:: printQueue()
{
    int i;

    if(heapSize==0)
    {
            cout<<"\nNo elements in the queue\n";
            return;
    }

    for(i=0; i<heapSize; i++)
    {
        cout<<"a["<<i<<"]\n";
        cout<<"Postorder: ";
        a[i].postorder();
        cout<<"\nInorder  : ";
        a[i].inorder();
        cout<<endl;
    }
}
