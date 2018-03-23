#include <iostream>
#include "vector.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


using namespace std;

void opciones(){
	cout<<"1. Agregar"<<endl;
	cout<<"2. Sacar"<<endl;
	cout<<"3. Verificar si llena"<<endl;
	cout<<"4. Imprimir arreglo"<<endl;
	cout<<"4. Salir"<<endl;
}

int main(int argc, char** argv) {
	int opc, elem;
	
	opciones();
	vector<int> veci(5);
	do{
		do{
			cout<<"Ingrese una de las opciones: ";
			cin>>opc;
			if(opc<1 || opc>4){
				cout<<"Opcion no posible";
				cin>>opc;
			}
		}while(opc>4 || opc<1);
		
		
		switch (opc){
			case 1:
				if(veci.esta_lleno()==false){
					cout<<"Ingrese el elemento que quiere agregar: ";
					cin>>elem;
					veci.agregar(elem);	
				}else{
					cout<<"No se puede agregar mas elementos el vector esta lleno"<<endl;
				}
				break;
			case 2:
				if(veci.sacar().veci[0]){
					cout<<veci.sacar()<<" Este es el ultimo que se saco"<<endl;
				}else{
					cout<<"No se puede sacar elementos porque no hay más"<<endl;
				}
				
				break;
			case 3:
				if(veci.esta_lleno()){
					cout<<"El vector esta lleno"<<endl;
				}else{
					cout<<"El vector NO esta lleno"<<endl;
				}
			case 4:
				cout<<"Gracias por usar esta cosa"<<endl;
				break;
		}
		//veci.imprimir();	
	}while(opc!=4);
	return 0;
}
