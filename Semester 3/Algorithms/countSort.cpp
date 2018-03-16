#include<iostream>

using namespace std;

/*
 * Counting Sort
 * used when range is known and of order n
 */

void display(int* a, int n)
{
    for(int i=0; i<n; i++)
        cout<<a[i]<<"  ";
}

int* countSort(int* a, int n, int r)
{
    int i;
    int* b = new int[n];                //final sorted array
    int* c = new int[r+1];              // for counting the elements

    for(i=0; i<=r; i++)
        c[i] = 0;

    for(i=0; i<n; i++)
        c[a[i]]++;

    for(i=1; i<=r; i++)
        c[i] = c[i] + c[i-1];

    for(i=n-1; i>=0; i--)
    {
        b[c[a[i]]-1] = a[i];
        c[a[i]]--;
    }

    delete []c;
    return b;
}

int main()
{
    int range,n,i;

    cout<<"\nEnter no of elements: ";
    cin>>n;

    do
    {
        cout<<"\nLower limit is 0 by default.";
        cout<<"\nEnter upper limit h [h <= 20]: ";
        cin>>range;

        if(range>20 || range<0)
            cout<<"\nPlease enter a valid upper limit.\n";
        else
            break;

    }while(1);

    int* a = new int[n];

    cout<<"\nEnter array:\n";
    for(i=0; i<n; i++)
        cin>>a[i];

    int* b = countSort(a,n,range);

    cout<<"\nSorted array:\n";
    display(b,n);

    delete []a;
    return 0;
}
