#include<iostream>
#include<cmath>
#include<cstdlib>

using namespace std;

/*
DATA MEMBERS    : length,breadth,height : numeric
MEMBER FUNCTIONS: Constructors: box(), box(int), box(int,int,int)
                : store(),display(),checkbox(),volume()
                : operator+ ,operator= , operator==
*/ 
 class box
{
  int length;
  int breadth;
  int height;

  public:
  box();
  box(int);
  box(int, int, int);
  box(box&);
  void display();
  box& operator + (box);
  box& operator = (box&);
  friend bool operator == (box , box);
  void store();
  int volume();
  bool checkbox();
};

/*
FORMAL PARAMETER: NULL
PURPOSE: initialises data members with ZERO
*/

 box:: box()
{
  length  = 0;
  breadth = 0;
  height  = 0;
}


/*
FORMAL PARAMETER:  a: integer
PURPOSE: initialises data members with the value of ' a '
*/

 box:: box(int a)
{
  cout<<"\n(INSIDE CONSTRUCTOR WITH 1 PARAMETER)";
  length  = breadth = height  = a;
}


/*
FORMAL PARAMETER:  l,b,h : integer
PURPOSE: initialises corresponding data members with the values
         l, b, h
*/

  box:: box(int l, int b, int h)
{
  cout<<"\n(INSIDE CONSTRUCTOR WITH 3 PARAMETER)";
  length  = l;
  breadth = b;
  height  = h;
}

 
/*
FORMAL PARAMETER:  b : reference to an object of box
PURPOSE: copies values from the parameter to the calling object
*/

  box:: box( box &b)
{
  cout<<"\n(INSIDE COPY CONSTRUCTOR)";
  length = b.length;
  breadth = b.breadth;
  height = b.height;
}


/*
FORMAL PARAMETER:  b1 : reference to an object of box
PURPOSE: assigns values from the parameter to the calling object
RETURN: reference to the calling object
*/

 box& box:: operator = (box& b1)
{
  length = b1.length;
  breadth = b1.breadth;
  height = b1.height;
   
  return (*this);	
}
  

/*
FORMAL PARAMETER: NULL
PURPOSE: enters values in length,breadth,height
RETURN: void
*/

 void box:: store()
{  
   cout<<"\nEnter length : ";
   cin>>length;
   cout<<"Enter breadth: ";
   cin>>breadth;
   cout<<"Enter height : ";
   cin>>height;
   cout<<endl;
 
}
  

/*
FORMAL PARAMETER: NULL
PURPOSE: displays values of length,breadth,height
RETURN: void
*/

  void box:: display()
{
   cout<<"\nLength : ";
   cout<<length;
   cout<<"\nBreadth: ";
   cout<<breadth;
   cout<<"\nHeight : ";
   cout<<height<<endl;
}


/*
FORMAL PARAMETER: NULL
PURPOSE: calculates volume of a box
RETURN: volume of the box : integer
*/

 int box:: volume()
{
  return (length*breadth*height);
}


/*
FORMAL PARAMETER: NULL
PURPOSE: checks whether sides form a cube or cuboid
RETURN: true if sides form a cube
        false if sides form a cuboid
*/

 bool box:: checkbox()
{
  return(length==breadth && breadth== height);
}
  

/*
FORMAL PARAMETER:  b1 : box
PURPOSE: adds two boxes by adding corresponding data members
APPROACH: values are stored using a pointer to a dynamically created box
          and returning the pointer
RETURN: reference to an object of class box
*/

 box& box:: operator + (box b1)
{
  box* temp = new box;
  temp->length = length + b1.length;
  temp->breadth = breadth+ b1.breadth;
  temp->height  = height + b1.height;
   
  return *temp;
}

/*
FORMAL PARAMETER: b1,b2 : box
PURPOSE: checks whether two boxes are equal
RETURN: true if boxes are equal
        false if boxes are not equal
*/
 
  bool operator == (box b1, box b2)
{
  return(b1.length==b2.length && b1.breadth== b2.breadth && b1.height==b2.height);
}


/*
FORMAL PARAMETER: NULL
PURPOSE: calls all the constructors and creates objects
       : displays the objects
RETURN: void
*/

 void chkctor()
{
  int l,b,h;
  cout<<"Please enter a dimension to create a cube: ";
  cin>>l;
  
  box b1(l);
  cout<<"\nDisplaying the cube:";
  b1.display();
  
  cout<<"\nEnter 3 dimensions to create a cuboid: ";
  cin>>l>>b>>h;
  
  box b2(l,b,h);
  cout<<"\nDisplaying the cuboid:";
  b2.display();
 
  cout<<"\nNow copying the values of the cuboid to a new box: ";
  box b3 = b2;
  cout<<"\nDisplaying the copied cuboid:";
  b3.display();
  cout<<endl;
}


/*
INPUT PARAMETER: ch: integer
                opt: char                 
PURPOSE: calls functions as per requirement
*/
 
 int main()
{
   int ch,vol;
   char opt;
   box b1,b2,b3;

 do{
   cout<<"\n------------------------------------------------------------------------\n";
   cout<<"\nMENU\n";
   cout<<"0.View constructor calls\n";
   cout<<"1.Enter first box\n";
   cout<<"2.Enter second box\n";
   cout<<"3.Display both boxes\n";
   cout<<"4.Add the two boxes\n";
   cout<<"5.Check if the two boxes are equal\n";
   cout<<"6.Check if the boxes are cube or cuboid\n";
   cout<<"7.Calculate volume of the boxes\n";
   cout<<"8.Assign Box 1 to Box 2 (display using 3)\n";
   cout<<"9.Exit\n";
   cout<<"------------------------------------------------------------------------\n";
   cout<<"\nEnter your choice: ";
   cin>>ch;
   cout<<"\n------------------------------------------------------------------------\n";
   switch(ch)
   {
     case 0:
     chkctor();
     break;

     case 1:
     cout<<"\nBOX 1:";
     b1.store();
     break;

     case 2:
     cout<<"\nBOX 2:";
     b2.store();
     break;
 
     case 3:
     cout<<"\nBOX 1:";
     b1.display();
     cout<<"\nBOX 2:";
     b2.display();
     break;

     case 4:
     b3 = b1 + b2;
     cout<<"\nBOX 1 + BOX 2:";
     b3.display();
     break;

    case 5:
     if(b1==b2)
      cout<<"\nThe two boxes are equal\n";
     else 
      cout<<"\nThe two boxes are not equal\n";
    break;
 
    case 6:
    if(b1.checkbox())
    cout<<"\nBOX 1 is a cube\n";
    else
     cout<<"\nBOX 1 is a cuboid\n";

    if(b2.checkbox())
    cout<<"\nBOX 2 is a cube\n";
    else
     cout<<"\nBOX 2 is a cuboid\n";
    break;

    case 7:
    cout<<"\nVolume of:\n";
    vol = b1.volume();
    cout<<"BOX 1: "<<vol;
    vol = b2.volume();
    cout<<"\nBOX 2: "<<vol;
    break;

    case 8: 
    b2 = b1;
    cout<<"\nBox 1 has been assigned to Box 2\n";
    break; 

    case 9:   
    exit(0);
    break;

    default: cout<<"\Enter a valid choice!\n";

   }
   
   cout<<"\n------------------------------------------------------------------------\n";
   cout<<"Do you wish to continue?(Y/N): ";
  cin>>opt;

 }while(opt=='y'|| opt=='Y');

return 0;
}
   
   
 

