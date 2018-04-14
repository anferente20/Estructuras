#include "string"
#include "listas.h"
#include <iostream>
using namespace std;
struct estudiante{
	string nombre;
	string carrera;
	string hobby;
	int edad;
	
	int sigN,sigC,sigH,sigE;	
};

class multilista{
	//Arreglo de cabezas
	estudiante **cab;
	//datos
	int tam;
	//arreglo de datos
	estudiante **est;
	
	public:
		multilista(){
			cab = new estudiante*[9];
			est = new estudiante*[11];
			tam = 0;
		}
		//Funcion vacia
		bool estaLlena(){
			if(tam == 0)
				return false;
			else
				return true;
		}
		
		//Insertar
		void insertar(estudiante *e){
			estudiante *aux  = e;
			if(estaLlena()){
				insertarC(e);
				est[tam+1] = aux;
				tam++;
			}
			else{
				aux->sigC = 0;
				aux->sigN = 0;
				aux->sigE = 0;
				aux->sigH = 0;
				est[1] = aux;
				anadirIC(e);
				tam++;
			}
		}
		
		//Insertar Carrera
		void insertarC(estudiante *e){
			estudiante *aux ;
			bool si = false;
			int q, i=1;
			estudiante  *temp = e;
			/**
			aux = est[i];
			q=aux->sigC;
			while (aux->carrera.compare(temp->carrera)!=0 && i<=tam && q!=0){
					aux = est[aux->sigC];
					q = aux->sigC;
			}
			if(i==tam){
				anadirIC(e);
			} else {
				
			}
			
			*/
			
			for(i = 1;i<=tam;i++){
				aux = est[i];
				q=aux->sigC;
				if(aux->carrera.compare(temp->carrera)==0){
					while(q!=0 && q<=tam){
						aux = est[aux->sigC];
						q = aux->sigC;
					}
					aux->sigC = tam+1;
					si = true;
					break;
				}
			}
			if(si == false){
				anadirIC(e);
			}
		}
		void anadirIC(estudiante *e){
			estudiante *aux = e;
			if(e->carrera.compare("Catastral")==0){
				cab[2] = aux;
			}
			if(e->carrera.compare("Electrica")==0){
				cab[3]= aux;
			}
			if(e->carrera.compare("Sistemas")==0){
				cab[4] = aux;
			}
			if(e->carrera.compare("Industrial")==0){
				cab[5] = aux;
			}
		}
		Lista<estudiante*> mostrarC(string carrera){
			Lista<estudiante*> aux1 ;
			estudiante *aux;
			if(carrera.compare("Catastral")==0){
				aux = cab[2];
			}
			if(carrera.compare("Electrica")==0){
				aux = cab[3];
			}
			if(carrera.compare("Sistemas")==0){
				aux = cab[4];
			}
			if(carrera.compare("Industrial")==0){
				aux = cab[5];
			}
			
			aux1.anadirFin(aux);
			
		}
	
};
