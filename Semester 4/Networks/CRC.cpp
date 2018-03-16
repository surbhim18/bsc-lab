#include<iostream>
#include<cstdlib>
#include<cmath>

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

void copyArr(int *a, int *b, int n)
{
    int i;
    for(i=0; i<n; i++)
    {
        a[i] = b[i];
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
        cout<<"0";
    else
    {
        int i = num;
        for(; i<n; i++)
            cout<<a[i]<<" ";
    }
}

/*
    The result of XOR will be reflected in the array a.
*/

void xorArr(int *a, int *b, int n)
{
    int i;
    for(i=0; i<n; i++)
    {
        if(a[i] == b[i])
            a[i] = 0;
        else
            a[i] = 1;
    }
}

int* solve(int *dvnd, int m, int *dvsr, int n)
{
    int *result = new int[m];
    copyArr(result,dvnd,m);

    while(noOfDigits(result,m) >= n )
    {
        cout<<noOfZeroes(result,m);
        int num = noOfZeroes(result,m);
        xorArr(result+num,dvsr,n);
    }

    return result;
}

void validateGeneratorFn(int *gen, int n)
{
    if(n<2)
        throw "\nThe generator function should have at least 2 bits.\n";

    if(gen[0]!=1 || gen[n-1]!=1)
        throw "\nFirst and last bit of the generator function should be 1 !!\n";

    int dvsr[2] = {1,1};
    int *rem = solve(gen,n,dvsr,2);

    if(noOfZeroes(rem,n)!=n)
        throw "\n(x+1) should be a factor of the generator function.\n";

    cout<<"\nGenerator function successfully validated!\n";
}


int main()
{
    int *gtor, n,i;

    cout<<"\nNote: First bit should always be 1.\n";

    // ENTER GENERATOR FUNCTION
    cout<<"\nEnter no of bits in generator function: ";
    cin>>n;

    gtor = new int[n];
    int degreeOfGen = n-1;

    cout<<"Enter the generator fn:\n";
    enter(gtor,n);

    // VALIDATING GENERATOR FUNCTION
    try
    {
        validateGeneratorFn(gtor,n);
    }

    catch(const char *msg)
    {
        cout<<msg;
        exit(0);
    }

    int *msg,*dvndMsg, m, lenOfDvnd;

    // ENTER ORIGINAL MESSAGE
    cout<<"\nEnter no of bits in message: ";
    cin>>m;

    lenOfDvnd = m+degreeOfGen;

    msg = new int[m];
    dvndMsg = new int[lenOfDvnd];

    cout<<"Enter the message:\n";
    enter(msg,m);

    // APPEND ZEROES TO MESSAGE
    copyArr(dvndMsg,msg,m);
    for(i=m; i<lenOfDvnd; i++)
        dvndMsg[i] = 0;

    // FIND THE REMAINDER
    int *remainder = solve(dvndMsg,lenOfDvnd,gtor,n);

    // FIND THE TRANSMITTED MESSAGE BY XOR-ING WITH REMAINDER
    xorArr(dvndMsg,remainder,lenOfDvnd);

    cout<<"\nMessage to be transmitted:\n";
    display(dvndMsg,lenOfDvnd);

    cout<<endl;

    delete []gtor;
    return 0;
}
