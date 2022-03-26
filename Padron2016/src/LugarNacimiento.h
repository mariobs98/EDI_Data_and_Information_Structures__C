/*
 * LugarNacimiento.h
 *
 *  Created on: 9 abr. 2018
 *      Author: enrique
 */

#ifndef LUGARNACIMIENTO_H_
#define LUGARNACIMIENTO_H_
#include <iostream>
#include <string>
using namespace std;

/*Realizado por Mario Bermejo y Enrique Moreno
 *
 * Esta clase controla que se pueda almacenar un lugar de nacimiento del archivo csv, asi como devolver la informacion contenida en ella.
 * Como atributos tiene varios strings, el de poblacion y el de provincia, y un tipo int de personas.
 *
 *
 */

class LugarNacimiento {
private:
	string poblacion;
	string provincia;
	int personas;

public:
	//Constructores
	/*Se encarga de crear un objeto LugarNacimiento vacio.
	 *PRE: No tiene precondiciones.
	 *POST: Crea un objeto LugarNacimiento vacio.
	 *Parametros:
	 *
	 *
	 *Complejidad:O(1).
	 */
	LugarNacimiento();


	/*Se encarga de crear un objeto LugarNacimiento lleno.
	 *PRE: Se tiene que pasar como datos la poblacion, la provincia y el numero de personas.
	 *POST: Crea un objeto LugarNacimiento lleno.
	 *Parametros:
	 *
	 *
	 *Complejidad:O(1).
	 */
	LugarNacimiento(string poblacion,string provincia,int personas);

	//Destructores
	/*Se encarga de destruir un objeto LugarNacimiento.
	 *PRE: Tiene que haber un objeto LugarNacimiento.
	 *POST: Destruye un objeto LugarNacimiento.
	 *Parametros:
	 *
	 *
	 *Complejidad:O(1).
	 */
	~LugarNacimiento();

	//SETS
	/*Se encarga de introducir una poblacion en un objeto LugarNacimiento.
	 *PRE: Se tiene que tener la informacion de la poblacion.
	 *POST: Introduce una poblacion en un objeto LugarNacimiento.
	 *Parametros:
	 *-string poblacion: tipo string que contiene la informacion de poblacion.
	 *
	 *Complejidad:O(1).
	 */
	void setpoblacion(string poblacion);

	/*Se encarga de introducir una provincia en un objeto LugarNacimiento.
	 *PRE: Se tiene que tener la informacion de la provincia.
	 *POST: Introduce una provincia en un objeto LugarNacimiento.
	 *Parametros:
	 *-string provincia: tipo string que contiene la informacion de provincia.
	 *
	 *Complejidad:O(1).
	 */
	void setprovincia(string provincia);

	/*Se encarga de introducir las personas en un objeto LugarNacimiento.
	 *PRE: Se tiene que tener la informacion de las personas.
	 *POST: Introduce las personas en un objeto LugarNacimiento.
	 *Parametros:
	 *-int personas: tipo int que contiene la informacion de provincia.
	 *
	 *Complejidad:O(1).
	 */
	void setpersonas(int personas);

	/*Se encarga de devolver la poblacion de un objeto LugarNacimiento.
	 *PRE: Se tiene que tener la informacion de la poblacion en un objeto LugarNacimiento.
	 *POST: Devuelve las personas de un objeto LugarNacimiento.
	 *Parametros:
	 *
	 *
	 *Complejidad:O(1).
	 */
	string getpoblacion();

	/*Se encarga de devolver la provincia de un objeto LugarNacimiento.
	 *PRE: Se tiene que tener la informacion de la provincia en un objeto LugarNacimiento.
	 *POST: Introduce las personas de un objeto LugarNacimiento.
	 *Parametros:
	 *
	 *
	 *Complejidad:O(1).
	 */
	string getprovincia();

	/*Se encarga de devolver las personas de un objeto LugarNacimiento.
	 *PRE: Se tiene que tener la informacion de las personas en un objeto LugarNacimiento.
	 *POST: Devuelve las personas de un objeto LugarNacimiento.
	 *Parametros:
	 *
	 *
	 *Complejidad:O(1).
	 */
	int getpersonas();

	//ALGORITMO 6
	/*Metodo que se encarga de cumplir el algoritmo 6(muestra la provincia y  las personas ).
	 *PRE: Se tiene que tener la informacion de las personas y la provincia.
	 *POST: Muestra las personas y la provincia.
	 *Parametros:
	 *
	 *
	 *Complejidad:O(1).
	 */
	void mostrarAlg6();

	/*Metodo muestra la informacion de LugarNacimiento.
	 *PRE: Se tiene que tener un objeto LugarNacimiento.
	 *POST: Muestra las personas y la provincia.
	 *Parametros:
	 *
	 *
	 *Complejidad:O(1).
	 */
	void show();


};

#endif /* LUGARNACIMIENTO_H_ */
