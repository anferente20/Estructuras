#include <iostream>
#include "listas.h"
#include "listas_ordenadas.h"


struct complejo{
		float real;
		float imaginario;
		complejo() { 
			real=0;
			imaginario = 0; 
		}	
	    complejo(float r, float i) { 
			real=r; 
			imaginario = i; 
		}
	    complejo(float r) { 
			real=r; 
			imaginario = 0; 
		}
		
	};
using namespace std;
int main(int argc, char** argv) {
	//Lo primero que hicimos :v
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
	cout<<endl;
	
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
	for(int i = 1;i<=car.getTam();i++){
		cout<<car.devolverDato(i)<<" ";
	}
	cout<<endl;
	
	//Lista de enteros
	Lista<int> ent;
	ent.anadirCabeza(15);
	ent.anadirFin(0);
	ent.anadirPos(78,6);
	ent.eliminarPos(3);
	ent.anadirCabeza(9);
	ent.anadirPos(65,2);
	ent.anadirPos(1,9);
	ent.eliminarFinal();
	ent.anadirFin(3);
	for(int i = 1;i<=ent.getTam();i++){
		cout<<ent.devolverDato(i)<<" ";
	}
	cout<<endl;
	
	//Lista de estructura en este caso complejos
	complejo z;
	Lista<complejo> com;
	z.real=5;
	z.imaginario=6;
	com.anadirCabeza(z);
	z.real=9;
	z.imaginario=2;
	com.anadirFin(z);
	z.real=4.3;
	z.imaginario=0;
	com.anadirPos(z, 4);

	com.eliminarPos(9);
	z.real=9.2;
	z.imaginario=7;
	com.anadirCabeza(z);
	z.real=65;
	z.imaginario=0;
	com.anadirPos(z, 2);
	z.real=8;
	z.imaginario=6;
	com.anadirPos(z, 9);
	
	com.eliminarFinal();
	z.real=3;
	z.imaginario=4;
	com.anadirFin(z);
	for(int i = 1;i<=com.getTam();i++){
		cout<<com.devolverDato(i).real<<"+"<<com.devolverDato(i).imaginario<<"i  ";
	}
	system ("cls");
	/**
	Lista ordenada de enteros
	**/
	
	Lista_ordenada enteros;
	elemento *estudiante = new elemento();
	estudiante->x  = 20161020058;
	estudiante->info  = "Andres";
	enteros.insertar(estudiante);
//	estudiante->x = 20161020031;
//	estudiante->info = "Sebastian";
//	enteros.insertar(estudiante);
	for(int i = 0;i<=enteros.getTam();i++){
		cout<<enteros.devolverDato(i)->info<<" "<<enteros.devolverDato(i)->x<<endl;
	}
	cout<<endl;
return 0;
}
