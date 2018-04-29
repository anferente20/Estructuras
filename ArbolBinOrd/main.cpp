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
	return 0;
}
