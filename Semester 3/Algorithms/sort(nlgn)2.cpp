/*
 * This program calculates no of comparisons
 * and no of function calls
 * and adds them, for no LOGICAL reason AT ALL
 */

#include<iostream>
#include<cstdlib>

using namespace std;

void swapp(int& a, int& b)
{
    int temp = a;
           a = b;
           b = temp;
}

void copyArr(int* b, int* a, int n)
{
    for(int i=0; i<n; i++)
    {
        b[i] = a[i];
    }
}

int noOfCallsM;
int timeToMerge;

int noOfCallsQ;
int timeToPart;

void mergeArrays(int*,int,int,int);

void mergeSort(int* a, int l, int h)
{
    noOfCallsM++;
    if(l < h)
    {
        int mid = (l+h)/2;
        mergeSort(a,l,mid);
        mergeSort(a,mid+1,h);
        mergeArrays(a,l,mid,h);
    }
}

void mergeArrays(int* a, int l, int mid, int h)
{
    int i,j,k,n;
    i = l;
    j = mid+1;
    n = l+h-1;

    int* b = new int[n];
    k = 0;

    while(i<=mid && j<=h)
    {
        timeToMerge++;
        if(a[i] < a[j])
            b[k++] = a[i++];
        else
            b[k++] = a[j++];
    }


    if(i<=mid)
    {
        while(i<=mid)
           b[k++] = a[i++];
    }
    else
    {
        while(j<=h)
           b[k++] = a[j++];
    }

    for(i=l,j=0; i<=h; i++,j++)
        a[i] = b[j];

    delete []b;
}

int partitionArr(int*,int,int);

void quickSort(int* a, int l, int h)
{
    noOfCallsQ++;
    if(l < h)
    {
        int pivot = partitionArr(a,l,h);
        quickSort(a,l,pivot-1);
        quickSort(a,pivot+1,h);
    }
}

int partitionArr(int* a, int l, int h)
{
    int i=l;
    int j=l+1;
    int pivotValue = a[i];

    while(j<=h)
    {
        timeToPart++;
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
    int i,j;

    cout<<"(calls,merge/partition = total time)\n";
    cout<<"...................................................\n";
    cout<<"n \t MergeSort \t QuickSort\n";
    cout<<"...................................................\n";
    for(i=50; i<=500; i+=50)
    {
        int n = i;

        noOfCallsM = 0;
        timeToMerge = 0;

        noOfCallsQ = 0;
        timeToPart = 0;

        int* a = new int[n];

        for(j=0; j<n; j++)
        {
            a[j] = rand();
        }

        int* b = new int[n];
        copyArr(b,a,n);

        mergeSort(a,0,n-1);
        copyArr(a,b,n);

        quickSort(a,0,n-1);

        int timeM = noOfCallsM + timeToMerge;
        int timeQ = noOfCallsQ + timeToPart;

        cout<<n<<"\t"<<noOfCallsM<<","<<timeToMerge<<" = "<<timeM<<"\t"<<noOfCallsQ<<","<<timeToPart<<" = "<<timeQ<<endl;

        delete []a;
        delete []b;
    }

    cout<<"...................................................\n";

    return 0;
}
