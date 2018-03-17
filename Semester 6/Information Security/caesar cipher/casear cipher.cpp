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

char* encrypt(char* text)
{
    int len = strlen(text);
    char *res = new char[len];

    int i;
    for(i=0; i<len; i++)
    {
        if(isupper(text[i]))
        {
            res[i] = ((text[i]-65+3)%26)+65;
        }
        else if(islower(text[i]))
        {
            res[i] = ((text[i]-97+3)%26)+97;
        }
        else
            res[i] = text[i];
    }

    res[i] = '\0';
    return res;
}

char* decrypt(char* text)
{
    int len = strlen(text);
    char *res = new char[len];

    int i;
    for(i=0; i<len; i++)
    {
        if(isupper(text[i]))
        {
            res[i] = mod((text[i]-65-3),26)+65;
        }
        else if(islower(text[i]))
        {
            res[i] = mod((text[i]-97-3),26)+97;
        }
        else
            res[i] = text[i];
    }

    res[i] = '\0';
    return res;
}


int main()
{
    char *text, *etext, *dtext;

    text = new char[500];

    do
    {
        int ch,n,len;

        cout<<"\n1. Encrypt text.";
        cout<<"\n2. Decrypt text.";
        cout<<"\n3. Exit.";
        cout<<"\n\nEnter choice: ";
        cin>>ch;

        cin.ignore();

        if(ch!=3)
        {
            cout<<"\nEnter text    : ";
            cin.getline(text,500);
        }

        switch(ch)
        {
        case 1:
        {
            etext = encrypt(text);
            cout<<"\nEncrypted text: "<<etext;
            cout<<endl;
        }
        break;

        case 2:
        {
            dtext = decrypt(text);
            cout<<"\nDecrypted text: "<<dtext<<"\n";
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
