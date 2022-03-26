/*
 * gestorBarrios.h
 *
 *  Created on: 12 mar. 2018
 *      Author: mario
 */

#ifndef GESTORBARRIOS_H_
#define GESTORBARRIOS_H_
#include "Barrio.h"

/*Realizado por Mario Bermejo y Enrique Moreno
 *
 * Esta clase controla que se pueda almacenar lista de objetos barrio, asi como devolver la informacion contenida en ella.
 * Como atributos tiene una lista de barrios.
 *
 *
 */


class gestorBarrios {

private:

	ListaPI<Barrio*>*pBarrio;

public:

	//Inicia la lista vacia.
	//constructor
	/*Se encarga de crear una lista de barrios vacia.
	 *PRE: No existen precondiciones.
	 *POST: Crea un objeto de lista de barrios vacia.
	 *Complejidad: O(1)
	 */
	gestorBarrios();

	//Borra a lista y la vacia.
	//Destructor
	/*Se encarga de destruir una lista de barrios.
	 *PRE: Tener la lista creada.
	 *POST:Destruye la lista de barrios.
	 *Complejidad: O(n)
	 */
	~gestorBarrios();

	//Llena la lista con todos los Barrios
	/*Se encarga de crear una lista de barrios llena.
	 *PRE: Tener la informacion de los barrios.
	 *POST: Crea un objeto de lista de barrios llena.
	 *Complejidad: O(n)
	 */
	void cargarBarrios();

	//Busca y devuelve el Barrio de la lista
	/*Se encarga de Buscar y devolver el Barrio de la lista
	 *PRE: Tener la informacion del barrio.
	 *POST: Devuelve el barrio.
	 *Parametros:
	 *string nombreBarrio: tipo string que contiene el nombre del barrio
	 *Barrio *&b: oobjeto dinamico(tipo puntero) que va a contener la informacion del barrio buscado
	 *Complejidad: O(n)
	 */
	void buscarBarrio(string nombreBarrio,Barrio *&b);

	//Muestra la lista de Barrios.
	/*Metodo para mostrar la lista de barrios.
	 *PRE: Se tiene que tener la lista .
	 *POST: muestra los barrios de la lista.
	 *Parametros:
	 *
	 *
	 *Complejidad:O(n).
	 */
	void mostrarBarrios();

	/*Metodo para mostrar las vias de un barrio de la lista.
	 *PRE: Se tiene que tener la lista, y el nombre del barrio.
	 *POST: muestra las vias del barrio de la lista.
	 *Parametros:
	 *ListaPI<Barrio*>*barrios: lista que contiene todos los barrios
	 * string nombreBarrio: tipo string que contiene el nombre del barrio
	 * bool enc: tipo bool que determina si se ha encontrado el barrio
	 *
	 *Complejidad:O(n).
	 */
	void mostrarvias(ListaPI<Barrio*>*barrios, string nombreBarrio,bool enc);
	void mostrarviaspublico(string nombreBarrio,bool enc);

	//Devuelve la lista llena con todas las Vias de todos los Barrios.
	/*Metodo para devolver las vias de todos los barrios en una lista.
	 *PRE: Se tiene que tener la lista vacia.
	 *POST: devuelve las vias de todos los barrios en una lista..
	 *Parametros:
	 *ListaPI<Via*>*&pViaAux: lista que contiene las vias que se van a utilizar.
	 *
	 *Complejidad:O(n).
	 */
	void devolverVias(ListaPI<Via*>*&pViaAux);

	//ALGORITMO 2
	//Muestra las Vias de un Barrio dado.
	/*
	 *PRE: Se tiene que tener el nombre del barrio.
	 *POST: muestra las vias del barrio.
	 *Parametros:
	 *
	 * string nombreBarrio: tipo string que contiene el nombre del barrio
	 *
	 *
	 *Complejidad:O(n).
	 */
	void mostrarViasdeUnBarrio(string nombreBarrio);

