#include <iostream>
#include<string.h>
#include"listas.h"
using namespace std;
struct arbolito{
	int clave;
	int hijoIzq;
	int hijoDer;
};
class arbolBin{
	arbolito arbolitoBin[14];      //ACA LO ARREGLE ANTES ESTABA EN 13 Y AHORA 14 CON ESO SE SOLUCIONA
	Lista<int> in;
	Lista<int> pre;
	Lista<int> pos;
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
		void vaciarListas(){
			in.vaciar();
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
		int getRaiz(){
			return arbolitoBin[0].hijoIzq;
		}
		void mostrarInfo(){
			for (int i=0; i<=13; i++){
				cout << "N: " << i << endl;
				cout << arbolitoBin[i].clave << endl;
				cout << arbolitoBin[i].hijoIzq << endl;
				cout << arbolitoBin[i].hijoDer << endl;
				cout << "----------------------------------" << endl;
			}
		}
		void inorden(int raiz){
			if(arbolitoBin[raiz].hijoIzq != 0 ){
				
				inorden(arbolitoBin[raiz].hijoIzq);
			}
			if(arbolitoBin[raiz].clave!=0){
				in.anadirFin(arbolitoBin[raiz].clave);	

			}
				
			if(arbolitoBin[raiz].hijoDer != 0 ){
				
				inorden(arbolitoBin[raiz].hijoDer);
			}	
				
		}
		void preorden(int raiz){
			pre.anadirFin(arbolitoBin[raiz].clave);
			//cout<<arbolitoBin[raiz].clave<<" ";
			if(arbolitoBin[raiz].hijoIzq != 0 ){				
				preorden(arbolitoBin[raiz].hijoIzq);
			}										
			if(arbolitoBin[raiz].hijoDer != 0 ){				
				preorden(arbolitoBin[raiz].hijoDer);
			}	
		}
		void posorden(int raiz){
						
			if(arbolitoBin[raiz].hijoIzq != 0 ){				
				posorden(arbolitoBin[raiz].hijoIzq);
			}										
			if(arbolitoBin[raiz].hijoDer != 0 ){				
				posorden(arbolitoBin[raiz].hijoDer);
			}	
			pos.anadirFin(arbolitoBin[raiz].clave);
			//cout<<arbolitoBin[raiz].clave<<" ";
		}	
		Lista<int> getin(){
			return in;
		}
		Lista<int> getpre(){
			return pre;
		}	
		Lista<int> getpos(){
			return pos;
		}
		
		void eliminar(int valor){
			int padre = 0;
			int hijo = arbolitoBin[padre].hijoIzq;
			int padre1,hijo1;
			//Busca los valores del padre y del hijo
			int aux;
			while( arbolitoBin[hijo].clave != valor ){
				if( arbolitoBin[hijo].clave > valor){
					aux = arbolitoBin[hijo].hijoIzq;
					padre = hijo;
					hijo = aux; 
				}
				else{
					aux = arbolitoBin[hijo].hijoDer;
					padre = hijo;
					hijo = aux; 
				}
			}	
			//Eliminar hoja
			if(arbolitoBin[hijo].hijoIzq == 0 && arbolitoBin[hijo].hijoDer == 0){
				if(arbolitoBin[padre].clave < arbolitoBin[hijo].clave ){
					arbolitoBin[padre].hijoDer = 0;
				}
				else{
					arbolitoBin[padre].hijoIzq = 0;
				}
			}
			//eliminar nodo con un hijo
			else if ((arbolitoBin[hijo].hijoIzq != 0 && arbolitoBin[hijo].hijoDer == 0) ||(arbolitoBin[hijo].hijoIzq == 0 && arbolitoBin[hijo].hijoDer != 0)){
				if(arbolitoBin[padre].clave < arbolitoBin[hijo].clave){
					if(arbolitoBin[hijo].hijoIzq == 0){
						arbolitoBin[padre].hijoDer = arbolitoBin[hijo].hijoDer;
					}
					else{
						arbolitoBin[padre].hijoDer = arbolitoBin[hijo].hijoIzq;
					}
				}else{
					if(arbolitoBin[hijo].hijoIzq == 0){
						arbolitoBin[padre].hijoIzq = arbolitoBin[hijo].hijoDer;
					}
					else{
						arbolitoBin[padre].hijoIzq = arbolitoBin[hijo].hijoIzq;
					}
				}
			}
			//Eliminar nodo con 2 hijos
			if(arbolitoBin[hijo].hijoIzq != 0 && arbolitoBin[hijo].hijoDer != 0){
				padre1 = hijo;
				hijo1 =arbolitoBin[hijo].hijoDer;
				
				// Se busca padre1 e hijo1 
				while(arbolitoBin[hijo1].hijoIzq != 0){
					aux = arbolitoBin[hijo1].hijoIzq;
					padre1 = hijo1;
					hijo1 = aux;
				}	
				//Desconectar padre1 e hijo1
				if(arbolitoBin[padre1].clave < arbolitoBin[hijo1].clave){
					arbolitoBin[padre1].hijoDer = 0;
				}else{
					arbolitoBin[padre1].hijoIzq = 0;
				}
				
				if(arbolitoBin[hijo1].hijoDer != 0){
					arbolitoBin[padre1].hijoIzq = arbolitoBin[hijo1].hijoDer;
					arbolitoBin[hijo1].hijoDer = 0;
				}
				//conectar padre con Hijo1
				if (padre == 0){
					//Caso raiz
					arbolitoBin[0].hijoIzq = hijo1;
				}
				else{
					if(arbolitoBin[padre].clave < arbolitoBin[hijo1].clave){
						arbolitoBin[padre].hijoDer = hijo1;
					}else{
						arbolitoBin[padre].hijoIzq = hijo1;
					}	
				}
				
				//reemplazo hijo con hijo1
				arbolitoBin[hijo1].hijoIzq = arbolitoBin[hijo].hijoIzq;
				arbolitoBin[hijo1].hijoDer = arbolitoBin[hijo].hijoDer;
			}
			
			//Caso Razíz
			if(valor == arbolitoBin[0].hijoIzq){
				
			}
			//Liberar Espacio
			arbolitoBin[hijo].clave = 0;
			arbolitoBin[hijo].hijoIzq = 0;
			arbolitoBin[hijo].hijoDer = arbolitoBin[0].hijoDer;
			arbolitoBin[0].hijoDer = hijo;
			
		}
		 bool pertenece(int valor){
		 	bool aux = false;
			for(int i =1;i<in.getTam();i++){
				if(valor == in.devolverDato(i))
					aux = true;
			}
			return aux;
		 }		
		
		string cortar(int valor){
			string aux = "El elemento no pertenece al arbol.";
			if(pertenece(valor) == true){
				eliminar(valor);
				aux = "Se elimino el elemento.";
			}
			return aux;
		}		
};
