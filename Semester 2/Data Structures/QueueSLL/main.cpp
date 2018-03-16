#include <iostream>
#include "QueueSLL.h"
#include "MyException.h"
#include <cstdlib>

using namespace std;

int main()
{
    int ch;
    QueueSLL listObj;

    int element;

    do{

        cout<<"\n--------------------------------------------------------------------------\n";
        cout<<"  QUEUE\n";
        cout<<"1.Enter element in the queue.\n";
        cout<<"2.Delete an element.\n";
        cout<<"3.Display the queue.\n";
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
            listObj.enqueue(element);
            break;

            case 2:
            try
            {
                element = listObj.dequeue();
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
