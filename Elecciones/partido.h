#include "avl.h"

struct partido{
	int clave;
	string nombre;
	AVL<int> candidatos;
};

class Partido{
	partido* partidos;
	candidatos can;
	int tam;
	
	public:
		Partido(candidatos candid, Lista<partido>  nombres){
			can = candid;
			tam = 0;
			partidos = new partido[100];
			for(int i = 1;i<nombres.getTam();i++){
				agregar(nombres.devolverDato(i));
			}
			for(int i = 1;i<=can.getCandidatos().getTam();i++){
				anadirC(can.getCandidato(i));
			}
		}
		
		//anadir partido
		void agregar(partido p){
			partidos[tam+1] = p;
			tam++;
		}
		//Función encargada de insertar un candidato
		void anadirC( candidato cani){
			if(partidos[cani.partido].candidatos.getTam() == 0)	{
				partidos[cani.partido].candidatos.insertarRaiz(cani.clave);
			}else{
				partidos[cani.partido].candidatos.insertarElemento(cani.clave);
			}
	
		}
		
		//Devuelve la cantidad de partidos
		int getTam(){
			return tam;
		}
		//funcion para consultar todos los partidos
		partido* getPartidos(){
			return partidos;
		}
		
		//Función para consultar un partido específico 
		partido getPartido(int partido){
			return partidos[partido];
		}
		
		
		//obtener el nombre de un partido
		string getNombre(int partido){
			return partidos[partido].nombre;
		}
		
		
		Lista<candidato> consultarC(int partido){
			Lista<int> aux;
			int auxp = 0;
			Lista<candidato> temp;
			for(int i =1;i<= tam;i++){
				if(partido == partidos[i].clave)
					auxp = i;
			}
			aux = partidos[auxp].candidatos.getin();
			for(int i =1;i<= aux.getTam();i++){
				temp.anadirFin(can.getCandidato(aux.devolverDato(i)));
			}
			return temp;
		}
		
		Lista<candidato> candidatosPresidencia(){
			Lista<int> aux;
			Lista<candidato> temp;
			for(int i = 1;i<= getTam();i++){
				aux = partidos[i].candidatos.getin();
				for(int j =1;j<= aux.getTam();j++){
					
					if(can.getCandidato(aux.devolverDato(j)).tipoCandidato == 1){
						temp.anadirFin(can.getCandidato(aux.devolverDato(j)));
					}
				}
			}
			return temp;
		}
};
