#include "Heap.h"
#include<iostream>
#include<climits>

using namespace std;

Heap:: Heap(int n)
{
    maxSize = n;
    heapSize = 0;

    a = new int[maxSize];
}

Heap:: ~Heap()
{
    delete []a;
}

int Heap:: retHeapSize()
{
    return heapSize;
}

void Heap:: insertEle(int element)
{
    if(heapSize+1 > maxSize)
    {
        cout<< "\nQueue Overflow\n";
        return;
    }
    a[heapSize] = element;
    heapSize++;

}


int Heap:: retEleAt(int index)
{
    return a[index];
}

void Heap:: printHeap()
{
    int i;

    if(heapSize==0)
    {
        cout<<"\nNo elements in the queue\n";
        return;
    }

    for(i=0; i<heapSize; i++)
        cout<<"H["<<i<<"]:"<<a[i]<<"   ";
}

int Heap:: findSecondMin()
{
    int min=a[0];
    int i;

    int min2 = INT_MAX;
    for(i=1; i<heapSize ;)
    {
        if(a[i]==min)
        {
            if(a[i+1]<min2)
                min2=a[i+1];
        }
        else //if(a[i+1]==min)
        {
            if(a[i]<min2)
                min2=a[i];
        }
        i=(i*2)+1;
    }

    return min2;
}
