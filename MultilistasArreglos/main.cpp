#include <iostream>
#include<stdlib.h>
#include <string.h>
#include "multilistas.h"
#include <windows.h>

using namespace std;
void menu(int cualMenu){
	switch (cualMenu){
		case 0:{
			cout << "MENU" << endl;
			cout << "1. Ingresar un nuevo estudiante " << endl;
			cout << "2. Mostrar por orden de nombre " << endl;
			cout << "3. Mostrar por orden de edad " << endl;
			cout << "4. Mostrar por hobby " << endl;
			cout << "5. Mostrar por carrera " << endl;
			cout << "6. Borrar " << endl;
			cout << "7. Modificar " << endl;
			cout << "8. Salir " << endl;
			break;
		}
		case 4:{
			cout << "1. Danza " << endl;
			cout << "2. Natacion " << endl;
			cout << "3. Basquet " << endl;
			cout << "4. Besibol" << endl;
			cout << "0. Volver " << endl;
			
			break;
		}
		case 5:{
			cout << "1. Catastral" << endl;
			cout << "2. Electrica" << endl;
			cout << "3. Sistemas" << endl;
			cout << "4. Industrial" << endl;
			cout << "0. Volver" << endl;
			break;
		}
		
		default:{
			break;
		}
	}
}
string validarCarrera(int num){
	string carrera;
	switch(num){
		case 1:{
			carrera="Catastral";
			break;
		}
		case 2:{
			carrera="Electrica";
			break;
		}
		case 3:{
			carrera="Sistemas";
			break;
		}
		case 4:{
			carrera="Industrial";
			break;
		}			
	}
	return carrera;
}

string validarHobby(int num){
	string hobby;
	switch(num){
		case 1:{
			hobby="Danza";
			break;
		}
		case 2:{
			hobby="Natacion";
			break;
		}
		case 3:{
			hobby="Basquet";
			break;
		}
		case 4:{
			hobby="Beisbol";
			break;
		}			
	}
	return hobby;
}

void imprimir (	Lista<estudiante*> listaAImprimir){
	estudiante *e;
	for(int i=1; i<=listaAImprimir.getTam();i++){
		e = listaAImprimir.devolverDato(i);
		cout << "Persona #:  " << i << endl;
		cout << "Nombre: " << e->nombre <<endl;
		cout << "Edad:  " << e->edad << endl;
		cout << "Carrera:  " << e->carrera << endl;
		cout << "Hobby:  " << e->hobby << endl;
		cout << "<<------------------------------>>" << endl;
	}
}

int main(int argc, char** argv) {	
	int opcion;
	multilista Multi;
	
	estudiante *e = new estudiante;
	const size_t BUFFER_SIZE = 1024;
	char *nombre = new char[BUFFER_SIZE];
	
	do{
		menu(0);
		cin >> opcion;
			switch(opcion){
				case 1:{
					
					estudiante *e = new estudiante;	
					nombre =  new char[BUFFER_SIZE];
					cout << "Nombre: ";
					cin >> nombre;
					e->nombre = nombre;
					cout << "Edad: " ;
					cin >> opcion;
					e->edad = opcion;
					menu(5);
					cin >> opcion;
					e->carrera= validarCarrera(opcion);
					menu(4);
					cin >> opcion;
					e->hobby = validarHobby(opcion);
					
					Multi.insertar(e);
				/*
					e = new estudiante;	
					e->nombre = "Godzilo";
					e->edad = 500;
					e->carrera= "Sistemas";
					e->hobby = "Natacion";
					Multi.insertar(e);
					
					e = new estudiante;
					e->nombre = "Godzilu";
					e->edad = 520;
					e->carrera= "Sistemas";
					e->hobby = "Danza";
					Multi.insertar(e);
					
					e = new estudiante;
					e->nombre = "jhoncena";
					e->edad = 1200;
					e->carrera= "Sistemas";
					e->hobby = "Danza";
					Multi.insertar(e);
					
					e = new estudiante;
					e->nombre = "jhoncena2";
					e->edad = 700;
					e->carrera= "Sistemas";
					e->hobby = "Danza";
					Multi.insertar(e);
					
					e = new estudiante;
					e->nombre = "jhoncena3";
					e->edad = 10000;
					e->carrera= "Sistemas";
					e->hobby = "Danza";
					Multi.insertar(e);
					
					*/
					break;
				}
				case 2:{
					if (Multi.getTam()!=0){
						cout<<endl;
						cout << "NOMBRE" << endl;
						imprimir(Multi.mostrarN());	
					} else {
						cout << "No hay estudiantes aun anadidos." << endl;
					}
					system("pause");
					break;
				
				}
				case 3:{
					if (Multi.getTam()!=0){
						cout<<endl;
						cout << "EDAD" << endl;
						imprimir(Multi.mostrarE());	
					} else {
						cout << "No hay estudiantes aun anadidos." << endl;
					}
					system("pause");
					break;
				}
				case 4:{
					menu(4);
					cin >> opcion;
					if (Multi.getTam()!=0){
						cout << "HOBBY" << endl;
						if (opcion<=4 && opcion>0){
							imprimir(Multi.mostrarH(validarHobby(opcion)));
						} else {
							menu(0);
						}	
					} else {
						cout << "No hay estudiantes aun anadidos." << endl;
					}
					system("pause");
					break;
				}
				case 5:{
					menu(5);
					if (Multi.getTam()!=0){
						cin >> opcion;
						cout << "CARRERA" << endl;
						if (opcion<=4 && opcion>0){
							imprimir(Multi.mostrarC(validarCarrera(opcion)));
						} else {
						menu(0);
						}		
					} else {
						cout << "No hay estudiantes aun anadidos." << endl;
					}
					system("pause");
					break;
				}
				case 6:
					cout<<"Ingrese nombre del estudiante a borrar: ";
					nombre =  new char[BUFFER_SIZE];
					cin>>nombre;
					Multi.Borrar(nombre);
					break;
				
				case 7:
					cout<<"Ingrese nombre del estudiante a modificar: ";
					char* nombre1 =  new char[BUFFER_SIZE];
					cin>>nombre1;
					estudiante *e = new estudiante;	
					nombre =  new char[BUFFER_SIZE];
					cout<<"NUEVOS DATOS:"<<endl;
					cout << "Nombre: ";
					cin >> nombre;
					e->nombre = nombre;
					cout << "Edad: " ;
					cin >> opcion;
					e->edad = opcion;
					menu(5);
					cin >> opcion;
					e->carrera= validarCarrera(opcion);
					menu(4);
					cin >> opcion;
					e->hobby = validarHobby(opcion);
					Multi.Modificar(nombre1,e);
					break;
			}	
			system("cls");	
		} while (opcion!=8);
return 0;
}

