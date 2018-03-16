#include <iostream>
#include "Frame.h"
#include "Packet.h"

using namespace std;

void sender2();
void receiver2();


int main()
{
    char ch;

    do
    {
        sender2();
        receiver2();

        cout<<"\nContinue(y/n): ";
        cin>>ch;
        cin.ignore();
    }
    while(ch=='y');

    return 0;
}
