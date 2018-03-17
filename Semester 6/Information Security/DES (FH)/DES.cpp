#include<fstream>
#include<iostream>
#include<cmath>

using namespace std;

#define DATASIZE 64
#define SIZE2    (DATASIZE - (DATASIZE/8))
#define SIZE3    (SIZE2 - 8)
#define HALFSIZE (DATASIZE/2)
#define NUM_CYCLES 16

const int initialP[DATASIZE] = {39,7,47,15,55,23,63,31,38,6,46,14,54,22,62,30,37,5,45,13,53,21,61,29,36,4,44,12,52,20,60,28,35,3,43,11,51,19,59,27,34,2,42,10,50,18,58,26,33,1,41,9,49,17,57,25,32,0,40,8,48,16,56,24};
const int finalP[DATASIZE]   = {57,49,41,33,25,17,9,1,59,51,43,35,27,19,11,3,61,53,45,37,29,21,13,5,63,55,47,39,31,23,15,7,56,48,40,32,24,16,8,0,58,50,42,34,26,18,10,2,60,52,44,36,28,20,12,4,62,54,46,38,30,22,14,6};
const int keyShifts[NUM_CYCLES] = {1,1,2,2,2,2,2,2,1,2,2,2,2,2,2,1};
const int choicePkeySelect[SIZE3] = {4,23,6,15,5,9,19,17,11,2,14,22,0,8,18,1,13,21,10,12,3,16,20,7,46,30,26,47,34,40,45,27,38,31,24,43,36,33,42,28,35,37,44,32,25,41,29,39};
const int straightP[HALFSIZE] = {8,16,22,30,12,27,1,17,23,15,29,5,25,19,9,0,7,13,24,2,3,28,10,18,31,11,21,6,4,26,14,20};

const char binMap[16][5] = {"0000","0001","0010","0011","0100","0101","0110","0111","1000","1001","1010","1011","1100","1101","1110","1111"};

const int sBox[8][4][16] = {{{14,4,13,1,2,15,11,8,3,10,6,12,5,9,0,7},
                            {0,15,7,4,14,2,13,1,10,6,12,11,9,5,3,8},
                            {4,1,14,8,13,6,2,11,15,12,9,7,3,10,5,0},
                            {15,12,8,2,4,9,1,7,5,11,3,14,10,0,6,13}},

                           {{15,1,8,14,6,11,3,4,9,7,2,13,12,0,5,10},
                            {3,13,4,7,15,2,8,14,12,0,1,10,6,9,11,5},
                            {0,14,7,11,10,4,13,1,5,8,12,6,9,3,2,15},
                            {13,8,10,1,3,15,4,2,11,6,7,12,0,5,14,9}},

                           {{10,0,9,14,6,3,15,5,1,13,12,7,11,4,2,8},
                            {13,7,0,9,3,4,6,10,2,8,5,14,12,11,15,1},
                            {13,6,4,9,8,15,3,0,11,1,2,12,5,10,14,7},
                            {1,10,13,0,6,9,8,7,4,15,14,3,11,5,2,12}},

                           {{7,13,14,3,0,6,9,10,1,2,8,5,11,12,4,15},
                            {13,8,11,5,6,15,0,3,4,7,2,12,1,10,14,9},
                            {10,6,9,0,12,11,7,13,15,1,3,14,5,2,8,4},
                            {3,15,0,6,10,1,13,8,9,4,5,11,12,7,2,14}},

                           {{2,12,4,1,7,10,11,6,8,5,3,15,13,0,14,9},
                            {14,11,2,12,4,7,13,1,5,0,15,10,3,9,8,6},
                            {4,2,1,11,10,13,7,8,15,9,12,5,6,3,0,14},
                            {11,8,12,7,1,14,2,13,6,15,0,9,10,4,5,3}},

                           {{12,1,10,15,9,2,6,8,0,13,3,4,14,7,5,11},
                            {10,15,4,2,7,12,9,5,6,1,13,14,0,11,3,8},
                            {9,14,15,5,2,8,12,3,7,0,4,10,1,13,11,6},
                            {4,3,2,12,9,5,15,10,11,14,1,7,6,0,8,13}},

                           {{4,11,2,14,15,0,8,13,3,12,9,7,5,10,6,1},
                            {13,0,11,7,4,9,1,10,14,3,5,12,2,15,8,6},
                            {1,4,11,13,12,3,7,14,10,15,6,8,0,5,9,2},
                            {6,11,13,8,1,4,10,7,9,5,0,15,14,2,3,12}},

                           {{13,2,8,4,6,15,11,1,10,9,3,14,5,0,12,7},
                            {1,15,13,8,10,3,7,4,12,5,6,11,0,14,9,2},
                            {7,11,4,1,9,12,14,2,0,6,10,13,15,3,5,8},
                            {2,1,14,7,4,10,8,13,15,12,9,0,3,5,6,11}}};

