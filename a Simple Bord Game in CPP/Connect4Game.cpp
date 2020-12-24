#include<iostream>
using namespace std;

class connect4game
{
private:
	int turn;
	int board[7][7];
	int port;
public:
	connect4game() 
	{
		turn = 0;
		port = 0;
		for (int i = 0; i < 7; i++)
		{
			for (int j = 0; j < 7; j++)
			{
				board[i][j] = 0;
			}
		}
	}
	connect4game(int t) 
	{
		turn = t;
	}
	
	~connect4game() 
	{
		cout<<"\nProgram Terminated!"<<endl;
	}
	
	bool isWon()
		{
				int x = 0,y = 0;
			for (int j = 0; j < 7; j++) //for vertical check
			{
				for (int i = 0; i < 7; i++)
				{
					if (board[i][j] == 1)
					{
						y++;
						if (y == 4)
						{
							return true;
						}
					}
					else
					{
						y = 0;
					}
				}
			}
			for (int i = 0; i < 7; i++) //for Horizontal check
			{
				for (int j = 0; j < 7; j++)
				{
					if (board[i][j] == 1)
					{
						x++;
						if (x == 4)
						{
							return true;
						}
					}
					else
					{
						x = 0;
					}
				}
			} 
			
			for(int a=6;a>=0;a--)
			{
				for (int i = a,j=0; i >= 0,j<7; i--,j++) //for bottom left to top right entries
				{
					if (board[i][j] == 1)
					{
						x++;
						if (x == 4)
						{
							return true;
						}
	
					}
					else
					{
						x = 0;
					}
				}
			}
			
			for(int a=6;a>0;a--)
			{
				for (int i = a,j=6 ; i >0,j>0 ; i--,j--) //for bottom right to top left entries
				{
					if (board[i][j] == 1)
					{
						x++;
						if (x == 4)
						{
							return true;
						}
	
					}
					else
					{
						x = 0;
					}
				}
			}
			return false;
		}
		
		bool isWon(int a)
		{
			int x = 0, y = 0;
			for (int j = 0; j < 7; j++) //for vertical check
			{
				for (int i = 0; i < 7; i++)
				{
					if (board[i][j] == 2)
					{
						y++;
						if (y == 4)
						{
							return true;
						}
					}
					else
					{
						y = 0;
					}
				}
			}
			
			for (int i = 0; i < 7; i++) //for Horizontal check
			{
				for (int j = 0; j < 7; j++)
				{
					if (board[i][j] == 2)
					{
						x++;
						if (x == 4)
						{
							return true;
						}
					}
					else
					{
						x = 0;
					}
				}
			}
			
			for(int a=6;a>=0;a--)
			{
				for (int i = a,j=0; i >= 0,j<7; i--,j++) //for bottom left to top right entries
				{
					if (board[i][j] == 2)
					{
						x++;
						if (x == 4)
						{
							return true;
						}
	
					}
					else
					{
						x = 0;
					}
				}
			}
			
			for(int a=6;a>0;a--)
			{
				for (int i = a,j=6 ; i > 0,j>0 ; i--,j--) //for bottom right to top left entries
				{
					if (board[i][j] == 2)
					{
						x++;
						if (x == 4)
						{
							return true;
						}
					}
					else
					{
						x = 0;
					}
				}
			}
			
			return false;
		}
		
		bool isBoardFull()
		{
			port++;
			if (port < 49)
			{
				return false;
			}
			else
			{
				return true;
			}
		}
		
		void valueInsert(int t, int c)
		{
			int col_full=0;
			
			if (t == 1 || t == 2)
			{
				for (int j = 0; j < 7; j++)
				{
					for (int i = 6; i >=0; i--)
					{
						if (j == c)
						{
							if (board[i][j] != 1 && board[i][j] != 2)
							{
								board[i][j] = turn;
								break;
							}
							else
							{
								col_full++;
							}
						}
					}
//					cout << "\n";
				}
				
				if(col_full>6)
				{
					cout<<"\nSelected Column is Full!\nPease Select Any Other."<<endl;
					col_full=0;
				}
				else
				{
					if(turn==1)
						turn=2;
					else if(turn==2)
						turn=1;
				}
			}
		}
		
		void showBoard()
		{
			for (int i = 0; i < 7; i++)
			{
				for (int j = 0; j < 7; j++)
				{
					cout << board[i][j];
				}
				cout << "\n";
			}
		}
		void switchturn(int t, int c)
		{   
			bool flag1 = false;
			bool flag2 = false;
			bool flag3=false;
			int a = 0;
	     	while (!isBoardFull())
			{
				if(!isWon()&&turn==1)
				{
					cout << " Player 1 Please Choose column between 1 to 7";
					cin >> c;
					valueInsert(turn,c-1);
					showBoard();
					isBoardFull();
				}
				else if(!isWon(a)&&turn==2)
				{
					cout << " Player 2 Please Choose column between 1 to 7";
					cin >> c;
					valueInsert(turn,c-1);
					showBoard();
					isBoardFull();
				}
				
				flag2 = isWon();
				flag3 = isWon(a);
				
				if (flag2)
				{
					cout << "Playes 1 has won the Match";
//					system("PAUSE");
					exit(0);
				}
				else if (flag3)
				{
					cout << "Playes 2 has won the Match";
//					system("PAUSE");
					exit(0);
	
				}
			}
			
			flag1 = isBoardFull();
			
			if (flag1)
			{
				cout << " The Board is Full ";
//				system("PAUSE");
				exit(0);
			}

		}
		
		void start()
		{
			int col = 0;
			turn = 1;
			cout << "\t Welcome to the Connect4Game\n";
			showBoard();
			switchturn(turn, col);
		}

};
int main()
{
	connect4game g;
	g.start();
}
