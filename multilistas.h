#include <string.h>
#include "listas.h"
#include <iostream>
using namespace std;
struct estudiante{
	char *nombre  ;
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
				cout<<est[1]->nombre<<" "<<est[1]->edad<<endl;
				insertarN(e);
				cout<<est[1]->nombre<<" "<<est[1]->edad<<endl;
				insertarE(e);
				cout<<tam<<endl;
				cout<<est[1]->nombre<<" "<<est[1]->edad<<endl;
				est[tam+1] = e;
				cout<<est[2]->nombre<<" "<<est[2]->edad<<endl;
				tam++;
			}
			else{				
				e->sigC = 0;
				e->sigN = 0;
				e->sigE = 0;
				e->sigH = 0;
				anadirIC(e);
				anadirIH(e);
				insertarN(e);
				cab[9] = e;
				est[1] = e;
				tam++;
			}
		}
		int getTam(){
			return tam;
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
		//Insertar Nombre
		void insertarN(estudiante *e){
			estudiante *aux = e;
			estudiante *temp;
			int pos;
			if(tam == 0 ){
				cab[0] = aux;
			}
			else{
				
				temp = cab[0];
				if(strcmp(cab[0]->nombre,aux->nombre)==1){
					
					for(int i = 1;i<=tam;i++){
						if(strcmp(cab[0]->nombre,est[i]->nombre)==0){
							pos = i;
						}
					}
					
					aux->sigN = pos;
					
					cab[0] = aux;	
				}	
				else{
					while(temp->sigN != 0){
					if(strcmp(est[temp->sigN]->nombre,aux->nombre)==-1){
						temp = est[temp->sigN];
					}
					else{
						break;
					}
				}
				aux->sigN = temp->sigN;
				temp->sigN  = tam+1;
				}
			}
		}
		//Insertar Edad
		void insertarE(estudiante *e){
			estudiante *aux;
			bool si = false;
			int pos, i;

			for(i = 1; i<=tam; i++){

				aux = est[i];
				pos = aux->sigE;
				if (cab[9]==aux){ 
					if (cab[9]->edad <= e->edad){
						e->sigE = i;
						cab[9] = e;
						si=true;
						break;
					} 
					if (cab[9]->edad > e->edad){
				
						while (e->edad <= aux->edad && e->edad <= est[aux->sigE]->edad && aux->sigE != 0){

								aux = est[aux -> sigE];
								pos = aux -> sigE;
									
						}	
						e->sigE = aux->sigE;
						aux->sigE = tam+1;						
						break;		
					}
				break;	
				} 																										
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
				cab[1] = e;
			}
			if(e->carrera.compare("Electrica")==0){
				cab[2]= e;
			}
			if(e->carrera.compare("Sistemas")==0){
				cab[3] = e;
			}
			if(e->carrera.compare("Industrial")==0){
				cab[4] = e;
			}
		}
		
		Lista<estudiante*> mostrarC(string carrera){
			Lista<estudiante*> aux1 ;
			estudiante *aux;
			int pos=-1;
			if(carrera.compare("Catastral")==0){
				aux=cab[1];
				aux1.anadirCabeza(cab[2]);
			}
			if(carrera.compare("Electrica")==0){
				aux=cab[2];
				aux1.anadirCabeza(cab[3]);
			}
			if(carrera.compare("Sistemas")==0){
				aux=cab[3];
				cout<<aux->sigC<<endl;
				aux1.anadirCabeza(cab[4]);
			}
			if(carrera.compare("Industrial")==0){
				aux=cab[4];
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
				aux=cab[5];
				aux1.anadirCabeza(aux);
			}
			if(hobby.compare("Natacion")==0){
				aux=cab[6];
				aux1.anadirCabeza(aux);
				
			}
			if(hobby.compare("Basquet")==0){
				aux=cab[7];
				aux1.anadirCabeza(aux);
			}
			if(hobby.compare("Beisbol")==0){
				aux=cab[8];
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
		
		Lista<estudiante*> mostrarN(){
			Lista<estudiante*> aux1;
			estudiante *aux = cab[0];
			aux1.anadirCabeza(aux);
			while(aux->sigN != 0){
				aux  = est[aux->sigN];
				aux1.anadirFin(aux);
			}
			return aux1;
		}
		Lista<estudiante*> mostrarE(){
			Lista<estudiante*> aux1;
			estudiante *aux;
			int pos;
			aux = cab[10];
			aux1.anadirCabeza(aux);
			pos =  aux->sigE;
			while(pos!=0 && pos<=tam){
				aux = est[aux->sigE];
				pos = aux->sigE;
				aux1.anadirFin(aux);
			}
			return aux1;
		}
		
	
};
