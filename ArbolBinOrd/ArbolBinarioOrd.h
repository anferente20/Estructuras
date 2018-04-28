#include <iostream>
using namespace std;
struct arbolito{
	int clave;
	int hijoIzq;
	int hijoDer;
};
class arbolBin{
	arbolito arbolitoBin[13];
	public:
		
		arbolBin(){
			arbolitoBin[0].clave = 0;
			arbolitoBin[0].hijoIzq = 1; 									//Se refiere a la cabeza
			for (int i=0; i<13; i++){									//Inicializa los hijos derechos como la posición del elemento siguiente
				arbolitoBin[i].hijoDer = i+1;
				arbolitoBin[i].clave = 0;
			}
			arbolitoBin[13].hijoDer = 0;
		}
		void insertarRaiz(int numero){							
			arbolitoBin[0].hijoDer = arbolitoBin[1].hijoDer;							
			arbolitoBin[1].clave = numero;
			arbolitoBin[1].hijoDer = 0;
			arbolitoBin[1].hijoIzq = 0;
		}
		void insertarElemento(int numero){
			int pos = 1, posAnt=1;
			int auxNum = arbolitoBin[0].hijoDer;
			
			arbolitoBin[0].hijoDer = arbolitoBin[auxNum].hijoDer;						
			arbolitoBin[auxNum].clave = numero;
			arbolitoBin[auxNum].hijoDer = 0;
			arbolitoBin[auxNum].hijoIzq = 0;
	
			while (pos!=0){
				posAnt=pos;
				arbolitoBin[pos];
				if (arbolitoBin[auxNum].clave > (arbolitoBin[pos].clave)){
					pos = arbolitoBin[pos].hijoDer;	
				}
				if (arbolitoBin[auxNum].clave < (arbolitoBin[pos].clave)){
					pos = arbolitoBin[pos].hijoIzq;	
				}
				
			}
			if (arbolitoBin[auxNum].clave > (arbolitoBin[posAnt].clave)){
				arbolitoBin[posAnt].hijoDer = auxNum;
			} else {
				arbolitoBin[posAnt].hijoIzq = auxNum;
			}
		}
		
		void mostrarInfo(){
			for (int i=1; i<14; i++){
				cout << "N: " << i << endl;
				cout << arbolitoBin[i].clave << endl;
				cout << arbolitoBin[i].hijoIzq << endl;
				cout << arbolitoBin[i].hijoDer << endl;
				cout << "----------------------------------" << endl;
			}
		}
};
