#include<iostream>
#include <windows.h>
#include<conio.h>
using namespace std;

main ()
{
	int tc,tb,tcont,c,b,wc,wb;
	char s;
	// tc=total cookies, tb=total boxes, tcount=total containers, c=no. of cookies in one box, b = no. of boxes in one container, wc= total discard cookies, wb=total discard boxes, 
	// Getting input
a:	cout<<"Enter Total Cookies= ";
	Beep(950,500);
	cin>>tc; 
c:	cout<<"Enter Cookies in 1 box= ";
	Beep(950,500);
	cin>>c;
		if(c<=0)	// Warning Message for wrong input 
		{
			Beep(950,500);
			cout<<"Alert!\nNo. of cookies can't be zero nor -ve"<<endl;
		e:	Beep(950,500);
			cout<<"Press 'Y' to Try again and 'N' for Exit Program= ";
			cin>>s;
				switch(s)		// Selection for Re-use
				{
					case 'y':case 'Y':
						goto c;
						break;
					case 'n':case 'N':
						goto d;
						break;
					default:		
						goto e;
				}
		}
f:	cout<<"Enter Boxes in 1 Container=";
	Beep(950,500);
	cin>>b;
		if(b<=0)	// Warning Message for wrong input 
		{
			Beep(950,500);
			cout<<"Alert!\nNo. of Boxes can't be zero nor -ve"<<endl;	
		g:	Beep(950,500);
			cout<<"Press 'Y' to Try again and 'N' for Exit Program= ";
			cin>>s;
				switch(s)		// Selection for Re-use
				{
					case 'y':case 'Y':
						goto f;
						break;
					case 'n':case 'N':
						goto d;
						break;
					default:
						goto g;
				}
		}
	wc=tc%c;		// Calculating no. of Discard cookies
	tb=tc/c;		// Calculating Total no. of boxes made
	wb=tb%b;		// Calculating no. of Discard boxes
	tcont=tb/b;		// Calculating total no. of containers made
	// Displays output
	Beep(950,700);
	cout<<"\n\t-----------------------------------"<<endl;
	cout<<"\t|\t\tRecipt\t\t  |"<<endl;
	cout<<"\t-----------------------------------"<<endl;
	cout<<"\tTotal Boxes=		|	"<<tb<<endl;
	cout<<"\tTotal Containers=	|	"<<tcont<<endl;
	cout<<"\tTotal Waste Cookies=	|	"<<wc<<endl;
	cout<<"\tTotal Waste Boxes=	|	"<<wb<<endl;
	cout<<"\t-----------------------------------"<<endl;
	cout<<"\nWanna Try Again(Y/N)=";
b:	cin>>s;
		switch(s)		// Selection for Re-use
		{
			case 'y':case 'Y':
				goto a;
				break;
			case 'n':case 'N':
				goto d;
				break;
			default:
				Beep(950,500);
				cout<<"Wanna Try Again(Y/N)=";
				goto b;
		}
d:	Beep(950,700);
	cout<<"\n\t\t****Thank You!****";
	getch();
}
