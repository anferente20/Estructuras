#include "listas.h"
using namespace std;
template<class T>
class colaP{ int tama;
			T *elementos;
			int posag=1;
			Lista<T> cola;
			
      public:colaP(int tam){
                    elementos = new T[tam+1];    
					for(int i=0; i<tam+1; i++ ){
						elementos[i] = 0;
					}   
					tama = tam+1;              
             }
             
             void agregar(T dato){
             	int aux = 0;
             	if(elementos[1]==0){             		
             			elementos[1] = dato;
						 				 
				 }else{
				 		aux = posag;
		         		 while(dato > elementos[aux/2] ){
		         			elementos[aux] = elementos[aux/2];
		         			aux = aux/2;
		         			if(aux == 1 ){
		         				break;
							}
						 }
						 elementos[aux] = dato;
						 
				 }				 				 
				 posag++;		
			 }
             void atender(){
             	int aux = 1;
             	int aux2=posag-1;				            
             	int hijom;             	
             	//cout<<"tam : "<<tama<<endl;
             	//cout<<"posag -1: "<< aux2<<endl;
             	while(aux < aux2 ){
             		if(elementos[2*aux] > elementos[2*aux+1]){
             	//		cout<<"carajo: hongo "<<2*aux<<" "<< 2*aux+1 <<endl;
             			hijom = 2*aux;	
					}else{
						hijom = (2*aux)+1;
					}
					elementos[aux] = elementos[hijom];
					aux = hijom;
					if(hijom*2 > aux2){
						
						break;
					}
					
				}
			//	cout<<"pos que necesito cambiar: "<<hijom<<endl;
				elementos[hijom] = elementos[aux2];
				elementos[aux2] =0;
				posag--;
			//	cout<<"posag actual: "<<posag<<endl;
				RefrescarLista();
			 }
			 void RefrescarLista(){
			 	cola.vaciar();
			 	int i;
			 	for(i=1; i<posag; i++){
			 		cola.anadirFin(elementos[i]);
				}
			 }
             T* getElementos(){
             	return elementos;
			 }
			 int getTam(){
			 	return tama;
			 }
             ~colaP(){
             	delete[] elementos;
			 }
			 Lista<T> getCola(){
			 	return cola;
			 }
      };
