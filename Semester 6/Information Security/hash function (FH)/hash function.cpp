#include<iostream>
#include<fstream>
#include<cstring>
#include<cstdlib>

using namespace std;

#define LEN 500 // a line can have max 500 chars

char calcHash(char *ptext, int n)
{
    int i;
    char h=0;

    for(i=0; i<n; i++)
    {
        h = h^ptext[i];
    }
    return h;
}

int main()
{
    ifstream fin;
    ofstream fout;
    char str[LEN];



    fin.open("ptext.txt");

    if(!fin)
    {
        cout<<"File could not be found";
        exit(1);
    }

    char hash1=0;
    do
    {
        fin.getline(str,LEN);
        hash1 = hash1^ (calcHash(str, strlen(str)));
        hash1 = hash1 ^ '\n';

    }while(fin);

    fin.close();

    cout<<"Initial hash: "<<hash1<<endl;

    /***************************************/
    fout.open("hash.txt");
    fout<<hash1;
    fout.close();
    /***************************************/

    /* change the file before pressing a key to check */
    cout<<"\nPress any key to check the file again";
    getchar();

    fin.open("ptext.txt");
    if(!fin)
    {
        cout<<"File could not be found";
        exit(1);
    }

    char hash2=0;
    do
    {
        fin.getline(str,LEN);
        hash2 = hash2 ^ (calcHash(str, strlen(str)));
        hash2 = hash2 ^ '\n';

    }while(fin);
    fin.close();

    cout<<"\nHash after recalculation: "<<hash2<<endl;

    /***************************************/

    char hashedOld;
    fin.open("hash.txt");
    fin>>hashedOld;
    fin.close();

    /***************************************/

    if(hash2 == hashedOld)
        cout<<"\nNo changes have been made!\n";
    else
        cout<<"\nFile has been changed!\n";

    return 0;
}
