/*
 * gestorAnoNacimiento.h
 *
 *  Created on: 9 may. 2018
 *      Author: mario
 */

#ifndef GESTORANONACIMIENTO_H_
#define GESTORANONACIMIENTO_H_
#include "AnoNacimiento.h"
#include "listapi.h"
#include "Utils.h"

using namespace std;

class gestorAnoNacimiento {

private:

	ListaPI<AnoNacimiento*>*pAnoNacim;

public:
	//Inicia la lista del gestorAnoNacimiento Vacia
	/*PRE=
	 * POST= Crea la lista vacia del gestor
	 * COMPLEJIDAD= O(1)
	 * */
	gestorAnoNacimiento();
	//Inicia la lista del gestor y la llena con los datos pasados de AnoNacimiento
	/*PRE=
	 * POST= Crea la lista del gestor llenandola con sus datos correspondientes de AnoNacimiento
	 * COMPLEJIDAD= O(n)
	 * */
	gestorAnoNacimiento(string anonacim);
	//Destruye el objeto gestorAnoNacimiento,vacia la lista y elimina los datos
	/*PRE=
	 * POST= Borra el gestor y vacia la lista
	 * COMPLEJIDAD= O(n)
	 * */
	~gestorAnoNacimiento();

	//algoritmo4
	/*PRE=Lista del gestor llena con AnoNacimiento
	 * POST= Llena el vector pasado en orden alternando de 10 en 10 anos cada posicion del vector
	 * de 0 a 100,segun la edad de los habitantes
	 * COMPLEJIDAD= O(n)
	 * */
	void algoritmo4Edad(int (&v)[11]);

	//ALGORITMO 7
	/*PRE=Lista del gestor llena
	 * POST= Devuelve en habitantes el numero de personas que hay para el rango de edad proporcionado
	 * COMPLEJIDAD= O(n)
	 * */
	void getTotalHabitantesRangoEdadDado(int &limInf,int &limSup,int &Habitantes);

	/*PRE=Lista del gestor llena
	 * POST= Muestra por consola la lista
	 * COMPLEJIDAD= O(n)
	 * */
	void mostrar();
};

#endif /* GESTORANONACIMIENTO_H_ */
