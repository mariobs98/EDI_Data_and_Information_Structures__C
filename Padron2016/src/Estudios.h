/*
 * Estudios.h
 *
 *  Created on: 9 may. 2018
 *      Author: enrique
 */

#ifndef ESTUDIOS_H_
#define ESTUDIOS_H_
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

/*Realizado por Mario Bermejo y Enrique Moreno
 *
 * Esta clase controla que se pueda almacenar un estudio del archivo csv, asi como devolver la informacion contenida en el.
 * Como atributos tiene un string NivelEstudios y un tipo int numero personas.
 *
 *
 */

class Estudios {
private:
	string nivelEstudios;
	int NumPersonas;
public:
	//Constructores
	/* Este metodo crea un objeto estudios vacio.
	 *PRE: no es necesaria ninguna precondicion.
	 *POST: Crea un objeto estudios vacio.
	 *Parametros:
	 *
	 *
	 *Complejidad:O(1).
	 */
	Estudios();

	/* Este metodo crea un objeto estudios lleno.
	 *PRE: Tener informacion del nivel de estudios y del numero de personas.
	 *POST: Crea un objeto estudios lleno.
	 *Parametros:
	 *string nivelEstudios: tipo string que contiene el nivel de estudios.
	 *int NumPersonas: tipo int que contiene el numero de personas
	 *
	 *Complejidad:O(1).
	 */
	Estudios(string nivelEstudios,int NumPersonas);
	//Destructor
	/* Este metodo destruye un objeto estudios .
	 *PRE: Haber creado un objeto estudios.
	 *POST: Destruye un objeto estudios.
	 *Parametros:
	 *
	 *
	 *Complejidad:O(1).
	 */
	~Estudios();
	//SEts
	/* Este metodo introduce un nivel de studios en un objeto estudios.
	 *PRE: Haber obtenido informacion sobre el nivel de estudios.
	 *POST: Introduce un nivel de studios en un objeto estudios.
	 *Parametros:
	 *
	 *
	 *Complejidad:O(1).
	 */
	void setnivelEstudios(string nivelEstudios);

	/* Este metodo introduce un numero de personas en un objeto estudios.
	 *PRE: Haber obtenido informacion sobre el numero de personas.
	 *POST: Introduce un numero de personas en un objeto estudios.
	 *Parametros:
	 *
	 *
	 *Complejidad:O(1).
	 */
	void setNumPersonas(int NumPersonas);
	//Gets
	/* Este metodo devuelve un nivel de estudios de un objeto estudios.
	 *PRE: Tener informacion sobre el nivel de estudios en un objeto estudios.
	 *POST: Devuelve un nivel de estudios de un objeto estudios.
	 *Parametros:
	 *
	 *
	 *Complejidad:O(1).
	 */
	string getnivelEstudios();

	/* Este metodo devuelve un numero de personas de un objeto estudios.
	 *PRE: Tener informacion sobre un numero de personas en un objeto estudios.
	 *POST: Devuelve un numero de personas de un objeto estudios.
	 *Parametros:
	 *
	 *
	 *Complejidad:O(1).
	 */
    int getNumPersonas();
	//mostrar
	/* Este metodo muestra la informacion de un objeto estudios.
	 *PRE: Tener un objeto estudios.
	 *POST: Muestra la informacion de un objeto estudios.
	 *Parametros:
	 *
	 *
	 *Complejidad:O(1).
	 */
    void mostrar();
};

#endif /* ESTUDIOS_H_ */
