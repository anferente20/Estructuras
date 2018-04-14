#include <iostream>
#include <string.h>
#include "multilistas.h"

using namespace std;
int main(int argc, char** argv) {
	multilista Multi;
	estudiante *e = new estudiante;
	e->nombre = "Godzila";
	e->edad = 300;
	e->carrera= "Sistemas";
	e->hobby = "Natacion";
	Multi.insertar(e);
	
	e = new estudiante;	
	e->nombre = "Godzilo";
	e->edad = 300;
	e->carrera= "Sistemas";
	e->hobby = "Natacion";
	Multi.insertar(e);
	
	e = new estudiante;
	e->nombre = "Godzilu";
	e->edad = 300;
	e->carrera= "Sistemas";
	e->hobby = "Danza";
	Multi.insertar(e);

	cout << "Prueba Carrera" << endl;	
	Lista<estudiante*> esti = Multi.mostrarC("Sistemas");
	for(int i=1; i<=esti.getTam();i++){
		e = esti.devolverDato(i);
		cout << "Persona " << i << endl;
		cout<< e->nombre <<endl;
		cout<< e->carrera << endl;
	}
	cout << "Prueba Hobby" << endl;
	Lista<estudiante*> esti2 = Multi.mostrarH("Natacion");
	for(int i=1; i<=esti2.getTam();i++){
		e = esti.devolverDato(i);
		cout << "Persona " << i << endl;
		cout<< e->nombre <<endl;
		cout<< e->hobby << endl;
	}

	return 0;
}
