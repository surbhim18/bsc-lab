#include<iostream>

using namespace std;

void merging(int*,int,int,int);

void mergeSort(int* a, int l, int h)
{
    if(l<h)
    {
        int mid = (l+h)/2;

        mergeSort(a,l,mid);
        mergeSort(a,mid+1,h);

        merging(a,l,mid,h);
    }
}

void merging(int* a, int l, int mid, int h)
{
    int m = mid-l+1;
    int n = h-mid;

    int* b = new int[m];
    int* c = new int[n];

    int i;
    for(i=l ; i<=mid ; i++)
        b[i-l] = a[i];

    for(i=mid+1 ; i<=h ; i++)
        c[i-(mid+1)] = a[i];


    int* d = new int[m+n];

    int j,k=0;
    for(i=0,j=0; i<m && j<n; )
    {
        if(c[j] < b[i])
            d[k++] = c[j++];
        else
            d[k++] = b[i++];
    }

    if(i<m)
    {
        while(i<m)
            d[k++] = b[i++];
    }
    else
    {
        while(j<n)
            d[k++] = c[j++];
    }

    for(i=l ; i<=h ;i++)
        a[i] = d[i-l];

    delete []b;
    delete []c;
    delete []d;
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
