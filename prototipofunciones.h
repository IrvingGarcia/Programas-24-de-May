/* Alumno: Irving Efren Garcia Ramos */
/* E-mail: irvin.16@outlook.es            */
/* Fecha de Creación: 14/05/2018          */
/* Fecha de actualización:                */
/* Descripción: Definición de constantes,
 estructura y prototipo de funciones      */

#ifndef PROTOTIPOFUNCIONES_H_
#define PROTOTIPOFUNCIONES_H_

#define TAM_NOM      50        /* Definicion del tamanio del arreglo unidimensional */
#define TAM_MARCA      12        /* Tamanio de la marca del producto               */
#define TOTAL_PRODUCTO 30         /* Tamanio total del producto */



/* Se define una estructura para modelar los datos de una producto. */
/* Los miembros de la estructura son:                             */
/*                                    - nombre                    */
/*                                    - marca                     */
/*                                    - precio                    */
typedef struct
{
	char nombre[TAM_NOM];
	char marca[TAM_MARCA];
	float precio;
}Producto;


/* Funciones que imprimen mensajes en pantalla */
void menuPrincipal(void);
void mostrarEncabezadoTabla(void);
void mostrarProducto(Producto);
void detenerPantalla(void);


/* Funciones que realizan las operaciones sobre la lista de alumnos */
Producto crearNuevoProducto(void);
void mostrarListaProducto(Producto [], int);
void buscarProducto(Producto []);
void actualizarProducto(Producto []);
void eliminarProducto(Producto []);


/* Funcion que permite eliminar el alumno, es invocada por la funcion eliminarAlumno() */
Producto * eliminarUnProducto(Producto [], int);


/* Funciones que permiten ordenar los datos de los alumnos */
int * ordenarAscendente(Producto [], int []);
int * ordenarDescendente(Producto [], int []);


#endif
