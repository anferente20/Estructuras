#include <iostream>
#include "lectura.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;
int main(int argc, char** argv) {
	Lectura lee;
	candidatos can(lee.lecturaCandidatos());
	candidato candi;
	//creo partido
	cout<< lee.lecturaPartido().devolverDato(1).nombre;
	Partido part(can,lee.lecturaPartido());
	Lista<candidato> cani = part.consultarC(6);
	cout<<part.getPartido(6).nombre<<endl;
	for(int i = 1; i<= cani.getTam();i++){
		candi = cani.devolverDato(i);
		cout<<"Clave: "<<candi.clave <<endl;
		cout<<"Nombre: "<<candi.nombre<<" "<<candi.apellido<<endl;
		cout<<"CC: "<<candi.id<<endl;
		cout<<"Sexo: "<<candi.sexo<<endl;
		cout<<"Estado: "<<candi.estadoCivil <<endl;
		cout<<"NAcimiento: "<<candi.fechaNac<<endl;
		cout<<"ciudadNac "<<candi.ciudadNac<<endl;
		cout<<"ciudadRes: "<<candi.ciudadRes<<endl;
		cout<<"partido: "<<part.getNombre(candi.partido)<<endl;
		cout<<"Tipo: "<<candi.tipoCandidato <<endl;
		cout<<"Vice: "<<candi.vicepresidente <<endl;
		cout<<"-------------------------------------------------"<<endl;
	}
	
	cani = part.candidatosPresidencia();
	cout<<endl<<"Presidencia"<<endl;
	for(int i = 1; i<= cani.getTam();i++){
		candi = cani.devolverDato(i);
		cout<<"Clave: "<<candi.clave <<endl;
		cout<<"Nombre: "<<candi.nombre<<" "<<candi.apellido<<endl;
		cout<<"CC: "<<candi.id<<endl;
		cout<<"Sexo: "<<candi.sexo<<endl;
		cout<<"Estado: "<<candi.estadoCivil <<endl;
		cout<<"NAcimiento: "<<candi.fechaNac<<endl;
		cout<<"ciudadNac "<<candi.ciudadNac<<endl;
		cout<<"ciudadRes: "<<candi.ciudadRes<<endl;
		cout<<"partido: "<<part.getNombre(candi.partido)<<endl;
		cout<<"Tipo: "<<candi.tipoCandidato <<endl;
		cout<<"Vice: "<<candi.vicepresidente <<endl;
		cout<<"-------------------------------------------------"<<endl;
	}
	
	return 0;
}

