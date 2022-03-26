/*
 * gestorEstudios.h
 *
 *  Created on: 9 may. 2018
 *      Author: enrique
 */

#ifndef GESTORESTUDIOS_H_
#define GESTORESTUDIOS_H_
#include"Estudios.h"
#include"listapi.h"
#include"Utils.h"

/*Realizado por Mario Bermejo y Enrique Moreno
 *
 * Esta clase controla que se pueda almacenar lista de objetos nivel de estudios, asi como devolver la informacion contenida en él. Cabe destacar que de en cada dato demografica hay una lista de nivel de estudios.
 * Como atributos tiene una lista de nivel estudios.
 *
 *
 */

class gestorEstudios {

private:

	ListaPI<Estudios*>*pEstudios;

public:
	//Constructores
	/*Se encarga de crear una lista de nivel estudios vacia.
	 *PRE: No existen precondiciones.
	 *POST: Crea un objeto de lista de nivel estudios vacia.
	 *Complejidad: O(1)
	 */
	gestorEstudios();
	/*Se encarga de crear una lista de nivel estudios llena.
	 *PRE: Tener la informacion del nivel de estudios.
	 *POST: Crea una lista de nivel estudios llena.
	 *Complejidad: O(1)
	 */
	gestorEstudios(string nivest);
	//Destructor
	/*Se encarga de destruir una lista de nivel estudios.
	 *PRE: Tener la lista creada.
	 *POST:Destruye la lista de nivel estudios.
	 *Complejidad: O(1)
	 */
	~gestorEstudios();

	//ALGORITMO 8
	/*Metodo que se encarga del algoritmo 8.
	 *PRE: Haber inicializado la lista vacia.
	 *POST: Rellena la lista de objetos de estudio segun condicion .
	 *Complejidad: O(n²)
	 */
	void InsertarEstudios(ListaPI<Estudios*>*&pEstudiosAux);
	//Mostrar
	/*Se encarga de mostrarla lista de nivel estudios.
	 *PRE: Tener la lista creada.
	 *POST: Muestra la lista de nivel estudios.
	 *Complejidad: O(1)
	 */
	void mostrar();
};

#endif /* GESTORESTUDIOS_H_ */
