#include<iostream>
#include<cstring>

using namespace std;

void LCS(char* str1, char* str2, int **res, char **dir)
{
    int i,j;

    for(i=0 ; i<= strlen(str1); i++)           // i: matrix row index
    {
        int I= i-1;
        for(j= 0; j<=strlen(str2); j++)       // j:matrix column index
        {
            int J= j-1;

            if(i==0 || j==0)
            {
                res[i][j] = 0;
                dir[i][j] = ' ';
            }
            else if(str1[I] == str2[J])
            {
                res[i][j] = res[i-1][j-1] + 1;
                dir[i][j] = '\\';
            }
            else
            {
                if(res[i][j-1] > res[i-1][j])
                {
                    res[i][j] = res[i][j-1];
                    dir[i][j] = '<';
                }
                else
                {
                    res[i][j] = res[i-1][j];
                    dir[i][j] = '^';
                }
            }
        }
    }
}

void print_all_info(int** res, char **dir, char* str1, char* str2)
{
    int i,j;
    cout<<"\t\b\b";
    for(i=0; i<strlen(str2); i++)
        cout<<"    "<<str2[i];

    cout<<endl;

    for(i=0; i<=strlen(str1); i++)
    {
        if(i>0)
        {
            cout<<str1[i-1]<<"    ";
        }
        else
        {
            cout<<"     ";
        }

        for(j=0 ; j<=strlen(str2); j++)
        {
            cout<<res[i][j]<<":"<<dir[i][j]<<"  ";
        }

        cout<<endl;
    }
}

void printLCS(char **dir, int i, int j, char* str)
{
    int I = i+1;
    int J = j+1;

    if(I==0 || J==0 )
        return;

    if(dir[I][J] == '\\')
    {
        printLCS(dir,i-1,j-1,str);
        cout<<str[i];
    }
    else if(dir[I][J] == '^')
        printLCS(dir,i-1,j,str);
    else
        printLCS(dir,i,j-1,str);
}

int main()
{
    int i,j;
    char* str1 = new char[50];
    char* str2 = new char[50];

    cout<<"\nEnter first string: ";
    cin>>str1;

    cout<<"\nEnter second string: ";
    cin>>str2;

    int len1 = strlen(str1)+1;
    int len2 = strlen(str2)+1;

    int **res = new int*[len1];
    for(i=0; i<len1; i++)
        res[i] = new int[len2];

    char **dir = new char*[len1];
    for(i=0; i<len1; i++)
        dir[i] = new char[len2];

    LCS(str1,str2,res,dir);
    print_all_info(res,dir,str1,str2);

    int m = len1-1;
    int n = len2-1;

    cout<<"\nLCS:\n";
    int lenLCS = res[m][n];

    char* str = new char[50];

    if(len1 > len2)
        strcpy(str,str1);
    else
        strcpy(str,str2);

    i = m;
    for(j=n; j>0; j--)
    {
        if(res[i][j]==lenLCS)
        {
            printLCS(dir,i-1,j-1,str);      //indices of string are being passed
            cout<<endl;
        }
    }

    delete []str1;
    delete []str2;
    delete []str;

    return 0;
}
