#include "PQueueH.h"
#include<iostream>
#include<climits>

using namespace std;

void swapp(int& a, int& b)
{
    int temp = a;
           a = b;
           b = temp;
}

PQueueH:: PQueueH(int n)
{
    maxSize = n;
    heapSize = 0;

    a = new int[maxSize];
}

PQueueH:: ~PQueueH()
{
    delete []a;
}

int PQueueH:: retHeapSize()
{
    return heapSize;
}

void PQueueH:: maxHeapify(int index)
{
    int i=index;
    int left = 2*i +1;
    int right = 2*i +2;
    int largest;

    if(left < heapSize && a[left] > a[i])
        largest = left;
    else
        largest = i;

    if(right < heapSize && a[right] > a[largest])
        largest = right;

    if(largest != i)
    {
        swapp(a[i],a[largest]);
        maxHeapify(largest);
    }
}

int PQueueH:: retMax()
{
    if(heapSize==0)
        throw "\nQueue Underflow\n";

    return a[0];
}

void PQueueH:: increaseKey(int index, int key)
{
    if(index < 0)
        throw "\nIndex should be greater than or equal to 0.\n";

    if(a[index] > key)
        throw "\nValue of key should be greater than the previous value.\n";

    a[index] = key;
    int parent = (index-1)/2;

    while(parent >= 0  && a[index] > a[parent])
    {
        swapp(a[parent], a[index]);

        index = parent;
        parent = (index-1)/2;
    }
}

void PQueueH:: insertEle(int element)
{
    if(heapSize+1 > maxSize)
        throw "\nQueue Overflow\n";

    a[heapSize] = INT_MIN;
    increaseKey(heapSize,element);
    heapSize++;

}

int PQueueH:: extractMax()
{
    if(heapSize==0)
        throw "\nQueue Underflow\n";

    int max = a[0];

    swapp(a[0],a[heapSize-1]);
    heapSize--;
    maxHeapify(0);

    return max;
}

void PQueueH:: printQueue()
{
    int i;

    if(heapSize==0)
    {
            cout<<"\nNo elements in the queue\n";
            return;
    }

    for(i=0; i<heapSize; i++)
        cout<<a[i]<<"   ";
}
