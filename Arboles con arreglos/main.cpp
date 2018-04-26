#include <iostream>
#include "arbol_arreglo.h"
#include <string>
using namespace std;
void menu(int opcion);
int main(int argc, char** argv) {
	Lista <string>listicaPrueba;
	arbol <string> arbol;
	string prueba;
	int opcion=0, numero;
	
	menu(5); 		//Ingresa la raiz 
	cin >> prueba;
	arbol.anadirRaiz(prueba);
	
	do{
	menu(0);
	cout << "> ";
	cin >> opcion;	
	switch(opcion){
		case 1:{
			menu(1);														//Añadir un nuevo hijo
			/*
			listicaPrueba = arbol.mostrarTodos();
			for (int i=1; i<=listicaPrueba.getTam(); i++){					//Imprime todos los elementos
				cout << i << ". " << listicaPrueba.devolverDato(i) << endl;
			}
			*/
			cout << endl << "> ";
			cin >> numero;
			menu(6); //Informacion del nuevo hijo
			cout << endl << "> ";
			cin >> prueba;
			arbol.anadirHijo(numero,prueba);
			break;
		}
		case 2:{
			menu(2);
			cout << endl << "> ";
			cin >> numero;
			listicaPrueba = arbol.mostrarHijos(numero);
			for (int i=1; i<=listicaPrueba.getTam(); i++){	
				cout << "Hijo " << i << ": " << listicaPrueba.devolverDato(i) << endl;
			}
			break;
		}
	}	
	} while (opcion!=4);
	/*
	cout << "Prueba hijo de la raiz 1" << endl;		//Prueba para ingresar hijos a la raiz
	cin >> prueba;
	arbolAnimales.anadirHijo(1,prueba);
	cout << "Prueba hijo de la raiz 2" << endl;
	cin >> prueba;
	arbolAnimales.anadirHijo(1,prueba);
	
	cout << "Prueba hijo del hijo 1.1" << endl; 		//Prueba para añadirle un hijo al primer hijo de la raiz
	cin >> prueba;
	arbolAnimales.anadirHijo(2, prueba);
	cout << "Prueba hijo del hijo 1.2" << endl; 		
	cin >> prueba;
	arbolAnimales.anadirHijo(2, prueba);
	cout << "Prueba hijo del hijo 1.3" << endl; 		
	cin >> prueba;
	arbolAnimales.anadirHijo(2, prueba);
	
	cout << "Muestra los hijos de la raiz" << endl;
	listicaPrueba = arbolAnimales.mostrarHijos(1);
	for (int i=1; i<=listicaPrueba.getTam(); i++){	
		cout << "Hijo " << i << ": " << listicaPrueba.devolverDato(i) << endl;
	}
	
	cout << "Muestra los hijos del primer hijo de la raiz" << endl;
	listicaPrueba = arbolAnimales.mostrarHijos(2);
	for (int i=1; i<=listicaPrueba.getTam(); i++){	
		cout << "Hijo " << i << ": " << listicaPrueba.devolverDato(i) << endl;
	}*/
	return 0;
}
void menu(int opcion){
	switch(opcion){
		case 0:{
			cout << "1. Ingresar un nuevo elemento al arbol" << endl;
			cout << "2. Mostrar los hijos de un nodo especifico" << endl;
			cout << "3. Mostrar el arbol" << endl;
			cout << "4. Salir" << endl;
			break;
		}
		case 1:{
			cout << "Seleccione cual sera el padre de este nuevo nodo" << endl;
			break;
		}
		case 2:{
			cout << "Seleccione el padre del que desea ver sus hijos " << endl;
			break;
		}
		case 5:{
			cout << "Ingrese la informacion de la raiz de su nuevo arbol" << endl;
			break;
		}
		case 6:{
			cout << "Escriba la informacion del nuevo hijo " << endl;
			break;
		}		
	}
}
