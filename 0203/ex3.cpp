#include <iostream>
#include <iomanip>

using namespace std;

int main(int argc, char** argv)
{
	int i;
	double d;
	
	cout<<"Digite um valor int   : 	";
	cin >> i;
    cout<<"Digite um valor double: 	";
	cin >> d;
	
	cout<< "Valor int   : 	" <<setw(10) << i << endl;
	cout<< "Valor double: 	" << setw(10) << d << endl;
	
	cout<< "Valor double: 	" << setprecision(2)<< setw(10) << d << endl;
	cout<< "Valor double: 	" << setprecision(3)<< setw(10) << d << endl;
	cout<< "Valor double: 	" << setprecision(4)<< setw(10) << d << endl;
	
	cout << fixed;
	cout<< "Valor double: 	" << setprecision(2)<< setw(10) << d << endl;
	cout<< "Valor double: 	" << setprecision(3)<< setw(10) << d << endl;
	cout<< "Valor double: 	" << setprecision(4)<< setw(10) << d << endl;
	
	return 0;
}