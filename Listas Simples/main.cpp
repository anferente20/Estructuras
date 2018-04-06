#include <iostream>
#include "listas.h"

using namespace std;
int main(int argc, char** argv) {
	Lista<int> var;
	var.anadirCabeza(10);
	var.anadirFin(120);
	var.anadirPos(15,2);
	var.anadirCabeza(5);
	var.anadirPos(18,4);
	var.anadirPos(25,6);
	for(int i = 1;i<=var.getTam();i++){
		cout<<var.devolverDato(i)<<" ";
	}
	cout<<endl;
	var.eliminarInicio();
	var.eliminarFinal();
	var.eliminarPos(3);
	for(int i = 1;i<var.getTam();i++){
		cout<<var.devolverDato(i)<<" ";
}
return 0;
}
