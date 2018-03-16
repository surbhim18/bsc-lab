#include <iostream>
#include "Frame.h"
#include "Packet.h"

using namespace std;

void sender1();
void receiver1();


int main()
{
    char ch;

    do
    {
        sender1();
        receiver1();

        cout<<"\nContinue(y/n): ";
        cin>>ch;
        cin.ignore();
    }
    while(ch=='y');

    return 0;
}
