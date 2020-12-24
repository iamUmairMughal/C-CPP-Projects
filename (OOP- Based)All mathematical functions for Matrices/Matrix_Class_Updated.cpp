#include <iostream>
using namespace std;

class Matrix
{

//Data Members
	int row;
	int col;
	int** ptr;


public:		//Member Functions
	//Constructor
	Matrix();
	Matrix(int row, int col);
	
	//Copy Constructor
	Matrix(Matrix& obj);
	
	// Setters&Getters 
	void setrow(int row);
	int getrow();
	void setcol(int col);
	int getcol();
	
	int get(int i, int j);
	void set(int i, int j, int val);


	//Methods
	bool isSquare();
	bool isIdentity();
	bool isDiagonal();
	bool isNullMatrix();
	bool isUpperTriangular();
	bool isLowerTriangular();
	
//	Transpose of Matrix
//	Matrix* Transpose();
	void Transpose();
	
//	Equal Matrix
	bool isEqual(Matrix &mat);
	
//	Addition of Matrix
//	Matrix addition(Matrix &mat);
	void addition(Matrix &mat);
	
//	Subtraction of Matrix
//	Matrix subtraction(Matrix &mat);
	void subtraction(Matrix &mat);
	
//	Muptiplication of Matrix
//	Matrix multiplication(Matrix &mat);
	void multiplication(Matrix &mat);
	
	void inputMatrix();
	void outputMatrix();
	//Destructors
	~Matrix();
};

Matrix:: Matrix()
	{
		row = 0;
		col = 0;
		ptr = new int* [row];
		for(int i=0; i<row;i++)
		{
			this->ptr[i]=new int [col];
		}
		cout << "Default Constructor/Non-Parameterized " << endl;
	}
Matrix:: Matrix(int row, int col)
	{
		this->row = row;
		this->col = col;
		ptr = new int* [row];
		for(int i=0; i<row;i++)
		{
			this->ptr[i]=new int [col];
		}
		cout << "Parametrized Constructor" << endl;
	}
	

Matrix:: Matrix(Matrix& obj)
	{
		this->row = obj.row;
		this->col = obj.col;
		this->ptr=obj.ptr;
		cout << "Copy Constructor"<< endl;
	}


Matrix:: ~Matrix()
	{
		delete[] ptr;
//		for(int i=0; i<row;i++)
//		{
//			delete[] ptr[i];
//		}
		cout << "Destructor" << endl;
	}
	
void Matrix::setrow(int row)
{
	this->row=row;
}

int Matrix::getrow()
{
	return row;
}

void Matrix::setcol(int col)
{
	this->col=col;
}

int Matrix::getcol()
{
	return col;
}

int Matrix::get(int i, int j)
	{
		return ptr[i][j];
	}
void Matrix::set(int i, int j, int val)
	{
		ptr[i][j] = val;
	}
	
	
void Matrix::inputMatrix()
{	
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			int val;
			cout<<"Enter Value at ["<<i<<"]["<<j<<"]: ";
			cin>>val;
			set(i,j,val);
		}
	}
}

void Matrix:: outputMatrix()
{
	cout<<"Output: "<<endl;
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			cout<<get(i,j)<<" ";
		}
		cout<<endl;
	}
}

bool Matrix:: isSquare()
{
	if(row==col)
		return true;
	else
		return false;
		
}

//Function for Identity Matrix

bool Matrix::isIdentity()
{
	int ones_count=0;
	int zeros_count=0;
	
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			if(i==j)
			{
				int temp=get(i,j);
				if(temp==1)
				{
					ones_count++;
				}
			}
			else
			{
				int temp=get(i,j);
				if(temp==0)
				{
					zeros_count++;
				}
			}
		}
	}
	
	if(ones_count==row&&zeros_count==((row*col)-row))
	{
		return true;
	}
	else
	{
		return false;
	}
}


//Function For Diagonal Matrix

bool Matrix::isDiagonal()
{
	int diagonal_count=0;
	int zeros_count=0;
	
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			if(i==j)
			{
				int temp=get(i,j);
				if(!(temp==0))
				{
					diagonal_count++;
				}
			}
			else
			{
				int temp=get(i,j);
				if(temp==0)
				{
					zeros_count++;
				}
			}
		}
	}
	
	if(diagonal_count<=row&&zeros_count==((row*col)-row))
	{
		return true;
	}
	else
	{
		return false;
	}
}

