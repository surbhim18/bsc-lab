#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

void display(int* a, int n)
{
    for(int i=0; i<n; i++)
        cout<<a[i]<<"  ";
}

void swapp(int& a, int& b)
{
    int temp = a;
           a = b;
           b = temp;
}

void selSort(int* a, int n)
{
    if(n > 1)
    {
        int i,minPos = 0;

        for(i=1;i<n;i++)
        {
            if(a[i]<a[minPos])
                minPos = i;
        }

        swapp(a[0],a[minPos]);
        selSort(a+1,n-1);
    }
}

int main()
{
    int range,n,i;

    cout<<"\nEnter no of elements: ";
    cin>>n;

    int* a = new int[n];

    cout<<"\nEnter array:\n";
    for(i=0; i<n; i++)
        cin>>a[i];

    selSort(a,n);

    cout<<"\nSorted array:\n";
    display(a,n);

    delete []a;
    return 0;
}
