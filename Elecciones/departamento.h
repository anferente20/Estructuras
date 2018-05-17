#include "listas.h"
#include "ciudad.h"
#include "string"

struct departamento{
	//El identificador del dept es la posicion en el array
	string nombre;
	Lista<ciudad> municipios;		//Tiene una lista de ciudades
	long long censoPersonas;	//Cantidad de personas que pueden votar en el departamento
};

class departamentos{
	departamento * dep;
	int tam;
	
	public:
		/**Constructos de departamento*/
		departamentos(){
			dep = new departamento[6];
			tam = 1; 
		}
		/** Get de arreglo de departamentos*/
		departamento* getArregloDep(){
			return dep;
		}
		
		/** Agregar departamento*/
		void agregarDept(string nombre){
			if(tam<=5){
				departamento dept;
				dept.nombre = nombre;
				dep[tam++] = dept;
			}
		}
		/** Agregar municipio a departamento*/
		void agregarMunicipio(ciudad municipio, int numDept){
			dep[numDept].municipios.anadirFin(municipio);		//Añade el municipio a el departamento correspondiente
			dept[numDept].censoPersonas=+municipio.censo;		//Va sumando la cantidad de personas al censo de el departamento
		}
		/** Muestra las ciudades de un departamento*/
		Lista <ciudad> mostrarCiudadesDept(int numDept){
			return dep[numDept].municipios;
		}
		
		
};
