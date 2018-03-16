#include<iostream>

#define INFINITY 100000000
#define MAX_NODES 1024

using namespace std;

int n, dist[MAX_NODES][MAX_NODES];
enum label {permanent, tentative};


struct nodes
{
    int predecessor;
    int length;
    label l;

}state[MAX_NODES];

void shortest_path(int s,int t, int* path, int& len)
{
    int i,k,min;

    for(i=0; i<n; i++)
    {
        state[i].predecessor = -1;
        state[i].length = INFINITY;
        state[i].l = tentative;
    }

    state[t].length = 0;
    state[t].l = permanent;
    k=t;
    do
    {
        for(i=0; i<n; i++)
        {
            if(dist[k][i]!=0 && state[i].l==tentative)
            {
                if(state[k].length + dist[k][i] < state[i].length)
                {
                    state[i].predecessor = k;
                    state[i].length = state[k].length + dist[k][i];
                }
            }
        }

        k=0;
        min = INFINITY;
        for(i=0; i<n; i++)
        {
            if(state[i].l== tentative && state[i].length < min)
            {
                min = state[i].length;
                k=i;
            }
        }
        state[k].l = permanent;
    }
    while(k!=s);

    i=0;
    k=s;
    do
    {
        path[i++]=k;
        len++;
        k = state[k].predecessor;
    }
    while(k>=0);
}

int main()
{
    int i,j;

    do
    {
        cout<<"\nEnter no. of nodes: ";
        cin>>n;
    }
    while(n>MAX_NODES);

    cout<<"\nEnter distance matrix: ";
    for(i=0; i<n; i++)
    {
        dist[i][i]=0;
        for(j=0; j<i; j++)
        {
            cout<<"dist["<<i<<"]["<<j<<"]: ";
            cin>>dist[i][j];

            dist[j][i]= dist[i][j];
        }
        cout<<endl;
    }

    int s,t;

    cout<<"Enter source node: ";
    cin>>s;
    cout<<"Enter destination node: ";
    cin>>t;

    int *path = new int[MAX_NODES];
    int len=0;

    shortest_path(s,t,path,len);

    cout<<"\nThe shortest path from node "<<s<<" to node "<<t<<":\n";
    for(i=0; i<len; i++)
    {
        cout<<"node "<<path[i]<<": ";
    }

    cout<<endl;
    return 0;
}
