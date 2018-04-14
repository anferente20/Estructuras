#include "string"
#include "listas.h"
#include <iostream>
using namespace std;
struct estudiante{
	string nombre;
	string carrera;
	string hobby;
	int edad;
	
	int sigN = 0,sigC = 0 ,sigH = 0 ,sigE = 0;	
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
			if(estaLlena()){
				insertarC(e);
				insertarH(e);
				est[tam+1] = e;
				tam++;
			}
			else{
				e->sigC = 0;
				e->sigN = 0;
				e->sigE = 0;
				e->sigH = 0;
				anadirIC(e);
				anadirIH(e);
				est[1] = e;
				tam++;
			}
		}
		
		//Insertar Carrera
		void insertarC(estudiante *e){
			estudiante *aux;
			bool si = false;
			int pos, i;
			for(i = 1;i<=tam;i++){
				aux = est[i];
				pos=aux->sigC;
				if(aux->carrera.compare(e->carrera)==0){
					while(pos!=0 && pos<=tam){
						aux = est[aux->sigC];
						pos = aux->sigC;
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
		
		//Insertar Hobby
		void insertarH(estudiante *e){
			estudiante *aux;
			bool si = false;
			int pos, i;
			for(i = 1;i<=tam;i++){
				aux = est[i];
				pos=aux->sigH;
				if(aux->hobby.compare(e->hobby)==0){
					si = true;
					e->sigH = i;
					anadirIH(e); 					
					break;
				}
			}
			if(si == false){
				anadirIH(e);
			}
		}
		void anadirIH(estudiante *e){
			if(e->hobby.compare("Danza")==0){
				cab[6] = e;
			}
			if(e->hobby.compare("Natacion")==0){
				cab[7]= e;
			}
			if(e->hobby.compare("Basquet")==0){
				cab[8] = e;
			}
			if(e->hobby.compare("Beisbol")==0){
				cab[9] = e;
			}
				
		}
		
		void anadirIC(estudiante *e){
			if(e->carrera.compare("Catastral")==0){
				cab[2] = e;
			}
			if(e->carrera.compare("Electrica")==0){
				cab[3]= e;
			}
			if(e->carrera.compare("Sistemas")==0){
				cab[4] = e;
			}
			if(e->carrera.compare("Industrial")==0){
				cab[5] = e;
			}
		}
		
		Lista<estudiante*> mostrarC(string carrera){
			Lista<estudiante*> aux1 ;
			estudiante *aux;
			int pos=-1;
			if(carrera.compare("Catastral")==0){
				aux=cab[2];
				aux1.anadirCabeza(cab[2]);
			}
			if(carrera.compare("Electrica")==0){
				aux=cab[3];
				aux1.anadirCabeza(cab[3]);
			}
			if(carrera.compare("Sistemas")==0){
				aux=cab[4];
				cout<<aux->sigC<<endl;
				aux1.anadirCabeza(cab[4]);
			}
			if(carrera.compare("Industrial")==0){
				aux=cab[5];
				aux1.anadirCabeza(cab[5]);
			}
			
			while(pos!=0){
				aux = est[aux->sigC];
				pos = aux->sigC;
				aux1.anadirFin(aux);
			}
			return aux1;
		}
		
		Lista<estudiante*> mostrarH(string hobby){
			Lista<estudiante*> aux1 ;
			estudiante *aux;
			int pos;
			if(hobby.compare("Danza")==0){
				aux=cab[6];
				aux1.anadirCabeza(aux);
			}
			if(hobby.compare("Natacion")==0){
				aux=cab[7];
				aux1.anadirCabeza(aux);
				
			}
			if(hobby.compare("Basquet")==0){
				aux=cab[8];
				aux1.anadirCabeza(aux);
			}
			if(hobby.compare("Beisbol")==0){
				aux=cab[9];
				aux1.anadirCabeza(aux);
			}
			pos =  aux->sigH;
			while(pos!=0){
				aux = est[aux->sigH];
				pos = aux->sigH;
				aux1.anadirFin(aux);
			}
			return aux1;
		}
		
	
};
