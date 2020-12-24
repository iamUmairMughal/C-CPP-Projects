#include <iostream>

using namespace std;
main()
{
	int d1,d2;
	double nb,pay,adb,im,ti;
	cout<<"Enter Balance in bill= ";
	cin>>nb;
	cout<<"Enter Payment made= ";
	cin>>pay;
	cout<<"Enter No. days in billing cycle= ";
	cin>>d1;
	cout<<"Enter No. of dayspayment made before billing cycle= ";
	cin>>d2;
	cout<<"Enter interest rate per mount= ";
	cin>>im;
	adb=(nb*d1-pay*d2)/d1;
	ti=adb*im;
	cout<<"Total Interest= "<<ti<<endl;
}
