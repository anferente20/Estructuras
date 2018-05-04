#include <iostream>
#include "ArbolBinarioOrd.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int main(int argc, char** argv) {
	int numero;
	arbolBin arbol;
	Lista<int> orden;
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
	
	
	arbol.inorden(1);    
	orden = arbol.getin();		
	//mostrando recorrido inorden
	int i;
	cout<<"Mostrando recorrido inorden: "<<endl;
	for(i=1; i<=orden.getTam(); i++){
		cout<<orden.devolverDato(i)<<" ";
	}
	cout<<endl;
	/*cout<<arbol.cortar(100)<<endl;
	arbol.vaciarListas();
	arbol.inorden(arbol.getRaiz());
	orden = arbol.getin();
	for(i=1; i<=orden.getTam(); i++){
		cout<<orden.devolverDato(i)<<" ";
	}
	*/
	cout<<"Mostrando recorrido preorden: "<<endl;
	
	arbol.preorden(1);
	orden = arbol.getpre();
	cout<<"tamaño de orden: "<<orden.getTam()<<endl;
	//mostrando recorrido preorden
	for(i=1; i<=orden.getTam(); i++){
		cout<<orden.devolverDato(i)<<" ";
	}
	cout<<endl;
	
	
	cout<<"Mostrando recorrido posorden: "<<endl;
	
	arbol.posorden(1);
	orden = arbol.getpos();
	cout<<"tamaño de orden: "<<orden.getTam()<<endl;
	//mostrando recorrido preorden
	for(i=1; i<=orden.getTam(); i++){
		cout<<orden.devolverDato(i)<<" ";
	}
	cout<<endl;
	
	return 0;
}
