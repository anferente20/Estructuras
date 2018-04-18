#include <iostream>
#include<stdlib.h>
#include <string.h>
#include <windows.h>
#include "menu.h"

void menus(int opcion);
void menuIngredientes(Lista<ingrediente*> ingr);
void menuRecetasSoloNombre(Lista<receta*> men);
void imprimirReceta(Lista<receta*> listaAImprimir );
void imprimirUnaReceta(receta *rec);
void menuRecetasSoloNombre(Lista<receta*> men);
receta* cambiarNombre(char *nombreN, receta* rOriginal);
receta* cambiarPrep(char *prepN, receta* rOriginal);

int main(int argc, char** argv) {
	
	int opcion = 0;
	const size_t BUFFER_SIZE = 1024;
	menu men;	
	char *nombre;
	char *preparacion;
	char *nombreI;
	float cant;
	char *medida;
	int val = 1, posR,posI;
	
	receta *rec;
	ingrediente *ig;
	
	do{
		menus(1);
		cin>>opcion;
		switch(opcion){
			case 1:{
				rec = new receta;
				nombre = new char[BUFFER_SIZE];
				preparacion = new char[BUFFER_SIZE];
				cout<<"Nombre de la receta:";
				cin.getline(nombre, BUFFER_SIZE);
				cin.ignore(BUFFER_SIZE, '\n');
				rec->nombre = nombre;
				cout<<"Preparación Receta: ";
				cin.getline(preparacion, BUFFER_SIZE);
				cin.ignore(BUFFER_SIZE, '\n');
				rec->preparacion = preparacion;
				system("cls");
				while(val == 1){
					ig = new ingrediente;
					nombreI = new char[BUFFER_SIZE];
					medida = new char[BUFFER_SIZE];
					cout<<"Nombre del ingrediente: ";
					cin>>nombreI;
					ig->nombre=nombreI;
					cout<<"Cantidad: ";
					cin>>cant;
					ig->cantidad=cant;
					cout<<"Medida del ingrediente: ";
					cin>>medida;
					ig->medida = medida;
					rec->ing.anadirFin(ig);
					system("cls");
					cout<<"¿Desea agregar otro ingrediente?"<<endl;
					cout<<"1. Si"<<endl;
					cout<<"2. No"<<endl;
					cin >> val;
				}
				val=1;
				men.agregarReceta(rec);
				system("pause");
				break;
			}
			case 2:{
				menus(2);
				nombre = new char[BUFFER_SIZE];
				cin >> nombre;
				rec = men.buscarReceta(nombre);	
				if (rec==NULL){
					cout << "No se encontro la receta." << endl;
				} else {
					imprimirUnaReceta(rec);
				}
				system("pause");
				break;
			}
			case 3:{
				menus(3);
				nombreI = new char[BUFFER_SIZE];
				cin >> nombreI;
				Lista<receta*> recAux = men.buscarIngrediente(nombreI);
				if(recAux.getTam()==0){
					cout << "No se encontraron recetas con este ingrediente." << endl;
				} else {
					imprimirReceta(recAux);
				}
				system("pause");
				break;
			}
			case 4:{
				menus(4);
				cin >> opcion;
				cout<<"Recetas del Menu: "<<endl;
				menuRecetasSoloNombre(men.devolverRecetas());
				cout << "Escriba el numero de la receta que desea cambiar. ";
				cin>>posR;
				rec = men.buscarRecetaPos(posR);	

				if(rec==NULL){
					cout << "No se encontro la receta." << endl;
				} else {
					if (opcion==1){
						nombre = new char[BUFFER_SIZE];
						cout << "Escriba el nuevo nombre de la receta: ";
						cin >> nombre;
						rec->nombre = nombre;
						men.modificarR(rec,posR); 	
						
					} else if (opcion==2){
						preparacion = new char[BUFFER_SIZE];
						cout << "Escriba la nueva preparacion de la receta: ";
						cin >> preparacion;
						rec->preparacion = preparacion;
						men.modificarR(rec,posR);
						
					} else if (opcion==3){
						cout << "Esta es la lista de ingredientes de la receta: " << endl;
						menuIngredientes(rec->ing);
						cout << "Escriba el numero para seleccionar la receta. ";
						cin>>posI;
						
						ig = men.buscarIngrediente(posR,posI);

						menus(6);
						
						cin>>opcion;
						switch(opcion){
							case 1:{
								nombre = new char[BUFFER_SIZE];
								cout << "Escriba el nuevo nombre del ingrediente: ";
								cin >> nombre;
								ig->nombre = nombre;
								men.modificarI(ig,posR,posI); 	
								
								break;
							}
							case 2:{
								cout << "Escriba la nueva cantidad del inggrediente: ";
								cin >> cant;
								ig->cantidad = cant;
								men.modificarI(ig,posR,posI); 
								break;
							}
							case 3:{
								medida = new char[BUFFER_SIZE];
								cout << "Escriba la nueva medida del ingrediente: ";
								cin >> medida;
								ig->medida = medida;
								men.modificarI(ig,posR,posI);
								break;
							}
						}					
					}
				}
				system("pause");
				break;
			}
			case 5:{
				menus(5);
				cin >> opcion;
				cout<<"Recetas del Menu: "<<endl;
				menuRecetasSoloNombre(men.devolverRecetas());
				cout << "Escriba el numero de la receta que desea cambiar." << endl;
				cin>>posR;
				rec = men.buscarRecetaPos(posR);	
				if (rec==NULL){
					cout << "No se encontro la receta." << endl;
				} else{
					if (opcion==1){
						men.borrarR(nombre);
						cout << "Receta eliminada con exito: " << endl;
						
							
					} else if(opcion==2){
						nombreI = new char[BUFFER_SIZE];
						cout << "Esta es la lista de ingredientes de la receta: " << endl;
						menuIngredientes(rec->ing);
						cout << "Escriba el nombre del ingrediente: " << endl;
						cin >> nombreI;
						men.borrarI(rec->nombre,nombreI);
						cout << "Ingrediente eliminado con exito: " << endl;	
					}
				}
				system("pause");
				break;
			}
			case 6:{
				imprimirReceta(men.devolverRecetas());
				system("pause");	
				break;
			}	
		}
		system("cls"); 	
	}while(opcion!=7);
	return 0;
}

