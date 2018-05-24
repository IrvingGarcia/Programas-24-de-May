/* Alumno: Irving Efren Garcia Ramos    */
/* E-mail: irvin.16@outlook.es          */
/* Fecha de Creación: 22/05/2018        */
/* Fecha de actualización: 23/05/2018   */
/* Descripción: Implementación de
 funciones sobre la estructura producto */

#include <stdio.h>
#include <string.h>

/* Se incluyen los archivos necesarios */
#include "colores.h"
#include "prototipofunciones.h"
#include "enums.h"

/* Variable global inicializada en principal.c */
extern int numProductos;


Producto crearNuevoProducto(void)
{
   Producto producto;

     printf(_TBLANCO _NEGRITA "Introduce la marca del producto: "              _NNEGRITA _TVERDE);
     fgets(producto.marca, TAM_MARCA, stdin);                                    /* Solicita la marca del producto al usuario          */
     strcpy(producto.marca, strtok(producto.marca, "\n"));								    /* Elimina el salto de linea '\n' que genera fgets() */

     printf(_TBLANCO _NEGRITA "Introduce el nombre del producto: "           _NNEGRITA _TVERDE);
     fgets(producto.nombre, TAM_NOM, stdin);                                 /* Solicita el nombre del producto al usuario      */
     strcpy(producto.nombre, strtok(producto.nombre, "\n"));             /* Elimina el salto de linea '\n' que genera fgets() */

     printf(_TBLANCO _NEGRITA "Introduce el precio del producto: "                _NNEGRITA _TVERDE);
     scanf("%f", &producto.precio);
     while(getchar() != '\n'); /* Limpiar el buffer en caso de tener almacenado el salgo de linea */

     printf("\n\n");

  return producto;
}




void mostrarListaProducto(Producto listaProducto[], int ordenar)
{
       int arrayTemp[numProductos];
       for(int i = 0; i < numProductos; i++)
       {
           arrayTemp[i] = i;
       }
       if(ordenar == 1)            /* 1: ordenacion ascendente  */
       {
            memcpy(arrayTemp, ordenarAscendente(listaProducto, arrayTemp), sizeof(arrayTemp));   /* memcpy: permite compiar un arreglo a otro */
       } else if(ordenar == 2){    /* 2: ordenacion descendente */
            memcpy(arrayTemp, ordenarDescendente(listaProducto, arrayTemp), sizeof(arrayTemp));  /* memcpy: permite compiar un arreglo a otro */
       }
       mostrarEncabezadoTabla();

       for(int i = 0; i < numProductos; i++)
       {
             mostrarProducto(listaProducto[arrayTemp[i]]);
             printf("\n");
       }
}



void buscarProducto(Producto listaProducto[])
{
       int opcionBuscar;
       char nombreBuscar[TAM_NOM];            /* Almacena el nombre a buscar dentro de la estructura                */
       char marcaBuscar[TAM_MARCA];         /* Almacena la marca a buscar dentro de la estructura             */

       printf(_TAMARILLO _NEGRITA "\n\n3. B U S C A R  P R O D U C T O\n\n");
       printf(_TCYAN     _NEGRITA "Buscar producto por:\n\n");
       printf(_TBLANCO   _NEGRITA "\t1. Marca\n");
       printf(_TBLANCO   _NEGRITA "\t2. Nombre \n\n");

       printf(_TCYAN     _NEGRITA "Introduce una opcion: ");
       scanf("%d", &opcionBuscar);

       switch(opcionBuscar)
       {
             case _xNombre:
                 while(getchar() != '\n');     /* Limpiar el buffer en caso de tener almacenado el salgo de linea */

                 printf(_TCYAN _NEGRITA "\n\nIngrese el nombre del producto: ");
                 fgets(nombreBuscar, TAM_NOM, stdin);
                 strcpy(nombreBuscar, strtok(nombreBuscar, "\n"));

                 for(int i = 0; i < numProductos; i++)
                 {
                     if(strcmp(nombreBuscar, listaProducto[i].nombre) == 0)
                     {
                           mostrarEncabezadoTabla();
                           mostrarProducto(listaProducto[i]);
                     }
                 }
             break;

             case _xMarca:
                  while(getchar() != '\n');     /* Limpiar el buffer en caso de tener almacenado el salgo de linea */

                  printf(_TCYAN _NEGRITA "\n\nIntroduce la marca del producto: ");
                  fgets(marcaBuscar, TAM_MARCA, stdin);
                  strcpy(marcaBuscar, strtok(marcaBuscar, "\n"));

                  for(int i = 0; i < numProductos; i++)
                  {
                       if(strcmp(marcaBuscar, listaProducto[i].marca) == 0)
                       {
                            mostrarEncabezadoTabla();
                            mostrarProducto(listaProducto[i]);
                       }
                  }
             break;
         }
}



