#include<fstream>
#include<iostream>
#include<cstring>

using namespace std;

int no; 

 class emp
{
 int eid;
 char name[20];
 int basic;
 int hra;
 int da;
 int extra;
 
 public:
 void enter();
 void print();
 
}e[10];

/*
 PURPOSE: enter the values of data members 
          for an object of the class
*/
 void emp:: enter()
{
  cout<<"\nEnter Eid        : ";
  cin>>eid;
  cout<<"Enter Name       : ";
  cin.ignore();
  cin.getline(name,20);
  cout<<"Enter basic      : ";
  cin>>basic;
  cout<<"Enter HRA        : ";
  cin>>hra;
  cout<<"Enter DA         : ";
  cin>>da;
  cout<<"Extra allowances : ";
  cin>>extra;
  cout<<"\n";
}

/*
 PURPOSE: prints the values of data members 
          for an object of the class
*/ 


 void emp:: print()
{
  cout<<"\nEid              : ";
  cout<<eid;
  cout<<"\nName             : ";
  cout.write(name,strlen(name));
  cout<<"\nBasic            : ";
  cout<<basic;
  cout<<"\nHRA              : ";
  cout<<hra;
  cout<<"\nDA               : ";
  cout<<da;
  cout<<"\nExtra allowances : ";
  cout<<extra;
  cout<<"\n\n";  
}

/*
 PURPOSE: calls enter() function 
        : writes records in files
*/   

 void fenter()
{
  ofstream fout;
  fout.open("A",ios::out| ios::binary);

  cout<<"\nEnter no. of records: ";
  cin>>no;

  for(int i=0;i<no;i++)
   {
     e[i].enter();
     fout.write((char*)&e[i],sizeof(e[i]));
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
  fin.open("A",ios::in| ios::binary);
   
 int i=0;
   while(fin)  
   {
     fin.read((char*)&e[i],sizeof(e[i]));
     if(fin)
     e[i].print();

     i++;
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
  cout<<"\nPrinting records of file...\n";
  fprint();\
}
