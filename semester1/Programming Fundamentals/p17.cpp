#include<fstream>
#include<iostream>
#include<cstring>

using namespace std;

ifstream fin;
ofstream fout;

/*
RETURN VALUE: void
PURPOSE: enters text in a file "c.txt"
*/

 void enter()
{
  fout.open("c.txt");
  char str[100];  

  cout<<"\nEnter text in your text file:\n";
  cin.getline(str,100);
  fout.write(str,strlen(str));

  fout.close();
}

/*
RETURN VALUE: void
PURPOSE: copies content from file "c.txt" to "d.txt" removing white spaces
*/


 void copy()
 {
   char word[20];
   fin.open("c.txt");
   fout.open("d.txt");

   while(fin)
  {
     fin>>word;
   
     fout.write(word,strlen(word));
    
  }

  fout.close();
  fin.close();
}

/*
RETURN VALUE: void
PURPOSE: prints text in the file "d.txt"
*/

  void print()
{
  fin.open("c.txt");
  char ch; 
 
  cout<<"\nThe contents of file 2 (with spaces removed):\n";

  while(fin)
  {
    fin>>ch;
    if(fin)
    cout<<ch;
  }
  cout<<"\n\n";
  fin.close();
 }

/*
PURPOSE: calls the functions: enter()
                            : copy()
                            : print()  

*/
 int main()
{
  enter();
  copy();
  print();
 }	
