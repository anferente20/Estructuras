#include <iostream>
#include<string.h>
#include"listas.h"
#include "pila.h"
using namespace std;
template<class T>
struct arbolito{
	T clave;
	int hijoIzq;
	int hijoDer;
	int Fe;
};
template<class T>
class AVL{
	arbolito<T> arbolitoBin[14];      //ACA LO ARREGLE ANTES ESTABA EN 13 Y AHORA 14 CON ESO SE SOLUCIONA
	Lista<T> in;
	Lista<T> pre;
	Lista<T> pos;
	int tam;
	public:
		
		AVL(){
			for (int i=0; i<13; i++){	
				tam = 0;									//Inicializa los hijos derechos como la posici�n del elemento siguiente
				arbolitoBin[i].hijoDer = i+1;
				arbolitoBin[i].clave = 0;
				arbolitoBin[i].hijoIzq = 0;
				arbolitoBin[i].Fe = 0;
			}
			arbolitoBin[0].clave = 0;
			arbolitoBin[0].hijoIzq = 1; 									//Se refiere a la cabeza
			arbolitoBin[13].hijoDer = 0;									
		}
		
		void insertarRaiz(T numero){							
			arbolitoBin[0].hijoDer = arbolitoBin[1].hijoDer;							
			arbolitoBin[1].clave = numero;
			arbolitoBin[1].hijoDer = 0;
			arbolitoBin[1].hijoIzq = 0;
		}
		
		void vaciarListas(){
			in.vaciar();
			pre.vaciar();
			pos.vaciar();			
		}
		
		//Funci�n para calcular altura
		int altura(arbolito <T> rama){
			if(rama.hijoIzq==0&&rama.hijoDer==0){
				return 0;
			}
			else{
				int aDer;
				int aIzq;
				if(rama.hijoDer==0||rama.hijoIzq==0){
					if(rama.hijoDer==0&&rama.hijoIzq!=0){
						return altura(arbolitoBin[rama.hijoIzq])+1;
					}
					else if(rama.hijoIzq==0&&rama.hijoDer!=0){
						return altura(arbolitoBin[rama.hijoDer])+1;
					}		
				}
				else {
					aDer=altura(arbolitoBin[rama.hijoDer]);
					aIzq=altura(arbolitoBin[rama.hijoIzq]);
					if(aIzq>aDer){
						return aIzq+1;
					}
					else{
						return aDer+1;
					}			
				}			
			}
		}
		
		//Calcula desequilibrio
		int desequilibrio(arbolito <T> rama){
				if(rama.hijoDer==0 && rama.hijoIzq==0){
					
					return 0;
				}
				else{
				
					if(rama.hijoDer==0 && rama.hijoIzq!=0){
						
						return 0-(altura(arbolitoBin[rama.hijoIzq])+1);
					}
				
					else if(rama.hijoIzq == 0 && rama.hijoDer!=0){
						return (altura(arbolitoBin[rama.hijoDer])+1);
					}
					else {
						int aDer,aIzq;
						aDer = altura(arbolitoBin[rama.hijoDer])+1;
						aIzq = altura(arbolitoBin[rama.hijoIzq])+1;
						return aDer-aIzq;
					
					}
				}
		}
		void insertarElemento(T numero){
			int pos = arbolitoBin[0].hijoIzq, posAnt=1;
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
			tam++;
			//Se asignan desequilibrios
			for(int i = 1;i<=tam;i++){
				arbolitoBin[i].Fe = desequilibrio(arbolitoBin[i]);
			}
			for(int i = tam;i>=1;i--){
				if(arbolitoBin[i].Fe == 2){
					if(arbolitoBin[arbolitoBin[i].hijoDer].Fe > 0){
						cout << "Simple izq" << endl;
						rotacionSimpleIzquierda(i);
					}
					else{
						cout << "Doble izq" << endl;
						rotacionDobleIzquierda(i);
					}
				}
				else if(arbolitoBin[i].Fe == -2){
					if(arbolitoBin[arbolitoBin[i].hijoIzq].Fe > 0){
						cout << "Doble  der" << endl;
						rotacionDobleDerecha(i);
					}
					else{
						cout << "Simple der" << endl;
						rotacionSimpleDerecha(i);
					}
				}
			}		
		}
		int max (int izq, int der){
			if (izq>der){
				return izq;
			} else{
				return der;
			}
		}
		
