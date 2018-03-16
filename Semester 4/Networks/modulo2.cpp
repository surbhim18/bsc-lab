/* Enter dividend and divisor without zeroes in the beginning  */

#include<iostream>
#include<cstdlib>

using namespace std;

void enter(int *a, int n)
{
    int i;
    for(i=0; i<n; i++)
    {
        cin>>a[i];
        if(a[i]!=0 && a[i]!=1)
            throw "INVALID INPUT";
    }
}

int noOfZeroes(int *a, int n)
{
    int i=0,num=0;
    while(i<n)
    {
      if(a[i]!=1)
        num++;
      else
        break;

      i++;
    }

    return num;
}

int noOfDigits(int *a, int n)
{
    return n - noOfZeroes(a,n);
}

void display(int *a, int n)
{
    int num = noOfZeroes(a,n);

    if(num == n)
    {
     cout<<"0";
    }
    else
    {
        int i = num;
        for(; i<n; i++)
            cout<<a[i];
    }
}

void xorArr(int *dvnd, int *dvsr, int n)
{
    int i;
    for(i=0; i<n; i++)
    {
        if((dvnd[i]==0 && dvsr[i]==0) || (dvnd[i]==1 && dvsr[i]==1))
            dvnd[i] = 0;
        else
            dvnd[i] = 1;
    }
}

void copyArr(int *a, int *b, int n)
{
    int i;
    for(i=0; i<n; i++)
    {
        a[i] = b[i];
    }
}

/*

return value    : condition
 1              : a > b
 0              : a = b
-1              : a < b

int compareMagnitude(int *a, int *b, int n)
{
    int i;
    int flag=0;
    for(i=0; i<n; i++)
    {
        if(a[i]!=b[i])
        {
            flag=1;
            break;
        }
    }

    if(flag==0)
        return 0;

    if(a[i]==1)
        return 1;
    else
        return -1;
}
*/

int* solve(int *dvnd, int m, int *dvsr, int n)
{
    int *result = new int[m];
    copyArr(result,dvnd,m);

    while(noOfDigits(result,m) >= n )
    {
        int num = noOfZeroes(result,m);
        xorArr(result+num,dvsr,n);
    }

    /*if(noOfDigits(result,m)==n)
    {
        int val = compareMagnitude(result,dvsr,n);

        if(val != -1)
        {
            int num = noOfZeroes(result,m);
            xorArr(result+num,dvsr,n);
        }
    }*/

    return result;
}

int main()
{
    int *dvnd, *dvsr;
    int m, n;

    cout<<"\nEnter no of digits in dividend: ";
    cin>>m;

    cout<<"\nEnter no of digits in divisor: ";
    cin>>n;

    dvnd = new int[m];
    dvsr = new int[n];


    try
    {
        cout<<"\nEnter dividend:\n";
        enter(dvnd,m);
        cout<<"\nEnter divisor:\n";
        enter(dvsr,n);
    }

    catch(char* msg)
    {
        cout<<msg;
        exit(0);
    }

    int *result;
    result = solve(dvnd,m,dvsr,n);

    cout<<"\nRemainder: ";
    display(result,m);
    cout<<endl;

    delete []dvnd;
    delete []dvsr;
    delete []result;
}