void menus(int opcion){
	switch(opcion){
		case 1:{
			cout << "LIBRO DE RECETAS" << endl;
			cout << "1. Ingresar nueva receta. " << endl;
			cout << "2. Buscar receta. " << endl;
			cout << "3. Buscar recetas con ingrediente especifico." << endl;
			cout << "4. Modificar una receta." << endl;
			cout << "5. Eliminar una receta o ingrediente." << endl; 
			cout << "6. Mostrar todas las recetas. " << endl;
			cout << "7. Salir." << endl;			
			break;
		}
		case 2:{
			cout << "Escriba el nombre de la receta que desea buscar: ";
			break;
		}
		case 3:{
			cout << "Escriba el nombre del ingrediente que desea buscar: ";
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
		case 6:{
			cout<< "1. Modificar nombre."<<endl;
			cout<< "2. Modificar cantidad." <<endl;
			cout<< "3. Modificar medida." <<endl;
			break;
		}
	}
	
}

//Essta funcion sirve para el caso 4, se muestran todas las listas de recetas que hay, luego se escoge cual se quiere modificar,
// teniendo en cuenta el tipo de modificación
void menuRecetasSoloNombre(Lista<receta*> men){
	for(int i = 1;i<=men.getTam();i++){
		cout<<i<<"."<<men.devolverDato(i)->nombre<<endl;
	}
}
//Muestra la lista de ingredientes, en caso de que se borre o modifique un ingrediente 
void menuIngredientes(Lista<ingrediente*> ingr){
	for(int i = 1;i<=ingr.getTam();i++){
		cout<<i<<"."<<ingr.devolverDato(i)->nombre<<endl;
	}
}

//Imprime la lista de todas las recetas con sus correspondientes ingredientes
void imprimirReceta(Lista<receta*> listaAImprimir){
	receta *e;
	ingrediente *ingred;
	for(int i=1; i<=listaAImprimir.getTam();i++){
		e = listaAImprimir.devolverDato(i);
		cout <<endl<< "Receta N#:  " << i << endl;
		cout << "Nombre de la receta: " << e->nombre <<endl;
		cout << "Preparacion: " << e->preparacion << endl;
		cout << "Ingredientes: "<< endl;
		for(int j = 1; j<=e->ing.getTam();j++){
			ingred = e->ing.devolverDato(j);
			cout <<endl<< "<<################################>>" << endl;
			cout << "Nombre del ingrediente N# " << j << ": "<<  ingred->nombre << endl;
			cout << "Cantidad: "<< ingred->cantidad << endl;
			cout << "Tipo de medida: "<< ingred->medida << endl;
		}
		cout <<endl<< "<<------------------------------>>" << endl;
	}
}
//Imprime solo una receta
void imprimirUnaReceta(receta *rec){
	ingrediente *ingred;
	cout <<endl<< "<<------------------------------>>" << endl;
	cout << "Nombre de la receta: " << rec->nombre <<endl;
	cout << "Preparacion: " << rec->preparacion << endl;
	cout << "Ingredientes: "<< endl;
	for(int i = 1; i<=rec->ing.getTam(); i++){
		ingred = rec->ing.devolverDato(i);
		cout <<endl<< "<<################################>>" << endl;
		cout << "Nombre del ingrediente N# " << i << ": "<<  ingred->nombre << endl;
		cout << "Cantidad: "<< ingred->cantidad << endl;
		cout << "Tipo de medida: "<< ingred->medida << endl;
	}
}


