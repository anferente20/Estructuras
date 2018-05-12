#include <cstdlib>
#include <iostream>
#include <fstream>   //libreria que permite el manejo de archivos
#include <iomanip>
#include "Lectura.h"
#include "Escritura.h"
using namespace std;

int main(int argc, char *argv[])
	{
	int j;
	int NumLectura;
	candidato* candidatos;
	cidepar *ciudades;
	cidepar *departamentos;
	cidepar *partidos;
	cout<<"ingrese la opcion que quiera: "<<endl;
	cin>>NumLectura;
	//aca se puede meter la opcion para realizar tal lectura, puede ahorrar codigo
	switch(NumLectura){
		case 1:{
			//Lectura de candidatos
			candidatos = lecturaCandidatos();
			
			//Este for es solo para validar que los datos estan bien metidos en el arreglo, lo pueden quitar
			//mostrar los candidatos con sus datos
			for(j=0;j<170;j++){
				cout << setw(10) << candidatos[j].nombre << setw(10) << candidatos[j].apellido << setw(10) << candidatos[j].cedula << 
				setw(10) << candidatos[j].sexo <<setw(10) << candidatos[j].estado << setw(10) << candidatos[j].fecha <<setw(10) << candidatos[j].ciudadn
				<< setw(10) << candidatos[j].partido << setw(10) << candidatos[j].tipo << setw(10) << candidatos[j].vice<<endl;
			}
			break;
		}case 2:{
			//Lectura de Departamentos
			departamentos = lecturadepartamento();			
			cout<< "Mostrando los departamentos del archivo"	<< endl;
			//mostrar las ciudades en este caso
			for(j=0;j<4; j++){
				cout<< setw(10)<< departamentos[j].id<< setw(10)<< departamentos[j].nombre<<endl;
			}
			break;
		}
		case 3:{
			//Lectura de Ciudades
			ciudades = lecturaciudad();
			
			cout<< "Mostrando las ciudades del archivo"	<< endl;
			//mostrar las ciudades en este caso
			for(j=0;j<20; j++){
				cout<< setw(10)<< ciudades[j].id<< setw(10)<< ciudades[j].nombre<<endl;
			}
			break;
		}
		case 4:{
			//Lectura de Partidos
			partidos = lecturapartido();
			
			cout<< "Mostrando los partidos del archivo"	<< endl;
			//mostrar las ciudades en este caso
			for(j=0;j<10; j++){
				cout<< setw(10)<< partidos[j].id<< setw(10)<< partidos[j].nombre<<endl;
			}
			break;
		}					
	}
	/*
	candidato can;
	can.id = 1;
	can.nombre = "Sebastian";
	can.apellido = "Mora";
	can.cedula = 1018509802;
	can.sexo= "Macho";
	can.estado "Soltero";
	can.fecha = "26/02/1999";
	can.ciudadn = 1;
	can.ciudadr = 1;
	can.partido = 6;
	can.tipo = 1;
	can.vice = 1;
	
	ModificarCandidato(can);
	cout<<"se tendria que haber cambiado bien el de id 1";
	//modicar un candidato
	*/				
}
