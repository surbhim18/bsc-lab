#include<iostream>

using namespace std;

int max(int &a, int& b)
{
    if(a > b)
        return a;
    else
        return b;
}

int rod_cut(int* p, int len)
{
    if(len==0)
        return 0;

    int i,maximum = -1;

    for(i=1; i<=len; i++)
        maximum = max(maximum, p[i] + rod_cut(p,len-i));

    return maximum;
}

int main()
{
    int n;

    cout<<"\nEnter maximum size of rod: ";
    cin>>n;

    int* p =new int[n+1];

    p[0]=0;
    int i;

    cout<<"\nPrices: \n";
    for(i=1; i<=n; i++)
    {
        cout<<"Length "<<i<<": ";
        cin>>p[i];
    }

    int length;
    cout<<"\nEnter length of rod: ";
    cin>>length;

    int optVal = rod_cut(p,length);

    cout<<"\nOptimum value: "<<optVal<<endl;

}
