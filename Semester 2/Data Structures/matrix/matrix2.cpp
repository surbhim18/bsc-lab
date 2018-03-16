#include<iostream>
#include<cstdlib>

using namespace std;

 
 class Matrix
{
  int **mat;
  int rows,cols;  

  public:
  Matrix() { }
  Matrix(const Matrix&);
  Matrix(int,int);
  Matrix& operator= (Matrix&);
  bool checkAdd(const Matrix&);
  bool checkMul(const Matrix&);
  void enter();
  void display();
  Matrix& operator+(const Matrix&);
  Matrix& operator*(const Matrix&); 
   ~Matrix();

};
  
  Matrix:: Matrix(const Matrix& M)
{
   rows = M.rows;
   cols = M.cols;
   int i,j;
    
   mat = new int*[rows];
   for(int i=0;i<rows;i++)
   mat[i] = new int[cols];

   for(i=0;i<rows;i++)
   {
     for(j=0;j<cols;j++)
      mat[i][j] = M.mat[i][j];
   }

}

  Matrix:: Matrix(int r,int c)
{
   rows = r;
   cols = c;
   int i,j;
    
   mat = new int*[rows];
   for(int i=0;i<rows;i++)
   mat[i] = new int[cols];

    for(i=0;i<rows;i++)
   {
     for(j=0;j<cols;j++)
      mat[i][j] = -1;
   }

 } 


 Matrix& Matrix:: operator= (Matrix& M)
{
   rows = M.rows;
   cols = M.cols;
   int i,j;

  for(i=0;i<rows;i++)
   {
     for(j=0;j<cols;j++)
      mat[i][j] = M.mat[i][j];
   }
 
  return(*this); 
}

   Matrix:: ~Matrix()
 {
    for(int i=0;i<rows;i++)
      delete []mat[i];

    delete []mat;
 } 

  void Matrix:: enter()
{
  int i,j;

   mat[i] = new int[cols];
  
  cout<<"Enter elements:\n";
  for(i=0;i<rows;i++)
   {
     for(j=0;j<cols;j++)
      cin>>mat[i][j];
   }

}
 
  void Matrix:: display()
{  
  int i,j;
  cout<<"\n";
  for(i=0;i<rows;i++)
   {
     for(j=0;j<cols;j++)
      cout<<mat[i][j]<<"  ";

     cout<<endl;
   }
} 
 

  bool Matrix:: checkAdd(const Matrix& b)
{
    return(rows==b.rows && cols==b.cols);
}


   bool Matrix:: checkMul(const Matrix& b)
{
    return(cols==b.rows);
}


   Matrix& Matrix:: operator+(const Matrix& b)
{
  
   Matrix* res;
   int i,j;

   res = new Matrix(rows,cols);
      for(i=0;i<rows;i++)
       {
         for(j=0;j<cols;j++)
           res->mat[i][j] = mat[i][j] + b.mat[i][j];
       }
     
 
   return (*res);
}

   
 Matrix& Matrix:: operator*(const Matrix& b)        
 {
  
   Matrix* res;
   int i,j,k;

   res = new Matrix(rows,b.cols);
      for(i=0;i<rows;i++)
       {
         for(j=0;j<b.cols;j++)
	 {
	   res->mat[i][j]=0;
	   for(k=0;k<cols;k++)
           res->mat[i][j] += (mat[i][k] * b.mat[k][j]);
	 }
       }
 
   return (*res);
}


  
   int main()
{
   int ch,m,n;
   char opt;
   Matrix *A,*B;

 do{
 
   cout<<"\n--------------------------------------------------------------------------\n";   
   cout<<"\nMatricies\n";
   cout<<"1.Enter first matrix\n";
   cout<<"2.Enter second matrix\n";
   cout<<"3.Display both matricies\n";
   cout<<"4.Add the matricies\n";
   cout<<"5.Multiply the matricies\n";
   cout<<"6.Exit\n";
   cout<<"\n--------------------------------------------------------------------------"; 
   cout<<"\nEnter choice: ";
   cin>>ch;
   cout<<"\n--------------------------------------------------------------------------"; 
   switch(ch)
   {
      case 1:
      {
	cout<<"\nEnter no. of rows: "; 
        cin>>m;
	cout<<"Enter no. of columns: ";
	cin>>n;
        cout<<"\nMatrix A:";
        A = new Matrix(m,n);
	A->enter();
      }
        break;
 
      case 2:
     {
	cout<<"\nEnter no. of rows: "; 
        cin>>m;
	cout<<"Enter no. of columns: ";
	cin>>n;
        cout<<"\nMatrix B:";
        B = new Matrix(m,n);
	B->enter();
      }
        break;
	
      case 3:
      {
        cout<<"\nMatrix1:";
        A->display();
        cout<<"\nMatrix2:";
        B->display();
      } 
      break;

      case 4:
      {
	if(!A->checkAdd(*B))
	{
	  cout<<"\nAddition not possible\n";
	  exit(0);
	}
	
	cout<<"\nA + B:\n";
	Matrix res= (*A)+(*B);
	res.display();
      }
      break;
	
      
     case 5:
      {
	if(!A->checkMul(*B))
	{
	  cout<<"\nMultiplication not possible\n";
	  exit(0);
	}
	
	cout<<"\nA X B:\n";
	Matrix res= A->operator*(*B);
	res.display();
      }
      break;
     

      case 6:
      exit(0);
   }
   
   cout<<"\n--------------------------------------------------------------------------"; 
   cout<<"\nDo you wish to continue: ";
   cin>>opt;
 
 }while(opt=='y'||opt=='Y');
  
  cout<<"\n--------------------------------------------------------------------------\n";
  
  
   delete A;
   delete B;
  
   return 0;
}  
 


   
     

  
