#include<string.h>
#include "departamento.h"
#include "listas.h"
#include "candidato.h"
#include "departamentos.h"

struct ciudad{
	string nombre;
	int departamento;
	long long censo;
	int idCabezaCand;		//Es el ultimo candidato que pertenece a la ciudad
};

class ciudades{
	ciudad *mun;
	int tam;
	
	public:{
		ciudades(){	
			mun = new ciudad[31];
			tam=1;
		}
		/**Anade ciudades*/
		void anadirCiudad(string nombre, idDept){
			ciudad aux;
			aux.nombre = nombre;
			aux.departamento = dept;
			aux.censo = 0;				//Aun no se genera el censo para la ciudad
			aux.idCabezaCand = 0;		//Por ahora no tiene candidatos asignados
			mun[++tam] = aux;
			
		}
		/**Muestra los candidatos de una ciudad*/
		Lista <candidato> mostrarCandPorCiudad(int posCiudad){
			return mun[posCiudad].cabCandidatosCiudad;
		}
		/**Añade candidatos a la ciudad en la que va a a particiar*/
		void anadirCandidatoCiudad(candidato cand, int posCiudad){
			int auxId;
			if (mun[posCiudad].idCabezaCand == 0){						//Si la ciudad aun no tiene candidatos, este es el primero
				mun[posCiudad].idCabezaCand = cand.clave;
			} else {
				cand.antCandCiudad = mun[posCiudad].idCabezaCand;		//El candidato guarda la clave del anterior candidato d ela misma ciudad
				mun[posCiudad].idCabezaCand = cand.clave;
				
			}
		}
		
		void anadirADept(){
			//Aun no hago esto
		}
	}
	
};


