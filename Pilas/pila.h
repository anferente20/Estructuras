template<class T>
class Pila{
	T *pila;
	int p;
	public:
		Pila(int max=100){
			pila = new T[max];
			p = 0;			
		}
		~Pila(){
			delete pila;
		}
		inline void meter(T v){
			pila[p++] = v;
		}
		inline T sacar(){			
			return pila[--p];
		}
		inline T sacar1(){			
			return pila[p-1];
		}
		inline int vacia(){
			return !p;
		}
};
