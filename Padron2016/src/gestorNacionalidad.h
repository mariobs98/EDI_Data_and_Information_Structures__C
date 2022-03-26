/*
 * gestorNacionalidad.h
 *
 *  Created on: 9 may. 2018
 *      Author: mario
 */

#ifndef GESTORNACIONALIDAD_H_
#define GESTORNACIONALIDAD_H_
#include "Nacionalidad.h"
#include "listapi.h"
#include "Utils.h"
using namespace std;

/*Realizado por Mario Bermejo y Enrique Moreno
 *
 * Esta clase controla que se pueda almacenar lista de objetos nacionalidad, asi como devolver la informacion contenida en él. Cabe destacar que de en cada dato demografica hay una lista de nacionalidad.
 * Como atributos tiene una lista de lugar de nacimiento.
 *
 *
 */

class gestorNacionalidad {

	ListaPI<Nacionalidad*>*pNacionalidad;

public:
	//constructores
	/*Se encarga de crear una lista de nacionalidad vacia.
	 *PRE: No existen precondiciones.
	 *POST: Crea un objeto de lista de nacionalidad vacia.
	 *Complejidad: O(1)
	 */
	gestorNacionalidad();

	/*Se encarga de crear una lista de nacionalidad llena.
	 *PRE: Tener la informacion de la nacionalidad.
	 *POST: Crea un objeto de lista de nacionalidad llena.
	 *Complejidad: O(n)
	 */
	gestorNacionalidad(string nacional);

	//Destructor
	/*Se encarga de destruir una lista de nacionalidad.
	 *PRE: Tener la lista creada.
	 *POST:Destruye la lista de nacionalidad.
	 *Complejidad: O(n)
	 */
	~gestorNacionalidad();

	//ALGORITMO 5
	/*Se encarga de insertar objetos de nacionalidad en una lista auxiliar.
	 *PRE: Tener la lista creada vacia.
	 *POST:devuelve una lista llena de nacionalidades segun condicion.
	 *Parametros:
	 *-ListaPI<Nacionalidad*>*&pNacionalidades:se trata de la lista que contiene las nacionalidades que se van a utilizar.
	 *Complejidad: O(n)
	 */
	void insertarNacionalidades(ListaPI<Nacionalidad*>*&pNacionalidades);
	//mostrar
	/*Metodo para mostrar la lista de nacionalidades.
	 *PRE: Se tiene que tener la lista .
	 *POST: muestra las nacionalidades de la lista.
	 *Parametros:
	 *
	 *
	 *Complejidad:O(n).
	 */
	void mostrar();
};

#endif /* GESTORNACIONALIDAD_H_ */
