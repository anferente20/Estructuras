#include <iostream>
#include <string>
#include "listas2.h"
using namespace std;
template <typename T>
struct arbolito{
	T info;
	int cabHijo;
};
struct auxiliar{
	int yoSoy;
	int sig;
};
template <typename T>
class arbol{
	arbolito <T> **arregloInfo; //Arreglo con la info y la cab de los hijos
	auxiliar **arregloAux;	//Arreglo auxiliar con las posiciones de los hermanos
	int tam, auxArreglo;
	int posRaiz = 1;
	public:
		arbol(){
			arregloInfo = new arbolito <T>* [11];
			arregloAux = new auxiliar*[10];
			tam = 0;
			auxArreglo = 0;
		}
		bool arbolVacio(){
			if (tam==0){
				return true;
			} else {
				return false;
			}
		}
		
		void anadirRaiz(T infoRaiz){
			if (arbolVacio()){
				arbolito <T> *aux = new arbolito <T>;
				aux->info = infoRaiz;
				aux->cabHijo = 0;
				arregloInfo[++tam] = aux;	
			}	
		}
		
		void anadirHijo(int posPadre, T infoHijo){
			arbolito <T> *aux2 = arregloInfo[posPadre];		//Auxiliar con la info del padre
			arbolito <T> *aux = new arbolito <T>;			//Nuevo elemento del arbol
		
			aux->info = infoHijo;
			aux->cabHijo = 0;
			arregloInfo[++tam] = aux;						//Añade el elemento al arreglo principal
			
			auxArreglo++;
			arregloAux[auxArreglo] = new auxiliar;		//En esa posicion se crea una nueva estructura
			arregloAux[auxArreglo]->yoSoy = tam;		//Esa estructura guarda la posicion en la que está pero en el arreglo principal
			arregloAux[auxArreglo]->sig = 0;
			
			if (aux2->cabHijo==0){
				aux2->cabHijo = auxArreglo;				//La cabeza es la posicion del arreglo auxiliar
			} else {
				int pos = aux2->cabHijo;	
				while ((arregloAux[pos]->sig) != 0){	//Navega por la lista de hijos del padre hasta que encuentre el final, para añadir el nuevo hijo
					pos = arregloAux[pos]->sig;
				}
				arregloAux[pos]->sig = auxArreglo; 	
			}
		}
		int getTamElementos(){
			return tam;
		}
		
		Lista <T> mostrarHijos(int posPadre){		//Este metodo muestra todos los hijos de un padre
			Lista <T> auxiliar;
			int pos, posReal;
			pos = arregloInfo[posPadre]->cabHijo;
			while ((arregloAux[pos]->sig) != 0){	//Navega por la lista de hijos del padre hasta que encuentre el final, para añadir el nuevo hijo a una lista
					posReal = arregloAux[pos]->yoSoy;
					auxiliar.anadirFin(arregloInfo[posReal]->info);
					pos = arregloAux[pos]->sig;
			}
			posReal = arregloAux[pos]->yoSoy;
			auxiliar.anadirFin(arregloInfo[posReal]->info);
			return auxiliar;
		}
		Lista <T> mostrarTodos(){
			Lista <T> auxiliar;
			int j;
			for(j=1; j<=tam; j++){
				auxiliar.anadirFin(arregloInfo[j]->info);
			} 
			return auxiliar;
		}		
};
