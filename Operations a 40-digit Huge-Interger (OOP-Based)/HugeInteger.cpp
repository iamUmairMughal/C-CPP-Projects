#include<iostream>
using namespace std;

class HugeInteger {

public:
	char number[40];
	int index;

	HugeInteger()
	{
		for (int i = 0; i < 40; i++)
		{
			number[i] = '0';
			index = 0;
		}
	}

	//OverLoading == Operator
	bool operator == (HugeInteger& obj)
	{
		int count = 0;
		if (index == obj.index)
		{
			for (int i = index; i < 40; i++)
			{
				if (number[i] == obj.number[i])
				{
					count++;
				}
			}
		}
		else
		{
			return false;
		}

		if (count == (40 - index))
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	//OverLoading != Operator
	bool operator != (HugeInteger& obj)
	{
		int count = 0;
		if (index == obj.index)
		{
			for (int i = index; i < 40; i++)
			{
				if (number[i] == obj.number[i])
				{
					count++;
				}
			}
		}
		else
		{
			return true;
		}

		if (count == (40 - index))
		{
			return false;
		}
		else
		{
			return true;
		}
	}


	//OverLoading + Operator
	HugeInteger operator + (HugeInteger& obj)
	{
		HugeInteger temp;

		int carry = 0;
		int d2 = 0;
		int num1 = 0;
		int num2 = 0;
		int num3 = 0;

		for (int i = 39; i >= 0; i--)
		{
			num1 = number[i];
			num1 -= 48;
			num2 = obj.number[i];
			num2 -= 48;
			num3 = num1 + num2;
			if (num3 > 9)
			{
				carry = num3 / 10;
				d2 = num3 % 10;
			}
			else if( num3==9&&temp.number[i]=='1')
			{
				carry=1;
				d2=0;
				temp.number[i]='0';
			}
			else
			{
				carry = 0;
				d2 = num3;
			}
			
			if(i==0)
			{
				temp.number[i] += d2;
//				temp.number[i - 1] += carry;	
			}
			else
			{	
				temp.number[i] += d2;
				temp.number[i - 1] += carry;	
			}
			
		}

		int i;
		for (i = 0; i < 40; i++)
		{
			if (temp.number[i] != '0')
			{
				break;
			}
		}

		temp.index = i;
		return temp;
	}
	bool operator <=(HugeInteger& obj)
	{
		if ((number < obj.number) || (number== obj.number))
		{
			return true;
		}
		else
		{
			return false;
		}

	}
	bool operator >=(HugeInteger& obj)
	{
		if ((number > obj.number) || (number == obj.number))
		{
			return true;
		}
		else
		{
			return false;
		}

	}

	//OverLoading - Operator
	HugeInteger operator - (HugeInteger& obj)
	{
		HugeInteger temp;

		int borrow = 0;
		int num1 = 0;
		int num2 = 0;
		int num3 = 0;

		for (int i = 39; i >= index; i--)
		{
			num1 = number[i];
			num1 -= 48;
			num2 = obj.number[i];
			num2 -= 48;

			num3 = num1 - num2;
			temp.number[i] = 48 + num3;
		}

		int i;
		for (i = 0; i < 40; i++)
		{
			if (temp.number[i] != '0')
			{
				break;
			}
		}

		temp.index = i;
		return temp;
	}

	//OverLoading > Operator
	bool operator > (HugeInteger& obj)
	{
		if ((40 - index) > (40 - obj.index))
		{
			return true;
		}
		else if ((40 - index) == (40 - obj.index))
		{
			for (int i = index; i < 40; i++)
			{
				if (number[i] > obj.number[i])
				{
					return true;
				}
			}

			return false;
		}
		else
		{
			return false;
		}
	}

	//OverLoading < Operator
	bool operator < (HugeInteger& obj)
	{
		if ((40 - index) < (40 - obj.index))
		{
			return true;
		}
		else if ((40 - index) == (40 - obj.index))
		{
			for (int i = index; i < 40; i++)
			{
				if (number[i] < obj.number[i])
				{
					return true;
				}
			}
			return false;
		}
		else
		{
			return false;
		}
	}

	//OverLoading [] operator to Get a Character
	HugeInteger operator [](int ind)
	{
		if (ind >= 0 && ind < 40)
		{
			cout<<"\nCurrent Value at index["<<ind<<"]: "<<number[ind]<<endl;
			cout << "Enter New Character: ";
			cin >> number[ind];
			//				return number[ind];
			cout << "\nValue setted successfully";
		}
		else
		{
			cout << "Array Index Out Of Range." << endl;
		}
	}

	//OverLoading () Operator to Get a Specific Part of Number
	HugeInteger operator () (int a, int b)
	{
		HugeInteger temp;
		temp.index=index;
		if (a >= 0 && b < 40)
		{
			for (int i = a; i <= b; i++)
			{
				temp.number[i]=number[i];
			}
			cout << endl;
		}
		else
		{
			cout << "Invalid Array Bounding." << endl;
		}
		return temp;
	}

	friend ostream& operator << (ostream& out, const HugeInteger& num);
	friend istream& operator >> (istream& in, HugeInteger& num);

};

ostream& operator << (ostream& out, const HugeInteger& num)
{
	if(num.index==40)
	{
		for (int i = 0; i < 40; i++)
		{
			out << num.number[i];
		}
		return out;
	}
	
	for (int i = num.index; i < 40; i++)
	{
		out << num.number[i];
	}
	return out;
}

istream& operator >> (istream& in, HugeInteger& num)
{

	string number;

	in >> number;
	
	for (int i = 0; i < 40; i++)
	{
		num.number[i] = '0';
	}
	
	int index = 40 - number.length();
	num.index = index;
	
	for (int i = 0; i < number.length(); i++)
	{
		num.number[index + i] = number[i];
	}

	return in;
}

int main()
{
	int check=0,ch;
	HugeInteger num1, num2, result;
	a:	cin >> num1;
		cin >> num2;
		cout<<num1<<endl;
		cout<<num2<<endl;
	
	while (check != 12)
	{
		cout << "\n\nPlease Enter 1 to add these arrays\nEnter 2 to subtract these arrays\nEnter 3 to find if these arrays are equal\nEnter 4 to find if these arrays are not equal\nEnter 5 to find ir first array is greater than second array\nEnter 6 to find if first array is less than second array\nEnter 7 to find if first array is less than equal to second array\nEnter 8 to find if first array is greater than equal to second array\nEnter 9 to set value at a specific index\nEnter 10 to read an array between indexes\nEnter 11 to ReEnter arrays\nEnter 12 to terminate program ";
		cin >> check;
		switch (check)
		{
			case 1:
			{
				result = num1 + num2;
				cout << "\nThe result to addition is = " << result;
				break;
			}
			case 2:
			{
				result = num1 - num2;
				cout << "\nThe result to subtraction is = " << result;
	
				/*if (num1 > num2)
				{
					result = num1 - num2;
					cout << result;
				}
				else
				{
					result = num2 - num1;
					cout << "-" << result;
				}*/
			}
			case 3:
			{
				if (num1 == num2)
				{
					cout << "\nYes they are both Equal ";
				}
				else
					cout << "\nthey are not Equal";
			}
			case 4:
			{
				if (num1 != num2)
				{
					cout << "\nYes they are both unEqual ";
				}
				else
					cout << "\nNo,they are both Equal";
			}
			case 5:
			{
				if (num1 > num2)
				{
					cout << "\nYes the first array is greater ";
				}
				else
					cout << "\nNo,the first array is not greater,";
	
			}
			case 6:
			{
				if (num1 < num2)
				{
					cout << "\nYes the first array is smaller ";
				}
				else
					cout << "\nNo,the first array is not smaller,";
			}
			case 7:
			{
//				if (num1 <= num2)
				if ((num1 < num2)||(num1==num2))
				{
					cout << "\nYes the first array is smaller or equal to second array  ";
				}
				else
					cout << "\nNo, the first array is not smaller or equal to second array ";
				break;
			}
			case 8:
//				if (num1 >= num2)
				if ((num1 > num2)||(num1==num2))
				{
					cout << "\nYes the first array is greater or equal to second array  ";
				}
				else
					cout << "\nNo,the first array is not greater or equal to second array ";
				break;
			case 9:
			{
				int a;
				cout << "\nPlease Enter the index :  ";
				cin >> ch;
				cout << "Enter the array 1 or 2? ";
				cin >> a;
				if (a == 1)
				{
					num1[ch];
					cout<<num1<<endl;
	
				}
				else if (a == 2)
				{
					num2[ch];
					cout<<num2<<endl;
				}
				else
					cout <<"Invalid Operator "<<endl;
				break;
	
			}
			case 10:
			{
				HugeInteger temp;
				int a, b;
				cout << "\nPlease enter the starting range : ";
				cin >> a;
				cout << " \nPlease enter the ending Range : ";
				cin >> b;
				if (a < b)
				{
					cout << "\nFrom which array you want to get data : ";
					cin >> ch;
					if (ch == 1)
					{
						temp=num1(a, b);
						for (int i = a; i <=b; i++)
						{
							cout << temp.number[i];
						}
						cout<<endl;
					}
					else if (ch == 2)
					{
						temp=num2(a, b);
						for (int i = a; i <=b; i++)
						{
							cout << temp.number[i];
						}
						cout<<endl;
					}
				}
				else
					cout << "\n Invalid Range ";
				break;
			}
			case 11:
			{
				goto a;
			}
		}
	}
		exit(0);
	
}

