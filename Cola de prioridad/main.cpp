#include <iostream>
#include "colaP.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
void menu(int opcion);
int main(int argc, char** argv) {
	cout<<"hola"<<endl;
	int opcion, i;
	int numero;
	Lista<int> cat;
	menu(5);
	
	cin>>opcion;
	
	colaP<int> cola(opcion);	
/*	
	cola.agregar(60);	
	cola.agregar(80);
	cola.agregar(20);
	cola.agregar(90);
	cola.agregar(50);
	cola.agregar(40);
	cola.agregar(30);
	cola.agregar(70);
	cola.agregar(55);
	cola.agregar(45);
*/							
	do{
		menu(0);
		cout << "> ";
		cin >> opcion;	
		switch(opcion){
			case 1:{
				cout << "Escriba el elemento que desea anadir" << endl;
				cin >> numero;
				cola.agregar(numero);
				
				break;
			}
			case 2:{
				cout << "Asi queda la cola luego de atender: " << endl;
				//mostramos la cola luego de atender
				cola.atender();
				cat = cola.getCola();	
				for(i = 1 ; i<=cat.getTam(); i++){
					cout << cat.devolverDato(i) <<" "; 
				}	
				cout << endl;		
				break;
			}
			case 3:{
				cout << "Elementos de la cola: " <<endl;
				cout << "tam de la cola: " <<cola.getTam() << endl;
				cola.RefrescarLista();
				cat = cola.getCola();	
				for (int i=1; i<=cat.getTam(); i++){
					cout<<cat.devolverDato(i)<<" ";
				}
				cout<<endl;
				break;
			}	
		}
	}while(opcion!=4);		
	return 0;
}

void menu(int opcion){
	switch(opcion){
		case 0:{
			cout << "1. Ingresar un nuevo elemento a la cola de prioridad" << endl;
			cout << "2. Atender la cola " << endl;
			cout << "3. Mostrar elementos de la cola" << endl;
			cout << "4. Salir" << endl;			
			break;
		}								
		case 5: {
			cout << "Ingrese la cantidad de nodos que tendra la cola" << endl;
			break;
		}
	}
}
