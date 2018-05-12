#include <cstdlib>
#include <iostream>
#include <fstream>
#include <iomanip>
#include "structs.h"
using namespace std;

candidato* lecturaCandidatos(){
	long cedula,j,i=0;
	int id;
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
	 candidato *candidatos= new candidato[170];     //150  por ciudad, 10 presidenciales, 10 vicepresidenciales
	
	 ifstream archEntrada("archivos/candidatos.txt", ios::in);   //lee el archivo para el modo lectura	 
	
	 if (!archEntrada.good())    //verifica que el archivo este disponible para abrir
	   {cerr << "No se pudo abrir el archivo trios" << endl;
	    exit(1);}                //en caso de no poder abrir se cierra el programa
	    
	 // lectura del archivo y creacion del arreglo   
	while(!archEntrada.eof()){        //mientras haya algo que leer, hagale
	   	archEntrada >> id;
	    candidatos[i].id=id;
	    archEntrada >> nombre;
	    candidatos[i].nombre=nombre;
	    archEntrada >> apellido;
	    candidatos[i].apellido=apellido;
	    archEntrada >> cedula;
	    candidatos[i].cedula=cedula;	    
	    archEntrada >> sexo;
	    candidatos[i].sexo=sexo;
	   	archEntrada >> estado;
	    candidatos[i].sexo=estado;
	    archEntrada >> fecha;
	    candidatos[i].fecha=fecha;
	    archEntrada >> ciudadn;
	    candidatos[i].ciudadn=ciudadn;
	    archEntrada >> ciudadr;
	    candidatos[i].ciudadr=ciudadr;
	    archEntrada >> partido;
	    candidatos[i].partido=partido;
	    archEntrada >> tipo;
	    candidatos[i].tipo=tipo;
	    archEntrada >> vice;
	    candidatos[i].vice=vice;
	    i++;
	}
	   
	archEntrada.close();			 	   
	return candidatos;
}

cidepar* lecturaciudad()
	{int i=0;
	int id;
	string nombre;
	cidepar *cidepa;
			
	//este caso es para las ciudades
	cidepa = new cidepar[20];
	ifstream archEntrada("archivos/Ciudades.txt", ios::in);   //lee el archivo para el modo lectura
	
	if (!archEntrada.good())    //verifica que el archivo este disponible para abrir
	   {cerr << "No se pudo abrir el archivo trios" << endl;
	    exit(1);}                //en caso de no poder abrir se cierra el programa
	    
	 // lectura del archivo y creacion del arreglo   
	while(!archEntrada.eof()){        //mientras haya algo que leer, hagale
	   	archEntrada >> id;
	    cidepa[i].id=id;
	    archEntrada >> nombre;
	    cidepa[i].nombre=nombre;
	    i++;
	}
	   
	archEntrada.close();			 	   
	return cidepa;
}

cidepar* lecturadepartamento()
	{int i=0;
	int id;
	string nombre;
	cidepar *cidepa;
			
	//este caso es para las ciudades
	cidepa = new cidepar[5];
	ifstream archEntrada("archivos/departamentos.txt", ios::in);   //lee el archivo para el modo lectura
	
	if (!archEntrada.good())    //verifica que el archivo este disponible para abrir
	   {cerr << "No se pudo abrir el archivo trios" << endl;
	    exit(1);}                //en caso de no poder abrir se cierra el programa
	    
	 // lectura del archivo y creacion del arreglo   
	while(!archEntrada.eof()){        //mientras haya algo que leer, hagale
	   	archEntrada >> id;
	    cidepa[i].id=id;
	    archEntrada >> nombre;
	    cidepa[i].nombre=nombre;
	    i++;
	}
	   
	archEntrada.close();			 	   
	return cidepa;
}

cidepar* lecturapartido()
	{int i=0;
	int id;
	string nombre;
	cidepar *cidepa;
			
	//este caso es para las ciudades
	cidepa = new cidepar[10];
	ifstream archEntrada("archivos/partidos.txt", ios::in);   //lee el archivo para el modo lectura
	
	if (!archEntrada.good())    //verifica que el archivo este disponible para abrir
	   {cerr << "No se pudo abrir el archivo trios" << endl;
	    exit(1);}                //en caso de no poder abrir se cierra el programa
	    
	 // lectura del archivo y creacion del arreglo   
	while(!archEntrada.eof()){        //mientras haya algo que leer, hagale
	   	archEntrada >> id;
	    cidepa[i].id=id;
	    archEntrada >> nombre;
	    cidepa[i].nombre=nombre;
	    i++;
	}
	   
	archEntrada.close();			 	   
	return cidepa;
}
