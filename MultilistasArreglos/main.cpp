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
	cout<<"HOLA ";
	Multi.insertar(e);
	e->nombre = "Godzilo";
	e->edad = 300;
	e->carrera= "Sistemas";
	e->hobby = "Natacion";
	cout<<"SI ";
	Multi.insertar(e);
	Lista<estudiante*> esti= Multi.mostrarC("Sistemas");
	for(int i =1; i<esti.getTam();i++){
		cout<< esti.getTam()<<endl;
	}
	return 0;
}