		int rotacionSimpleIzquierda(int rama){
			int aux = arbolitoBin[rama].hijoDer;
			arbolitoBin[rama].hijoDer = arbolitoBin[aux].hijoIzq;
			arbolitoBin[aux].hijoIzq = rama;
			if (arbolitoBin[rama].clave == arbolitoBin[arbolitoBin[0].hijoIzq].clave){
				arbolitoBin[0].hijoIzq = aux;
			} 
			for(int i = 1;i<=tam;i++){
				arbolitoBin[i].Fe = desequilibrio(arbolitoBin[i]);
			}
			return aux;
		}
		int rotacionSimpleDerecha(int rama){
			int aux = arbolitoBin[rama].hijoIzq;
			arbolitoBin[rama].hijoIzq = arbolitoBin[aux].hijoDer;
			arbolitoBin[aux].hijoDer = rama;
			if (arbolitoBin[rama].clave == arbolitoBin[arbolitoBin[0].hijoIzq].clave){
				arbolitoBin[0].hijoIzq = aux;
			}
			for(int i = 1;i<=tam;i++){
				arbolitoBin[i].Fe = desequilibrio(arbolitoBin[i]);
			}

			return aux;
		}
		
		int rotacionDobleIzquierda(int rama){
			int aux = rama;
			arbolitoBin[aux].hijoDer =  rotacionSimpleDerecha(arbolitoBin[aux].hijoDer);
			return rotacionSimpleIzquierda(aux);
			
		}
		
		int rotacionDobleDerecha(int rama){
			int aux = rama;
			arbolitoBin[aux].hijoIzq =  rotacionSimpleIzquierda(arbolitoBin[aux].hijoIzq);
			return rotacionSimpleDerecha(aux);
		}
		
		int getRaiz(){
			return arbolitoBin[0].hijoIzq;
		}
		
		void mostrarInfo(){
			for (int i=1; i<=tam+1; i++){
				cout << "N: " << i << endl;
				cout << arbolitoBin[i].clave << endl;
				cout << arbolitoBin[i].hijoIzq << endl;
				cout << arbolitoBin[i].hijoDer << endl;
				cout << arbolitoBin[i].Fe<<endl; 
				cout << "----------------------------------" << endl;
			}
		}
		
		
		void inorden(int raiz){						
			pila<T> pilo;
			int aux = raiz;
			while (aux != 0){
				pilo.Push(aux);
				aux = arbolitoBin[aux].hijoIzq;
			}				
			int aux2 ;
			while (!pilo.PilaVacia()){
				aux2 = pilo.Pop();
				in.anadirFin(arbolitoBin[aux2].clave);
				if (arbolitoBin[aux2].hijoDer != 0){
					inorden(arbolitoBin[aux2].hijoDer);
				}
				
			}										
		}
		
		void preorden(int raiz){
			pila<T> pilo;
			int aux = raiz;
			do{
				if(aux!= 0){
				//	cout<<"a�ade: "<<arbolitoBin[aux].clave<<endl;
					pre.anadirFin(arbolitoBin[aux].clave);
					//mostrar, guardar en la lista para eso 
					pilo.Push(aux);
					aux = arbolitoBin[aux].hijoIzq;
				}else if(!pilo.PilaVacia()){
					aux = pilo.Pop();
					
					aux = arbolitoBin[aux].hijoDer;
				}
			}while(!pilo.PilaVacia() || aux != 0);	
		}
		
		void posorden(int raiz){
			pila<T> pilo;
			int aux = raiz;
			while (aux != 0){
				pilo.Push(aux);
				aux = arbolitoBin[aux].hijoIzq;
			}				
			int aux2 ;
			while (!pilo.PilaVacia()){
				aux2 = pilo.Pop();
				if (arbolitoBin[aux2].hijoDer != 0){
					posorden(arbolitoBin[aux2].hijoDer);
				}
				pos.anadirFin(arbolitoBin[aux2].clave);
			}
			/*
			int aux2;
			do{
				if(aux!=0){
					pilo.Push(aux);
					aux = arbolitoBin[aux].hijoIzq;
				}
				if (!pilo.PilaVacia()){
					aux2 = pilo.Pop();
					if(arbolitoBin[aux2].hijoDer != 0){
						posorden(arbolitoBin[aux].hijoDer);
					}
					pos.anadirFin(arbolitoBin[aux2].clave);
					
				}
			}while(aux!=0 || !pilo.PilaVacia());
			*/				
		}
		
		Lista<T> getin(){
			return in;
		}
		Lista<T> getpre(){
			return pre;
		}	
		Lista<T> getpos(){
			return pos;
		}
		
		void eliminar(T valor){
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
			
			//Caso Raz�z
			if(valor == arbolitoBin[0].hijoIzq){
				
			}
			//Liberar Espacio
			arbolitoBin[hijo].clave = 0;
			arbolitoBin[hijo].hijoIzq = 0;
			arbolitoBin[hijo].hijoDer = arbolitoBin[0].hijoDer;
			arbolitoBin[0].hijoDer = hijo;
			
		}
		 bool pertenece(T valor){
		 	bool aux = false;
			for(int i =1;i<in.getTam();i++){
				if(valor == in.devolverDato(i))
					aux = true;
			}
			return aux;
		 }		
		
		string cortar(T valor){
			string aux = "El elemento no pertenece al arbol.";
			if(pertenece(valor) == true){
				eliminar(valor);
				aux = "Se elimino el elemento.";
			}
			return aux;
		}		
		
		
};
