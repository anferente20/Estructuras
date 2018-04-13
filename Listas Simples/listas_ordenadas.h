#include <string>
/**
Listas Ordenadas
**/
using namespace std;
struct elemento{
	long long x;
	string info;
	elemento *sig;	
};
using namespace std;
class Lista_ordenada{
		elemento *cab,*fin, *cabcen, *fincen;
		int tam;
	
	public:
		Lista_ordenada(){
			//nuevo
			cab = new elemento;
			fin = new elemento;
			cabcen = new elemento;      //centinela para la cabeza
			fincen = new elemento; 	 //centinela para el fin
			//nuevo
			cab=cabcen;			
			cabcen->sig = fincen;
			fin=fincen;
			tam=0;
		}
		bool estaVacia(){
			if(tam ==0)
				return true;
			else
				return false;
		}
		
		void anadirFin(elemento *a){
			elemento *b = new elemento;
			b->x = a->x;
			b->info=a->info;
			b-> sig = NULL;
			if(estaVacia()){
				cab = b;
				fin = b;
			}
			else{
				fin->sig = b;
				fin = b;
			}
			tam++;
			
		}
		int getTam(){
			return tam;
		}
		void anadirCabeza(elemento *a){
			elemento *b = new elemento;
			b->x = a->x;
			b->info=a->info;
			b-> sig = NULL;
			if(estaVacia()){
				cab = b;
				fin = b;
			}
			else{
				b->sig = cab;
				cab = b;
			}
			tam++;
		}
		
		void insertar(elemento *a){
			elemento *actual, *siguiente;
			elemento *b = new elemento;
			b->x = a->x;
			b->info = a->info;
			b->sig = NULL;
			
			if(estaVacia()){
				cout<<"carajos no carga";	
				//anadirCabeza(a);
				cabcen->sig=b;												
				b->sig = fincen;				
				
			}
			else{				
				actual = cab;								
				siguiente = cab->sig;												
				for(int i=0 ; i<=tam; i++){										
					if(b->x<siguiente->x || siguiente==fincen){						
						
						b->sig=siguiente;												
						actual->sig=b;											
						break; 
					}else{						
						
						actual = siguiente;						
						siguiente = siguiente->sig;
					}						
				}
				
				tam++;		
			}
		}
		
		void cambiar(elemento *a,int Pos){
			if(estaVacia()){
				anadirCabeza(a);
			}
			else{
				if(Pos>tam)
					anadirFin(a);
				else{
					elemento *aux = new elemento;
					aux=cab;
					for(int i=2;i<=Pos;i++){
						if(a->x < aux->x){
							aux=aux->sig;								
						}else{
							break;
						}
					}
					
					aux->info=a->info;
				}	
			}
		}
		
		void eliminarFinal(){
			if(!estaVacia()){
				elemento *aux = new elemento;
				aux=cab;
				for(int i=2;i<getTam();i++){
					aux = aux->sig;
				}
				fin = aux;
				aux= aux->sig;
				fin->sig=NULL;
				delete aux;
				tam--;				
			}
		}
		
		void eliminarInicio(){
			if(!estaVacia()){	
				elemento *aux = new elemento;							
				aux = cab->sig;
				cab = aux;
				tam--;
			}
		}
		
		void eliminar(int pos){
			if(pos>tam || pos==tam){
				eliminarFinal();
			}else{
				elemento *aux = new elemento;
				elemento *temp = new elemento;
				aux=cab;
				for(int i=2;i<pos;i++){
					aux=aux->sig;
				}
				temp=aux->sig;
				aux->sig=temp->sig;
				delete temp;
				tam--;
			}
						
		}
		
		
		elemento* devolverDato(int Pos){
			int contador = 1;
			elemento *aux = new elemento;
			aux = cabcen;
			while(contador<= Pos){
				if(contador == Pos){
					return aux;
				}
				else{
					aux = aux->sig;
					contador++;
				}
			}
		}
		
		string buscar(long long codigo){
			
		}
};
