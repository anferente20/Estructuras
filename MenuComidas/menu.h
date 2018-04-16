#include <string.h>
#include "listas.h"
#include <iostream>

using namespace std;
struct ingrediente{
	char *nombre;
	float cantidad;
	char *medida;
};

struct receta{
	char *nombre;
	char *preparacion;
	Lista<ingrediente*> ing;
};

class menu{
	Lista<receta*> meni;
	
	public:
		menu(){
		}
		
		void agregarReceta(receta *r){
			receta *aux = r;
			meni.anadirFin(r);
		}
		
		Lista<receta*> devolverRecetas(){
			return meni;
		}
};
