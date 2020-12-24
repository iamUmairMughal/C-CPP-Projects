#include <iostream>

using namespace std;
main()
{
	int isl,pak,eng,math,total;
	char s;
	bool a,b;
start:	cout<<"Are you Muslim? (Y/N)= ";
		cin>>s;
		switch(s)
		{
			case 'Y': case 'y':
			i:	cout<<"\nEnter Marks in Islamiyat= ";
				cin>>isl;
				if(isl>=50&&isl<=100)
				{
					cout<<"\nCongratulations!\nYou're Pass in Islamiyat."<<endl;
					a=isl>=50;
				}
				else if(isl<50&&isl>=0)
				{
					goto f; 
				}
				else
				{
					cout<<"Invalid Marks!"<<endl;
					goto i;
				}
				b=true;
				
				break;
			case 'N':case 'n':
				isl=0;
				a=true;
				b=false;
				break;
			default:
				cout<<"Invalid Input!"<<endl;
				goto start;
		}
p:		cout<<"\nEnter Marks in Pak-Studies= ";
		cin>>pak;
		if(pak<=100)
		{
		
			if(a&&pak>=50)
			{
				cout<<"\nCongratulations!\nYou're Pass in Pak-Studies."<<endl;
			e:	cout<<"\nEnetr Marks in English= ";
				cin>>eng;
				if(eng<=100&&eng>=0)
				{
					goto m;
				}
				else
				{
					cout<<"Invalid Marks!"<<endl;
					goto e;
				}
			m:	cout<<"Enetr Marks in Maths= ";
				cin>>math;
				if(math<=100)
				{
					if(eng>=50)
					{
						cout<<"\nYou're Pass in English."<<endl;
					}
					else
					{
						cout<<"\nYou're Fail in English."<<endl;
					}
					if(math>=50)
					{
						cout<<"You're Pass in Maths."<<endl;
					}
					else
					{
						cout<<"You're Fail in Maths."<<endl;
					}
					cout<<"\n\t------------------------------"<<endl;
					cout<<"\t\tOverall Performence"<<endl;
					cout<<"\t------------------------------"<<endl;
						if(b)
						{
							cout<<"\tIslamiyat=	|	"<<isl<<endl;
						}
					cout<<"\tPak-Studies=	|	"<<pak<<endl;
					cout<<"\tEnglish=	|	"<<eng<<endl;
					cout<<"\tMaths=		|	"<<math<<endl;	
					total=isl+pak+eng+math;
					cout<<"\n\tTotal=		|	"<<total<<endl;
					cout<<"\t------------------------------"<<endl;
				}
				else
				{
					cout<<"Invalid Marks!"<<endl;
					goto m;
				}
				
			}
			else
			{
		f:		cout<<"\nSorry! You're Totally Fail."<<endl;
			}
		}
		else
		{
			cout<<"Inavlid Marks!"<<endl;
			goto p;
		}
re:		cout<<"\nWanna re-use? (Y/N)= ";
		cin>>s;
		switch(s)
		{
			case 'Y': case 'y':
				goto start;			
				break;
			case 'N':case 'n':
				goto end;
				break;
			default:
				cout<<"Invalid Input!"<<endl;
				goto re;			
		}
end:	cout<<"\n\t......Thank You!......"<<endl;
		
}

