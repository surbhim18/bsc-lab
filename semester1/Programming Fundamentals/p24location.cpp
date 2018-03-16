#include<iostream>
#include<cstdlib>

using namespace std;

/*
DATA MEMBERS    : latitude, longitude : numeric
MEMBER FUNCTIONS: Constructors: Location()
                : store(),display()
                : operator+ ,operator++, operator--
*/ 
 class Location
{
  int latitude;
  int longitude;

  public:
  void store();
  void display();
  Location();
  friend Location operator + (Location,int);
  friend Location operator + (int,Location);
  Location operator ++();
  const Location operator ++(int);
  Location operator --();
  const Location operator --(int);
};


/*
FORMAL PARAMETER: NULL
PURPOSE: initialises data members with ZERO
*/

 Location:: Location()
{
  latitude = 0;
  longitude = 0;
}


/*
FORMAL PARAMETER: NULL
PURPOSE: enters values in latitude, longitude 
RETURN: void
*/

 void Location:: store()
{
  cout<<"\nEnter latitude : ";
  cin>>latitude;
  cout<<"Enter longitude: ";
  cin>>longitude;
}

 
/*
FORMAL PARAMETER: NULL
PURPOSE: displays values of latitude, longitude 
RETURN: void
*/ 

 void Location:: display()
{
  cout<<"\nLatitude : "<<latitude;
  cout<<"\nLongitude: "<<longitude<<endl;
} 


/*
FORMAL PARAMETER: L: location
                  a: integer
PURPOSE: adds the integer to latitude and longitude
RETURN: object of Location with the changed values
*/ 

  Location operator + (Location L,int a)
{
  Location temp;
  temp.latitude = L.latitude + a;
  temp.longitude = L.longitude + a;
  return temp;
}


/*
FORMAL PARAMETER: a: integer
                  L: location                 
PURPOSE: adds the integer to latitude and longitude
RETURN: object of Location with the changed values
*/ 

 Location operator + (int a,Location L)
{
  Location temp;
  temp.latitude = L.latitude + a;
  temp.longitude = L.longitude + a;
  return temp;
}


/*
FORMAL PARAMETER: NULL
PURPOSE: to pre-increment the values of the calling object
RETURN: reference to the calling object
*/

  Location Location:: operator ++()
{
  longitude++;
  latitude++;
  return (*this);
}


/*
FORMAL PARAMETER: NULL
PURPOSE: to pre-decrement the values of the calling object
RETURN: reference to the calling object
*/

  Location Location:: operator --()
{
  longitude--;
  latitude--;
  return (*this);
}


/*
FORMAL PARAMETER: int (CONVENTION)
PURPOSE: to post-increment the values of the calling object
APPROACH: original object copied and returned
        : values of calling object incremented
RETURN: saved object: Location 
*/

  const Location Location:: operator ++ (int)
{
  const Location saveobj(*this);
  latitude++;
  longitude++;
  return saveobj;
}


/*
FORMAL PARAMETER: int (CONVENTION)
PURPOSE: to post-decrement the values of the calling object
APPROACH: original object copied and returned
        : values of calling object decremented
RETURN: saved object: Location 
*/

  const Location Location:: operator -- (int)
{
  const Location saveobj(*this);
  latitude--;
  longitude--;
  return saveobj;
}


/*
INPUT PARAMETER: ch: integer
                opt: char                 
PURPOSE: calls functions as per requirement
*/

int main()
{

   int ch,i;
   char opt;
   Location l1,l2;

 do{
   cout<<"\n------------------------------------------------------------------------\n";
   cout<<"\n MENU\n";
   cout<<"1. Enter first location L1\n";
   cout<<"2. Display L1\n";
   cout<<"3. Display L2\n";
   cout<<"4. L1 = L1 + integer\n";
   cout<<"5. L1 = integer + L1\n";
   cout<<"6. L2 = L1++\n";
   cout<<"7. L2 = ++L1\n";
   cout<<"8. L2 = L1--\n";
   cout<<"9. L2 = --L1\n";
   cout<<"10.Exit\n";
   cout<<"------------------------------------------------------------------------\n";
   cout<<"\nEnter your choice: ";
   cin>>ch;
   cout<<"\n------------------------------------------------------------------------\n";

   switch(ch)
   {
     case 1:
     cout<<"\nL1:";
     l1.store();
     break;

     case 2:
     cout<<"\nL1:";
     l1.display();
     break;

     case 3:
     cout<<"\nL2:";
     l2.display();
     break;
   
     case 4:
     cout<<"\nEnter an integer: ";
     cin>>i;
     cout<<"L1 = L1 + "<<i<<"\n";
     l1 = l1 + i;
     break;

     case 5:
     cout<<"\nEnter an integer: ";
     cin>>i;
     cout<<"L1 = "<<i<<"+ L1\n";
     l1 = i + l1;
     break;

     case 6:
     cout<<"L2 = L1++\n";
     l2 = l1++;
     break;

     case 7:
     cout<<"L2 = ++L1\n";
     l2 = ++l1;
     break;

     case 8:
     cout<<"L2 = L1--\n";
     l2 = l1--;
     break;
 
     case 9:
     cout<<"L2 = --L1\n";
     l2 = --l1;
     break; 

     case 10:   
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


