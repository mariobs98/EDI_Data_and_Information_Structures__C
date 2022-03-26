/*
 * gestorVias.h
 *
 *  Created on: 22 abr. 2018
 *      Author: mario
 */

#ifndef GESTORVIAS_H_
#define GESTORVIAS_H_
#include "Via.h"
#include "listapi.h"
#include "arbol.h"

/*Realizado por Mario Bermejo y Enrique Moreno
 *
 * Esta clase controla que se pueda almacenar lista de objetos vias, asi como devolver la informacion contenida en ella.
 * Como atributos tiene una lista de vias y los metodos del arbol.
 *
 *
 */

class gestorVias {

private:

	ListaPI<Via*>*pVia;
	Arbol<Via*, CompararPtrVias> *aVias;

	// 1. Mostrar elementos en orden
	/*Se encarga de mostrar la vias del arbol
	 *PRE: Tener la informacion de la via.
	 *POST: Devuelve la via.
	 *Parametros:
	 *Arbol<Via *, CompararPtrVias> *arbolVias: arbol que contiene todas las vias.
	 *Complejidad: O(n)
	 */
	void mostrarEnOrden (Arbol<Via *, CompararPtrVias> *arbolVias);


	// 2. Buscar en el arbol
	/*Se encarga de Buscar y devolver la via del arbol
	 *PRE: Tener la informacion de la via.
	 *POST: Devuelve la via.
	 *Parametros:
	 *string nombre: tipo string que contiene el nombre de la via
	 *Via *v: objeto dinamico(tipo puntero) que va a contener la informacion de la via.
	 *Arbol<Via *, CompararPtrVias> *arbolVias: arbol que contiene todas las vias.
	 *Complejidad: O(n)
	 */

	bool buscarEnArbol (Arbol<Via *, CompararPtrVias> *arbolVias, string nombre, Via* &v);

	/*Metodo empleado en el algoritmo 12 encargado de devolver las vias en un arbol segun el nombreVia introducido.
	 *PRE: Dar un nombreVia valido.
	 *POST: devolver las vias en un arbol segun el nombreVia introducido.
	 *Parametros:
	 *-string nombreVia: parametro tipo string, utilizado para devolver la via correspondiente.
	 *-Arbol<Via*, CompararPtrVias>  *&ArbolAux: arbol auxiliar tipo entrada-salida empleada para devolver las vias que corresponden a ese nombreVia.
	 *Complejidad:O(n).
	 */
	void algoritmo12(Arbol<Via *, CompararPtrVias> *arbolVias,string nombreVia,Arbol<Via*, CompararPtrVias>  *&ArbolAux );
public:

	//Inicia la lista vacia.
	/*Se encarga de crear una lista de vias vacia.
	 *PRE: No existen precondiciones.
	 *POST: Crea un objeto de lista de vias vacia.
	 *Complejidad: O(1)
	 */
	gestorVias();

	//Borra la lista y la vacia.
	//Destructor
	/*Se encarga de destruir una lista de vias.
	 *PRE: Tener la lista creada.
	 *POST:Destruye la lista de vias.
	 *Complejidad: O(n)
	 */
	~gestorVias();

	//Llena la lista con todas las Vias.ç
	/*Se encarga de crear una lista de barrios llena.
	 *PRE: Tener la informacion de los barrios.
	 *POST: Crea un objeto de lista de barrios llena.
	 *Complejidad: O(n)
	 */
	void cargarVias();

	//Inserta la Via dada a la lista de Vias del Barrio----para la carga
	void insertarEnOrdenViaABarrio(Via *v);

	void devolverUnaViayComparar(ListaPI<Via*>*&auxv);

	//Devuelve todas las vias del Barrio en la lista dada;
	void devolverVias(ListaPI<Via*>*&pViaAux);

	//Llena la lista de cada Barrio de Vias, con sus respectivas Vias.
	void insertarViasaBarrio(string nombreBarrio);

	//ALGORITMO 3
	/*Se encarga de Buscar una via de la lista.(true si la encuentra, false si no la encuentra)
	 *PRE: Pasarle la via que queremos comprobar.
	 *POST: Devuelvetrue si la encuentra, false si no la encuentra.
	 *Parametros:
	 *Via *v: objeto dinamico(tipo puntero) que contiene la informacion de la via.
	 *Complejidad: O(n)
	 */
	bool buscarViaRepe(Via *v);

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
	 *
	 *-int &limInf: parametro tipo int, parametro de entrada-salida, utilizado para establecer el limite inferior.
	 *-int &limSup: parametro tipo int, parametro de entrada-salida, utilizado para establecer el limite superior.
	 *-int &Habitantes: parametro tipo int, parametro de entrada-salida, utlizado para devolver el numero total de habitantes.
	 *Complejidad: O(n).
	 */
	void getTotalHabitantesRangoEdadDado(int &limInf,int &limSup,int &totalHabitantes);

