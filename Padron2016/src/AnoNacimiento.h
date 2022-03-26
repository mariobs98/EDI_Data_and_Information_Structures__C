/*
 * AnoNacimiento.h
 *
 *  Created on: 9 may. 2018
 *      Author: mario
 */

#ifndef ANONACIMIENTO_H_
#define ANONACIMIENTO_H_
#include <iostream>
#include <string>
using namespace std;
/*Realizado por Mario Bermejo y Enrique Moreno
 *
 * Esta clase controla que se pueda almacenar un año de nacimiento del archivo csv, asi como devolver la informacion contenida en el.
 * Como atributos tiene dos int el año nacimiento, numero de personas.
 *
 *
 */
class AnoNacimiento {
private:
	int ano;
	int numPersonas;

public:
	//Constructores
	/* Este metodo crea un objeto año nacimiento vacio.
	 *PRE: no es necesaria ninguna precondicion.
	 *POST: Crea un objeto demografico vacio.
	 *Parametros:
	 *
	 *
	 *Complejidad:O(1).
	 */
	AnoNacimiento();

	/* Este metodo crea un objeto año nacimiento lleno.
	 *PRE: Tener un año de nacimiento valido, y un numero de personas valido.
	 *POST: Crea un objeto año nacimiento lleno.
	 *Parametros:
	 *int ano: tipo int que contiene el año de nacimiento.
	 *int numPersonas: tipo int que contiene el numero de personas.
	 *
	 *Complejidad:O(1).
	 */
	AnoNacimiento(int ano,int numPersonas);
	//Destructores
	/* Este metodo destruye un objeto año nacimiento.
	 *PRE: Haber creado un objeto año nacimiento.
	 *POST: Destruye un objeto año nacimiento.
	 *Parametros:
	 *
	 *
	 *Complejidad:O(1).
	 */
	~AnoNacimiento();

	/* Este metodo introduce un año de nacimiento en el objeto año de nacimiento.
	 *PRE: Tener un año nacimiento.
	 *POST: Introduce un año de nacimiento en el objeto año de nacimiento.
	 *Parametros:
	 *int ano: contiene el año de nacimiento.
	 *
	 *Complejidad:O(1).
	 */
	void setano(int ano);

	/* Este metodo introduce un numero de personas en el objeto año de nacimiento.
	 *PRE: Tener un numero de personas.
	 *POST: Introduce un numero de personas en el objeto año de nacimiento.
	 *Parametros:
	 *int numPersonas: tipo int que contiene el numero de personas.
	 *
	 *Complejidad:O(1).
	 */
	void setnumPersonas(int numPersonas);

	/* Este metodo devuelve un año de nacimiento del objeto año de nacimiento.
	 *PRE: Tener informacion de año nacimiento en el objeto.
	 *POST: Devuelve un año de nacimiento en el objeto año de nacimiento.
	 *Parametros:
	 *
	 *
	 *Complejidad:O(1).
	 */
	int getano();

	/* Este metodo devuelve un numero de personas del objeto año de nacimiento.
	 *PRE: Tener informacion de un numero de personas en el objeto.
	 *POST: Devuelve un numero de personas en el objeto año de nacimiento.
	 *Parametros:
	 *
	 *
	 *Complejidad:O(1).
	 */
	int getnumPersonas();

	/* Este metodo muestra la informacion del objeto año de nacimiento.
	 *PRE: Tener un objeto año de nacimiento.
	 *POST: Muestra la informacion del objeto año de nacimiento.
	 *Parametros:
	 *
	 *
	 *Complejidad:O(1).
	 */
	void mostrar();
};

#endif /* ANONACIMIENTO_H_ */
