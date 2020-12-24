#include <iostream>
#include<windows.h>
using namespace std; 
main() 
{
	int age;
	double mv,av,av1,ar,taxr,tax;
	bool a=false;
	Beep(950,500);
	cout<<"Enter your Age= ";
	cin>>age;
	Beep(950,500);
	cout<<"Enter Actual Value of Property= $";
	cin>>mv;
	Beep(950,500);
	cout<<"Enter Assessed Rate= $";
	cin>>ar;
	av=mv/ar;			// Calculating assessed value
	av1=av;
	if(age>=60&&av>=5000)
	{
		av-=5000;
		a=true;
	}
	
	Beep(950,500);
	cout<<"Enter Tax Rate per $100= $";
	cin>>taxr;
	tax=(av/100)*taxr;		// Calculating tax
	Beep(950,500);
	Sleep(800);
	cout<<"\n\t-------------------------------------------"<<endl;
	cout<<"\t\t\t   Recipt"<<endl;
	cout<<"\t-------------------------------------------"<<endl;
	Sleep(800);
	Beep(950,500);
	cout<<"\tAssessed Value of Property=\t|  $"<<av1<<endl;
	if(a)
	{
		Sleep(800);
		Beep(950,500);
		cout<<"\tSenior Citizen Discount=\t|  $"<<av<<endl;
	}
	Sleep(800);
	Beep(950,500);
	cout<<"\tTotal Tax on Property=\t\t|  $"<<tax<<endl;
	Sleep(800);
	cout<<"\t-------------------------------------------"<<endl;
}