//Function For NUll Matrix

bool Matrix::isNullMatrix()
{

	int zeros_count=0;
	
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			int temp=get(i,j);
			if(temp==0)
			{
				zeros_count++;
			}
		}
	}
	
	if(zeros_count==(row*col))
	{
		return true;
	}
	else
	{
		return false;
	}
}


//Function for UpperTriangle

bool Matrix::isUpperTriangular()
{
	int diagonal_count=0;
	int zeros_count=0;
	
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<=i;j++)
		{
			if(i==j)
			{
				int temp=get(i,j);
				if(!(temp==0))
				{
					diagonal_count++;
				}
			}
			else
			{
				int temp=get(i,j);
				if(temp==0)
				{
					zeros_count++;
				}
			}
		}
	}
	
	int l_zeros=((row*col)-row)/2;
	if(diagonal_count<=row&&zeros_count==l_zeros)
	{
		return true;
	}
	else
	{
		return false;
	}
}


//Function for LowerTriangle

bool Matrix::isLowerTriangular()
{
	int diagonal_count=0;
	int zeros_count=0;
	
	for(int i=0;i<row;i++)
	{
		for(int j=i;j<col;j++)
		{
			if(i==j)
			{
				int temp=get(i,j);
				if(!(temp==0))
				{
					diagonal_count++;
				}
			}
			else
			{
				int temp=get(i,j);
				if(temp==0)
				{
					zeros_count++;
				}
			}
		}
	}
	int u_zeros=((row*col)-row)/2;
	if(diagonal_count<=row&&zeros_count==u_zeros)
	{
		return true;
	}
	else
	{
		return false;
	}
}


//Function for Transpose
//Matrix* Matrix::Transpose()
//{
//	Matrix T(col,row);
//	
//	for(int i=0;i<row;i++)
//	{
//		for(int j=0;j<col;j++)
//		{
//			int temp=get(i,j);
//			T.set(j,i,temp);
//		}	
//	}
//	
//	return &T;
//	
//}

void Matrix::Transpose()
{
	Matrix T(col,row);
	
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			int temp=get(i,j);
			T.set(j,i,temp);
		}	
	}
	
	T.outputMatrix();
	
}


//Function For Equal Matrix

