#include <cstdlib>
#include <iostream>

using namespace std;

void arreglo(int *p)
{int i;
 for (i=0; i<10; i++)
 p[i]=i*2;
     }
     

int main(int argc, char *argv[])
{int i, a[10], *pa, **ppa;
 for (i=0; i<10; i++)
     a[i]=0;
 pa=a; //a es un apuntador entonces pa al ser igualado a  'a' entonces se hacen modificaciones y toda modificacion en pa ser� una modificacion a 'a'
 for (i=0; i<10; i++)
     cout<< pa[i]<<" ";   
 arreglo(pa);
 cout<<endl;
 ppa=&pa;// a ppa se le asigna la direcci�n de  pa  
 for (i=0; i<10; i++)
   cout<< *(*ppa+i)<<" ";
   /**
   *(*ppa+i)
   *ppa apunta a la direcci�n de pa
   *ppa+i hace que se apute a la siguiente posici�n del arreglo pa
   *(*ppa+i) muestra lo que hay en la posici�n del arreglo pa
   */
    system("PAUSE");
    return EXIT_SUCCESS;
}
