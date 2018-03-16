#include<iostream>
#include<cstring>
#include<cstdlib>

using namespace std;

 int n;

 struct employee
{
  int eno;
  char name[20];
  int age;
  char addr[40];

}emp[10];

 void enter(int i,int mod=0)
{ 
 if(mod==0)
  {
  cout<<"\nEnter Eno    : ";
  cin>>emp[i].eno;
  }
  cout<<"Enter name   : "; 
  cin.ignore();
  cin.getline(emp[i].name,20);
  cout<<"Enter age    : ";
  cin>>emp[i].age;
  cout<<"Enter address: ";
  cin.ignore();
  cin.getline(emp[i].addr,40);

}


 void print1(int i)
{
   cout<<"\nEno    : ";
   cout<<emp[i].eno;
   cout<<"\nName   : ";	
   cout.write(emp[i].name,strlen(emp[i].name));
   cout<<"\nAge    : ";
   cout<<emp[i].age;
   cout<<"\nAddress: ";
   cout.write(emp[i].addr,strlen(emp[i].addr));
   cout<<"\n\n";
 
}

 void print()
{
  for(int i=0;i<n;i++)
   print1(i);
}

	
 int search(int seno)
{
  int i;	
  for(i=0;i<n;i++)
  {
     if(emp[i].eno==seno)
      return i;
  }
  
  return -1;

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
  enter(found,1);
  
  cout<<"\nYour record is successfully modified!";

  cout<<"\n\nPrinting all records...\n";
  print();
 }

}

 void remove()
{
  int no,i,found;
  employee temp;

  cout<<"\nEnter the record u wish to delete: ";
  cin>>no;
 
 found= search(no);

  if(found==-1)
   cout<<"\nNo such record exists!!!!";
 else
  {
     for(i=found; i<n-1;i++)
      emp[i]=emp[i+1];

    n--;
  
   cout<<"\nRecord successfully deleted!\n";
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
   enter(i);

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
   enter(n);
   n++;
   break;

   case 2:
   cout<<"\nEnter Eno to be searched: ";
   cin>>no;  

   found= search(no);
   if(found==-1)
   cout<<"\nSorry..your record was not found..\n";
   else
   {
     cout<<"Record found!\n";
     print1(found);
   }
   
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
