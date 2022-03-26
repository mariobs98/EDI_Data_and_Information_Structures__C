/*
 * gestorLugardeNacimiento.h
 *
 *  Created on: 9 abr. 2018
 *      Author: enrique
 */

#ifndef GESTORLUGARDENACIMIENTO_H_
#define GESTORLUGARDENACIMIENTO_H_
#include "LugarNacimiento.h"
#include "listapi.h"
#include "Utils.h"
/*Realizado por Mario Bermejo y Enrique Moreno
 *
 * Esta clase controla que se pueda almacenar lista de objetos lugar de nacimiento, asi como devolver la informacion contenida en él. Cabe destacar que de en cada dato demografica hay una lista de lugar de nacimiento.
 * Como atributos tiene una lista de lugar de nacimiento.
 *
 *
 */

class gestorLugardeNacimiento {
private:

	ListaPI<LugarNacimiento*>*LiN;

public:
	//Constructores
	/*Se encarga de crear una lista de lugar nacimiento vacia.
	 *PRE: No existen precondiciones.
	 *POST: Crea un objeto de lista de lugar nacimiento vacia.
	 *Complejidad: O(1)
	 */
	gestorLugardeNacimiento();

	/*Se encarga de crear un objeto lista de lugar nacimiento llena.
	 *PRE: Tener la informacion del lugar nacimiento.
	 *POST: Crea una lista de lugar nacimiento llena.
	 *Complejidad: O(n)
	 */
	gestorLugardeNacimiento(string text);

	//Destructor
	/*Se encarga de destruir una lista de lugar nacimiento.
	 *PRE: Tener la lista creada.
	 *POST:Destruye la lista de lugar nacimiento.
	 *Complejidad: O(n)
	 */
	~gestorLugardeNacimiento();

	//ALGORITMO 6
	/*Metodo que se encarga insertar lugares de nacimiento.
	 *PRE: Se tiene que tener la lista inicializada vacia.
	 *POST: inserta lugares de nacimiento.
	 *Parametros:
	 *-ListaPI<LugarNacimiento*>*&pLugNac: se trata de la lista que contiene los lugares de nacimiento que se van a utilizar.
	 *
	 *Complejidad:O(n²).
	 */
	void insertarLugarNacimiento(ListaPI<LugarNacimiento*>*&pLugNac);

    //algoritmo10
	/*Metodo que se encarga insertar lugares de nacimiento segun provincia.
	 *PRE: Se tiene que tener la lista inicializada vacia.
	 *POST: inserta lugares de nacimiento.
	 *Parametros:
	 *-ListaPI<LugarNacimiento*>*&pLugNac: se trata de la lista que contiene los lugares de nacimiento que se van a insertar.
	 *
	 *Complejidad:O(n²).
	 */
    void algoritmo10provincias(ListaPI<LugarNacimiento*>*&LNAux, string provincia);

    //algoritmo11
	/*Metodo que se encarga insertar lugares de nacimiento.
	 *PRE: Se tiene que tener la lista inicializada vacia.
	 *POST: inserta lugares de nacimiento.
	 *Parametros:
	 *-ListaPI<LugarNacimiento*>*&pLugNac: se trata de la lista que contiene los lugares de nacimiento que se van a utilizar.
	 *
	 *Complejidad:O(n).
	 */
    void obtenerdatosNacimientos(ListaPI<LugarNacimiento*>*&LNAux);

    //algoritmo12
	/*Metodo que se encarga insertar lugares de nacimiento.
	 *PRE: Se tiene que tener la lista inicializada vacia.
	 *POST: inserta lugares de nacimiento.
	 *Parametros:
	 *-ListaPI<LugarNacimiento*>*&pLugNac: se trata de la lista que contiene los lugares de nacimiento que se van a utilizar.
	 *
	 *Complejidad:O(n).
	 */
    void MuestrapersonasProvincia(ListaPI<LugarNacimiento*>*&LNAux);

    //mostrar
	/*Metodo para mostrar la lista de lugares de nacimiento.
	 *PRE: Se tiene que tener la lista .
	 *POST: muestra los lugares de nacimiento de la lista.
	 *Parametros:
	 *
	 *
	 *Complejidad:O(n).
	 */
    void mostrar();

};

#endif /* GESTORLUGARDENACIMIENTO_H_ */
