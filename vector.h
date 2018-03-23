#include <iostream>
using namespace std;
template<class T>

class vector{
	private:
		T *p;
		int indice;
		int tam;
	
	public:
		vector(int tm){
			tam=tm;
			indice = 0 ;
			p= new T[tam];
		}
		~vector(){
			delete []p;
		}
		void agregar(T elem){
			p[indice]=elem;
			indice++;
		}
		//opcion 1
		bool esta_lleno(){
			if(indice<tam){
				return false;
			}
			if(indice==tam){
				return true;
			}
			return false;
		}
		T sacar(){
			if(indice>0){
				return p[--indice];	
			}else{
				return p(indice);
			}
				
		}
		
};
