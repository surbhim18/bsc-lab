#include <iostream>
#include "StackSLL.h"
#include "MyException.h"
#include <cstdlib>

using namespace std;

int main()
{
    int ch;
    StackSLL listObj;

    int element;

    do{

        cout<<"\n--------------------------------------------------------------------------\n";
        cout<<"  STACK\n";
        cout<<"1.Push element in the stack.\n";
        cout<<"2.Pop an element.\n";
        cout<<"3.Display the stack.\n";
        cout<<"4.Exit\n";
        cout<<"\n--------------------------------------------------------------------------";
        cout<<"\nEnter choice: ";
        cin>>ch;
        cout<<"\n--------------------------------------------------------------------------";

        switch(ch)
        {
            case 1:
            cout<<"\nEnter element: ";
            cin>>element;
            listObj.push(element);
            break;

            case 2:
            try
            {
                element = listObj.pop();
                cout<<"\nElement: "<<element;
            }
            catch(MyException& ex)
            {
                ex.print();
            }
            break;

            case 3:
            listObj.display();
            break;

            case 4:
            exit(0);
        }

    }while(1);

    cout<<"\n--------------------------------------------------------------------------";

  return 0;
}




