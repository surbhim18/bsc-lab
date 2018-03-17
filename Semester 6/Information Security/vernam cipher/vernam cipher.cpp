#include<iostream>
#include<cstring>
#include <cmath>
#include<ctime>
#include<cstdlib>

using namespace std;

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

void fillRandomSeq(short int *seq, int n)
{
    int i;
    for(i=0; i<n; i++)
        seq[i] = rand()%100;
}

char* encrypt(char* text, short int* seq)
{
    int len = strlen(text);
    char *res = new char[len];

    fillRandomSeq(seq,len);

    int i;
    for(i=0; i<len; i++)
    {
        if(isupper(text[i]))
        {
            res[i] = (((text[i]-65)+seq[i])%26)+65;
        }
        else if(islower(text[i]))
        {
            res[i] = (((text[i]-97)+seq[i])%26)+97;
        }
        else
            res[i] = text[i];
    }
    res[i] = '\0';

    return res;
}

char* decrypt(char* text, short int* seq)
{
    int len = strlen(text);
    char *res = new char[len];

    int i;
    for(i=0; i<len; i++)
    {
        if(isupper(text[i]))
        {
            res[i] = mod(((text[i]-65)-seq[i]),26)+65;
        }
        else if(islower(text[i]))
        {
            res[i] = mod(((text[i]-97)-seq[i]),26)+97;
        }
        else
            res[i] = text[i];
    }
    res[i] = '\0';

    return res;
}


int main()
{
    srand((unsigned)time(NULL));
    char *text, *etext, *dtext;
    text = new char[500];

    do
    {
        int ch,n,len;
        short int *seq;

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

            len = strlen(text);
            seq = new short int[len];
        }

        switch(ch)
        {
        case 1:
        {
            etext = encrypt(text,seq);
            cout<<"\nEncrypted text: "<<etext;

            cout<<"\n\nRandom number sequence used:\n";
            for(int i=0; i<len; i++)
                cout<<seq[i]<<"  ";

            cout<<endl;
        }
        break;

        case 2:
        {
            cout<<"\nEnter number sequence :\n";
            for(int i=0; i<len; i++)
                cin>>seq[i];

            dtext = decrypt(text,seq);
            cout<<"\nDecrypted text: "<<dtext<<"\n\n";
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
