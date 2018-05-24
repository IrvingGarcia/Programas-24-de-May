/* Alumno: Irving Efren Garcia Ramos  */
/* E-mail: irvin.16@outlook.es        */
/* Fecha de Creación: 21/05/2018      */
/* Fecha de actualización: 23/05/2018 */
/* Descripción: Programa donde se
ejemplifican los archivos .h y .c     */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "colores.h"   /* Se definen las secuencias para los colores */
#include "prototipofunciones.h"  /* Se definen todos los prototipos de funciones */
#include "enums.h"  /* Se definen los enums para los menus */

/* Los #define estan en el archivo de prototipofunciones.h */

int numProductos;          /* Variable Global: se declara aqui para la función main()
                          pero se utiliza en: operacionproducto.c y ordenacion.c */
int main(void)
{
     Producto listaProducto[TOTAL_PRODUCTO];    /* Declaración de una variable de arreglo de estructura producto[] */
     int opcion;                   /* Variable que controla las opciones del menu principal */

     do {
         menuPrincipal();            /* Se invoca a la  función menuprincipal() en operacionespantalla.c */

         printf(_TCYAN _NEGRITA"\n\nIngrese la opcion que desea realizar: ");
         scanf("%d", &opcion);

         switch (opcion) {

             case CREAR:
                     while (getchar() != '\n');  /* Limpiar el búfer en caso de salto de linea */
                     printf(_TROJO _NEGRITA"\n\n1. C R E A C I O N  D E  P R O D U C T O S\n\n");
                     printf(_TAMARILLO _NEGRITA"\n\nIntroduce el numero de productos: "_TVERDE);
                     scanf("%d", &numProductos);
                     printf("\n\n"_ARESET);

                     for(int i=0; i < numProductos; i++)
                     {
                         while (getchar() != '\n');    /* Limpiar el búfer en caso de salto de linea */
                         listaProducto[i] = crearNuevoProducto(); // Se invoca la función CrearNuevoProducto()implementada en operacionesProducto.c
                     }
                     while (getchar() != '\n');
                     detenerPantalla();       /* Se invoca la función detenerpantalla() implementada en operacionespantalla.c */
             break;

             case  LISTAR:
                   while (getchar() != '\n');  /* Limpiar el búfer en caso de salto de linea */
                   printf("\n\n2. L I S T A  D E  P R O D U C T O S\n\n");
                   mostrarListaProducto(listaProducto, 0);   /* Se invoca a la función de mostrarListaProducto() implementada en operacionesProducto.c */
                   detenerPantalla();      /* Se invoca a la función de detenerpantalla() implementada en operacionespantalla.c */
             break;


             case LISTAR_ASC:
                   while(getchar() != '\n');   /* Limpiar el búfer en caso de salto de linea */
                   printf(_TAMARILLO _NEGRITA"\n\n3. L I S T A R  P R O D U C T O S  A S C E N D E N T E\n\n");
                   mostrarListaProducto(listaProducto, 1);   /* Se invoca a la función de detenerpantalla() implementada en operacionespantalla.c */
                   detenerPantalla();   /* Se invoca a la función de detenerpantalla() implementada en operacionespantalla.c */
             break;


             case LISTAR_DES:
                   while(getchar() != '\n');   /* Limpiar el búfer en caso de salto de linea */
                   printf(_TAMARILLO _NEGRITA"\n\n4. L I S T A R  P R O D U C T O S  D E S C E N D E N T E\n\n");
                   mostrarListaProducto(listaProducto, 2);   /* Se invoca a la función de detenerpantalla() implementada en operacionespantalla.c */
                   detenerPantalla();   /* Se invoca a la función de detenerpantalla() implementada en operacionespantalla.c */
             break;


             case BUSCAR:
                   while(getchar() != '\n');  /* Limpiar el búfer en caso de salto de linea */
                   printf("\n\n4. B U S C A R  P R O D U C T O\n\n");
                   buscarProducto(listaProducto);  /* Se invoca la función de buscarProducto() immplementada en operacionesProducto.c */
                   detenerPantalla();    /* Se invoca a la función de detenerpantalla() implementada en operacionespantalla.c */
             break;


             case ACTUALIZAR:
                   while(getchar() != '\n');
                   printf(_TAMARILLO _NEGRITA"\n\n5. A C T U A L I Z A R  P R O D U C T O\n\n");
                   actualizarProducto(listaProducto);  /* Se invoca la función actualizarProducto() implementada en operacionesProducto.c */
                   while(getchar() != '\n');   /* Limpiar el búfer en caso de salto de linea */
                   detenerPantalla();     /* Se invoca la función detenerpantalla() implementada en operacionespantalla.c */
             break;


             case ELIMINAR:
                   while(getchar() != '\n');
                   printf(_TAMARILLO _NEGRITA"\n\n6. E L I M I N A R  P R O D U C T O\n\n");
                   eliminarProducto(listaProducto);   /* Se invoca la función eliminarProducto() implementada en operacionesProducto.c */
                   detenerPantalla(); /* Se invoca la función detenerpantalla() implementada en operacionespantalla.c */
             break;


             case SALIR:
                   system("clear");      /* Limpiar la pantalla, antes de terminar la ejecución */
                   exit(0);             /* Termina la ejecución del programa */

         }

     } while(opcion != SALIR);

    return 0;
}
