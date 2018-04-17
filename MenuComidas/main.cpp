#include <iostream>
#include<stdlib.h>
#include <string.h>
#include <windows.h>
#include "menu.h"

int main(int argc, char** argv) {
/*	
	ESTO SIRVE PARA MOSTRAR RECETA
	
	for(int i = 1;i<=men.devolverRecetas().getTam();i++){
		cout<<men.devolverRecetas().devolverDato(i)->nombre<<endl;
		for(int j = 1;j<=men.devolverRecetas().devolverDato(i)->ing.getTam();j++){
			cout<<men.devolverRecetas().devolverDato(i)->ing.devolverDato(j)->nombre
			<<endl;
		}
	}*/
	
	int opcion = 0;
	const size_t BUFFER_SIZE = 1024;
	char *nombre ;
	char *preparacion ;
	char *nombreI ;
	float cant;
	char *medida ;
	int val = 1;
	menu men;
	receta *rec;;
	ingrediente *ig;
	do{
		menu(1);
		cin>>opcion;
		switch(opcion){
			case 1:
				rec = new receta;
				cout<<"Nombre Receta: ";
				nombre = new char[BUFFER_SIZE];
				preparacion = new char[BUFFER_SIZE];
				nombreI = new char[BUFFER_SIZE];
				medida = new char[BUFFER_SIZE];
				cin>>nombre;
				rec->nombre = nombre;
				cout<<"Preparación Receta: ";
				cin>>preparacion;
				rec->preparacion=preparacion;
				system("cls");
				while(val == 1){
					ig = new ingrediente;
					cout<<"Nombre del ingrediente: ";
					cin>>nombreI;
					ig->nombre=nombreI;
					cout<<"Cantidad disponible: ";
					cin>>cant;
					ig->cant=cant;
					cout<<"Medida del ingrediente: ";
					cin>>medida;
					ig->medida = medida;
					rec->ing.anadirFin(ig);
					system("cls");
					cout<<"¿Desea agregar otro ingrediente?"<<endl;
					cout<<"1. Si"<<endl;
					cout<<"2. No"<<endl;
				}
				men.agregarReceta(rec);
				break;
		}
		
	}while(opcion!=6)
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

//Essta funcion sirve para el caso 4, se muestran todas las listas de recetas que hay, luego se escoge cual se quiere modificar,
// teneiendo en cuenta el tipo de modificación
void menuRecetas(Lista<receta*> men){
	for(int i = 1;i<=men.getTam();i++){
		cout<<i<<"."<<men.devolverDato(i)->nombre<<endl;
	}
}
//Muestra la lista de ingredientes, en caso de que se borre o modifique un ingrediente 

void menuIngrediente(List<ingrediente*> ing){
	for(int i = 1;i<=ing.getTam();i++){
		cout<<i<<"."<<ing.devolverDato(i)->nombre<<endl;
	}
}	
