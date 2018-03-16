#include <iostream>
#include <cstdlib>
#include "include/RodCut.h"

using namespace std;

int main()
{
    int ch,n,len;

    cout<<"\nEnter maximum size of rod: ";
    cin>>n;

    RodCut r(n);

    r.enterPrices();

    do{

        cout<<"\n--------------------------------------------------------------------------\n";
        cout<<"  ROD CUT\n";
        cout<<"1.Print optimal value for rod of length n.\n";
        cout<<"2.Print optimal solution for rod of length n.\n";
        cout<<"3.Print all information.\n";
        cout<<"4.Exit.\n";
        cout<<"\n--------------------------------------------------------------------------";
        cout<<"\nEnter choice: ";
        cin>>ch;
        cout<<"\n--------------------------------------------------------------------------";

        switch(ch)
        {
            case 1:
            cout<<"\nEnter length of rod: ";
            cin>>len;

            r.printOptimalValue(len);
            break;

            case 2:
            cout<<"\nEnter length of rod: ";
            cin>>len;

            r.printOptimalSolution(len);
            break;

            case 3:
            r.printAll();
            break;

            case 4:
            exit(0);

            default: cout<<"\nPlease enter a valid choice\n";

        }

    }while(1);

    cout<<"\n--------------------------------------------------------------------------\n";

    return 0;

}
