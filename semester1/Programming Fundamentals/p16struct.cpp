#include<fstream>
#include<iostream>
#include<cstring>
using namespace std;

struct student
{
  int rollno;
  char name[25];
  int clas;
  int yr;
  int totalm;
}s;


/*
 PURPOSE: enter the values of data members 
          for an object of the structure student
*/

 void enter()
{
  cout<<"\nEnter roll.no.   : ";
  cin>>s.rollno;
  cout<<"Enter name       : ";
  cin.ignore();
  cin.getline(s.name,25);
  cout<<"Enter class      : ";
  cin>>s.clas;
  cout<<"Enter year       : ";
  cin>>s.yr;
  cout<<"Enter total marks: ";
  cin>>s.totalm;
  cout<<"\n";
}


/*
 PURPOSE: prints the values of data members 
          for the object of the structure
*/ 

 void print()
{ 
  cout<<"\nRoll.no.   : ";
  cout<<s.rollno;
  cout<<"\nName       : ";
  cout.write(s.name,25);
  cout<<"\nClass      : ";
  cout<<s.clas;
  cout<<"\nYear       : ";
  cout<<s.yr;
  cout<<"\nTotal marks: ";
  cout<<s.totalm;
  cout<<"\n";
}		


/*
 PURPOSE: calls enter() function 
        : writes records in files
*/   

 void fenter()
{
  int n;
  ofstream fout;

  fout.open("B",ios::out| ios::binary);
 
  cout<<"\nEnter no of records: ";
  cin>>n;

  for(int i=0;i<n;i++)
  {
    enter();
    fout.write((char*)&s,sizeof(s));
  }

  fout.close();
}


/*
 PURPOSE: reads records from file
        : calls print() function
*/

 void fprint()
{
  ifstream fin;
  
  fin.open("B",ios::in | ios::binary);

  while(fin)
 {
   fin.read((char*)&s,sizeof(s));
    if(fin)
    print();
 }

  fin.close();
}



/*
 PURPOSE: calls functions to write into file
                             read from file
*/    
  
  int main()
{
   fenter();
   cout<<"\nPrinting all records....";
   fprint();

} 	
