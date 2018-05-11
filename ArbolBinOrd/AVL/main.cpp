#include <iostream>
#include "avl.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	AVL<int> arbol;
	arbol.insertarRaiz(10);
	arbol.insertarElemento(20);
	arbol.insertarElemento(30);
	arbol.insertarElemento(40);
	arbol.insertarElemento(50);
//	arbol.insertarElemento(60);
//	arbol.insertarElemento(10);
	arbol.mostrarInfo();
	return 0;
}
