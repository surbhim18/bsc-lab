#include <iostream>
#include "BST.h"

using namespace std;

int main()
{

    int ch, element;
    BST tree;

    do{

        cout<<"\n---------------------------------------------------------------\n";
        cout<<"  BINARY SEARCH TREE\n";
        cout<<" 1.Insert element iteratively (1).\n";
        cout<<" 2.Insert element iteratively (2).\n";
        cout<<" 3.Insert element recursively (1).\n";
        cout<<" 4.Insert element recursively (2).\n";
        cout<<" 5.Insert element recursively (3).\n";
        cout<<" 6.Insert element recursively (4).\n";
        cout<<"..............................................\n";
        cout<<" 7.Deletion by merging (1).\n";
        cout<<" 8.Deletion by merging (2).\n";
        cout<<" 9.Deletion by copying. (using predeccesor)\n";
        cout<<"10.Deletion by copying. (using successor)\n";
        cout<<"..............................................\n";
        cout<<"11.Create mirror image.\n";
        cout<<"12.Calculate height of the tree.\n";
        cout<<"13.Calculate sum and average of nodes.\n";
        cout<<"14.Calculate number of nodes in the tree.\n";
        cout<<"15.Find maximum and minimum node of tree.\n";
        cout<<"..............................................\n";
        cout<<"16.Display preorder traversal.\n";
        cout<<"17.Display inorder traversal.\n";
        cout<<"18.Display postorder traversal.\n";
        cout<<"19.Display BFS.\n";
        cout<<"20.Display DFS.\n";
        cout<<"..............................................\n";
        cout<<"21.Exit.\n";
        cout<<"---------------------------------------------------------------";
        cout<<"\nEnter choice: ";
        cin>>ch;
        cout<<"\n---------------------------------------------------------------";

        switch(ch)
        {
            case 1:
            cout<<"\nEnter element: ";
            cin>>element;
            tree.insertI1(element);
            break;

            case 2:
            cout<<"\nEnter element: ";
            cin>>element;
            tree.insertI2(element);
	        break;

            case 3:
            cout<<"\nEnter element: ";
            cin>>element;
            if(tree.root == 0)
                tree.root = new Node(element);
            else
                tree.insertR1(tree.root,element);
            break;


            case 4:
            cout<<"\nEnter element: ";
            cin>>element;
            if(tree.root == 0)
                tree.root = new Node(element);
            else
                tree.insertR2(0,tree.root,element);
            break;


            case 5:
            cout<<"\nEnter element: ";
            cin>>element;
            tree.insertR3(tree.root,element);
            break;


            case 6:
            cout<<"\nEnter element: ";
            cin>>element;
            tree.root = tree.insertR4(tree.root,element);
            break;

            case 7:
            if(tree.noTree())
                cout<<"\nNo tree exists.";
            else
            {
                cout<<"\nEnter element to be deleted: ";
                cin>>element;
                tree.deletionM1(element);
            }
            break;

            case 8:
            if(tree.noTree())
                cout<<"\nNo tree exists.";
            else
            {
                cout<<"\nEnter element to be deleted: ";
                cin>>element;
                tree.deletionM2(element);
            }
            break;

            case 9:
            if(tree.noTree())
                cout<<"\nNo tree exists.";
            else
            {
                cout<<"\nEnter element to be deleted: ";
                cin>>element;
                tree.deletionC1(element);
            }
            break;

            case 10:
            if(tree.noTree())
                cout<<"\nNo tree exists.";
            else
            {
                cout<<"\nEnter element to be deleted: ";
                cin>>element;
                tree.deletionC2(element);
            }
            break;

            case 11:
            if(tree.noTree())
                cout<<"\nNo tree exists.";
            else
            {
                tree.mirror(tree.root);
                cout<<"\nMirroring complete. View the tree.";
            }
            break;

            case 12:
            if(tree.noTree())
                cout<<"\nNo tree exists.";
            else
                cout<<"\nThe height of the tree: "<<tree.calc_height(tree.root);
            break;

            case 13:
            if(tree.noTree())
                cout<<"\nNo tree exists.";
            else
            {
                int sum = tree.calc_sum(tree.root);
                cout<<"\nThe sum of all nodes    : "<<sum;
                cout<<"\nThe average of all nodes: "<<(float)sum/(tree.noOfNodes(tree.root));
            }
            break;

            case 14:
            cout<<"\nThe number of nodes: "<<tree.noOfNodes(tree.root);
            break;

            case 15:
            if(tree.noTree())
                cout<<"\nNo tree exists.";
            else
            {
                cout<<"\nThe minimum of all nodes : "<<tree.calcMin(tree.root);
                cout<<"\nThe maximum of all nodes : "<<tree.calcMax(tree.root);
            }
            break;

            case 16:
            cout<<"\nPreorder: \n";
            tree.preorder(tree.root);
            break;

            case 17:
            cout<<"\nInorder: \n";
            tree.inorder(tree.root);
            break;

            case 18:
            cout<<"\nPostorder: \n";
            tree.postorder(tree.root);
            break;

            case 19:
            cout<<"\nBFS: \n";
            tree.BFS();
            break;

            case 20:
            cout<<"\nDFS: \n";
            tree.BFS();
            break;

            case 21:
            exit(0);

            default: cout<<"\nPlease enter a valid choice\n";

        }

    }while(1);

    cout<<"\n---------------------------------------------------------------\n";

    return 0;

}
