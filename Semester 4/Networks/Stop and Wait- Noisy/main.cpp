#include <iostream>
#include <ctime>
#include "Frame.h"
#include "Packet.h"

using namespace std;

void sender3();
void receiver3();
//extern bool complete;

int main()
{
    char ch;

    do
    {
        sender3();
        receiver3();

        // if(complete)
        //{
        cout<<"\n\nContinue(y/n): ";
        cin>>ch;
        cin.ignore();
        //}
        //else
        //  ch='y';
    }
    while(ch=='y');

    return 0;
}
