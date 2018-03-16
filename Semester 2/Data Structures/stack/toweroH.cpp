#include<iostream>
using namespace std;

void send(char from, char via, char to, int disks)
{
  if(disks==1)
    cout<<"\nDisk "<<disks<<" from "<<from<<" to "<<to;
  
  else
  {
    send(from,to,via,disks-1);
    cout<<"\nDisk "<<disks<<" from "<<from<<" to "<<to;
    send(via,from,to,disks-1);
  }
}

 int main()
 {
   int n;
   cout<<"\n--------------------------------------------------------------------------";
   cout<<"\nA: source   B: intermediate    C: destination";
   cout<<"\n--------------------------------------------------------------------------";
   cout<<"\nEnter no of disks: ";
   cin>>n;
   cout<<"--------------------------------------------------------------------------";
   cout<<"\nSteps:";
   cout<<"\n--------------------------------------------------------------------------";
   send('A','B','C',n);
   cout<<"\n--------------------------------------------------------------------------\n";
   
   return 0;
 }
   