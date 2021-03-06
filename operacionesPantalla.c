/* Alumno: Irving Efren Garcia Ramos       */
/* E-mail: irvin.16@outlook.es             */
/* Fecha de Creación: 22/05/2018           */
/* Fecha de actualización: 23/05/2018      */
/* Descripción: Implementación de funciones
con datos mostrados en pantalla            */

#include <stdio.h>
#include <stdlib.h>

#include "colores.h"
#include "prototipofunciones.h"

void menuPrincipal(void)
{
  system("clear");  /* Limpia toda la pantalla.           */
  puts("");         /* Haciendo salto de lina con puts(). */

  printf(_FVERDE _TCYAN  _NEGRITA _SUBRAYADO "\nT I E N D A  D E  T E C N O L O G I A S" _ARESET);

  printf(_TMORADO _NEGRITA "\nM\n");

  printf(_TAMARILLO _NEGRITA "\n\t1. Ingresar producto");
  printf(_TAMARILLO _NEGRITA "\n\t2. Lista de productos");
  printf(_TAMARILLO _NEGRITA "\n\t3. Lista de productos ascendente");
  printf(_TAMARILLO _NEGRITA "\n\t4. Lista de productos descendente");
  printf(_TAMARILLO _NEGRITA "\n\t5. Buscar producto");
  printf(_TAMARILLO _NEGRITA "\n\t6. Actualizar producto");
  printf(_TAMARILLO _NEGRITA "\n\t7. Eliminar producto");
  printf(_TAMARILLO _NEGRITA "\n\t8. Salir");
}

void mostrarEncabezadoTabla(void)
{
    printf(_TROJO     _NEGRITA);
    printf("   MARCA   |   NOMBRE    |      PRECIO     |");
    printf("\n--------------------------------------------------------------------------------\n");
}

void mostrarProducto(Producto producto)
{
  printf(_TBLANCO _NEGRITA);
  printf("  %-12s|  %-1s      | %.2f|", producto.marca, producto.nombre, producto.precio);
}

void detenerPantalla(void)
{
  char c;                           /* Lee un caracter y valida el salto de linea para salir de la opcion. */
  printf(_TAMARILLO _NEGRITA "\n\nPresiones Enter para salir: ");
  while((c=getchar()) != '\n')  /* Solicita un enter al usuario para reiniciar el menu principal */
  {}
}
