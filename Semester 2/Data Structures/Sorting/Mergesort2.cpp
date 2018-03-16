#include<iostream>

using namespace std;

void merging(int*,int,int*,int);

void mergeSort(int* a, int l, int h)
{
    if(l<h)
    {
        int mid = (l+h)/2;

        mergeSort(a,l,mid);
        mergeSort(a,mid+1,h);

        merging(a+l,mid-l+1,a+mid+1,h-mid);
    }
}

void merging(int* a, int m, int* b, int n)
{
    int* c = new int[m+n];

    int i,j,k=0;

    for(i=0,j=0; i<m && j<n; )
    {
        if(b[j] < a[i])
            c[k++] = b[j++];
        else
            c[k++] = a[i++];
    }

    if(i<m)
    {
        while(i<m)
            c[k++] = a[i++];
    }
    else
    {
        while(j<n)
            c[k++] = b[j++];
    }

    for(i=0;i<m;i++)
        a[i] = c[i];

    for(j=0;j<n;j++)
        b[j] = c[i+j];

    delete []c;
}

int main()
{
    int ele;

    cout<<"\nMerge sort";
    cout<<"\nEnter the no. of elements: ";
    cin>>ele;

    int* a = new int[ele];

    int i;
    cout<<"\nEnter the elemets\n";
    for(i=0 ; i<ele ; i++)
        cin>>a[i];

    mergeSort(a,0,ele-1);

    cout<<"\nThe sorted array is\n";
     for(i=0 ; i<ele ; i++)
        cout<<a[i]<<"   ";

    cout<<endl;

    delete []a;
    return 0;
}
