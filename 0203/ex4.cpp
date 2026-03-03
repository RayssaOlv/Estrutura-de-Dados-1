#include <iostream>
#include <iomanip>
#include <locale.h>

using namespace std;

int main(int argc, char** argv)
{
	setlocale(LC_ALL,"");
	
	
	int i;
    double j;
    double *pj;
    
    i = 100;
    j = 200;
    
    cout<< "Valor da variável i: "<< i << endl;
    cout<< "Tamanho da variável i: "<< sizeof(i) << endl;
    cout<< "Endereço da variável i: "<< &i << endl;
	cout << endl;
	cout<< "Valor da variável j: "<< j << endl;
    cout<< "Tamanho da variável j: "<< sizeof(j) << endl;
    cout<< "Endereço da variável j: "<< &j << endl;
    cout << endl;
    
    pj = &j;
    *pj = 500;
    
    cout<< "Valor da variável pj: "<< pj << endl;
    cout<< "Valor do Endereço para onde pj aponta: "<< *pj << endl;
    cout<< "Tamanho da variável pj: "<< sizeof(pj) << endl;
    cout<< "Endereço da variável pj: "<< &pj << endl;
    cout << endl;
    
    cout<< "Valor da variável j: "<< j << endl;
    cout<< "Tamanho da variável j: "<< sizeof(j) << endl;
    cout<< "Endereço da variável j: "<< &j << endl;
	return 0;
}