#include <iostream>
#include<stdlib.h>
#include<cstring>
#include "MyException.h"
#include "CircularSLL.h"

using namespace std;

int main()
{

    int ch,element,data;
    CircularSLL listObj;

    do{

        cout<<"\n--------------------------------------------------------------------------\n";
        cout<<"  CIRCULAR LINK-LIST\n";
        cout<<"1.Add element at head.\n";
        cout<<"2.Add element at tail.\n";
        cout<<"3.Delete an element from head.\n";
        cout<<"4.Delete an element from tail.\n";
        cout<<"5.Search whether an element is in the list.\n";
        cout<<"6.Delete an element from the list.\n";
        cout<<"7.Add data before element.\n";
        cout<<"8.Add data after element.\n";
        cout<<"9.Delete data before an element.\n";
        cout<<"10.Delete data after an element.\n";
        cout<<"11.Reverse the link list.\n";
        cout<<"12.Display the list.\n";
        cout<<"13.Exit.\n";
        cout<<"\n--------------------------------------------------------------------------";
        cout<<"\nEnter choice: ";
        cin>>ch;
        cout<<"\n--------------------------------------------------------------------------";

        switch(ch)
        {
            case 1:
            cout<<"\nEnter element: ";
            cin>>element;
            listObj.addToHead(element);
            break;

            case 2:
            cout<<"\nEnter element: ";
            cin>>element;
            listObj.addToTail(element);
	        break;

            case 3:
            try
            {
                element = listObj.deleteFromHead();
                cout<<"\nElement: "<<element;
            }
            catch(MyException& ex)
            {
                ex.print();
            }
            break;


            case 4:
            try
            {
                element = listObj.deleteFromTail();
                cout<<"\nElement: "<<element;
            }
            catch(MyException& ex)
            {
                ex.print();
            }
            break;


            case 5:
            cout<<"\nEnter element: ";
            cin>>element;
            try
            {
                if(listObj.isInList(element))
                    cout<<endl<<element<<" is present in the list.";
                else
                    cout<<endl<<element<<" is not present in the list.";
            }

            catch(MyException& ex)
            {
                ex.print();
            }
            break;


            case 6:
            cout<<"\nEnter element: ";
            cin>>element;
            try
            {
                if(listObj.delet(element))
                    cout<<endl<<element<<" has been deleted from the list.";
                else
                    cout<<endl<<element<<" is not present in the list!";
            }

            catch(MyException ex)
            {
                ex.print();
            }
            break;


            case 7:
            cout<<"\nEnter element before which new data is to be added: ";
            cin>>element;
            cout<<"Enter the data: ";
            cin>>data;

            if(listObj.addBefore(element,data))
                cout<<"\nThe element has been added successfully.";
            else
                cout<<"\nThe element you entered could not be found.";

            break;

            case 8:
            cout<<"\nEnter element after which new data is to be added: ";
            cin>>element;
            cout<<"Enter the data: ";
            cin>>data;

            if(listObj.addAfter(element,data))
                cout<<"\nThe element has been added successfully.";
            else
                cout<<"\nThe element you entered could not be found.";

            break;

            case 9:
            cout<<"\nEnter element before which data is to be deleted: ";
            cin>>element;

            if(listObj.deleteBefore(element))
                cout<<"\nThe element has been deleted successfully.";
            else
                cout<<"\nThe element you entered either could not be found or had no data before it.";
            break;

            case 10:
            cout<<"\nEnter element after which data is to be deleted: ";
            cin>>element;

            if(listObj.deleteAfter(element))
                cout<<"\nThe element has been deleted successfully.";
            else
                cout<<"\nThe element you entered either could not be found or had no data after it.";

            break;

            case 11:
            listObj.reverseCSLL();
            cout<<"\nThe list has been succesfully reversed.";
            break;

            case 12:
            listObj.display();
            break;

            case 13:
            exit(0);

            default: cout<<"\nPlease enter a valid choice\n";

        }

    }while(1);

    cout<<"\n--------------------------------------------------------------------------\n";

    return 0;

}
