#include<iostream>
#include<cstdlib>

using namespace std;

/*
DATA MEMBERS    : feet,inch : numeric
MEMBER FUNCTIONS: Constructors: Length()
                : input(),display(),check()
                : operator+ ,operator-
*/ 

 class Length
{
  int feet;
  int inch;

  public:
  Length();
  void input();
  void display();
  void check();
  Length operator + (Length);
  Length operator - (Length);
};


/*
FORMAL PARAMETER: NULL
PURPOSE: initialises data members with ZERO
*/

 Length:: Length()
{
  feet = 0;
  inch = 0;
}

/*
FORMAL PARAMETER: NULL
PURPOSE: checks whether the values are valid
       : makes the class Length invariant
RETURN: void
*/

 void Length:: check()
{
  if(feet< 0 || inch < 0)
  {
    cout<<"\nVALUES INVALID!!\nTERMINATING!!";
    cout<<"\n------------------------------------------------------------------------\n";
    exit(100);
  }

  feet+= (inch/12); 
  inch = inch % 12;
 }


/*
FORMAL PARAMETER: NULL
PURPOSE: enters values in feet,inch
       : calls check() function
RETURN: void
*/

 void Length:: input()
{
  cout<<"\nEnter feet  : ";
  cin>>feet;
  cout<<"Enter inches: ";
  cin>>inch;

  check();
}


/*
FORMAL PARAMETER: NULL
PURPOSE: displays values of feet,inch
RETURN: void
*/

 void Length:: display()
{
  cout<<"\n"<<feet<<" feet  "<<inch<<" inches\n\n";
}


/*
FORMAL PARAMETER: l1: Length
PURPOSE: to add corresponding latitudes and longitudes of 2 objects
RETURN: temp: Length
*/

 Length Length:: operator + (Length l1)
{
  Length temp;
  temp.inch = inch + l1.inch + 12*(feet + l1.feet);
  temp.check();
  return temp;
}


/*
FORMAL PARAMETER: l1: Length
PURPOSE: to subtract corresponding latitudes and longitudes of 2 objects
RETURN: temp: Length
*/

 Length Length:: operator - (Length l1)
{
  Length temp;
  temp.inch = inch+ 12*feet - (l1.inch + 12*l1.feet);
  temp.check();
  return temp;
}


/*
INPUT PARAMETER: ch: integer
                opt: char                 
PURPOSE: calls functions as per requirement
*/
  
 int main()
{
   int ch;
   char opt;
   Length l1,l2,l3;

 do{
   cout<<"\n------------------------------------------------------------------------\n";
   cout<<"\nMENU\n";
   cout<<"1.Enter first length\n";
   cout<<"2.Enter second length\n";
   cout<<"3.Display both lengths\n";
   cout<<"4.Add the two lengths\n";
   cout<<"5.Subtract the two lengths\n";
   cout<<"6.Exit\n";
   cout<<"\n------------------------------------------------------------------------\n";
   cout<<"\nEnter your choice: ";
   cin>>ch;
   cout<<"\n------------------------------------------------------------------------\n";   

   switch(ch)
   {
     case 1:
     cout<<"\nLENGTH 1:";
     l1.input();
     break;

     case 2:
     cout<<"\nLENGTH 2:";
     l2.input();
     break;
 
     case 3:
     cout<<"\nLENGTH 1:";
     l1.display();
     cout<<"\nLENGTH 2:";
     l2.display();
     break;

     case 4:
     l3 = l1 + l2;
     cout<<"\nLENGTH 1 + LENGTH 2:";
     l3.display();
     break;

    case 5:
    l3 = l1 - l2;
    cout<<"\nLENGTH 1 - LENGTH 2:";
    l3.display();
    break;
 
    case 6:   
    cout<<"\nThanks for using the program!\n";
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
   
