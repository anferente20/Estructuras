#include <iostream>
#include <string.h>
#include "multilistas.h"

using namespace std;
int main(int argc, char** argv) {	

	multilista Multi;
	estudiante *e = new estudiante;
	e->nombre =  "Ben";
	e->edad = 1000;
	e->carrera= "Sistemas";
	e->hobby = "Natacion";
	Multi.insertar(e);

	e = new estudiante;	
	e->nombre = "Bet";
	e->edad = 550;
	e->carrera= "Sistemas";
	e->hobby = "Natacion";
	Multi.insertar(e);

	e = new estudiante;
	e->nombre = "Diana";
	e->edad = 590;
	e->carrera= "Sistemas";
	e->hobby = "Danza";
	Multi.insertar(e);
	
	e = new estudiante;
	e->nombre = "Ana";
	e->edad = 900;
	e->carrera= "Sistemas";
	e->hobby = "Danza";
	Multi.insertar(e);

/*	cout << "Prueba Carrera" << endl;	
	Lista<estudiante*> esti = Multi.mostrarC("Sistemas");
	cout<<esti.getTam();
	for(int i=1; i<=esti.getTam();i++){
		e = esti.devolverDato(i);
		cout << "Persona " << i << endl;
		cout<< e->nombre <<endl;
		cout<< e->carrera << endl;
	}
	
	cout << endl; 
	cout << "Prueba Hobby" << endl;
	Lista<estudiante*> esti2 = Multi.mostrarH("Natacion");
	for(int i=1; i<=esti2.getTam();i++){
		e = esti2.devolverDato(i);
		cout << "Persona " << i << endl;
		cout<< e->nombre <<endl;
		cout<< e->hobby << endl;
	}
*/	
	cout<<endl;
	cout << "Prueba Nombre" << endl;
	Lista<estudiante*> esti3 = Multi.mostrarN();
	for(int i=1; i<=esti3.getTam();i++){
		e = esti3.devolverDato(i);
		cout<< e->nombre <<" "<<e->edad<<endl;
	}
	cout<<endl;
	cout << "Prueba edad" << endl;
	Lista<estudiante*> esti4 = Multi.mostrarE();
	for(int i=1; i<=esti4.getTam();i++){
		e = esti4.devolverDato(i);
		cout<< e->nombre <<" "<<e->edad<<endl;
	}
	return 0;
}
