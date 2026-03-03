#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
	int i;
	double d;
	char c;
	string s;
	
	c = 'a';
	
	cout << "Valor char:" << c << endl;
	s="IFSP";
    cout <<"Digite um valor string: ";
	cin >> s;
	
	/*cout<<"Digite um valor int: ";
	cin >> i;
    cout<<"Digite um valor double: ";
	cin >> d;
	
	cout<< "Valor int: " << i << endl;
	cout<< "Valor double: " << d << endl;
	*/
	
	cout<< "Tamanho da sting: " << s.size() << endl;
	return 0;
}