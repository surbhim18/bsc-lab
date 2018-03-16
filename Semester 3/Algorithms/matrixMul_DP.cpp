#include <iostream>
#include <cstdlib>
#include<climits>

using namespace std;

int num;

/*void allocate(int** res)
{
    int i;

    res = new int*[num];
    for(i=0; i<num; i++)
        res[i] = new int[num];
}*/

/*void deallocate(int** res)
{
    int i;

    for(i=0; i<num; i++)
        delete []res[i];

    delete []res;
}*/

void enterDimensions(int* d)
{
    cout<<"\nOrder: \n";
    for(int i=0; i<=num; i++)
    {
        cout<<"d["<<i<<"]: ";
        cin>>d[i];
    }
}

void printDimensions(int* d)
{
    cout<<"\nOrder of matricies: \n";

    for(int i=0; i<num; i++)
    {
        cout<<"Matrix["<<i<<"]: ";
        cout<<d[i]<<" X "<<d[i+1]<<endl;
    }
}


void matrixChain(int** res, int* d)
{
    int i,j,k,len;
    for(i=0; i<num; i++)
    {
        res[i][i] = 0;
    }

    for(len=1; len<num; len++)
    {
        int lim = num - len;

        for(i=0; i<lim; i++)
        {
            j = len + i;

            res[i][j] = INT_MAX;
            int q = INT_MAX;

            for(k=i; k<=j-1; k++)
            {
                q = res[i][k] + res[k+1][j] + d[i]*d[k+1]*d[j+1];

                if(q < res[i][j])
                {
                    res[i][j] = q;      // storing optimal value

                    res[j][i] = k;      // storing parentheses symmetrically
                }
            }
        }
    }
}

void printMatrix(int** res)
{
    int i,j;

    for(i =0; i<num; i++)
    {
        for(j=0; j<num; j++)
        {
            if(i<=j)
                cout<<res[i][j]<<" : "<<res[j][i]<<"    ";
            else
                cout<<"            ";
        }
        cout<<endl;
    }
}

//pass such that mat1 < mat2
void printOptimalSolution(int mat1, int mat2, int **res)
{
    if(mat1==mat2)
    {
        cout<<"Matrix["<<mat1<<"]";
        return;
    }
    else
    {
        cout<<"(";
        printOptimalSolution(mat1,res[mat2][mat1],res);
        cout<<" * ";
        printOptimalSolution(res[mat2][mat1]+1, mat2, res);
        cout<<")";
    }
}

void printOptimalValue(int mat1, int mat2, int **res)
{
    if(mat1 > mat2 || mat2 >= num)
    {
        cout<<"\nThis operation is not possible";
        return;
    }

    cout<<"\nOptimum value of matrix multiplication from matrix "<<mat1<<" to "<<mat2<<" : "<<res[mat1][mat2];

}

int main()
{
    int n,i;

    cout<<"\nEnter the no of matricies: ";
    cin>>n;

    num = n;

    int** res;
    res = new int*[num];
    for(i=0; i<num; i++)
        res[i] = new int[num];

    //allocate(res);

    int* dim = new int[n+1];
    enterDimensions(dim);
    printDimensions(dim);

    matrixChain(res,dim);

    int ch;
    int mat1,mat2;

    do{

        cout<<"\n--------------------------------------------------------------------------\n";
        cout<<"  MATRIX CHAIN MULTIPLICATION\n";
        cout<<"1.Print optimal value for matricies A to B.\n";
        cout<<"2.Print optimal solution for matricies A to B.\n";
        cout<<"3.Print entire result matrix.\n";
        cout<<"4.Exit.\n";
        cout<<"\n--------------------------------------------------------------------------";
        cout<<"\nEnter choice: ";
        cin>>ch;
        cout<<"\n--------------------------------------------------------------------------\n";

        switch(ch)
        {
            case 1:
            cout<<"\nEnter first matrix: ";
            cin>>mat1;
            cout<<"Enter second matrix: ";
            cin>>mat2;

            if(mat1> mat2 || mat2 >= num)
            {
                cout<<"First matrix < Second matrix.\nMatricies are from 0-"<<num-1;
                break;
            }

            printOptimalValue(mat1, mat2,res);
            break;

            case 2:
            cout<<"\nEnter first matrix: ";
            cin>>mat1;
            cout<<"Enter second matrix: ";
            cin>>mat2;
            if(mat1> mat2 || mat2 >= num)
            {
                cout<<"First matrix < Second matrix.\nMatricies are from 0-"<<num-1;
                break;
            }

            printOptimalSolution(mat1, mat2,res);
            break;

            case 3:
            printMatrix(res);
            break;

            case 4:
            exit(0);

            default: cout<<"\nPlease enter a valid choice\n";

        }

    }while(1);

    cout<<"\n--------------------------------------------------------------------------\n";

    delete []dim;
    //deallocate(res);
    for(i=0; i<num; i++)
        delete []res[i];
    delete []res;

    return 0;
}
