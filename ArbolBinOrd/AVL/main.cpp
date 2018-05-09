#include <iostream>
#include "avl.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	AVL<int> arbol;
	arbol.insertarRaiz(90);
	arbol.insertarElemento(138);
	arbol.insertarElemento(100);

	arbol.mostrarInfo();
	return 0;
}
