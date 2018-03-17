#include<iostream>
#include<cstring>
#include <cmath>
#include<cstdlib>

using namespace std;

char* encrypt(char* text, int col)
{
    int len = strlen(text);
    int rows = ceil((float)len/col);

    int i,j,k;
    char **mat = new char*[rows];
    for(i=0; i<rows; i++)
        mat[i] = new char[col];

    k=0;
    for(i=0; i<rows; i++)
    {
        for(j=0; j<col; j++)
        {
            if(i*col + j < len)
                mat[i][j] = text[k++];
            else
                mat[i][j] = ' ';
        }
    }

    char *res = new char[len];

    k=0;
    for(j=0; j<col; j++)
    {
        for(i=0; i<rows; i++)
        {
            if(mat[i][j]!=' ')
            {
                res[k] = mat[i][j];
                k++;
            }
        }
    }
    res[k] = '\0';

    return res;
}

char* decrypt(char* text, int col)
{
    int len = strlen(text);
    int rows = ceil((float)len/col);

    int i,j,k;
    char **mat = new char*[rows];
    for(i=0; i<rows; i++)
        mat[i] = new char[col];

    bool flag = false;
    int remLen= len;
    k=0;
    for(j=0; j<col; j++)
    {
        for(i=0; i<rows; i++)
        {
            mat[i][j] = text[k++];
        }

        remLen = remLen-rows;
        int remCol = col - j -1;
        if(ceil((float)remLen/remCol) < rows)
        {
            flag = true;
            break;
        }

        if(flag)
            break;
    }

    if(flag)
    {
        j++;
        for( ; j<col; j++)
        {
            for(i=0; i<rows-1; i++)
            {
                mat[i][j] = text[k++];
            }
        }
    }

    char *res = new char[len];
    k=0;

    flag= false;
    for(i=0; i<rows; i++)
    {
        for(j=0; j<col; j++)
        {
            if((i*col + j) < len)
                res[k++] = mat[i][j];
            else
            {
                flag = true;
                break;
            }
        }

        if(flag)
            break;
    }
    res[k] = '\0';

    return res;
}


int main()
{
    char *text, *etext, *dtext;

    text = new char[500];

    do
    {
        int ch,n;

        cout<<"\n1. Encrypt text.";
        cout<<"\n2. Decrypt text.";
        cout<<"\n3. Exit.";
        cout<<"\n\nEnter choice: ";
        cin>>ch;

        cin.ignore();

        if(ch!=3)
        {
            cout<<"\nEnter text : ";
            cin.getline(text,500);

            cout<<"Column size: ";
            cin>>n;
        }

        switch(ch)
        {
        case 1:
            etext = encrypt(text,n);
            cout<<"\nEncrypted text: "<<etext<<"\n\n";
            break;

        case 2:
            dtext = decrypt(text,n);
            cout<<"\nDecrypted text: "<<dtext<<"\n\n";
            break;

        case 3:
            exit(0);

        default:
            cout<<"\nEnter valid choice!";
        }
    }
    while(1);

    return 0;
}