bool Matrix::isEqual(Matrix &mat)
{
	int matched_counts=0;
	
	if(row==mat.row && col==mat.col)
	{
		for(int i=0;i<row;i++)
		{
			for(int j=0;j<col;j++)
			{
				if(get(i,j)==mat.get(i,j))
				{
					matched_counts++;				
				}
			}
		}
		
		if(matched_counts==(row*col))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}


//Function for Addition of Matrix

void Matrix::addition(Matrix &mat)
{
	Matrix Result(row,col);
	
		for(int i=0;i<row;i++)
		{
			for(int j=0;j<col;j++)
			{
				Result.set(i,j,(get(i,j)+mat.get(i,j)));
			}
		}
		
		Result.outputMatrix();
//		return Result;
}


//Function for Subtraction of Matrix

void Matrix::subtraction(Matrix &mat)
{
	Matrix Result(row,col);
	
		for(int i=0;i<row;i++)
		{
			for(int j=0;j<col;j++)
			{
				Result.set(i,j,(get(i,j)-mat.get(i,j)));
			}
		}
		
		Result.outputMatrix();
}

//Function for Multiplication of Matrix

void Matrix::multiplication(Matrix &mat)
{
	Matrix Result(row,mat.getcol());
	
		for(int i = 0; i < row; ++i)
        {
        	for(int j = 0; j < mat.getcol(); ++j)
       		{
       			int sum=0;
			    for(int k = 0; k < col; ++k)
            	{
                	sum += get(i,k) * mat.get(k,j);
            	}
            	
            	Result.set(i,j,sum);
			}
        	
		}
		
		Result.outputMatrix();	
}

	//Functions
int inputrow();
int inputcol();


main()
{
	
	bool flag=false;
	bool flag1=false;
	bool flag2=false;
start1:	cout<<"1st Matrix Input"<<endl;
		int row=inputrow();
		int col=inputcol();
	
	Matrix m(row,col);
	m.inputMatrix();
	
	cout<<endl;
	cout<<"\n1st Matrix Input"<<endl;
	row=inputrow();
	col=inputcol();
	
	Matrix n(row,col);
	n.inputMatrix();
	
	cout<<endl;
	
	cout<<"\n1st Matrix Output"<<endl;
	m.outputMatrix();
	cout<<"\n1st Matrix Output"<<endl;
	n.outputMatrix();
	
	int s;
	bool result;
	start:  result=false;
			cout<<"\nEnter Number Coresponding to Function You wanna Check: ";
			cout<<"\n1-Square Matrix?\n2-Identity Matrix?\n3-Diagonal Matrix?";
			cout<<"\n4-Null Matrix?\n5-Upeer Triangle Matrix?\n6-Lower Triangle Matrix?\n7-Transpose?";
			cout<<"\n8-Addition\n9-Subtraction?\n10-Multiplication?\n11-Equal?\n12-Edit Matrices?\n13-Exit?"<<endl;
			cin>>s;
			
			switch(s)
			{
				case 1:
					result=m.isSquare();
					if(result)
					{
						cout<<"\nTrue"<<endl;
					}
					else
					{
						cout<<"\nFalse"<<endl;
					}
//					system("CLS");
					break;
				case 2:
					result=m.isSquare();
					if(result)
					{
						result=m.isIdentity();
						if(result)
						{
							cout<<"\nTrue"<<endl;
						}
						else
						{
							cout<<"\nFalse"<<endl;
						}
					}
					else
					{
						cout<<"\nFalse"<<endl;
					}
					break;
				case 3:
					result=m.isSquare();
					if(result)
					{
						result=m.isDiagonal();
						if(result)
						{
							cout<<"\nTrue"<<endl;
						}
						else
						{
							cout<<"\nFalse"<<endl;
						}
					}
					else
					{
						cout<<"\nFalse"<<endl;
					}
					break;
				case 4:
					result=m.isNullMatrix();
					if(result)
					{
						cout<<"\nTrue"<<endl;
					}
					else
					{
						cout<<"\nFalse"<<endl;
					}
					break;
				case 5:
					result=m.isSquare();
					if(result)
					{
						result=m.isUpperTriangular();
						if(result)
						{
							cout<<"\nTrue"<<endl;
						}
						else
						{
							cout<<"\nFalse"<<endl;
						}
					}
					else
					{
						cout<<"\nFalse"<<endl;
					}
					break;
				case 6:
					result=m.isSquare();
					if(result)
					{
						result=m.isLowerTriangular();
						if(result)
						{
							cout<<"\nTrue"<<endl;
						}
						else
						{
							cout<<"\nFalse"<<endl;
						}
					}
					else
					{
						cout<<"\nFalse"<<endl;
					}
					break;
				case 7:
//					Matrix* Temp;
					m.Transpose();
//					Temp->outputMatrix();
					break;
				case 8:
					flag=m.isEqual(n);
					if(flag)
					{
						m.addition(n);
					}
					else
					{
						cout<<"Addition Not Possible"<<endl;
					}
					break;
				case 9:
					flag1=m.isEqual(n);
					if(flag1)
					{
						m.subtraction(n);
					}
					else
					{
						cout<<"Subtraction Not Possible"<<endl;
					}
					break;
				case 10:
					
					if(m.getrow()==n.getcol())
					{
						m.multiplication(n);
					}
					else
					{
						cout<<"Multiplication Not Possible"<<endl;
					}
					break;
				case 11:
					flag2=m.isEqual(n);
					
					if(flag2)
					{
						cout<<"\nTrue"<<endl;
					}
					else
					{
						cout<<"\nFalse"<<endl;
					}
					break;
				case 12:
					row=inputrow();
					col=inputcol();
					
					m.setrow(row);
					m.setcol(col);
					m.inputMatrix();
					m.outputMatrix();
					
					break;
				case 13:
					goto end;
					break;
			}
			
		goto start;
		
		end:	cout<<"\nProgram Terminated."<<endl;
				return 0;
}


int inputrow()
{
	int row;
	cout<<"Enter No. Rows: ";
	cin>> row;
	return row;	
}

int inputcol()
{
	int col;
	cout<<"Enter No. Cols: ";
	cin>> col;
	return col;	
}