void actualizarProducto(Producto listaProducto[])
{
       int opcionBuscar;
       char nombreBuscar[TAM_NOM];            /* Almacena el nombre a buscar dentro de la estructura                */
	     char marcaBuscar[TAM_MARCA];         /* Almacena la marca a buscar dentro de la estructura             */

       printf(_TCYAN     _NEGRITA "Buscar el producto a actualizar por:\n\n");
       printf(_TBLANCO   _NEGRITA "\t1. Marca\n");
       printf(_TBLANCO   _NEGRITA "\t2. Nombre \n\n");

       printf(_TCYAN     _NEGRITA "Introduce una opcion: ");
       scanf("%d", &opcionBuscar);

         switch(opcionBuscar)
         {
             case _xNombre:
                    while(getchar() != '\n');     /* Limpiar el buffer en caso de tener almacenado el salgo de linea */

                    printf(_TCYAN _NEGRITA "\n\nIntroduce el nombre del producto: ");
                    fgets(nombreBuscar, TAM_NOM, stdin);
                    strcpy(nombreBuscar, strtok(nombreBuscar, "\n"));

                   for(int i = 0; i < numProductos; i++)
                   {
                         if(strcmp(nombreBuscar, listaProducto[i].nombre) == 0)
                         {
                                 mostrarEncabezadoTabla();
                                 mostrarProducto(listaProducto[i]);

                                 printf("\n\n");

                                listaProducto[i] = crearNuevoProducto();

                                mostrarEncabezadoTabla();
                                mostrarProducto(listaProducto[i]);

                                break;
                         }
                   }
             break;

             case _xMarca:
                  while(getchar() != '\n');     /* Limpiar el buffer en caso de tener almacenado el salgo de linea */

                  printf(_TCYAN _NEGRITA "\n\nIntroduce la marca del producto: ");
                  fgets(marcaBuscar, 50, stdin);
                  strcpy(marcaBuscar, strtok(marcaBuscar, "\n"));

                  for(int i = 0; i < numProductos; i++)
                  {
                       if(strcmp(marcaBuscar, listaProducto[i].marca) == 0)
                       {
                               mostrarEncabezadoTabla();
                               mostrarProducto(listaProducto[i]);

                               printf("\n\n");

                                listaProducto[i] = crearNuevoProducto();

                                mostrarEncabezadoTabla();
                                mostrarProducto(listaProducto[i]);

                           break;
                       }
                  }

             break;
         }
}



void eliminarProducto(Producto listaProducto[])
{
        int opcionBuscar;
        char nombreBuscar[TAM_NOM];            /* Almacena el nombre a buscar dentro de la estructura                */
	      char marcaBuscar[TAM_MARCA];         /* Almacena la matricula a buscar dentro de la estructura             */

        printf(_TCYAN     _NEGRITA "Eliminar producto por:\n\n");
        printf(_TBLANCO   _NEGRITA "1. Marca\n");
        printf(_TBLANCO   _NEGRITA "2. Nombre \n\n");

        printf(_TCYAN     _NEGRITA "Introduce una opcion: ");
        scanf("%d", &opcionBuscar);

        switch(opcionBuscar)
        {
             case _xNombre:
                  while(getchar() != '\n');     /* Limpiar el buffer en caso de tener almacenado el salgo de linea */

                  printf(_TCYAN _NEGRITA "\n\nIntroduce el nombre: ");
                  fgets(nombreBuscar, TAM_NOM, stdin);
                  strcpy(nombreBuscar, strtok(nombreBuscar, "\n"));

                  for(int i = 0; i < numProductos; i++)
                  {
                          if(strcmp(nombreBuscar, listaProducto[i].nombre) == 0)
                          {
                              mostrarEncabezadoTabla();
                              mostrarProducto(listaProducto[i]);

                              printf("\n\n");

                              printf(_TBLANCO _NEGRITA "\n\nPresione una (Y) si esta seguro de eliminar el registo:  "                _NNEGRITA _TVERDE);

                              char opcionEliminar;
                              while((opcionEliminar = getchar()) == 'Y')
                              {
                                    printf("\nSizeof: %lu\n", sizeof(* listaProducto));
                                    listaProducto = eliminarUnProducto(listaProducto, i);
                              }

                              printf("\n\n");
                              break;
                          }
                    }
             break;

              case _xMarca:
                   while(getchar() != '\n');     /* Limpiar el buffer en caso de tener almacenado el salgo de linea */

                   printf(_TCYAN _NEGRITA "\n\nIntroduce la matricula: ");
                   fgets(marcaBuscar, TAM_MARCA, stdin);
                   strcpy(marcaBuscar, strtok(marcaBuscar, "\n"));

                   for(int i = 0; i < numProductos; i++)
                   {
                         if(strcmp(marcaBuscar, listaProducto[i].marca) == 0)
                         {
                               mostrarEncabezadoTabla();
                               mostrarProducto(listaProducto[i]);

                               printf("\n\n");

                               printf(_TBLANCO _NEGRITA "\n\nPresione una (Y) si esta seguro de eliminar el registo:  "                _NNEGRITA _TVERDE);

                               char opcionEliminar;
                               while((opcionEliminar = getchar()) == 'Y')
                               {
                                     listaProducto = eliminarUnProducto(listaProducto, i);
                               }

                               printf("\n\n");
                               break;
                         }
                   }
        }
}



Producto * eliminarUnProducto(Producto listaProducto[], int posicion)
{
        if(posicion < (numProductos - 1))
        {
            for(int j = posicion; j < (numProductos-1); j++)
            {
                    strcpy(listaProducto[j].nombre,          listaProducto[j+1].nombre);
                    strcpy(listaProducto[j].marca,       listaProducto[j+1].marca);
                    listaProducto[j].precio     = listaProducto[j+1].precio;
            }
          }

           strcpy(listaProducto[numProductos-1].nombre,          "");
           strcpy(listaProducto[numProductos-1].marca,       "");
           listaProducto[numProductos-1].precio    = -1;

           numProductos--;

           printf("\n\nEl registro se ha eliminado exitosamente.\n\n");

    return listaProducto;
}
