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

	
	//Lista Flotantes 
	Lista<float> flot;
	flot.anadirCabeza(1.987654323456);
	flot.anadirFin(12.87654320);
	flot.anadirPos(1.5,2);
	flot.eliminarPos(2);
	flot.anadirCabeza(5.09876543);
	flot.anadirPos(1.8,4);
	flot.anadirPos(2.5,6);
	flot.eliminarFinal();
	flot.anadirFin(1.997);
	for(int i = 1;i<=flot.getTam();i++){
		cout<<flot.devolverDato(i)<<" ";
	}
	cout<<endl;
	
	//Lista caracteres 
	Lista<char> car;
	car.anadirCabeza('O');
	car.anadirFin('L');
	car.anadirPos('A',2);
	car.eliminarPos(2);
	car.anadirCabeza('H');
	car.anadirPos('A',4);
	car.anadirPos('I',6);
	car.eliminarFinal();
	car.anadirFin('!');
	for(int i = 1;i<=flot.getTam();i++){
		cout<<car.devolverDato(i)<<" ";
	}
	cout<<endl;
	
	
return 0;
}
