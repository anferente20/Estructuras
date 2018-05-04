#include <iostream>
#include "ArbolBinarioOrd.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
void menu(int opcion);
int main(int argc, char** argv) {
	int numero, i, opcion;
	arbolBin arbol;
	Lista<int> orden;
	/**
	arbol.insertarRaiz(100);
	arbol.insertarElemento(150);
	arbol.insertarElemento(50);
	arbol.insertarElemento(30);
	arbol.insertarElemento(75);
	arbol.insertarElemento(125);
	arbol.insertarElemento(170);
	arbol.insertarElemento(10);
	arbol.insertarElemento(60);
	arbol.insertarElemento(90);
	arbol.insertarElemento(180);
	arbol.insertarElemento(140);
	arbol.insertarElemento(160);
	
	*/
	
	menu(5); 		//Ingresa la raiz 
	cin >> numero;
	arbol.insertarRaiz(numero);
	
	do{
	menu(0);
	cout << "> ";
	cin >> opcion;	
	switch(opcion){
		case 1:{
			cout << "Escriba el elemento que desea anadir" << endl;
			cin >> numero;
			arbol.insertarElemento(numero);
			break;
		}
		case 2:{
			arbol.inorden(1);    
			orden = arbol.getin();		
			//mostrando recorrido inorden
			cout<<"Elementos del arbol: "<<endl;
			for(i=1; i<=orden.getTam(); i++){
				cout<<orden.devolverDato(i)<<" ";
			}
			cout<<endl;
			cout << "Escriba el elemento que desea eliminar" << endl;
			cin >> numero;
			break;
		}
		case 3:{
			menu(3);
			cin >> numero;
			if (numero==1){
				arbol.inorden(1);    
				orden = arbol.getin();		
				//mostrando recorrido inorden
				cout<<"Mostrando recorrido inorden: "<<endl;
				for(i=1; i<=orden.getTam(); i++){
					cout<<orden.devolverDato(i)<<" ";
				}
				cout<<endl;
			}
			if (numero==2){
				cout<<"Mostrando recorrido preorden: "<<endl;	
				arbol.preorden(1);
				orden = arbol.getpre();
				cout<<"tamaño de orden: "<<orden.getTam()<<endl;
				//mostrando recorrido preorden
				for(i=1; i<=orden.getTam(); i++){
					cout<<orden.devolverDato(i)<<" ";
				}
				cout<<endl;
			}
			if (numero==3){
				cout<<"Mostrando recorrido posorden: "<<endl;
				arbol.posorden(1);
				orden = arbol.getpos();
				cout<<"tamaño de orden: "<<orden.getTam()<<endl;
				//mostrando recorrido preorden
				for(i=1; i<=orden.getTam(); i++){
					cout<<orden.devolverDato(i)<<" ";
				}
				cout<<endl;
			}
			break;
		}
	}	
	} while (opcion!=4);
	

	/*cout<<arbol.cortar(100)<<endl;
	arbol.vaciarListas();
	arbol.inorden(arbol.getRaiz());
	orden = arbol.getin();
	for(i=1; i<=orden.getTam(); i++){
		cout<<orden.devolverDato(i)<<" ";
	}
	*/
	return 0;
}
void menu(int opcion){
	switch(opcion){
		case 0:{
			cout << "1. Ingresar un nuevo elemento al arbol" << endl;
			cout << "2. Eliminar un elemento del arbol" << endl;
			cout << "3. Mostrar recorridos" << endl;
			cout << "4. Salir" << endl;
			break;
		}
		
		case 2:{
			cout << "Escriba el elemento que desea eliminar " << endl;
			break;
		}
		case 3:{
			cout << "1. In orden" << endl;
			cout << "2. Pre orden" << endl;
			cout << "3. Post orden" << endl;
			break;
		}		
		case 5: {
			cout << "Ingrese la informacion de la raiz de su nuevo arbol" << endl;
			break;
		}
	}
}
