#include<iostream>
#include<cmath>

using namespace std;

void display(int* a, int n)
{
    for(int i=0; i<n; i++)
        cout<<a[i]<<"  ";

    cout<<endl;
}

int* radixSort(int* a, int n, int d)
{
    int i,j,index;
    int r=9;

    int* value = new int[n];        // stores digit info starting from ones place
    int* b = new int[n];            // stores the remaining array

    int* res = new int[n];          // stores the final result
    int* c = new int[r+1];          // array used for counting

    for(i=0; i<n; i++)              // copy of array created
        b[i] = a[i];

    for(j=1; j<=d; j++)             // d: no of digits in a number
    {
        for(i=0; i<=r; i++)         // make c array empty
            c[i] = 0;

        //display(b,n);
        for(i=0; i<n; i++)
        {
            value[i] = b[i]%10;
            //b[i] = b[i]/10;
            c[value[i]]++;
        }
        //display(value,n);

        for(i=1; i<=r; i++)
            c[i] = c[i] + c[i-1];

        for(i=n-1; i>=0; i--)
        {
            res[c[value[i]]-1] = a[i];      // stores the actual array
            c[value[i]]--;
        }

        for(i=0; i<n; i++)
        {
            a[i] = res[i];
            b[i] = res[i]/pow(10,j);
        }

        //display(res,n);
        cout<<endl;
    }

    delete []b;
    delete []c;
    delete []value;
    return res;
}

int main()
{
    int d,n,i;

    cout<<"\nEnter no of elements: ";
    cin>>n;

    cout<<"Enter no of digits in each number: ";
    cin>>d;

    int* a = new int[n];

    cout<<"\nEnter array:\n";
    for(i=0; i<n; i++)
        cin>>a[i];

    int* b = radixSort(a,n,d);

    cout<<"\nSorted array:\n";
    display(b,n);

    delete []a;
    return 0;
}
