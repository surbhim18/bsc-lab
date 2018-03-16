#include<cstdlib>
#include<iostream>
#include<cstring>

using namespace std;

 class convert
{
  protected:
  double val1;
  double val2;
  
  public:
  void store()
  {
    cin>>val1;
  }
  double getval() { return val1; }
  double getconv() { return val2; }
  virtual void calc() = 0;
};


  class litre_gallon : public convert
{
  public:
  void calc()
  {
    val2 = (1/3.7854)*val1;
   }
};


   class fah_celsius : public convert
{
  public:
  void calc()
  {
    val2 = (5/9.0)*(val1-32);
   }
};


int main()
{

   int ch,i;
   double val1,val2;
   char opt;
   convert* c1;

 do{
   cout<<"\n------------------------------------------------------------------------\n";
   cout<<"\n MENU\n";
   cout<<"1. Convert litres to gallons\n";
   cout<<"2. Convert faherneit to celsius\n";
   cout<<"3.Exit\n";
   cout<<"------------------------------------------------------------------------\n";
   cout<<"\nEnter your choice: ";
   cin>>ch;
   cout<<"\n------------------------------------------------------------------------\n";

   switch(ch)
   {
     case 1:
     c1 = new litre_gallon;
     cout<<"\nEnter value in litres: ";
     c1->store();
     c1->calc();
     val1 = c1->getval();
     val2 = c1->getconv();
     cout<<endl<<val1<<" liters = "<<val2<<" gallon\n"; 
     delete c1;
     break;

     case 2:
     c1 = new fah_celsius;
     cout<<"\nEnter value in faherneit: ";
     c1->store();
     c1->calc();
     val1 = c1->getval();
     val2 = c1->getconv();
     cout<<endl<<val1<<" faherneit  = "<<val2<<" celsius\n"; 
     delete c1;
     break;


     case 3:   
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
