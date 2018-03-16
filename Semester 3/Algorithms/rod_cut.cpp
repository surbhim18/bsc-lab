#include <iostream>
#include <cstdlib>

using namespace std;

int maxLen;

void rod_cut_opt(int *p, int *r, int *s)
{
    r[0] = 0;
    s[0] = 0;
    int i,j;

    for(i=1; i<maxLen; i++)
    {
        int maximum = -1;

        for(j=1; j<=i; j++)
        {
            int val = p[j] + r[i-j];

            if(val > maximum)
            {
                maximum = val;
                s[i] = j;
            }
        }

        r[i] = maximum;
    }
}

void enterPrices(int* p)
{
    p[0]=0;
    int i;

    cout<<"\nPrices: \n";
    for(i=1; i<maxLen; i++)
    {
        cout<<"Length "<<i<<": ";
        cin>>p[i];
    }
}


void printOptimalValue(int *r,int len)
{
    if(len > maxLen-1)
    {
        cout<<"\nLength given is greater than maximum length";
        return;
    }

    cout<<"\nOptimum value of rod of length "<<len<<" is: "<<r[len];

}

void printOptimalSolution(int *s,int len)
{
    if(len > maxLen-1)
    {
        cout<<"\nLength given is greater than maximum length";
        return;
    }

    int n = len;
    int i=1;

    while(n>0)
    {
        cout<<"\nCut "<<i<<": "<<s[n];
        n= n-s[n];
        i++;
    }
}

void printAll(int *r, int *s)
{
    int i;

    cout<<"\nLength\tOpt Value\tOpt Cuts\n";
    cout<<"---------------------------------\n";
    for(i=1; i<maxLen; i++)
    {
        cout<<i<<"\t"<<r[i]<<"\t\t";

        int n = i;
        while(n>0)
        {
            cout<<s[n]<<" ";
            n= n-s[n];
        }
        cout<<"\n";
    }

}

int main()
{
    int ch,n,len;

    cout<<"\nEnter maximum size of rod: ";
    cin>>n;

    maxLen = n+1;

    int *p = new int[maxLen];
    int *r = new int[maxLen];
    int *s = new int[maxLen];

    enterPrices(p);

    rod_cut_opt(p,r,s);

    do{

        cout<<"\n--------------------------------------------------------------------------\n";
        cout<<"  ROD CUT\n";
        cout<<"1.Print optimal value for rod of length n.\n";
        cout<<"2.Print optimal solution for rod of length n.\n";
        cout<<"3.Print all information.\n";
        cout<<"4.Exit.\n";
        cout<<"\n--------------------------------------------------------------------------";
        cout<<"\nEnter choice: ";
        cin>>ch;
        cout<<"\n--------------------------------------------------------------------------";

        switch(ch)
        {
            case 1:
            cout<<"\nEnter length of rod: ";
            cin>>len;

            printOptimalValue(r,len);
            break;

            case 2:
            cout<<"\nEnter length of rod: ";
            cin>>len;

            printOptimalSolution(s,len);
            break;

            case 3:
            printAll(r,s);
            break;

            case 4:
            exit(0);

            default: cout<<"\nPlease enter a valid choice\n";

        }

    }while(1);

    cout<<"\n--------------------------------------------------------------------------\n";

    delete []p;
    delete []r;
    delete []s;

    return 0;

}