	//algoritmo3
	//Devuelve la lista llena con todas las Vias  de los Barrios que cumplen la condicion.
	/*
	 *PRE: Se tiene que tener la lista vacia.
	 *POST: Devuelve la lista llena con todas las Vias  de los Barrios que cumplen la condicion.
	 *Parametros:
	 *ListaPI<Via*>*&pViaAux: lista que contiene las vias que se van a utilizar.
	 *
	 *Complejidad:O(n).
	 */
	void algoritmo3(ListaPI<Via*>*&auxv);

	//Metodo que compara los barrios para ver si son iguales o no, para mostrar aquellas vias que son de distintos barrios.
	/*
	 *PRE: Se tiene que tener el nombre del primer barrio, y la informacion de la via.
	 *POST: Devuelve aquellos barrios que pasan por una via.
	 *Parametros:
	 *int &contador: tipo int que cuenta los distintos barrios.
	 *string nombreBarrioAux: tipo string que contiene el nombre del primer barrio
	 *Via *v: objeto dinamico(tipo puntero) que contiene la informacion de la via.
	 *
	 *Complejidad:O(n).
	 */
	void compararBarriosalgt(int &contador,string nombreBarrioAux,Via *v);
	//ALGORITMO 5
	/*Metodo utilizado en el algoritmo 5 para insertar las correspondientes nacionalidades en una lista auxiliar.
	 *PRE: Haber creado la lista auxiliar correctamente y vacia.
	 *POST: Devuelve una lista auxiliar llena de nacionalidades.
	 *Parametros:
	 *-ListaPI<Nacionalidad*>*&pNacionalidades: se trata de una lista auxiliar de nacionalidades.
	 *
	 *Complejidad: O(n).
	 */
	void insertarNacionalidades(ListaPI<Nacionalidad*>*&pNacionalidades);

	//ALGORITMO 6
	/*Metodo utilizado en el algoritmo 6 que se encarga de insertar los lugares de nacimiento correspondientes en una lista auxiliar.
	 *PRE: Haber inicializado la lista auxliar correctamente y vacia.
	 *POST: Devuelve una lista con los lugares de nacimiento, segun condicion en el metodo.
	 *Parametros:
	 *-ListaPI<LugarNacimiento*>*&pLugNac: se trata de una lista auxiliar de lugares de nacimiento.
	 *
	 *Complejidad:O(n)
	 */
	void insertarLugarNacimiento(ListaPI<LugarNacimiento*>*&pLugNac);

	//ALGORITMO 7
	/*Metodo utilizado en el algoritmo 7 que se encarga de devolver el numero total de habitantes segun un rango de edad determinado por el usuario.
	 *PRE: Introducir un valor de rango de edad valido.
	 *POST: Devuelve el numero total de habitantes segun el rango de edad indicado previamente.
	 *Parametros:
	 *string &nombreBarrio: tipo string entrada-salida utilizado para encontrar dicho barrio.
	 *-int &limInf: parametro tipo int, parametro de entrada-salida, utilizado para establecer el limite inferior.
	 *-int &limSup: parametro tipo int, parametro de entrada-salida, utilizado para establecer el limite superior.
	 *-int &Habitantes: parametro tipo int, parametro de entrada-salida, utlizado para devolver el numero total de habitantes.
	 *Complejidad: O(n).
	 */
	void barrioMayorNumHabitantes(string &nombreBarrio,int &limInf,int &limSup,int &totalHabitantes);

	//ALGORITMO 8
	/* Metodo utilizado en el algoritmo 8 que se encarga de insertar el nivel de estudios en una lista auxiliar, segun la condicion.
	 *PRE: Haber inicializado la lista auxiliar correctamente y vacia.
	 *POST: Devuelve la lista auxiliar llena de niveles de estudio, segun condiciones.
	 *Parametros:
	 *-ListaPI<Estudios*>*&pEstudiosAux: lista auxiliar empleada para insertar los niveles de estudio, segun corresponda.
	 *string nombreBarrio: tipo string utilizado para encontrar dicho barrio.
	 *Complejidad: O(n).
	 */
	void InsertarEstudios(ListaPI<Estudios*>*&pEstudiosAux,string nombreBarrio);

