#include<iostream>
#include<cstring>
#include<cstdlib>

using namespace std;

 int n;

 class employee
{
  int eno;
  char name[20];
  int age;
  char addr[40];

  public:
  void enter(int);
  void cprint();
  int reno()
  {
    return eno;
  }
}e[10];

  void employee:: enter(int chk=0)
{ 
 if(chk==0)
  {
  cout<<"\nEnter Eno    : ";
  cin>>eno;
  }
  cout<<"Enter name   : "; 
  cin.ignore();
  cin.getline(name,20);
  cout<<"Enter age    : ";
  cin>>age;
  cout<<"Enter address: ";
  cin.ignore();
  cin.getline(addr,40);

}


 void employee:: cprint()
{ 
   cout<<"\nEno    : ";
   cout<<eno;
   cout<<"\nName   : ";	
   cout.write(name,strlen(name));
   cout<<"\nAge    : ";
   cout<<age;
   cout<<"\nAddress: ";
   cout.write(addr,strlen(addr));
   cout<<"\n\n";

}
 
 void print()
{
  int i;
  for(i=0;i<n;i++)
   e[i].cprint();
}
  



 int search(int seno)
{
   int i;	
  for(i=0;i<n;i++)
  {
     if(e[i].reno()==seno)
      return i;
  }
  
  return -1;
}


 void find()
{
   int no,found;

   cout<<"\nEnter Eno to be searched: ";
   cin>>no;  

   found= search(no);
   if(found==-1)
   cout<<"\nSorry..your record was not found..\n";
   else
   {
     cout<<"Record found!\n";
     e[found].cprint();
   } 
}

 void remove()
{
   int no,i,found;
 
  cout<<"\nEnter the record u wish to delete: ";
  cin>>no;
 
 found= search(no);

  if(found==-1)
   cout<<"\nNo such record exists!!!!";
 else
  {
     for(i=found; i<n-1;i++)
      e[i]=e[i+1];

    n--;
  
   cout<<"\nRecord successfully deleted!\n";
   cout<<"\n\nPrinting all records...\n";
   print();
  }

}
 
 void modify()
{
  int no,found;
  cout<<"\nEnter Eno to be modified: ";
  cin>>no;

  found= search(no);

  if(found==-1)
   cout<<"\nNo such record exists!!!!";
  else
  { 
   cout<<"\nPlease modifify your record: \n"; 
    e[found].enter(1);
  
  cout<<"\nYour record is successfully modified!";

  cout<<"\n\nPrinting all records...\n";
  print();
 }
} 



   int main()
{
   int i,ch,no,found;
   char opt;
   

   cout<<"\nEnter no of records: ";
   cin>>n;

  for(i=0;i<n;i++)
   e[i].enter();

do{
 
 cout<<"\nMENU\n";
 cout<<"1.ENTER NEW RECORD\n";
 cout<<"2.SEARCH A RECORD using eno\n";
 cout<<"3.MODIFY A RECORD\n"; 
 cout<<"4.DELETE AN EXISTING RECORD\n";
 cout<<"5.DISPLAY ALL RECORDS\n";
 cout<<"6.EXIT\n";

 cout<<"\nEnter ur choice: ";
 cin>>ch; 
 
 switch(ch)
 {
   case 1: 
   e[n].enter();
   n++;
   break;

   case 2:
   find();   
   break;

  case 3:
  modify();
  break;

  case 4:  
  remove();
  break;

  case 5:
   print();
  break;

  case 6:
  exit(0);
  break;

  default: cout<<"\nPlease enter a valid choice!\n";
  }

   cout<<"\nDo you wish to continue?(Y/N): ";
   cin>>opt; 
 
 }while(opt=='y'|| opt=='Y');
  
}