	//ALGORITMO 8
	/* Metodo utilizado en el algoritmo 8 que se encarga de insertar el nivel de estudios en una lista auxiliar, segun la condicion.
	 *PRE: Haber inicializado la lista auxiliar correctamente y vacia.
	 *POST: Devuelve la lista auxiliar llena de niveles de estudio, segun condiciones.
	 *Parametros:
	 *-ListaPI<Estudios*>*&pEstudiosAux: lista auxiliar empleada para insertar los niveles de estudio, segun corresponda.
	 *
	 *Complejidad: O(n).
	 */
	void InsertarEstudios(ListaPI<Estudios*>*&pEstudiosAux);

	//ALGORITMO 9
	//Devuelve el total de hombres de todas las Vias.

	/*
	 *PRE: Utilizar el barrio correcto.
	 *POST: Devuelve el total de hombres del barrio utilizado.
	 *Parametros:
	 *-int &hom: parametro tipo int, parametro tipo entrada-salida, utilizado para devolver el total de hombres de un barrio.
	 *
	 *Complejidad:O(n).
	 */
	void getNumHombres(int &totalhom);

	//Devueve el total de mujeres de todas las Vias.
	/*
	 *PRE: Utilizar el barrio correcto.
	 *POST: Devuelve el total de mujeres del barrio utilizado.
	 *Parametros:
	 *int &muj: parametro tipo int, parametro tipo entrada-salida, utilizado para devolver el total de mujeres de un barrio.
	 *
	 *Complejidad: O(n).
	 */
	void getNumMujeres(int &totalmuj);

	//algoritmo11
	/*Metodo empleado en el algoritmo 11 encargado de devolver una via segun el nombreVia introducido.
	 *PRE: Dar un nombreVia valido.
	 *POST: Devuelve una via segun el nombreVia introducido.
	 *Parametros:
	 *-string &nombreVia: parametro tipo string, de entrada-salida, utilizado para devolver la via correspondiente.
	 *-Via *&vaux: parametro dinamico(tipo puntero),de entrada-salida utilizado para devolver aquella via que se indica en nombreVia.
	 *Complejidad:O(n).
	 */
	void devolverViasCorrespondientes(string &nombreVia, Via *&vaux);

	//algoritmo12
	/*Metodo empleado en el algoritmo 12 encargado de devolver las vias en una lista segun el nombreVia introducido.
	 *PRE: Dar un nombreVia valido.
	 *POST: devolver las vias en una lista segun el nombreVia introducido.
	 *Parametros:
	 *-string nombreVia: parametro tipo string, utilizado para devolver la via correspondiente.
	 *-Via *&vaux: parametro dinamico(tipo puntero),de entrada-salida utilizado para devolver aquella via que se indica en nombreVia.
	 *Complejidad:O(n).
	 */
	void viasEmpiezanPor(string nombreVia, ListaPI<Via*>*&pViaAux);

	/*Metodo empleado en el algoritmo 12 encargado de devolver las vias en un arbol segun el nombreVia introducido.
	 *PRE: Dar un nombreVia valido.
	 *POST: devolver las vias en un arbol segun el nombreVia introducido.
	 *Parametros:
	 *-string nombreVia: parametro tipo string, utilizado para devolver la via correspondiente.
	 *-Arbol<Via*, CompararPtrVias>  *&ArbolAux: arbol auxiliar tipo entrada-salida empleada para devolver las vias que corresponden a ese nombreVia.
	 *Complejidad:O(n).
	 */
	void algoritmo12Arbol (string nombreVia,Arbol<Via*, CompararPtrVias>  *&ArbolAux );

	//Muestra la lista de Vias.
	/*Metodo para mostrar la lista de vias.
	 *PRE: Se tiene que tener la lista .
	 *POST: muestra las vias de la lista.
	 *Parametros:
	 *
	 *
	 *Complejidad:O(n).
	 */
    void mostrariterativo();

	/*Metodo para mostrar el arbol de vias.
	 *PRE: Se tiene que tener el arbol.
	 *POST: muestra las vias del arbol.
	 *Parametros:
	 *
	 *
	 *Complejidad:O(n).
	 */
    void mostrarArbol ();

	/*Se encarga de Buscar y devolver la via de la lista
	 *PRE: Tener la informacion de la via.
	 *POST: Devuelve la via.
	 *Parametros:
	 *string nombre: tipo string que contiene el nombre de la via
	 *Via *v: objeto dinamico(tipo puntero) que va a contener la informacion de la via.
	 *Complejidad: O(n)
	 */
    bool buscar (string nombre, Via* &v);


};

#endif /* GESTORVIAS_H_ */
