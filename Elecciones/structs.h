#ifndef STRUCTS_H
#define STRUCTS_H
#include <iostream>
#include <cstdlib>
#include <string>
#include <iomanip>
using namespace std;
struct candidato{
			int id; 
			string nombre; 
			string apellido;
			long cedula; 
			string sexo; 
			string estado;
			string fecha;
			int ciudadn; 
			int ciudadr; 
			int partido; 
			int tipo; 
			int vice;
};

/*
Por ahora una estructura para ciudad, departamento y partido, pues consisten en lo mismo en los archivos, id y nombre
*/
struct cidepar{
	int id;
	string nombre;
};
#endif


