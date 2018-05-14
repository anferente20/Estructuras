#include <cstdlib>
#include <iostream>
#include <fstream>
#include <iomanip>
#include "candidato.h"
#include "partido.h"

using namespace std;

class Lectura{
		public:
			Lista<candidato> lecturaCandidatos(){
				long long id;
				int clave;
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
				Lista<candidato> candi;     //150  por ciudad, 10 presidenciales, 10 vicepresidenciales
				candidato c;
			 	ifstream archEntrada("archivos/candidatos.txt", ios::in);   //lee el archivo para el modo lectura	 
			
			 	if (!archEntrada.good())    //verifica que el archivo este disponible para abrir
			   		{cerr << "No se pudo abrir el archivo trios" << endl;
			    	exit(1);}                //en caso de no poder abrir se cierra el programa
			    
					 // lectura del archivo y creacion del arreglo   
					while(!archEntrada.eof()){        //mientras haya algo que leer, hagale
					   	archEntrada >> clave;
					    c.clave=clave;
					    archEntrada >> nombre;
					    c.nombre=nombre;
					    archEntrada >> apellido;
					    c.apellido=apellido;
					    archEntrada >> id;
					  	c.id=id;	    
					    archEntrada >> sexo;
					    c.sexo=sexo;
					   	archEntrada >> estado;
					    c.estadoCivil=estado;
					    archEntrada >> fecha;
					    c.fechaNac=fecha;
					    archEntrada >> ciudadn;
					    c.ciudadNac=ciudadn;
					    archEntrada >> ciudadr;
					    c.ciudadRes=ciudadr;
					    archEntrada >> partido;
					    c.partido=partido;
					    archEntrada >> tipo;
					    c.tipoCandidato=tipo;
					    archEntrada >> vice;
					    c.vicepresidente=vice;
					    candi.anadirFin(c);
					}
				   
				archEntrada.close();			 	   
				return candi;
			}
			
			Lista<partido> lecturaPartido(){
				int id;
				string nombre;
				partido p;
				Lista<partido> parti;

				ifstream archEntrada("archivos/partidos.txt", ios::in);   //lee el archivo para el modo lectura
				
				if (!archEntrada.good())    //verifica que el archivo este disponible para abrir
				   {cerr << "No se pudo abrir el archivo trios" << endl;
				    exit(1);}                //en caso de no poder abrir se cierra el programa
				    								    
				 // lectura del archivo y creacion del arreglo   
				while(!archEntrada.eof()){        //mientras haya algo que leer, hagale
				   	archEntrada >> id;
				    p.clave=id;
				    archEntrada >> nombre;
				    p.nombre=nombre;
					parti.anadirFin(p);
				}
				
				archEntrada.close();		 	   
				return parti;
			}
};
