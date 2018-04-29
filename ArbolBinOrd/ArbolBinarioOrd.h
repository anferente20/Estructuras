#include <iostream>
#include"listas.h"
using namespace std;
struct arbolito{
	int clave;
	int hijoIzq;
	int hijoDer;
};
class arbolBin{
	arbolito arbolitoBin[13];
	Lista<int> in;
	public:
		
		arbolBin(){
			for (int i=0; i<13; i++){										//Inicializa los hijos derechos como la posición del elemento siguiente
				arbolitoBin[i].hijoDer = i+1;
				arbolitoBin[i].clave = 0;
				arbolitoBin[i].hijoIzq = 0;
			}
			arbolitoBin[0].clave = 0;
			arbolitoBin[0].hijoIzq = 1; 									//Se refiere a la cabeza
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
			while(pos!=0){
				posAnt=pos;
				if (numero >  arbolitoBin[posAnt].clave){
					pos = arbolitoBin[posAnt].hijoDer;
				} else {
					pos = arbolitoBin[posAnt].hijoIzq;
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
		
		void inorden(int raiz){
			int ayuda ;
			int izq = arbolitoBin[raiz].hijoIzq;
			int der = arbolitoBin[raiz].hijoDer;
			if(izq != 0){
				inorden(arbolitoBin[raiz].hijoIzq);
			}
			ayuda = arbolitoBin[raiz].clave;
			cout<<ayuda<<" ";
			if(der !=0){
				inorden(arbolitoBin[raiz].hijoDer);
			}		
		}	
		
};
