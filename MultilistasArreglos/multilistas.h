#include <string.h>
#include "listas.h"
#include <iostream>
using namespace std;
struct estudiante{
	char *nombre;
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
			cab = new estudiante*[10];
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
				insertarE(e);
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
				insertarN(e);
				cab[10] = e;
				est[1] = e;
				cout<<e->sigC<<endl;
				tam++;
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
			estudiante *auxCab , *aux;
			bool si = false;
			int pos, i;
			if(e->hobby.compare("Danza")==0){
				auxCab = cab[6];
				pos=6;
			}
			if(e->hobby.compare("Natacion")==0){
				auxCab = cab[7];
				pos=7;
			}
			if(e->hobby.compare("Basquet")==0){
				auxCab = cab[8];
				pos=8;
			}
			if(e->hobby.compare("Beisbol")==0){
				auxCab = cab[9];
				pos=9;
			}
			//anadirIH(e);
			for(i = 1;i<=tam;i++){
				aux = est[i];
				//pos=aux->sigH;
				if(auxCab == aux){
					e->sigH=i;
					cab[pos]=e;
					break;
				}
				
			}
			if(si == false){
				anadirIH(e);
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
				if (cab[10]==aux){ 
					if (cab[10]->edad <= e->edad){
						e->sigE = i;
						cab[10] = e;
						si=true;
						break;
					} 
					if (cab[10]->edad > e->edad){
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
			int pos;
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
			pos = aux->sigC;
			while(pos!=0 && pos<=tam){
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
			while(pos!=0 && pos<=tam){
				aux = est[aux->sigH];
				pos = aux->sigH;
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
		int getTam(){
			return tam;
		}
		
		void Borrar(char* nombre){
			int pos;
			int i;
			Lista<estudiante *> aux;
			for(i = 1;i<=tam;i++){
				if(strcmp(est[i]->nombre,nombre)==0){
					pos = i;
					break;
				}
			}	
			for(i = 1;i<= tam;i++){
				if(i!=pos){
					est[i]->sigN =0;
					est[i]->sigE =0;
					est[i]->sigH =0;
					est[i]->sigC =0;
					aux.anadirFin(est[i]);
				}
			}
			tam=0;
			delete est;
			est = new estudiante*[11];
			for(i=1;i<=aux.getTam();i++){
				insertar(aux.devolverDato(i));

			}
		}
		
		void Modificar(char* nombre, estudiante* esti){
			int pos;
			int i;
			Lista<estudiante *> aux;
			for(i = 1;i<=tam;i++){
				if(strcmp(est[i]->nombre,nombre)==0){
					pos = i;
					break;
				}
			}	
			for(i = 1;i<= tam;i++){
				if(i==pos){
					est[i]->nombre = esti->nombre;
					est[i]->edad = esti->edad;
					est[i]->carrera = esti->carrera;
					est[i]->hobby = esti->hobby;	
				}
				est[i]->sigN =0;
				est[i]->sigE =0;
				est[i]->sigH =0;
				est[i]->sigC =0;
				aux.anadirFin(est[i]);
			}
			tam=0;
			delete est;
			est = new estudiante*[11];
			for(i=1;i<=aux.getTam();i++){
				insertar(aux.devolverDato(i));

			}
		}
};

