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

void iter_activity_selector(int **act, int *order, int &n)
{
    order[0] = 0;
    n =1;

    int k=0;
    int m;
    int i=1;

    for(m=1; m < num; m++)
    {
        if(act[m][0] >= act[k][1] )
        {
            order[i++] = m;
            n++;
            k = m;
        }
    }
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

    int numOfAct =0;

    iter_activity_selector(act,order,numOfAct);

    cout<<"\nOrder in which activities should be scheduled:\n";
    for(i=0; i<numOfAct; i++)
        cout<<order[i]<<"   ";

    cout<<endl;

    return 0;
}
