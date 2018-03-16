#include<iostream>
#include<cstdlib>
#include<cmath>
#include<ctime>

using namespace std;

int *gtor, lenOfGen;

// Generates a random number between 0 to n-1
int random(int n)
{
    return rand()%n;
}

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

bool isZero(int *a, int n)
{
    if(noOfZeroes(a,n)==n)
        return true;
    else
        return false;
}

int noOfDigits(int *a, int n)
{
    return n - noOfZeroes(a,n);
}

void complement(int *message, int i)
{
    if(message[i]==0)
        message[i] = 1;
    else
        message[i] = 0;
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

// The result of XOR will be reflected in the array a.
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
        int num = noOfZeroes(result,m);
        xorArr(result+num,dvsr,n);
    }
    return result;
}

void validateGeneratorFn()
{
    if(lenOfGen<2)
        throw "\nThe generator function should have at least 2 bits.\n";

    if(gtor[0]!=1 || gtor[lenOfGen-1]!=1)
        throw "\nFirst and last bit of the generator function should be 1 !!\n";

    int dvsr[2] = {1,1};
    int *rem = solve(gtor,lenOfGen,dvsr,2);

    if(noOfZeroes(rem,lenOfGen)!=lenOfGen)
        throw "\n(x+1) should be a factor of the generator function.\n";

    cout<<"\nGenerator function successfully validated!\n";
}

void errorIntroduction(int *message, int n)
{
    int ch=random(3);

    if(ch==0)
    {
        int bit = random(n);
        complement(message,bit);
    }
    else
    {
        int r1 = random(n);
        int r2 = random(n);
        while(r2 == r1)
            r2 = random(n);

        // complements 2 bits in double bit error; complements the lower and higher bit in case of burst error;
        complement(message,r1);
        complement(message,r2);

        if(ch==2)       // in case of burst error
        {
            int higher, lower;
            if(r1 > r2)
            {
                higher = r1;
                lower = r2;
            }
            else
            {
                higher = r2;
                lower = r1;
            }

            int i;
            for(i=lower+1; i<=higher-1; i++)
            {
                int p = random(10);    //With probability 1/10
                if(p==0)
                    complement(message,i);
            }
        }
    }
}


int errorDetection(int *message, int n)
{
    int *result = solve(message,n,gtor,lenOfGen);

    if(isZero(result,n))
        cout<<"\n\nThe received message is correct.";
    else
        cout<<"\n\nThe received message is incorrect.";
}

void reciever(int *recievedMsg, int len)
{
    cout<<"\n\nMessage received:\n";
    display(recievedMsg,len);
    errorDetection(recievedMsg,len);
}

void physicalMedium(int *transmittedMsg, int len)
{
    // NOISY CHANNEL
    int p= random(2);
    if(p==0)
        errorIntroduction(transmittedMsg,len);

    reciever(transmittedMsg,len);
}


void sender()
{
    int *msg, m, *dvndMsg,lenOfDvnd;
    int degreeOfGen = lenOfGen-1;

    // ENTER ORIGINAL MESSAGE
    cout<<"\nEnter no of bits in message: ";
    cin>>m;

    lenOfDvnd = m+degreeOfGen;

    msg = new int[m];
    dvndMsg = new int[lenOfDvnd];

    cout<<"\nEnter the message:\n";
    enter(msg,m);

    // APPEND ZEROES TO MESSAGE
    copyArr(dvndMsg,msg,m);
    for(int i=m; i<lenOfDvnd; i++)
        dvndMsg[i] = 0;

    // FIND THE REMAINDER
    int *remainder = solve(dvndMsg,lenOfDvnd,gtor,lenOfGen);

    // FIND THE TRANSMITTED MESSAGE BY XOR-ING WITH REMAINDER
    xorArr(dvndMsg,remainder,lenOfDvnd);

    cout<<"\nMessage to be transmitted:\n";
    display(dvndMsg,lenOfDvnd);

    physicalMedium(dvndMsg,lenOfDvnd);
}

void enterGenerator()
{
    // ENTER GENERATOR FUNCTION
    cout<<"\nEnter no of bits in generator function: ";
    cin>>lenOfGen;

    gtor = new int[lenOfGen];

    cout<<"\nEnter the generator fn:\n";
    enter(gtor,lenOfGen);

    // VALIDATING GENERATOR FUNCTION
    validateGeneratorFn();
}

int main()
{
    srand((unsigned)time(NULL));

    cout<<"\nNote: First bit should always be 1.\n";

    try
    {
        enterGenerator();
    }
    catch(const char *msg)
    {
        cout<<msg;
        exit(0);
    }

    cout<<"\n---------------------------------------------------------------\n";
    sender();

    cout<<endl;
    cout<<"\n---------------------------------------------------------------\n";

    return 0;
}
