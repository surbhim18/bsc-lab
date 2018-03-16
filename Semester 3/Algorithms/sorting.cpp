#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

void copyArr(int* b, int* a, int n)
{
    for(int i=0; i<n; i++)
    {
        b[i] = a[i];
    }
}

void swapp(int& a, int& b)
{
    int temp = a;
           a = b;
           b = temp;
}

int noOfComB;
int noOfComI;
int noOfComS;

void bSort(int* a, int n)
{
    int i,j;
    for(i=0; i<n-1; i++)
    {
        for(j=0; j<n-i-1; j++)
        {
            noOfComB++;
            if(a[j] > a[j+1])
                swapp(a[j],a[j+1]);
        }
    }
}

void selSort(int* a, int n)
{
    int i,j;

    for(i=0; i<n-1; i++)
    {
        int minPos = i;

        for(j=i+1; j<n; j++)
        {
            noOfComS++;
            if(a[j] < a[minPos])
                minPos = j;
        }

        swapp(a[i],a[minPos]);
    }
}

void insSort(int* a,int n)
{
   int i,j;

   for(int i=1; i<n; i++)
   {
       int j = i-1;
       int temp = a[i];

       while(j>=0 && temp < a[j])
       {
           noOfComI++;
           a[j+1] = a[j];
           j--;
       }
       noOfComI++;      //one comparison more, i.e., temp < a[j], as exit condition

       a[j+1] = temp;
   }
}

int main()
{
    int i,j;
    srand((unsigned)time(NULL));

    cout<<"n     Bubble  Selection  Insertion\n";

    for(i=50; i<=500; i+=50)
    {
        int n = i;
        noOfComB = 0;
        noOfComS = 0;
        noOfComI = 0;

        int* a = new int[n];

        for(j=0; j<n; j++)
        {
            a[j] = rand();
        }

        int* b = new int[n];
        copyArr(b,a,n);

        bSort(a,n);
        copyArr(a,b,n);

        selSort(a,n);
        copyArr(a,b,n);

        insSort(a,n);

        cout<<n<<"\t"<<noOfComB<<"\t"<<noOfComS<<"\t  "<<noOfComI<<endl;

        delete []a;
        delete []b;
    }

    return 0;
}
