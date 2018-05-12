#include <cstdlib>
#include <iostream>
#include <fstream>
#include <iomanip>
#include "structs.h"

using namespace std;

void ModificarCandidato(candidato Ncandidato, int id){
	long cedula,j,i=0;
	int id1;				//variable para comparar en la busqueda del candidato
	string sexo;
	string apellido;
    string nombre;
	string estado;
	string fecha;
	int ciudadn;
	int ciudadr;
	int partido;
	int tipo;
	int vice;
	 
	ifstream archEntrada("archivos/candidatos.txt", ios::in);   //lee el archivo para el modo lectura
	ifstream archsalida("archivos/temp.txt", ios::out|ios::trunc);    //Crea un archivo para escribirlo
	if (!archEntrada.good())
    {	cerr << "No se pudo abrir el archivo " << endl;
    	exit(1);
	}
	if (!archsalida.good())
    {	cerr << "No se pudo abrir el archivo " << endl;
    	exit(1);
	}    
	                  
	while(!archEntrada.eof()){
		archEntrada>>id1;
		archEntrada>>nombre;
		archEntrada>>apellido;
		archEntrada>>cedula;
		archEntrada>>sexo;
		archEntrada>>estado;
		archEntrada>>fecha;
		archEntrada>>ciudadn;
		archEntrada>>ciudadr;
		archEntrada>>partido;
		archEntrada>>tipo;
		archEntrada>>vice;
		/*
		if(id1 == id){
			/*archsalida<<id<<" "<<Ncandidato->nombre<<" "<<Ncandidato.apellido<<" "<<Ncandidato.cedula<<" "
			<<Ncandidato.sexo<<" "<<Ncandidato.estado<<" "<<Ncandidato.fecha<<" "<<Ncandidato.ciudadn<<" "
			<<Ncandidato.ciudadr<<" "<<Ncandidato.partido<<" "Ncandidato.tipo<<" "<<Ncandidato.vice<<endl;			
			archsalida <<id1<<" "<<nombre<<" "<<apellido<<" "<<cedula<<" "<<sexo<<" "<<estado<<" "<<fecha<<" "<<ciudadn<<" "
				  	  <<ciudadr<<" "<<partido<<" "<<tipo<<" "<<vice<<endl;
		}else{
			archsalida<<id1<<" "<<nombre<<" "<<apellido<<" "<<cedula<<" "<<sexo<<" "<<estado<<" "<<fecha<<" "<<ciudadn<<" "
				  	  <<ciudadr<<" "<<partido<<" "<<tipo<<" "<<vice<<endl;
		}			*/
	}
	archEntrada.close();   
    archsalida.close();
}
void ModificarCiudad(){
	
}
void ModificarDepartamento(){
	
}
void ModificarPartido(){
	
}
