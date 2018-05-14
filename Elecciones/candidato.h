#include <cstring>
#include "listas.h"
struct candidato{
	string nombre;
	string apellido;
	long long id;
	string sexo;
	string estadoCivil;
	string fechaNac;
	int ciudadNac;
	int ciudadRes;
	int partido;
	int tipoCandidato;
	int vicepresidente;
	int clave;	
};

class candidatos{
	Lista<candidato> cand;
	public:
	candidatos(Lista<candidato> can){
		cand = can;
	}
	candidatos(){
	}
	
	//agregar un nuevo candidato
	void anadir(candidato c){
		cand.anadirFin(c);
	}
	
	//Devuelve la lista de candidatos
	Lista<candidato> getCandidatos(){
		return cand;
	}
	//Para obtener un candidato
	candidato getCandidato(int clave){
		return cand.devolverDato(clave);
	}
};