	//ALGORITMO 9
	//Devuelve el total de hombres de un Barrio.
	/*Metodo que devuelve el total de los hombres del Barrio----algoritmo 9
	 *PRE: Utilizar el barrio correcto.
	 *POST: Devuelve el total de hombres del barrio utilizado.
	 *Parametros:
	 *-int &hom: parametro tipo int, parametro tipo entrada-salida, utilizado para devolver el total de hombres de un barrio.
	 *string &nombreBarriohom: tipo string entrada-salida utilizado para encontrar dicho barrio.
	 *Complejidad:O(n).
	 */
	void algoritmo_9hom(string &nombreBarriohom,int &hom);

	//Devuelve el total de mujeres de un Barrio.
	/*Metodo que devuelve el total de las mujeres del Barrio----algoritmo 9
	 *PRE: Utilizar el barrio correcto.
	 *POST: Devuelve el total de mujeres del barrio utilizado.
	 *Parametros:
	 *int &muj: parametro tipo int, parametro tipo entrada-salida, utilizado para devolver el total de mujeres de un barrio.
	 *string &nombreBarriohom: tipo string entrada-salida utilizado para encontrar dicho barrio.
	 *Complejidad: O(n).
	 */
	void algoritmo_9muj(string &nombreBarriomuj,int &muj);

	//algoritmo11
	/*Metodo empleado en el algoritmo 11 encargado de devolver una via segun el nombreVia introducido.
	 *PRE: Dar un nombreVia valido.
	 *POST: Devuelve una via segun el nombreVia introducido.
	 *Parametros:
	 *-string &nombreVia: parametro tipo string, de entrada-salida, utilizado para devolver la via correspondiente.
	 *-Via *&vaux: parametro dinamico(tipo puntero),de entrada-salida utilizado para devolver aquella via que se indica en nombreVia.
	 *Complejidad:O(n).
	 */
    void algoritmo11(string &nombreVia,Via *&vaux);

	/*Metodo empleado en el algoritmo 11 encargado de devolver una via segun el nombreVia introducido(caso arbol).
	 *PRE: Dar un nombreVia valido.
	 *POST: Devuelve una via segun el nombreVia introducido.
	 *Parametros:
	 *-string &nombreVia: parametro tipo string, de entrada-salida, utilizado para devolver la via correspondiente.
	 *-Via *v: parametro dinamico(tipo puntero),de entrada-salida utilizado para devolver aquella via que se indica en nombreVia.
	 *Complejidad:O(n).
	 */
    void algoritmo11Arbol(string &nombreViaArbol,Via *&vArbol);

    //algoritmo12
	/*Metodo utilizado en el algoritmo 12 para devolver una lista auxiliar de vias segun el nombreVia dado.
	 *PRE: Dar un nombreVia valido.
	 *POST: Devuelve una lista de vias segun el nombreVia introducido.
	 *Parametros:
	 *-string &nombreVia: parametro tipo string, de entrada-salida, utilizado para devolver la lista de vias correspondiente.
	 *-ListaPI<Via*>*&pViaAux: lista auxiliar tipo entrada-salida empleada para devolver las vias que corresponden a ese nombreVia.
	 *Complejidad:O(n).
	 */
    void algoritmo12(string nombreVia,ListaPI<Via*>*&pViaAux);

	/*Metodo utilizado en el algoritmo 12 para devolver un arbol auxiliar de vias segun el nombreVia dado(caso arbol).
	 *PRE: Dar un nombreVia valido.
	 *POST: Devuelve un arbol de vias segun el nombreVia introducido.
	 *Parametros:
	 *-string &nombreVia: parametro tipo string, de entrada-salida, utilizado para devolver arbol de vias correspondiente.
	 *-:Arbol<Via*, CompararPtrVias>  *&ArbolAux: arbol auxiliar tipo entrada-salida empleada para devolver las vias que corresponden a ese nombreVia.
	 *Complejidad:O(n).
	 */
    void algoritmo12Arbol(string nombreVia,Arbol<Via*, CompararPtrVias>  *&ArbolAux );
};


#endif /* GESTORBARRIOS_H_ */
