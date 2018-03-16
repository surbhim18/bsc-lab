#include <iostream>
#include <ctime>
#include "Frame.h"
#include "Packet.h"

using namespace std;

void system1();
void system2();

int main()
{
    char ch;

    do
    {
        system1();
        system2();

        cout<<"\n\n-------------------------------------------------------";
        cout<<"\nContinue(y/n): ";
        cin>>ch;
        cout<<"-------------------------------------------------------\n";

        cin.ignore();
    }
    while(ch=='y');

    return 0;
}
