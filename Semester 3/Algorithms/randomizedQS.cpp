#include<iostream>
#include<cstdlib>

using namespace std;

int partitionArr(int*,int,int);

void swapp(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void quickSort(int* a, int l, int h)
{
    if(l < h)
    {
        int pivot = partitionArr(a,l,h);
        quickSort(a,l,pivot-1);
        quickSort(a,pivot+1,h);
    }
}

int partitionArr(int* a, int l, int h)
{
    int randIndex = l + rand()%(h-l+1);
    swapp(a[l],a[randIndex]);            // randomizing the l

    int i=l;
    int j=l+1;

    int pivotValue = a[l];              //always selects 'l' as the pivot value (algorithm-wise)

    while(j<=h)
    {
        if(a[j] < pivotValue)
        {
            i++;
            swapp(a[i],a[j]);
        }
        j++;
    }

    swapp(a[l],a[i]);

    return i;
}

int main()
{
    int n;

    cout<<"\nQuick sort";
    cout<<"\nEnter the no. of elements: ";
    cin>>n;

    int* a = new int[n];

    int i;
    cout<<"\nEnter the elements\n";
    for(i=0 ; i<n ; i++)
        cin>>a[i];

    quickSort(a,0,n-1);

    cout<<"\nThe sorted array is\n";
     for(i=0 ; i<n ; i++)
        cout<<a[i]<<"   ";

    cout<<endl;

    delete []a;
    return 0;
}
