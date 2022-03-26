/*
 * GestorGeneral.h
 *
 *  Created on: 23 abr. 2018
 *      Author: mario
 */

#ifndef GESTORGENERAL_H_
#define GESTORGENERAL_H_
#include "gestorBarrios.h"
#include "gestorPadron.h"
#include "timer.h"
#include <iostream>
/*
 * Realizado por Mario Bermejo y Enrique Moreno
 * Esta clase controla los algoritmos a realizar junto con la carga de los datos en la estructura diseñada
 *
 * Los atributos privados son un puntero a un gestor de Barrios que consiste en una lista de barrios y lo mismo pero con datos del padron.
 * */
class GestorGeneral {

private:

	gestorBarrios *gb;
	gestorPadron *gp;

public:
	/*PRE=Archivos necesitados en el proyecto
	 *POST= llena cada estructura de datos con sus datos correspondientes
	 *Complejidad= O(1)
	 */
	GestorGeneral();
	/*PRE=
	 *POST= Vacia y borra todas las estructuras
	 *Complejidad= O(n)
	 */
	~GestorGeneral();

	//CARGAS

	/*PRE=
	 *POST= //Inicia todos los modulos de cargar datos del GestorGeneral.
	 *Complejidad= O(1)
	 */
	void carga();


	/*PRE=
	 *POST= 	//Inicia el modulo del gestorBarrios para cargar la lista de
				//todos los Barrios.
	 *Complejidad= O(1)
	 */
	void cargarBarrios();


	/*PRE=
	 *POST= 	//Inicia el modulo del gestorPadron para cargar la lista de
				//todos los Datos Demograficos de todas las Vias.
	 *Complejidad= O(1)
	 */
	void cargarDatosdemograficos();


	/*PRE=
	 *POST= //Introduce a cada Barrio sus Vias correspondientes junto con su dato demografico.
	 *Complejidad= O(n2)
	 */
	void cargarViasYPadron();


	/*PRE=Estructuras de datos cargadas
	 *POST= //Muestra la lista con los Datos Demograficos.
	 *Complejidad= O(1)
	 */
	void mostrarListaPadron();


	/*PRE=Estructuras de datos cargadas
	 *POST= 	//Muestra la lista con los Barrios.
	 *Complejidad= O(1)
	 */
	void mostrarListaBarrios();



	/*PRE=Estructuras de datos cargadas
	 *POST= //Muestra todas las vias de un barrio introducido. Las muestra alfabeticamente.
	 *Complejidad= O(1)
	 */
	void algoritmo_2();


	/*PRE=Estructuras de datos cargadas
	 *POST= //Mostrar las vías que pertenecen a varios barrios
	 *Complejidad= O(n)
	 */
	void algoritmo_3();


	/*PRE=Estructuras de datos cargadas
	 *POST= //Muestra el número de habitantes de Cáceres agrupados por rango de edad cada 10 años.
	 *Complejidad= O(1)
	 */
	void algoritmo_4();


	/*PRE=Estructuras de datos cargadas
	 *POST= //Muestra todas las nacionalidades de los habitantes de cáceres
			//ordenados de forma descendente por número de habitantes.
	 *Complejidad= O(n)
	 */
	void algoritmo_5();
	//Dada una Lista y un objeto nacionalidad,las organiza en orden descente segun el numero de personas
	/*PRE=Estructura auxiliar tipo lista vacia
	 *POST= Devuelve la lista llena en orden
	 *Complejidad= O(n)
	 */
	void insertarNacionalidadEnOrden(ListaPI<Nacionalidad*>*&pNacionalidades,Nacionalidad *n);


	/*PRE=Estructuras de datos cargadas
	 *POST=	//Muestra el número de habitantes por provincia de nacimiento, ordenados
			//alfabéticamente por provincia, excluyendo habitantes no nacidos en España.
	 *Complejidad= O(n)
	 */
	void algoritmo_6();
	//Dada una Lista y un objeto lugar nacimiento,las organiza en orden alfabetico segun la provincia
	/*PRE=Estructura auxiliar tipo lista vacia
	 *POST= Devuelve la lista llena en orden
	 *Complejidad= O(n)
	 */
	void insertarLugarNacimientoEnOrden(ListaPI<LugarNacimiento*>*&pLugNacAux,LugarNacimiento *ln);

	//Muestra el barrio con mayor número de habitantes para un rango de edad
	//indicado por el usuario por consola.
	/*PRE=Estructuras de datos cargadas
	 *POST= llena cada barrio de gb con sus vias y padron
	 *Complejidad= O(n2)
	 */
	void algoritmo_7();


	/*PRE=Estructuras de datos cargadas
	 *POST= //Genera un fichero con el nivel de estudios de todos los ciudadanos de un barrio indicado y el
			//número de habitantes para cada nivel, ordenado de mayor a menor por el número de habitantes.
	 *Complejidad= O(1)
	 */
	void algoritmo_8();
	//Dada una Lista y un objeto Estudio,las organiza en orden de descendente segun el numero de habitantes
	/*PRE=Estructura auxiliar tipo lista vacia
	 *POST= Devuelve la lista llena en orden
	 *Complejidad= O(n)
	 */
	void insertarEstudiosEnOrden(ListaPI<Estudios*>*&pEstudiosAux,Estudios *e);


	/*PRE=Estructuras de datos cargadas
	 *POST= 	//Muestra el Barrio con mayor porcentaje de hombres y el Barrio
				//con mayor porcentaje de mujeres.
	 *Complejidad= O(1)
	 */
	void algoritmo_9();


	/*PRE=Estructuras de datos cargadas
	 *POST= 	//Genera un fichero que contiene un listado con el nombre y número de habitantes que
				//proceden de los pueblos de una provincia, detallada por el usuario por consola.
	 *Complejidad= O(n)
	 */
	void algoritmo_10();


	/*PRE=Estructuras de datos cargadas
	 *POST= //Genera un fichero con el listado de los lugares de nacimiento de los vecinos de una
			//calle, introducida por el usuario por consola
	 *Complejidad= O(n)
	 */
	void algoritmo_11();


	/*PRE=Estructuras de datos cargadas
	 *POST= //Muestra el número de personas nacidas en una provincia dada
			//para todas las vías que comiencen por una subcadena determinada
	 *Complejidad= O(n)
	 */
	void algoritmo_12();

	//Ejecuta cada algoritmo con un caso dado y muestra el tiempo que tarda
	void pruebasTiempo();
	void algoritmoP_2();
	void algoritmoP_3();
	void algoritmoP_4();
	void algoritmoP_5();
	void algoritmoP_6();
	void algoritmoP_7();
	void algoritmoP_8();
	void algoritmoP_9();
	void algoritmoP_10();
	void algoritmoP_11();
	void algoritmoP_12();
};


#endif /* GESTORGENERAL_H_ */
