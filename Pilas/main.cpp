#include <iostream>
#include "pila.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int main(int argc, char** argv) {
	/*char c;
	Pila<char> guardar(50);
	while(cin.get(c)){
		while(c>='0' && c<='9'){
			cout.put(c);
			cin.get(c);
		}
		if(c==')')cout.put(guardar.sacar());
		if(c=='+')guardar.meter(c);
		if(c=='*')guardar.meter(c);
		if(c!='(')cout<<' ';
	}
	cout<<'\n';*/
	
	char c;
	Pila <char>acc(50);
	int x;
	while(cin.get(c) && c != '\n'){
		x = 0;
		while(c==' ')cin.get(c);
		while(c>='0' && c<='9'){
			x = 10*x + (c-48);
			cin.get(c);
		}
		
		if(c=='+'){
			x = acc.sacar() + acc.sacar(); 
				
		}
		if(c=='*'){
			x = acc.sacar()*acc.sacar(); 
		
		}
		acc.meter(x);
				
	}
	cout<<"Resultado : "<<x<<endl;
	return 0;
}
