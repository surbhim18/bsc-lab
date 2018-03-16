#include<iostream>

using namespace std;

int num;

void enter_time(int **act)
{
    int i;
    for(i=0; i<num; i++)
    {
        cout<<"Activity["<<i<<"]\n";
        cout<<"Start time : ";
        cin>>act[i][0];
        cout<<"Finish time: ";
        cin>>act[i][1];
        cout<<endl;
    }
}

void view_time(int **act)
{
    int i,j;
    cout<<"----------------------------------------------------------------------\n";
    for(i=0; i<num; i++)
        cout<<i<<"   ";
    cout<<"\n----------------------------------------------------------------------\n";

    for(j=0; j<2; j++)
    {
        for(i=0; i<num; i++)
        {
            cout<<act[i][j]<<"   ";
        }
        cout<<endl;
    }
    cout<<"----------------------------------------------------------------------\n";
}

void rec_activity_selector(int **act, int *order, int k, int i, int &n)
{
    int m = k+1;

    while( m < num && act[m][0] < act[k][1] )
        m = m+1;

    if(m < num)
    {
        order[i] = m;
        n++;
        rec_activity_selector(act,order,m,i+1,n);
    }
    else
        return;
}


//Activities are entered in the ascending order of finishing time.
int main()
{
    int n,i;
    cout<<"\nEnter no. of activities: ";
    cin>>n;

    num = n;

    int **act = new int*[num];
    for(i=0; i<num; i++)
        act[i] = new int[2];

    enter_time(act);
    view_time(act);

    int *order = new int[num];

    int numOfAct = 1;
    order[0] = 0;

    rec_activity_selector(act,order,0,1,numOfAct);

    cout<<"\nOrder in which activities should be scheduled:\n";
    for(i=0; i<numOfAct; i++)
        cout<<order[i]<<"   ";

    cout<<endl;

    return 0;
}
