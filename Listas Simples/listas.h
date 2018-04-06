template<class T>
struct Nodo{
	T x;
	Nodo<T> *sig;
};
template<class T>
class Lista{
	Nodo<T> *cab,*fin;
	int tam;
	
	public:
		Lista(){
			cab=fin=NULL;
			tam=0;
		}
		bool estaVacia(){
			if(tam ==0)
				return true;
			else
				return false;
		}
		
		void anadirFin(T a){
			Nodo<T> *b = new Nodo<T>;
			b->x = a;
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
		void anadirCabeza(T a){
			Nodo<T> *b = new Nodo<T>;
			b->x = a;
			b-> sig = NULL;
			if(estaVacia()){
				cab = b;
				fin = b;
			}
			else{
				b->sig = cab;
				cab=b;
			}
			tam++;
		}
		
		void anadirPos(T a, int Pos){
			Nodo<T> *b = new Nodo<T>;
			b->x = a;
			b-> sig = NULL;
			if(estaVacia()){
				anadirCabeza(a);
			}
			else{
				if(Pos>tam)
					anadirFin(a);
				else{
					Nodo<T> *aux = new Nodo<T>;
					aux=cab;
					for(int i=2;i<Pos;i++){
						aux=aux->sig;
					}
					b->sig=aux->sig;
					aux->sig=b;
					tam++;
				}	
			}
		}
		
		//revisar
		void modificar(T a,int Pos){
			if(estaVacia())
				anadirFin(a);
			if(Pos>tam)
				anadirCabeza(a);
			else{
				int contador = 1;
				Nodo<T> *aux = new Nodo<T>;
				aux = cab;
				while(contador<Pos){
					if(contador == Pos){
						aux->x =a;
 					}
					else{
						aux = aux->sig;
						contador++;
					}
				}
			}	
		}
		
		void eliminarFinal(){
			if(!estaVacia()){
				int contador = 1;
				Nodo<T> *aux = new Nodo<T>;
				aux = cab;
				while(contador<= tam-1){
				if(contador == tam){
					delete aux->sig;
					aux->sig = NULL;
				}
				else{
					aux = aux->sig;
						contador++;
				}
			}
			}
		}
		
		void eliminarInicio(){
			Nodo<T> *aux = new Nodo<T>;
			
			if(!estaVacia()){								
				aux = cab->sig;
				cab = aux;
				tam--;
			}
		}
		//Revisar
		void eliminarPos(int pos){
			if(!estaVacia()){
				
				int contador = 1;
				Nodo<T> *aux = new Nodo<T>;
				aux = cab;
				
				while(contador<pos){
					if(contador == pos){
						aux = aux->sig;    //tengo mis dudas :v
						tam--;
 					}
					else{
						aux = aux->sig;
						contador++;
					}
				}	
			}
		}	
		
		
		T devolverDato(int Pos){
			int contador = 1;
			Nodo<T> *aux = new Nodo<T>;
			aux = cab;
			while(contador<= Pos){
				if(contador == Pos){
					return aux->x;
				}
				else{
					aux = aux->sig;
					contador++;
				}
			}
		}
};
