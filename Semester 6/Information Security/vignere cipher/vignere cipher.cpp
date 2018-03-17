/*
 *  codeword and plain text should be in the same case.
 */

#include<iostream>
#include<cstring>
#include<cstdlib>

using namespace std;

/*
 * to calculate mod of negative numbers.
 */

int mod(int x, int y)
{
    if(x < 0)
    {
        x= x *-1;
        int temp = x%y;
        return (y - temp)%y;
    }
    else
        return x%y;

}

char* encrypt(char* text, char* code)
{
    int len = strlen(text);
    int lenCode = strlen(code);

    char *res = new char[len];

    int i,j=0;
    for(i=0; i<len; i++)
    {
        if(isupper(text[i]))
        {
            res[i] = (((text[i]-65)+(code[j]-65))%26)+65;
        }
        else if(islower(text[i]))
        {
            res[i] = (((text[i]-97)+(code[j]-97))%26)+97;
        }
        else
            res[i] = text[i];

        j = (j+1)%lenCode;
    }

    res[i] = '\0';
    return res;
}

char* decrypt(char* text, char* code)
{
    int len = strlen(text);
    int lenCode = strlen(code);

    char *res = new char[len];

    int i,j=0;
    for(i=0; i<len; i++)
    {
        if(isupper(text[i]))
        {
            res[i] = mod(((text[i]-65)-(code[j]-65)),26)+65;
        }
        else if(islower(text[i]))
        {
            res[i] = mod(((text[i]-97)-(code[j]-97)),26)+97;
        }
        else
            res[i] = text[i];

        j = (j+1)%lenCode;
    }

    res[i] = '\0';
    return res;
}


int main()
{
    char *text, *code, *etext, *dtext;

    text = new char[500];
    code = new char[500];


    do
    {
        int ch,n,len;
        int key;

        cout<<"\n1. Encrypt text.";
        cout<<"\n2. Decrypt text.";
        cout<<"\n3. Exit.";
        cout<<"\n\nEnter choice: ";
        cin>>ch;

        cin.ignore();

        if(ch!=3)
        {
            cout<<"\nEnter text      : ";
            cin.getline(text,500);

            cout<<"Enter code word : ";
            cin>>code;

        }

        switch(ch)
        {
        case 1:
        {
            etext = encrypt(text,code);
            cout<<"\nEncrypted text  : "<<etext<<"\n\n";
            break;
        }
        break;

        case 2:
        {
            dtext = decrypt(text,code);
            cout<<"\nDecrypted text  : "<<dtext<<"\n\n";
            break;
        }
        break;

        case 3:
            exit(0);

        default:
            cout<<"\nEnter valid choice!";
        }
        cout<<"\n----------------------------------";
    }
    while(1);

    return 0;
}
