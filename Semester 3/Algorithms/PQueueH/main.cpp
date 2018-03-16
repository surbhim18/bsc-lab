#include <iostream>
#include<cstdlib>
#include "PQueueH.h"

using namespace std;

int main()
{
    int ch,n,element,index;

    cout<<"\nEnter maximum size of queue: ";
    cin>>n;

    PQueueH q1(n);

    do{

        cout<<"\n--------------------------------------------------------------------------\n";
        cout<<"  PRIORITY QUEUE (USING HEAPS)\n";
        cout<<"1.Print maximum element of queue.\n";
        cout<<"2.Extract maximum element of queue.\n";
        cout<<"3.Insert an element.\n";
        cout<<"4.Increase the value at position i to k.\n";
        cout<<"5.Print the queue.\n";
        cout<<"6.Exit.\n";
        cout<<"\n--------------------------------------------------------------------------";
        cout<<"\nEnter choice: ";
        cin>>ch;
        cout<<"\n--------------------------------------------------------------------------";

        switch(ch)
        {
            case 1:
            try
            {
                cout<<"\nMaximum element: "<<q1.retMax();
            }
            catch(const char* str)
            {
                cout<<str;
            }
            break;

            case 2:
            try
            {
            cout<<"\nMaximum element: "<<q1.extractMax();
            }
            catch(const char* str)
            {
                cout<<str;
            }
	        break;

            case 3:
            try
            {
                cout<<"\nEnter element: ";
                cin>>element;
                q1.insertEle(element);
                cout<<"\nElement entered successfully";
            }
            catch(const char* str)
            {
                cout<<str;
            }
            break;

            case 4:
            try
            {
                cout<<"\nEnter index: ";
                cin>>index;

                if(index+1 > q1.retHeapSize())
                {
                    cout<<"\nYou have entered an invalid index.\n";
                    break;
                }

                cout<<"\nEnter increased key: ";
                cin>>element;
                q1.increaseKey(index,element);
                cout<<"\nThe value has been successfully increased. Print queue using 5.";
            }
            catch(const char* str)
            {
                cout<<str;
            }
            break;


            case 5:
            cout<<"\nQueue is:\n";
            q1.printQueue();
            break;


            case 6:
            exit(0);

            default: cout<<"\nPlease enter a valid choice\n";

        }

    }while(1);

    cout<<"\n--------------------------------------------------------------------------\n";

    return 0;

}
