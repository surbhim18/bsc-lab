#include<iostream>
#include<stdlib.h>

using namespace std;

int main()
{
	int choice;
	char ch;
	
	do
	{	
		cout<<"\t\tMenu\t\t\n";
		cout<<"1. Cpu version\n2. Cpu info\n3. Memory info\n4. Exit\n";
		cin>>choice;
		
		switch(choice)
		{ 	
	
		case 1:	system("awk '{print $1 $2 $3}' /proc/version");
			break;
	
		case 2: system("awk NR==4,NR==5'{print $0}' /proc/cpuinfo");
			break;
		
		case 3:	system("awk NR==2,NR==4'{print $0}' /proc/meminfo");
			break;

		case 4: exit(0);
			break;

		}
	
	cout<<"Do You Want to see more (Y or y for Yes) \n";
	cin>>ch;

	}while(ch=='Y'||ch=='y');

			
	return 0;
}
