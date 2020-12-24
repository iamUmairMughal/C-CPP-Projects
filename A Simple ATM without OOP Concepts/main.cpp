#include <iostream>
#include<windows.h>
#include<conio.h>

using namespace std;
main()
{
	string tpass,pass="123",reset,pass1,pass2;
	float amnt=0,bal=0;
	char s;
start:	Beep(950,500);
	cout<<"Enter Password= ";
	cin>>tpass;
		if(tpass==pass)
		{
			cout<<"Welcome User!"<<endl;
		menu:	Beep(950,500);
			cout<<"\nPress\n'd' to deposit amount\n'w' to withdraw ammount and\n'i' for balance inquiry\n'r' to reset password\n'e' to Exit= ";
			cin>>s;
				switch(s)
				{
					case'd': case'D':
						Beep(950,500);
						cout<<"Type amount= ";
						cin>>amnt;
						bal+=amnt;
						Beep(950,500);
						Sleep(800);
						cout<<"\n\t--------------------------------------"<<endl;
						cout<<"\t\t\tRecipt"<<endl;
						cout<<"\t--------------------------------------"<<endl;
						Sleep(800);
						cout<<"\tYour balance is=	|	Rs."<<bal<<endl;
						cout<<"\t--------------------------------------"<<endl;
					t1:	Beep(950,500);
						cout<<"Wanna Try Again(Y/N)?= ";
								cin>>s;
									switch(s)
									{
										case'y':case'Y':
											goto menu;
											break;
										case'n':case'N':
											goto exit;
											break;
									default:
											cout<<"Invalind Input!"<<endl;
											goto t1;
									}

						break;
					case'w':case'W':
					w:	Beep(950,500);
						cout<<"Enter Amount= ";
						cin>>amnt;
							if(amnt>bal)
							{
								Beep(950,500);
								cout<<"Sorry! Invalid amount"<<endl;
							t2:	cout<<"\nWanna try again?(Y/N)= ";
								cin>>s;	
									switch(s)
									{
										case'y':case'Y':
											goto w;
											break;
										case'n':case'N':
											goto exit;
											break;
										default:
											cout<<"Invalind Input!";
											Beep(950,500);
											goto t2;
									}
							}
						bal-=amnt;
						Beep(950,500);
						Sleep(800);
						cout<<"\n\t--------------------------------------"<<endl;
						cout<<"\t\t\tRecipt"<<endl;
						cout<<"\t--------------------------------------"<<endl;		
						Beep(950,500);
						Sleep(800);
						cout<<"\tWithdrawed Amount=	|	Rs."<<amnt<<endl;
						Beep(950,500);
						Sleep(800);
						cout<<"\tRemaining Balance=	|	Rs."<<bal<<endl;
						cout<<"\t--------------------------------------"<<endl;
					t3:	Beep(950,500);
						cout<<"\nNeed another Transaction(Y/N)?= ";
								cin>>s;
									switch(s)
									{
										case'y':case'Y':
											goto menu;
											break;
										case'n':case'N':
											goto exit;
											break;
									default:
											cout<<"Invalind Input!"<<endl;
											goto t3;
									}

						break;
					case'i':case'I':
						Beep(950,500);
						Sleep(800);
						cout<<"\n\t--------------------------------------"<<endl;
						cout<<"\t\t\tRecipt"<<endl;
						cout<<"\t--------------------------------------"<<endl;
						Sleep(800);
						Beep(950,500);
						cout<<"\tCurrent Balance=	|	Rs."<<bal<<endl;
						cout<<"\t--------------------------------------"<<endl;
					t4:	Beep(950,500);
						cout<<"\nWanna Use Again(Y/N)?= ";
						cin>>s;
								switch(s)
								{
									case'y':case'Y':
										goto menu;
										break;
									case'n':case'N':
										goto exit;
										break;
									default:
										cout<<"Invalind Input!"<<endl;
										goto t4;
								}
						break;
					case'r': case'R':
					p1:	Beep(950,500);
						cout<<"Type old Password= ";
						cin>>reset;
							if(reset==pass)
							{
							p:	Beep(950,500);
								cout<<"Type New Password= ";
								cin>>pass1;
								cout<<"Confirm Password= ";
								cin>>pass2;
									if(pass2==pass1)
									{
										pass=pass2;
										cout<<"\nPassword changed!"<<endl;
										Beep(950,500);
										goto start;
									}
									else
									{
										cout<<"Password not match "<<endl;
									p3:	Beep(950,500);
										cout<<"\nWanna Try Again(Y\N)?= ";
										cin>>s;
											switch(s)
											{
												case'y':case'Y':
													goto p;
													break;
												case'n':case'N':
													goto exit;
													break;
												default:
													cout<<"Invalind Input!"<<endl;
													goto p3;
											}
										
									}
							}
							else
							{
							p2:	Beep(950,500);
								cout<<"Invalid Password!";
								cout<<"\nWanna try again(Y/N)?= ";
								cin>>s;
									switch(s)
									{
										case'y':case'Y':
											goto p1;
											break;
										case'n':case'N':
											goto exit;
											break;
										default:
											cout<<"Invalind Input!"<<endl;
											goto p2;
							}
							}
					case'e': case'E':
						goto exit;
						break;
					default:
						cout<<"Invalid Input!"<<endl;
					t5:	Beep(950,500);
						cout<<"\nWanna try again?(Y/N)= ";
						cin>>s;
							switch(s)
							{
								case'y':case'Y':
									goto menu;
									break;
								case'n':case'N':
									goto exit;
									break;
								default:
									cout<<"Invalind Input!"<<endl;
									goto t5;
							}		
				}
				
		}
		else
		{
			cout<<"Error!\nWrong Password!"<<endl;
		t6:	Beep(950,500);
			cout<<"Wanna Try Again(Y/N)?= ";
			cin>>s;
				switch(s)
				{
					case'y':case'Y':
						goto start;
						break;
					case'n':case'N':
						goto exit;
						break;
					default:
						cout<<"Invalind Input!"<<endl;
						goto t6;
				}
		}
exit:Beep(950,500);
	cout<<"Are you sure to Eixt(Y/N)?=";
	cin>>s;
		switch(s)
		{
			case'Y': case'y':
				goto exit1;
			case'n': case'N':
				goto menu;
			default:
				cout<<"Invalid Input!"<<endl;
				goto exit;		
		}
exit1:Beep(950,500);
	Sleep(800);
	cout<<"\n\t------------------------------"<<endl;
	cout<<"\t\t***Thanks You!***"<<endl;
	getch();
}
