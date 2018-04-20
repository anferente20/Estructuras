using namespace std;
class Pila2{
	public:
		Pila2(){
			cabeza = new nodo;
			z=  new nodo;
			cabeza->sig = z;
			z->sig = z;
		}	
		~Pila2(){
			struct nodo *t = cabeza;
			while(t!=z){
				cabeza = t;
				t = t->sig;
				delete cabeza;				
			}
		delete z;
		}		
		meter(int v){
			struct nodo *t= new nodo;
			t->clave = v;
			t->sig= cabeza->sig;
			cabeza->sig=t;
		}	
		char sacar(){
			char x;
			struct nodo *t= cabeza->sig;
			cabeza->sig = t->sig;
			x = t->clave;
			delete t;
			return x;
		}
		int vacia(){
			return cabeza->sig == z ;
		}
	private:
		struct nodo{
			int clave;
			struct nodo *sig;
		};	
		struct nodo *cabeza, *z;		
			
};	
