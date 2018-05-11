#include <iostream>
#include "avl.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
void menu(int opcion);
int main(int argc, char** argv) {
	AVL<int> arbol;
	int numero;
	int i, opcion;
	Lista<int> orden;
	
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
			arbol.inorden(arbol.getRaiz());    
			orden = arbol.getin();		
			//mostrando recorrido inorden
			cout<<"Elementos del arbol: "<<endl;
			for(i=1; i<=orden.getTam(); i++){
				cout<<orden.devolverDato(i)<<" ";
			}
			cout<<endl;
			cout << "Escriba el elemento que desea eliminar" << endl;
			cin >> numero;
			arbol.eliminar(numero);
			system("pause");
			break;
		}
		case 3:{
			menu(3);
			cin >> opcion;
			if (opcion==1){
		
				arbol.inorden(arbol.getRaiz());    
	
				orden = arbol.getin();		
				//mostrando recorrido inorden
				cout<<"Mostrando recorrido inorden: "<<endl;
				for(i=1; i<=orden.getTam(); i++){
					cout<<orden.devolverDato(i)<<" ";
				}
				cout<<endl;
			}
			if (opcion==2){
				cout<<"Mostrando recorrido preorden: "<<endl;	
				arbol.preorden(arbol.getRaiz());
				orden = arbol.getpre();
				cout<<"tamaño de orden: "<<orden.getTam()<<endl;
				//mostrando recorrido preorden
				for(i=1; i<=orden.getTam(); i++){
					cout<<orden.devolverDato(i)<<" ";
				}
				cout<<endl;
			}
			if (opcion==3){
				cout<<"Mostrando recorrido posorden: "<<endl;
				arbol.posorden(arbol.getRaiz());
				orden = arbol.getpos();
				cout<<"tamaño de orden: "<<orden.getTam()<<endl;
				//mostrando recorrido preorden
				for(i=1; i<=orden.getTam(); i++){
					cout<<orden.devolverDato(i)<<" ";
				}
				cout<<endl;
			}
			system("pause");
			break;
		}
		case 4:{
			arbol.mostrarInfo();
			system("pause");
			break;
		}
	}	
	//arbol.mostrarInfo();
	system("cls");
	arbol.vaciarListas();
	} while (opcion!=5);
	return 0;
}
void menu(int opcion){
	switch(opcion){
		case 0:{
			cout << "1. Ingresar un nuevo elemento al arbol" << endl;
			cout << "2. Eliminar un elemento del arbol" << endl;
			cout << "3. Mostrar recorridos" << endl;
			cout << "4. Mostrar todos lo datos" << endl;
			cout << "5. Salir" << endl;
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
