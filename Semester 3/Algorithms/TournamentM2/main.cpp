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
    obj = new Heap[n];

    int i;
    for(i=0; i<n; i++)
    {
        obj[i].insertEle(a[i]); /// insert element from array
    }

    int num = n;
    bool isEven;

    while(num!=1)
    {
        int j=0;

        if(num%2==0)
            isEven = true;
        else
            isEven = false;

        /*for(i=0; i<num; i++)          //remove comments to see the working of the code
        {
            obj[i].printHeap();
            cout<<"\n";
        }*/

        Heap* objNew=0;

        int x = num/2;
        int newNum;

        if(!isEven)
        {
            newNum = num-1;
            x++;
        }
        else
            newNum = num;

        objNew = new Heap[x];

        for(i=0; i<newNum; i+=2)
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

        if(!isEven)
            objNew[j].insertEle(obj[num-1].retEleAt(0));

        delete []obj;
        obj = objNew;

        num = x;                  /// making appropriate changes for looping
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

    cout<<"\nSecond largest element: "<<tournament(a,n)<<"\n";

    delete []a;
    return 0;
}
