#include <iostream>
#include<stdlib.h>
#include <string.h>
#include <windows.h>
#include "menu.h"

int main(int argc, char** argv) {
	const size_t BUFFER_SIZE = 1024;
	char *nombre = new char[BUFFER_SIZE];
	char *preparacion = new char[BUFFER_SIZE];
	char *nombreI = new char[BUFFER_SIZE];
	float cant;
	char *medida = new char[BUFFER_SIZE];
	cin>>nombre;
	cin>>preparacion;
	int val=1;
	menu men;
	receta *rec = new receta;
	ingrediente *ig;
	rec->nombre = nombre;
	rec->preparacion = preparacion;
	while(val == 1){
		medida = new char[BUFFER_SIZE];
		nombreI = new char[BUFFER_SIZE];
		ig = new ingrediente;
		cin>>nombreI;
		ig->nombre=nombreI;
		cin>>cant;
		ig->cantidad=cant;
		cin>>medida;
		ig->medida = medida;
		rec->ing.anadirFin(ig);
		cin>>val;
		
	}
	men.agregarReceta(rec);
	
	for(int i = 1;i<=men.devolverRecetas().getTam();i++){
		cout<<men.devolverRecetas().devolverDato(i)->nombre<<endl;
		for(int j = 1;j<=men.devolverRecetas().devolverDato(i)->ing.getTam();j++){
			cout<<men.devolverRecetas().devolverDato(i)->ing.devolverDato(j)->nombre
			<<endl;
		}
	}
	return 0;
}

void menu(int opcion){
	switch(opcion){
		case 1:{
			cout << "LIBRO DE RECETAS" << endl;
			cout << "1. Ingresar nueva receta. " << endl;
			cout << "2. Buscar receta. " << endl;
			cout << "3. Buscar recetas con ingrediente especifico." << endl;
			cout << "4. Modificar una receta." << endl;
			cout << "5. Eliminar una receta." << endl; 
			cout << "6. Salir." << endl;			
			break;
		}
		case 4:{
			cout << "1. Modificar nombre. " << endl;
			cout << "2. Modificar preparacion." << endl;
			cout << "3. Modificar ingrediente." << endl;
			break;
		}
		case 5:{
			cout << "1. Eliminar receta. " << endl;
			cout << "2. Eliminar ingrediente de una receta." << endl;
			break;
		}
	}
	
}
