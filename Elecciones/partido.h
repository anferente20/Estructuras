#include "candidato.h"
#include "listas.h"

struct partido{
	string nombre;
	Lista<candidato> candidatos;
};

class Partido{
	partido* partidos;
	
	public:
		Partido(){
			partidos = new [5];
		}
};
