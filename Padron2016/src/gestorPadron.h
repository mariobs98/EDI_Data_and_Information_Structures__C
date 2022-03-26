/*
 * gestorPadron.h
 *
 *  Created on: 22 abr. 2018
 *      Author: mario
 */

#ifndef GESTORPADRON_H_
#define GESTORPADRON_H_
#include"datosDemograficos.h"
#include "listapi.h"
#include <fstream>

/*
 * Realizado por Mario Bermejo y Enrique Moreno
 * Esta clase almacena los datos demograficos de todas las vias en una lista junto con todos los metodos para realizar o bien carga de datos
 *  o algoritmos sobre la lista
 *
 * El atributo privado es una lista de Datos demograficos que se inicia vacia.
 * Los publicos son los metodos mencionados anteriormente.
 * */
class gestorPadron {

private:

	ListaPI<datos_Demograficos*>*pPadron;

public:

	//Inicia la lista  vacia.
	gestorPadron();

	//Borra la lista y la vacia.
	 //Complejidad= O(n)
	~gestorPadron();

	//Llena la lista de todos los datos demograficos de todas las vias.
	/*PRE=Lista iniciada y vacia
	 *POST= Llejna la lista con todos los datos demograficos
	 *Complejidad= O(n2)
	 */
	void cargarDatos_Demograficos();

	//Busca y devuelve el dato demografico a buscar segun el codigo de via dado
	/*PRE=Lista llena con datos demograficos
	 *POST= devuelve en dd el dato demografico correspondiente al codigo de la via
	 *Complejidad= O(n)
	 */
	void buscarDatosDemografico(int codigoVia,datos_Demograficos *&dd);

	/*PRE=Lista llena con datos demograficos
	 *POST= devuelve un enntero con la suma de hombres y mujeres de todo caceres,el total de habitantes
	 *Complejidad= O(n)
	 */
	int numeroTotalHabitantes();

	/*PRE=Lista llena con datos demograficos
	 *POST= muestra por consola la lista
	 *Complejidad= O(n)
	 */
	void mostrargestorPadron();

	//algoritmo_4
	/*PRE=Lista llena con datos demograficos
	 *POST= Muestra por consola las edades de toda la poblacion de caceres ordenadas de 0 a 100 en grupos de 10
	 *Complejidad= O(n)
	 */
	void algoritmo4MuestraPersonas();

    //algoritmo_10
	/*PRE=Lista llena con datos demograficos
	 *POST= Devuelve LNAux llena con las personas nacidas en una determinada provincia,la cual es proporcionada por el ususario tambien
	 *Complejidad= O(n)
	 */
	void algoritmo10(ListaPI<LugarNacimiento*>*&LNAux,string provincia);
};

#endif /* GESTORPADRON_H_ */
