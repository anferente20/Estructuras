#include "listas.h"
#include "ciudad.h"

struct departamento{
	string nombre;
	Lista<ciudad> municipios;
};

class departamentos{
	departamento * dep;
	int tam;
	
	public:
		//Constructor
		departamentos(){
			dep = new departamento[6];
			tam = 1; 
		}
		//Get de arreglo de departamentos
		departamento* getDep(){
			return dep;
		}
		
		//Agregar departamento
		void agregarDept(departamento dept){
			if(tam<5){
				dep[tam+1] = dept;
			}
		}
		//Agregar ciudad a un departamento
		void agregarMunicipio(Ciudad municipio, int departamento){
			dep[departamento]->municipios.anadirFin(municipio);
		}
		
		
		
};
