#include <iostream>
#include <cstdlib>
#include "RBtree.h"

using namespace std;

int main()
{

    int ch, element;
    RBtree t1;

    do{

        cout<<"\n-------------------------------------------------------------------------------\n";
        cout<<"  RED BLACK TREE\n";
        cout<<" 1.Insert element.\n";
        cout<<" 2.Delete element.\n";
        cout<<" 3.Display inorder traversal.\n";
        cout<<" 4.Display postorder traversal.\n";
        cout<<" 5.Exit.\n";
        cout<<"----------------------------------------------------------------------------------";
        cout<<"\nEnter choice: ";
        cin>>ch;
        cout<<"\n-------------------------------------------------------------------------------";

        switch(ch)
        {
            case 1:
            cout<<"\nInsert element: ";
            cin>>element;
            t1.insert(element);
            break;

            case 2:
            cout<<"\nDelete element: ";
            cin>>element;
            t1.deletion(element);
            break;

            case 3:
            cout<<"\nInorder: \n";
            t1.inorder();
            break;

            case 4:
            cout<<"\nPostorder: \n";
            t1.postorder();
            break;

            case 5:
            exit(0);

            default: cout<<"\nPlease enter a valid choice\n";

        }

    }while(1);

    cout<<"\n-----------------------------------------------------------------------------\n";

    return 0;

}
