//============================================================================
// Name        : UI.h
// Author      : profesores de la asignatura EDI
// Version     : curso 17/18
// Copyright   :
// Description : Interfaz de usuario
//============================================================================


#ifndef UI_H_
#define UI_H_
#include "GestorGeneral.h"
#include "PRUEBASclases.h"
class UI {

private:
	// TODO instanciar la clase principal
	GestorGeneral *gg;

	int  menu     ();
	void ejecutar ();


public:

	UI();
	//Realiza la carga de todos los datos a usar en la ejecucion de los algoritmos.
	void algoritmo_1();

	//Muestra todas las vias de un barrio introducido. Las muestra alfabeticamente.
	void algoritmo_2();

	//Mostrar las vías que pertenecen a varios barrios
	void algoritmo_3();

	//Muestra el número de habitantes de Cáceres agrupados por rango de edad cada 10 años.
	void algoritmo_4();

	//Muestra todas las nacionalidades de los habitantes de cáceres
	//ordenados de forma descendente por número de habitantes.
	void algoritmo_5();

	//Muestra el número de habitantes por provincia de nacimiento, ordenados
	//alfabéticamente por provincia, excluyendo habitantes no nacidos en España.
	void algoritmo_6();

	//Muestra el barrio con mayor número de habitantes para un rango de edad
	//indicado por el usuario por consola.
	void algoritmo_7();

	//Genera un fichero con el nivel de estudios de todos los ciudadanos de un barrio indicado y el
	//número de habitantes para cada nivel, ordenado de mayor a menor por el número de habitantes.
	void algoritmo_8();

	//Muestra el Barrio con mayor porcentaje de hombres y el Barrio
	//con mayor porcentaje de mujeres.
	void algoritmo_9();

	//Genera un fichero que contiene un listado con el nombre y número de habitantes que
	//proceden de los pueblos de una provincia, detallada por el usuario por consola.
	void algoritmo_10();

	//Genera un fichero con el listado de los lugares de nacimiento de los vecinos de una
	//calle, introducida por el usuario por consola
	void algoritmo_11();

	//Muestra el número de personas nacidas en una provincia dada
	//para todas las vías que comiencen por una subcadena determinada
	void algoritmo_12();

	//Ejecuta cada algoritmo con un caso dado y muestra el tiempo que tarda
	void pruebasTiempo();

	void ejecutarpruebasclases();

	~UI();
};

#endif /* UI_H_ */
