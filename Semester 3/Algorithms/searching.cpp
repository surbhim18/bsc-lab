#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

void bSort(int* a, int n)
{
    int i,j;
    for(i=0; i<n-1; i++)
    {
        for(j=0; j<n-i-1; j++)
        {
            if(a[j] > a[j+1])
            {
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }

    }

}

int noOfTimesL;
int noOfTimesB;

/*
 * IF the element is definitely present in the array
 */

int lSearch(int* a, int n, int ele)
{
    int i,pos;
    for(i=0; i<n; i++)
    {
        noOfTimesL++;
        if(a[i]== ele)
        {
            pos = i;
            break;
        }
    }
    return pos;
}

int bSearch(int* a, int n, int ele)
{
    int beg = 0;
    int last = n-1;
    int mid = (beg+last)/2;

    while(beg <= last && a[mid]!=ele)
    {
        noOfTimesB++;

        if(a[mid] > ele)
            last = mid - 1;
        else
            beg = mid + 1;

        mid = (beg+last)/2;
    }

    return mid;
}

int main()
{
    int i,j;
    srand((unsigned)time(NULL));

    cout<<"n\t"<<"Linear         "<<"Binary \n";

    for(i=50; i<=500; i+=50)
    {
        int n = i;
        noOfTimesL = 0;
        noOfTimesB = 0;

        int* arr = new int[n];

        for(j=0; j<n; j++)
        {
            arr[j] = rand();
        }

        bSort(arr,n);

        for(j=0; j<n; j++)
        {
            lSearch(arr,n,arr[j]);
            bSearch(arr,n,arr[j]);
        }

        float avgL = (float)noOfTimesL/n;
        float avgB = (float)noOfTimesB/n;

        cout<<n<<"\t"<<avgL<<"\t\t"<<avgB<<endl;

        delete []arr;
    }

    return 0;
}
