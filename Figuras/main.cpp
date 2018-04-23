#include <cstdlib>
#include <iostream>
#include <ctype.h>
#include <iomanip>
#include "pila.h"
#include "cola.h"

using namespace std;

int main(int argc, char *argv[])
{cola Cola; 
pila Pila[3]; 
pila opcion[3];
 int i,j, tam, grupo=0, orden[3];
 char x; 
 int aux;
 char *posible; //en esta variable se guardan los posibles valores que puede tomar el signo escogido
 char *lista; // acá se guarda todos los signos de la columna de la primera elección
 int decision; // con este entero se sabe cual es la primera columa que se escogió
 do{
   cout<<"Escriba un mùltiplo de 3: ";
   cin>> tam;
   lista = new char[tam/3];// se separa memoria para lista
   }
 while (tam%3!=0);
 i=1;
 x=0;
 cout<<x;
 while(i<=tam && i<255)
  { if((x==0)||(x==13)||(x==32)||(x>6&&x<11))
        x++;
     else 
       {Cola.InsCola(x);
        i++; x++;
       }
  }
 cout<<"mire cuidadosamente los sìmbolos y elija uno\n";
if( tam>=9){
	aux = (tam/3)-2;
}
else{
	aux = tam /3;
}
for(j=1; j<=aux; j++) //Cambié el limite de las veces que toca repetirlo 24

 {cout<<"  Gr1  "<<"Gr2  "<<"Gr3  "<<endl;
  while (!Cola.ColaVacia())
   {for (i=0; i<3; i++)
      {x=Cola.AtenderCola();
       cout<<setw(4)<< x;
       Pila[i].Push(x);
       if(j == 1){
       	opcion[i].Push(x);//Se guardan los valores en una pila auxiliar
       }
       }
    cout<<"\n"; 
    }
 
   cout<< "elija el grupo en el que quedò el sìmbolo elegido (1, 2 o 3): ";
  cin>> grupo;
  if(j ==1){
  	decision = grupo;//Se guarda el valor de la primera elececcion, es decir la primera columna
  }
  switch(grupo){
         case 1 : {orden[0]=1; orden[1]=0; orden[2]=2;break;}
         case 2 : {orden[0]=0; orden[1]=1; orden[2]=2;break;}       
         case 3 : {orden[0]=0; orden[1]=2; orden[2]=1;break;}       
                }
  for (i=0; i<3; i++)
    {while (!Pila[orden[i]].PilaVacia())
        {Cola.InsCola(Pila[orden[i]].Pop());}
    }
  }

j=tam-tam/2;

if(tam % 2 ==0){ //En caso de ser un número par  se trata diferente
	for (i=1; i<=j; i++)
   {x=Cola.AtenderCola();}
   posible = new char[2];// como son dos posibles opciones necesitamos dos espacios para guardarlas
   posible[0] = x;//se guarda la de la mitad
   x =Cola.AtenderCola();
   posible[1]=x;// se guarda la siguiente a la mitad
   for( i = 0;i<tam/3;i++){
   	lista[i] = opcion[decision-1].Pop();//se llena la lista con los signos de la columna de la primera decision
   }
   
   //Se realizan las validaciones de los signos 
   for(i = 0;i<tam/3;i++){
		for(j = 0;j<2;j++){
			if(posible[j]==lista[i]){
				x = posible[j];
			}
		}
   }
}else{
	for (i=1; i<=j; i++)
   {x=Cola.AtenderCola();}
}
cout<<"La figura elegida es: "<< x<<endl; 
    system("PAUSE");
    return EXIT_SUCCESS;
}

