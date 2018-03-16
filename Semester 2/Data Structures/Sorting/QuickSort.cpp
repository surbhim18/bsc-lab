#include<iostream>
#include<cstdlib>

using namespace std;

void swapp(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int partitioning(int* a, int l, int h)
{
     int pivotIndex = l + rand()%(h-l+1);       //rand()%(h-l-1) gives a max value of h-l..ie 0-h-l..
     int pivotValue = a[pivotIndex];            //add l so it becomes from l-h

    swapp(a[h],a[pivotIndex]);

    int storeIndex = l;
    int i;
    for(i=l ; i<=h-1 ; i++)
    {
            if(a[i]<pivotValue)
            {
                swapp(a[i],a[storeIndex++]);
            }
    }

    swapp(a[storeIndex],a[h]);

    return storeIndex;
}

void quickSort(int* a, int l, int h)
{
    if(l<h)
    {
        int p = partitioning(a,l,h);
        quickSort(a,l,p-1);
        quickSort(a,p+1,h);
    }
}



int main()
{
    int ele;

    cout<<"\nQuick sort";
    cout<<"\nEnter the no. of elements: ";
    cin>>ele;

    int* a = new int[ele];

    int i;
    cout<<"\nEnter the elements\n";
    for(i=0 ; i<ele ; i++)
        cin>>a[i];

    quickSort(a,0,ele-1);

    cout<<"\nThe sorted array is\n";
     for(i=0 ; i<ele ; i++)
        cout<<a[i]<<"   ";

    cout<<endl;

    delete []a;
    return 0;
}
