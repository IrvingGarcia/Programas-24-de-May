/* Alumno: Irving Efren Garcia Ramos  */
/* E-mail: irvin.16@outlook.es        */
/* Fecha de Creación: 14/05/2018      */
/* Fecha de actualización:            */
/* Descripción: Implementación de las
funciones de ordenación               */

#include <string.h>
#include "prototipofunciones.h"

extern int numProductos;

int * ordenarAscendente(Producto listaProducto[], int arrayTemp[])
{
  for(int i = 0; i < numProductos; i++)
  {
      for(int j = i + 1; j < numProductos; j++)
      {
          if(strcmp(listaProducto[arrayTemp[i]].nombre, listaProducto[arrayTemp[j]].nombre) > 0)
          {
                int aux = arrayTemp[i];
                arrayTemp[i] = arrayTemp[j];
                arrayTemp[j] = aux;
          }
      }
  }
  return arrayTemp;
}



int * ordenarDescendente(Producto listaProducto[], int arrayTemp[])
{
     for(int i = 0; i < numProductos; i++)
     {
           for(int j = i + 1; j < numProductos; j++)
           {
                 if(strcmp(listaProducto[arrayTemp[i]].nombre, listaProducto[arrayTemp[j]].nombre) < 0)
                 {
                        int aux = arrayTemp[i];
                        arrayTemp[i] = arrayTemp[j];
                        arrayTemp[j] = aux;
                 }
           }
     }
  return arrayTemp;
}
