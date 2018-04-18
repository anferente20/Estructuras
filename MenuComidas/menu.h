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
		
		void modificarR(receta *recipe, char *nombre){
			int pos;
			for(int i = 1;i<=meni.getTam();i++){
				if(strcmp(nombre, meni.devolverDato(i)->nombre)==0){
					pos = i;
				break;
				}
			}
			meni.modificar(recipe, pos);
		}
		
		int getTamI(receta *rec){
			return rec->ing.getTam();
		}
		
		Lista<ingrediente*> devolverIngredientes(receta *rec){
			return rec->ing;
		}
		
		void borrarI(char *nombreR,char *nombreI){
			int posR,posI;
			for(int i = 1;i<=meni.getTam();i++){
				if(strcmp(nombreR, meni.devolverDato(i)->nombre)==0){
					posR = i;
				break;
				}
			}
			receta *aux = meni.devolverDato(posR);
			for(int i = 1; i<=getTamI(aux);i++){
				if(strcmp(nombreI, devolverIngredientes(aux).devolverDato(i)->nombre)==0){
					posI = i;
				break;
				}
			}
			aux->ing.eliminarPos(posI);
		}
		
		void borrarR(char *nombreR){
			int pos, i;
			for(i = 1;i<=meni.getTam();i++){
				if(strcmp(nombreR, meni.devolverDato(i)->nombre)==0){
					pos = i;
				break;
				}
			}
			meni.eliminarPos(i);
		}
		
		receta* buscarReceta(char *nombre){
			for(int i = 1;i<=meni.getTam();i++){
				if(strcmp(nombre, meni.devolverDato(i)->nombre)==0){
					return meni.devolverDato(i);
					break;
				} 
			}
		}
		
		Lista<receta*> buscarIngrediente(char *nombreI){
			int i,j;
			Lista<receta*> recetasPorI;
			receta *rAux;
			ingrediente *iAux;
			for(i = 1;i <= meni.getTam(); i++){
				rAux=meni.devolverDato(i);
				for(j = 1; j <= rAux->ing.getTam();j++){
					iAux= rAux->ing.devolverDato(j);
					if(strcmp(nombreI, iAux->nombre)==0){
						recetasPorI.anadirFin(rAux);
					}
				}
			}
			return recetasPorI;
		}
};
