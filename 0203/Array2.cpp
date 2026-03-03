#include <iostream>
#include <iomanip>
#include <locale.h>

using namespace std;

void mostra_array1(int p[])
{
		for(int i=0; i<5; ++i)
	{
		cout << p[i] << endl;
	}
	cout << endl;
}
void mostra_array2(int p[])
{
		for(int i=0; i<5; ++i)
	{
		cout << *p << endl;
		++p;
	}
	cout << endl;
}

void mostra_endereco_array(int p[])
{
		for(int i=0; i<5; ++i)
	{
		cout << p << endl;
		++p;
	}
	cout << endl;
}

const QTD = 5;
int main(int argc, char** argv)
{
	int *a;
	a= (int*)malloc(QTD * sizeof(int));
	for(int i=0; i< QTD; ++i )
	{
		a[i] = (i+1) * 10;
	}
			for(int i=0; i< QTD; ++i )
	{
		cout << setw(2) << a[i] << endl;
	}
	
		for(int i=0; i< QTD; ++i )
	{
		cout << setw(2) << *a << endl;
		++a;
	}
	
	
	mostra_array1(a);
	mostra_array2(a);
	mostra_endereco_array(a);

	return 0;
}