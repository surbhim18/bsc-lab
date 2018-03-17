/** keys calculated        **/
/** inverse calculated : method 1 **/

#include<iostream>
#include<cstring>
#include <cmath>
#include<ctime>
#include<cstdlib>

using namespace std;

#define noOfKeys 12     // hard-coded no of keys

int gcd(int a, int b)
{
    if(a == 0)
        return b;
    else
        return gcd(b%a, a);
}

int* calcKeys(int n)
{
    int i,k=0;
    int *keys = new int[noOfKeys];
    for(i=2; i<n; i++)
    {
        if(gcd(n,i)==1)
            keys[k++] = i;
    }
    return keys;
}

bool checkKey(int *keys, int val)
{
    for(int i=0; i<noOfKeys; i++)
    {
        if(val == keys[i])
            return true;
    }
    return false;
}

char* encrypt(char* text, int key)
{
    int len = strlen(text);
    char *res = new char[len];

    int i;
    for(i=0; i<len; i++)
    {
        if(isupper(text[i]))
        {
            res[i] = (((text[i]-65)*key)%26)+65;
        }
        else if(islower(text[i]))
        {
            res[i] = (((text[i]-97)*key)%26)+97;
        }
        else
            res[i] = text[i];
    }

    res[i] = '\0';

    return res;
}

int calcInverse(int x, int *keys)
{
    int inverse;
    for(int i=0; i<12; i++)
    {
        if((x*keys[i])%26 == 1)
        {
            inverse = keys[i];
            break;
        }
    }
    return inverse;
}

char* decrypt(char* text, int key, int *keys)
{
    int len = strlen(text);
    char *res = new char[len];

    int i;
    int inv = calcInverse(key, keys);

    for(i=0; i<len; i++)
    {
        if(isupper(text[i]))
        {
            res[i] = (((text[i]-65)*inv)%26)+65;
        }
        else if(islower(text[i]))
        {
            res[i] = (((text[i]-97)*inv)%26)+97;
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
    int key;

    int *keys = calcKeys(26);

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

            key = keys[rand()%12];
        }

        switch(ch)
        {
        case 1:
        {
            etext = encrypt(text,key);
            cout<<"\nEncrypted text: "<<etext;
            cout<<"\nKey used      : "<<key;
            cout<<endl;
        }
        break;

        case 2:
        {
            do
            {
                cout<<"Enter key     : ";
                cin>>key;
            }
            while(!checkKey(keys,key));

            dtext = decrypt(text,key,keys);
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
