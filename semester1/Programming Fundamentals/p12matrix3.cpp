#include<iostream>
#include<cstdlib>

using namespace std;

 class matrix
{
  int a[10][10];
  int m,n;
  int adcheck(matrix);
  int mulcheck(matrix);

  public:
  matrix();
  matrix(int,int);
  matrix add(matrix);
  matrix subtract(matrix);
  matrix multi(matrix);
  matrix trans();
  void print();
  void enter();
}a,b,c;                     

  matrix :: matrix()
 {
   m=0;
   n=0;
 }

  matrix :: matrix(int r, int c)
  {
     m=r;
     n=c;
  }


//Matrix is entered
  void matrix:: enter()
  {
    int i,j;
  
    cout<<"Enter dimensions:\n";
    cin>>m>>n;
 
    cout<<"Enter matrix:\n";
 
    for(i=0;i<m;i++)
    {
      for(j=0;j<n;j++)
       cin>>a[i][j];
    }
  }


//Matrix is printed
   void matrix:: print()
{
  int i,j;
  
  
  for(i=0;i<m;i++)
  {
    for(j=0;j<n;j++)
     cout<<a[i][j]<<"   ";

   cout<<"\n";
  }
}


/*
FORMAL PARAMETER: object of class matrix
PURPOSE: check whether matricies can be added
RETURN: 1 if matricies can be added
        0 if cannot be added
*/

  int matrix:: adcheck(matrix b)
  {
    if(m==b.m && n==b.n)
    return 1;
    else
    return 0;
     
  }


/*
FORMAL PARAMETER: object of class matrix
PURPOSE: check whether matricies can be multiplied
RETURN: 1 if matricies can be multiplied
        0 if cannot be multiplied
*/
   int matrix:: mulcheck(matrix b)
  {
    
   if(n==b.m)
   return 1;
   else
   return 0;
 
  }


/*
FORMAL PARAMETER: object of class matrix
PURPOSE: adds two matricies
RETURN: resultant addition matrix
*/
   matrix matrix:: add(matrix b)
  {  
     int ch,i,j;

    
    ch=adcheck(b);          //checks whether matricies can be added


    if(ch==1)
   {
     for(i=0;i<m;i++)
      {
       for(j=0;j<n;j++)
        c.a[i][j]=a[i][j]+b.a[i][j];
       }
    cout<<"\nA+B\n";
    
    c.m=m;
    c.n=n;

   return c;
 
  }
    else
    { 
       cout<<"\nAddition not possible!!\n";
       exit(0);
    }
 } 


/*
FORMAL PARAMETER: object of class matrix
PURPOSE: subtracts two matricies
RETURN: resultant subtraction matrix
*/  
  matrix matrix:: subtract(matrix b)
{  
    int ch,i,j;

    
    ch=adcheck(b);       //checks whether matricies can be subtracted

    if(ch==1)
   {
     for(i=0;i<m;i++)
      {
       for(j=0;j<n;j++)
        c.a[i][j]=a[i][j]-b.a[i][j];
      }
     cout<<"\nA-B\n";
     c.m=m;
    c.n=n;

   return c;
 
  }

    else
   {
     cout<<"\nSubtraction not possible!!\n";
     exit(0);
   }
    
 } 


/*
FORMAL PARAMETER: object of class matrix
PURPOSE: multiplies two matricies
RETURN: resultant multiplication matrix
*/
   matrix matrix:: multi(matrix b)
{  

   int i,j,k,check;

   check= mulcheck(b);       //checks whether matricies can be multiplied

  if(check==1)
 {
   
   for(i=0;i<m;i++)
    {
     for(j=0;j<b.n;j++)
     {
       c.a[i][j]=0;
       for(k=0;k<n;k++)
        c.a[i][j]+=a[i][k]*b.a[k][j];
     }
    }
   cout<<"\nA X B\n";
   
    c.m=m;
    c.n=b.n;

   return c;
    
 }
 else
  {
   cout<<"Matrix multiplication not possible!\n";
   exit(0);
  }
 
}

/*
INPUT PARAMETER: NULL
PURPOSE: calculates transpose of matrix
RETURN: transposed matrix
*/
  matrix matrix:: trans()
 {
  int i,j;
  
  cout<<"\nYour matrix\n";
 
   
 for(i=0;i<m;i++)
  {
    for(j=0;j<n;j++)
     c.a[j][i]=a[i][j];
  }
  
  cout<<"\nTransposed matrix\n";
  c.m=n;
  c.n=m;
  

 return c;
}


/*
INPUT PARAMETER: ch: integer
PURPOSE: calls functions as per requirement
*/

  int main()
{
  int ch;
  char cont;
  matrix res;

do{  
  cout<<"\nMatricies\n";
  cout<<"1.Enter first matrix\n";
  cout<<"2.Enter second matrix\n";
  cout<<"3.Display both matricies\n";
  cout<<"4.Add the matricies\n";
  cout<<"5.Subtract the matricies\n";
  cout<<"6.Multiply the matricies\n";
  cout<<"7.Transpose first matrix\n";
  cout<<"8.Transpose second matrix\n";
  cout<<"9.Exit\n";
 
  cout<<"\nEnter ur choice: ";
  cin>>ch;
  
   switch(ch)
 {

  case 1:
    cout<<"\nA\n";
    a.enter();
    break;
  
 case 2:
    cout<<"\nB\n";
    b.enter();
    break;
   
 case 3:
    cout<<"\nA:\n";
    a.print();
    cout<<"\nB:\n";
    b.print();
    break;
 
 case 4:
   
   res=a.add(b);                      //object of matrix type returned
   res.print();
   break;
 
 case 5:
  
   res=a.subtract(b);                //object of matrix type returned
   res.print();
   break;

 case 6:

   res= a.multi(b);                   //object of matrix type returned
   res.print();
   break;

 case 7:
  
    res= a.trans();                  //object of matrix type returned
    res.print();
    break;

 case 8:
 
    res= b.trans();                  //object of matrix type returned
    res.print();
    break;
 

 default: cout<<"Enter a valid choice!!\n";

 } 

 cout<<"\nDo you wish to continue?(Y/N): ";
 cin>>cont;

}while(cont=='y'|| cont=='Y');         // works again if user enters y/Y
 return 0;
}
