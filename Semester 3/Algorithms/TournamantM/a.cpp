#include <iostream>
#include<climits>
#include "Heap.h"

using namespace std;

void display(int* a, int n)
{
    for(int i=0; i<n; i++)
        cout<<a[i]<<"  ";
}

int tournament(int* a, int n)
{
    Heap* obj=0;
    if(n%2==0)
        obj = new Heap[n];
    else
    {
        obj = new Heap[n+1];
        obj[n].insertEle(INT_MAX);
    }

    int i;
    for(i=0; i<n; i++)
    {
        obj[i].insertEle(a[i]);
    }

    int num;
    if(n%2==0)
        num=n;
    else
        num=n+1;

    while(num!=1)
    {
        int j=0;

        for(i=0; i<num; i++)
        {
            obj[i].printHeap();
            cout<<"\n";
        }

        Heap* objNew=0;
        if(num%2==0)
        {
            int x = num/2;
            if(x%2==0)
                objNew = new Heap[x];
            else
            {
                objNew = new Heap[x+1];
                objNew[x].insertEle(INT_MAX);
            }
        }

        for(i=0; i<num; i+=2)
        {
            int ele1 = obj[i].retEleAt(0);
            int ele2 = obj[i+1].retEleAt(0);

            if(ele1 < ele2)
                objNew[j].insertEle(ele1);
            else
                objNew[j].insertEle(ele2);

            int m;
            for(int k=0; k<obj[i].retHeapSize();)
            {
                for(m=k; m<=2*k; m++)
                    objNew[j].insertEle(obj[i].retEleAt(m));

                for(m=k; m<=2*k; m++)
                    objNew[j].insertEle(obj[i+1].retEleAt(m));

                k = m;
            }
            j++;
        }

        delete []obj;
        obj = objNew;

        if(num%2==0)
            num = num/2;
        else
            num = num/2 +1;
    }

    return obj->findSecondMin();
}

/*
    works for n: even
*/
int main()
{
    int n,i;

    cout<<"\nEnter no of elements: ";
    cin>>n;

    int* a = new int[n];

    cout<<"\nEnter array:\n";
    for(i=0; i<n; i++)
        cin>>a[i];

    cout<<"\n"<<tournament(a,n)<<"\n";

    delete []a;
    return 0;
}
