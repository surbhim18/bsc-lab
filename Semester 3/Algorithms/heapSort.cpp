#include<iostream>
#include<cstdlib>

using namespace std;

int heapSize;

void swapp(int& a, int& b)
{
    int temp = a;
           a = b;
           b = temp;
}

/*
 * i: index at which heap is created assuming left and right are heaps
 */
void maxHeapify(int* a, int i)
{
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
        maxHeapify(a,largest);
    }
}

void buildMaxHeap(int* a)
{
    int n = heapSize;
    int i;

    for(i=(n/2)-1; i>=0; i--)
    {
        maxHeapify(a,i);
    }
}

void heapSort(int* a)
{
    buildMaxHeap(a);

    int i;
    int n = heapSize;

    for(i=n-1; i>0; i--)
    {
        swapp(a[i],a[0]);
        heapSize--;
        maxHeapify(a,0);
    }

    heapSize = n;
}

void displayHeap(int* a)
{
    int i;
    for(i=0; i<heapSize; i++)
        cout<<a[i]<<"  ";

}

int main()
{
    int* a = new int[20];
    int j;
        for(j=0; j<20; j++)
        {
            a[j] = rand();
        }

    heapSize = 20;

    displayHeap(a);
    cout<<endl;

    heapSort(a);

    displayHeap(a);

    delete []a;
}