void enter(char *a, int n)
{
    for(int i=0; i<n; i++)
        cin>>a[i];
}

void print(char *a, int n)
{
    for(int i=0; i<n; i++)
        cout<<a[i];
}

char* shortenKey(char *key)
{
    char *newKey = new char[SIZE2+1];
    int i,j=0;

    for(i=0; i<DATASIZE; i++)
    {
        if(i%8 != 7)
            newKey[j++] = key[i];
    }
    newKey[j] = '\0';
    return newKey;
}

char* initialPermutation(char *data)
{
    char *newData = new char[DATASIZE+1];
    int i;
    for(i=0; i<DATASIZE; i++)
    {
        newData[initialP[i]] = data[i];
    }
    newData[i] = '\0';
    return newData;
}

char* finalPermutation(char *data)
{
    char *newData = new char[DATASIZE+1];
    int i;
    for(i=0; i<DATASIZE; i++)
    {
        newData[finalP[i]] = data[i];
    }
    newData[i] = '\0';
    return newData;
}

char* expandRightHalf(char *data)
{
    char *newRH = new char[SIZE3+1];

    int j=0,pos1,pos2;
    int count=SIZE3-1;
    bool flag = false;      /* set when goes in first if */
    for(int i=HALFSIZE; i<DATASIZE; i++)
    {
        if(i%8 == 0 || i%8 ==3 || i%8 == 4 || i%8 ==7)
        {
            if(flag)
            {
                count = count-2;
            }
            pos1 = count;
            pos2 = (count+2)%SIZE3;
            count = (pos2+1)%SIZE3;

            newRH[pos1] = data[i];
            newRH[pos2] = data[i];
            flag = true;
        }
        else
        {
            pos1 = count;
            count = (count+1)%SIZE3;

            newRH[pos1] = data[i];
            flag = false;
        }
    }

    newRH[SIZE3] = '\0';
    return newRH;
}

/* shift halves left circularly by n bits */
void shiftHalvesLC(char *key, int n)
{
    int i=0;
    int len= SIZE2/2;

    char *buffer = new char[n];

    for(i=0; i<n; i++)
    {
        buffer[i] = key[i];
    }
    for(i=0; i<len-n;i++)
    {
        key[i] = key[i+n];
    }
    for(i=0; i<n; i++)
    {
        key[len-n+i] = buffer[i];
    }

    for(i=0; i<n; i++)
    {
        buffer[i] = key[len+i];
    }
    for(i=len; i<SIZE2-n; i++)
    {
        key[i] = key[i+n];
    }
    for(i=0; i<n; i++)
    {
        key[SIZE2-n+i] = buffer[i];
    }

    delete buffer;
}

char* choicePermutationKey(char *key)
{
    char *newKey = new char[SIZE3+1];
    int j=0;
    for(int i=0; i<SIZE2; i++)
    {
        if(i==8 || i==17 || i==21 || i==24 || i==34 || i==37 || i==42 || i==53);
        else
            newKey[j++] = key[i];
    }
    newKey[SIZE3] = '\0';
    return newKey;
}

