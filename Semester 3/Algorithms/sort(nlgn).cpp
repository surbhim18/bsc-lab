/*
 * This program calculates no of comparisons only.
 */

#include<iostream>
#include<cstdlib>
#include<ctime>

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

int noOfComM;
int noOfComQ;
int noOfComH;

void mergeArrays(int*,int,int,int);

void mergeSort(int* a, int l, int h)
{
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
    n = h-l+1;

    int* b = new int[n];
    k = 0;

    while(i<=mid && j<=h)
    {
        noOfComM++;
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
        noOfComQ++;
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

int heapSize;

void maxHeapify(int* a, int i)
{
    int left = 2*i +1;
    int right = 2*i +2;
    int largest;

    noOfComH++;
    if(left < heapSize && a[left] > a[i])
        largest = left;
    else
        largest = i;

    noOfComH++;
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


int main()
{
    int i,j;
    srand((unsigned)time(NULL));

    cout<<"n     MergeSort      QuickSort         HeapSort\n";
    cout<<"..................................................\n";
    for(i=50; i<=500; i+=50)
    {
        int n = i;

        noOfComM=0;
        noOfComQ=0;
        noOfComH=0;

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
        copyArr(a,b,n);

        heapSize = n;
        heapSort(a);

        cout<<n<<"\t"<<noOfComM<<"\t\t"<<noOfComQ<<"\t\t"<<noOfComH<<endl;

        delete []a;
        delete []b;
    }

    return 0;
}
