/*
 * Nacionalidad.h
 *
 *  Created on: 9 may. 2018
 *      Author: mario
 */

#ifndef NACIONALIDAD_H_
#define NACIONALIDAD_H_
#include <iostream>
#include <string>
using namespace std;

/*Realizado por Mario Bermejo y Enrique Moreno
 *
 * Esta clase controla que se pueda almacenar una nacionalidad del archivo csv, asi como devolver la informacion contenida en el.
 * Como atributos tiene un string pais y un tipo int numero de personas.
 *
 *
 */

class Nacionalidad {

private:

	string pais;
	int numPersonas;

public:
	//Constructores
	/* Este metodo crea un objeto Nacionalidad vacio.
	 *PRE: no es necesaria ninguna precondicion.
	 *POST: Crea un objeto nacionalidad vacio.
	 *Parametros:
	 *
	 *
	 *Complejidad:O(1).
	 */
	Nacionalidad();

	/* Este metodo crea un objeto Nacionalidad lleno.
	 *PRE: Se debe tener la informacion del pais y el numero de personas.
	 *POST: Crea un objeto nacionalidad lleno.
	 *Parametros:
	 *string pais: tipo string que contiene el nombre del pais.
	 *int numPersonas: tipo int que contiene el numero de personas.
	 *
	 *Complejidad:O(1).
	 */
	Nacionalidad(string pais,int numPersonas);
	//Destructor
	/* Este metodo destruye un objeto Nacionalidad.
	 *PRE: Haber creado un objeto Nacionalidad.
	 *POST: Destruye un objeto Nacionalidad.
	 *Parametros:
	 *
	 *
	 *Complejidad:O(1).
	 */
	~Nacionalidad();

	/* Este metodo introduce un pais en un objeto Nacionalidad.
	 *PRE: Tener la informacion del pais.
	 *POST: Introduce un pais en un objeto Nacionalidad.
	 *Parametros:
	 *
	 *
	 *Complejidad:O(1).
	 */
	void setPais(string pais);

	/* Este metodo introduce un numero de personas en un objeto Nacionalidad.
	 *PRE: Tener la informacion del numero de personas.
	 *POST: Introduce un numero de personas en un objeto Nacionalidad.
	 *Parametros:
	 *
	 *
	 *Complejidad:O(1).
	 */
	void setnumPersonas(int numPersonas);

	/* Este metodo devuelve un pais de un objeto Nacionalidad.
	 *PRE: Tener la informacion del pais en un objeto Nacionalidad.
	 *POST: devuelve un pais de un objeto Nacionalidad.
	 *Parametros:
	 *
	 *
	 *Complejidad:O(1).
	 */
	string getPais();

	/* Este metodo devuelve un numero de personas de un objeto Nacionalidad.
	 *PRE: Tener la informacion del numero de personas en un objeto Nacionalidad.
	 *POST: devuelve un numero de personas de un objeto Nacionalidad.
	 *Parametros:
	 *
	 *
	 *Complejidad:O(1).
	 */
	int getnumPersonas ();

	/* Este metodo muestra la informacion de un objeto Nacionalidad.
	 *PRE: Tener un objeto Nacionalidad.
	 *POST: muestra la informacion de un objeto Nacionalidad.
	 *Parametros:
	 *
	 *
	 *Complejidad:O(1).
	 */
	void mostrar();


};

#endif /* NACIONALIDAD_H_ */