char* transformKey(char *key, int cycleNo)
{
    char *newKey;

    shiftHalvesLC(key,keyShifts[cycleNo]);
    newKey = choicePermutationKey(key);

    return newKey;
}

char* xorCombine(char *a, char *b, int n)
{
    char *res = new char[n+1];
    int i;
    for(i=0; i<n; i++)
    {
        if(a[i] == b[i])
            res[i] = '0';
        else
            res[i] = '1';
    }
    res[i] = '\0';
    return res;
}

/*
 *  The data can have bits as 0, 1 only.
 */
int* retIntArray(char *str, int n)
{
    int *res = new int[n];
    for(int i=0; i<n; i++)
    {
        if(str[i] == '0')
            res[i] = 0;
        else
            res[i] = 1;
    }
    return res;
}

int convert(char bin[5], int n)
{
    int res=0;
    int *binary = retIntArray(bin,n);

    for(int i=0; i<n; i++)
    {
        res +=  (binary[i] * pow(2,n-i-1));
    }
    return res;
}

char* substitute(char *data)
{
    char *newData = new char[HALFSIZE+1];
    char *x = new char[5];

    int r,c;
    int i,j;
    int sno=0,n=0;
    for(i=0; i<SIZE3; i+=6)
    {
        x[0] = data[i];
        x[1] = data[i+5];
        x[2] = '\0';

        r = convert(x,2);

        x[0] = data[i+1];
        x[1] = data[i+2];
        x[2] = data[i+3];
        x[3] = data[i+4];
        x[4] = '\0';

        c = convert(x,4);
        int bin = sBox[sno][r][c];

        int k=0;
        for(j=n; j<n+4; j++)
        {
            newData[j] = binMap[bin][k];
            k++;
        }
        n+=4;
        sno++;
    }

    newData[HALFSIZE] = '\0';
    return newData;
}

char* straightPermutation(char *data)
{
    char *newData = new char[HALFSIZE+1];
    int i;
    for(i=0; i<HALFSIZE; i++)
    {
        newData[straightP[i]] = data[i];
    }
    newData[i] = '\0';
    return newData;
}

void copyToLeft(char *data)
{
    for(int i=0; i<HALFSIZE; i++)
    {
        data[i] = data[i+HALFSIZE];
    }
}

void copyToRight(char *data, char *temp)
{
    for(int i=0; i<HALFSIZE; i++)
    {
        data[i+HALFSIZE] = temp[i];
    }
}

int main()
{
    ifstream fin;
    ofstream fout;

    char *data, *key;
    data = new char[DATASIZE+1];
    key  = new char[DATASIZE+1];

    fin.open("key.txt");
    fin.read(key,DATASIZE);
    fin.close();

    key[DATASIZE] = '\0';
    cout<<"\nKEY :\n"<<key;

    fin.open("ptext.txt");
    fin.read(data,DATASIZE);
    fin.close();

    data[DATASIZE] = '\0';
    cout<<"\n\nDATA:\n"<<data;

    key = shortenKey(key);              /* key length : 56 */
    data = initialPermutation(data);    /* data length: 64 */

    int i;
    for(i=0; i< NUM_CYCLES ; i++)
    {
        char *expandedRH = expandRightHalf(data);        /* length : 48 */

        char *transformedKey = transformKey(key,i);      /* key length : 48 */

        char *xoredRes = xorCombine(expandedRH,transformedKey,SIZE3);   /* length : 48 */

        char *subRes = substitute(xoredRes);            /* length : 32 */

        char *pRes = straightPermutation(subRes);       /* length : 32 */

        copyToLeft(data);
        copyToRight(data,pRes);
    }

    data = finalPermutation(data);



    cout<<"\n\nEncrypted data  :\n";
    cout<<data<<endl;

    fout.open("etext.txt");
    fout<<data;
    fout.close();

    return 0;
}
