#include<iostream>
#include<cstdlib>

using namespace std;

void swapp(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
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

int select(int* a, int l, int h, int i)
{
    if(l == h)
        return a[l];

    int pivot = partitionArr(a,l,h);

    int k = pivot-l+1;

    if(k == i)
        return a[pivot];
    else if(i < k)
        return select(a,l,pivot-1,i);
    else
        return select(a,pivot+1,h,i-k);
}

int main()
{
    int n;

    cout<<"\nSelection problem";
    cout<<"\nEnter the no. of elements: ";
    cin>>n;

    int* a = new int[n];

    int i;
    cout<<"\nEnter the elements\n";
    for(i=0 ; i<n ; i++)
        cin>>a[i];

    cout<<"\nFind ith order statistic: ";


    while(1)
    {
        cout<<"\n\nEnter i (enter -1 to exit) : ";
        cin>>i;

        if(i<0 || i>=n)
            break;

        cout<<"Element["<<i<<"]: "<<select(a,0,n-1,i);
    }

    cout<<endl;

    delete []a;
    return 0;
}
