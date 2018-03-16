#include<iostream>
#include<cstdlib>
#include<cstring>

using namespace std;

/*
DATA MEMBERS    : name,addr: char[]
                : age      : integer
MEMBER FUNCTIONS: store(),display(), ~Person()
*/ 

 class Person
{
  protected:
  char name[25];
  int age;
  char addr[75];

  public:
  virtual ~Person()
  {
    cout<<"(DESTRUCTOR OF Person CALLED)\n";
  }
  virtual void store();
  virtual void display() const;
};


/*
FORMAL PARAMETER: NULL
PURPOSE: enters values in name,age,addr
RETURN: void
*/

 void Person:: store()
{
  cout<<"(INSIDE THE STORE FUNCTION OF PERSON)\n";
  cout<<"\nEnter name       : ";
  cin.ignore();
  cin.getline(name,25);
  cout<<"Enter age        : ";
  cin>>age;
  cout<<"Enter address    : ";
  cin.ignore();
  cin.getline(addr,75);
}


/*
FORMAL PARAMETER: NULL
PURPOSE: displays values of name,age,addr
RETURN: void
*/

 void Person:: display() const
{ 
  cout<<"(INSIDE THE PRINT FUNCTION OF PERSON)\n"; 
  cout<<"\nName   : ";
  cout.write(name,strlen(name));
  cout<<"\nAge    : ";
  cout<<age;
  cout<<"\nAddress: ";
  cout.write(addr,strlen(addr));
  cout<<endl;
}


/*
DATA MEMBERS    : empid      : integer
MEMBER FUNCTIONS: store(),display(), ~Teacher()
*/ 

 class Teacher : public Person
{
  protected:
  int empid;

  public:
  ~Teacher()
  {
    cout<<"\n(DESTRUCTOR OF Teacher CALLED)\n";
  }
  virtual void store();
  virtual void display() const;
};


/*
FORMAL PARAMETER: NULL
PURPOSE:calls store() function of base class Person 
       :enters value in empid
RETURN: void
*/

  void Teacher:: store()
{
  cout<<"\n(INSIDE THE STORE FUNCTION OF TEACHER)\n";
  Person:: store();
  cout<<"Enter employee ID: ";
  cin>>empid;
}


/*
FORMAL PARAMETER: NULL
PURPOSE:calls display() function of base class Person 
       :displays value of empid
RETURN: void
*/

  void Teacher:: display() const
{
  cout<<"\n(INSIDE THE PRINT FUNCTION OF TEACHER)\n"; 
  Person:: display();
  cout<<"EmpID  : ";
  cout<<empid<<endl;
}
       

/*
DATA MEMBERS    : rno      : integer
MEMBER FUNCTIONS: store(),display(), ~Student()
*/ 

 class Student : public Person
{
  protected:
  int rno;

  public:
  ~Student()
  {
    cout<<"\n(DESTRUCTOR OF Student CALLED)\n";
  }
  virtual void store();
  virtual void display() const;
};


/*
FORMAL PARAMETER: NULL
PURPOSE:calls store() function of base class Person 
       :enters value in rno
RETURN: void
*/

  void Student:: store()
{
  cout<<"\n(INSIDE THE STORE FUNCTION OF STUDENT)\n";
  Person:: store();
  cout<<"Enter roll no.   : ";
  cin>>rno;
}


/*
FORMAL PARAMETER: NULL
PURPOSE:calls display() function of base class Person 
       :displays value of rno
RETURN: void
*/

  void Student:: display() const
{ 
  cout<<"\n(INSIDE THE PRINT FUNCTION OF STUDENT)\n"; 
  Person:: display();
  cout<<"RollNo : ";
  cout<<rno<<endl;
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
   Person* objptr;
   cout<<"\n------------------------------------------------------------------------\n";
   cout<<"\nA POINTER POINTING TO AN OBJECT OF CLASS Person CREATED\n";

 do{
   cout<<"\n------------------------------------------------------------------------\n";
   cout<<"\nMENU\n";
   cout<<"Enter and display an object of class\n";
   cout<<"1.Person\n";
   cout<<"2.Teacher\n";
   cout<<"3.Student\n";
   cout<<"4.Exit\n";
   cout<<"------------------------------------------------------------------------\n";
   cout<<"\nEnter your choice: ";
   cin>>ch;
   cout<<"------------------------------------------------------------------------\n";
   switch(ch)
   {
     case 1:
     objptr = new Person;
     cout<<"\nTHE POINTER ASSOCIATED WITH OBJECT OF Person\n";
     cout<<"\nEnter data for PERSON:\n";
     objptr->store(); 
     cout<<"\nPerson:\n";
     objptr->display();
     cout<<"\n";
     delete objptr;
     break;

     case 2:
     objptr = new Teacher;
     cout<<"\nTHE POINTER ASSOCIATED WITH OBJECT OF Teacher\n";
     cout<<"\nEnter data for TEACHER:";
     objptr->store(); 
     cout<<"\nTeacher:";
     objptr->display();
     delete objptr;
     break;
 
     case 3:
     objptr = new Student;
     cout<<"\nTHE POINTER ASSOCIATED WITH OBJECT OF Student\n";
     cout<<"\nEnter data for STUDENT:";
     objptr->store(); 
     cout<<"\nStudent:";
     objptr->display();
     delete objptr;
     break;

    case 4:   
    exit(0);
    break;

    default: cout<<"\Enter a valid choice!\n";

   }

   cout<<"\n------------------------------------------------------------------------\n";
   cout<<"Do you wish to continue?(Y/N): ";
  cin>>opt;
   
 }while(opt=='y'|| opt=='Y');

 cout<<"\n-------------------------------------------------------\n\n";
return 0;

}







