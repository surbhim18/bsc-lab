#include <iostream>
#include "SLL.h"

using namespace std;

void display(float* a, int n)
{
    for(int i=0; i<n; i++)
        cout<<a[i]<<"  ";
}

void bucketSort(float* a, int n)
{
    SLL* value = new SLL[n];

    int i;
    for(i=0; i<n; i++)
    {
        int x = a[i] * n;
        cout<<"here";
        value[x].addToList(a[i]);
    }

    int j=0;
    for(i=0; i<n; i++)
    {
        while(!value[i].isEmpty())
        {
            a[j++] = value[i].deleteFromHead();
        }
    }
}

int main()
{
    int n,i;

    cout<<"\nEnter no of elements: ";
    cin>>n;

    float* a = new float[n];

    cout<<"\nEnter array:\n";
    for(i=0; i<n; i++)
        cin>>a[i];

    bucketSort(a,n);

    cout<<"\nSorted array:\n";
    display(a,n);

    delete []a;
    return 0;
}
