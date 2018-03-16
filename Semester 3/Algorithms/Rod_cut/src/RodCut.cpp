#include<iostream>
#include "../include/RodCut.h"

using namespace std;

RodCut::RodCut(int len)
{
    maxLen = len+1;

    p = new int[maxLen];
    r = new int[maxLen];
    s = new int[maxLen];
}

RodCut::~RodCut()
{
    delete []p;
    delete []r;
    delete []s;
}

void RodCut:: enterPrices()
{
    p[0]=0;
    int i;

    cout<<"\nPrices: \n";
    for(i=1; i<maxLen; i++)
    {
        cout<<"Length "<<i<<": ";
        cin>>p[i];
    }

    rod_cut_opt();
}

void RodCut:: rod_cut_opt()
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

void RodCut:: printOptimalValue(int len)
{
    if(len > maxLen-1)
    {
        cout<<"\nLength given is greater than maximum length";
        return;
    }

    cout<<"\nOptimum value of rod of length "<<len<<" is: "<<r[len];

}

void RodCut:: printOptimalSolution(int len)
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

void RodCut:: printAll()
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
