#include "string"
#include<cstring>
#include "listas.h"
#include <iostream>
using namespace std;
struct estudiante{
	char nombre[8] ;
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
				insertarN(e);
				
				est[tam+1] = e;
				tam++;
			}
			else{				
				e->sigC = 0;
				e->sigN = 0;
				e->sigE = 0;
				e->sigH = 0;
				cab[1] = e;
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
		//Insertar Nombre
		void insertarN(estudiante *e){
			estudiante *aux = e;
			estudiante *temp;
			int pos;
			if(tam == 0 ){
				cab[1] = aux;
			}
			else{
				temp = cab[1];
				while(temp->sigN != 0){
					if(strcmp(est[temp->sigN]->nombre,aux->nombre)==-1){
						temp = est[temp->sigN];
					}
				}
				aux->sigN = temp->sigN;
				temp->sigN  = tam+1;	
			}
		}
		//Insertar Edad
	/**	void insertarE(estudiante *e){
			cout<<"hola aca estoy insertando edad"<<endl;
			estudiante *aux;
			estudiante *aux1;
			bool si = false;
			int pos, i;
			for(i = 1; i<=tam; i++){
				aux = est[i];
				pos=aux->sigE;
				if( aux->edad < e->edad){
					si = true;
					int j=1;
					while(j<tam){
						if(e->edad > est[j]->edad){
							j++;
						}
						if((e->edad < est[j]->edad)){
							break;
						}
					}
					cout<<"j :"<<j<<endl;
					e->sigE = j;
					cout<<"edad: "<<e->edad<<" "<<"cuanto es sigE : "<<e->sigE<<endl;
					cout<<"edad anterior: "<<est[i]->edad<<" "<<"cuanto es sigE : "<<est[i]->sigE<<endl;
					cab[1] = e;					
					break;	
					//cout<<"hola"<<endl;																												
				}					
				if(aux->edad >= e->edad){	
					pos = est[i]->sigE;
					int j=1;
					while(j<tam){
						if(e->edad < est[j]->edad){
							j++;
						}
						if((e->edad > est[j]->edad)){
							break;
						}
					}
					cout<<"j :"<<j<<endl;
					
					est[i]->sigE++;
					cout<<"edad: "<<est[i]->edad<<" "<<"cuanto es sigE: "<<est[i]->sigE<<endl;
					e->sigE = i;	
					cout<<"edad: "<<e->edad<<" "<<"cuanto es sigE de e : "<<e->sigE<<endl;
					break;							
				}							
			}	
					
			/*if(si == false){
				e->sigE = 0;
				cab[1] = e;			
			}
		}
		**/
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
		
		Lista<estudiante*> mostrarN(){
			Lista<estudiante*> aux1;
			estudiante *aux = cab[1];
			while(aux->sigN != 0){
				aux1.anadirFin(aux);
				aux =  est[aux->sigN];
			}
			return aux1;
		}
		Lista<estudiante*> mostrarE(){
			Lista<estudiante*> aux1;
			estudiante *aux;
			int pos=-1;
			aux = cab[1];
			aux1.anadirCabeza(aux);
			pos =  aux->sigE;
			cout<<"edad: "<<aux->edad<<endl;
			cout<<"sig: "<<aux->sigE<<endl;
			
			while(pos>0){
				if(est[1]->sigE > 0){
					aux = est[aux->sigE+1];   // mas 1 o normal
				}else{
					aux = est[aux->sigE];   // mas 1 o normal
				}				
				cout<<"sig: "<<aux->sigE<<endl;
				pos = aux->sigE;
				aux1.anadirFin(aux);
			}
			return aux1;
		}
		
	
};
