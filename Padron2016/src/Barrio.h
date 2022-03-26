/*
 * ClaseBarrio.h
 *
 *  Created on: 19 feb. 2018
 *      Author: mario
 */

#ifndef BARRIO_H_
#define BARRIO_H_
#include "gestorVias.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;


/*Realizado por Mario Bermejo y Enrique Moreno
 *
 * Esta clase controla que se pueda almacenar un barrio del archivo csv, asi como devolver la informacion contenida en él. Cabe destacar que de cada barrio se recoge una serie de vias o calles.
 * Como atributos tiene un string del nombre del barrio y un string para el distrito al que pertenece, así como una lista de vias, que guarda las vias que pertenecen a ese barrio
 *
 *
 */



class Barrio {

private:

	//Atributos de la clase
	string nombreBarrio;
	string nombreDistrito;
	gestorVias *gv;

public:

	//Metodos de la clase
	//Constructores

	/*Se encarga de crear un objeto barrio, pero con los campos del nombre del barrio y del distrito vacios, y reservando memoria para la lista de vias
	 *PRE: No existen precondiciones.
	 *POST: Crea un objeto de barrio vacio
	 *Complejidad: O(1)
	 */
	Barrio();

	/*Se encarga de crear un objeto barrio, pero con los campos del nombre del barrio y del distrito rellenados con los parametros que se le pasan, y reservando memoria para la lista de vias
	 *PRE: Escribir un nombre de barrio y de distrito correctos.
	 *POST: Crea un objeto de barrio con su nombre de barrio y distrito.
	 *Parametros:
	 *-string nombreBarrio: tipo string que contiene el nombre del barrio.
	 *-string nombreDistrito: tipo string que contiene el nombre del distrito.
	 *Complejidad: O(1).
	 */
	Barrio(string nombreBarrio,string nombreDistrito);

	//Destructores
	/* Se encarga de destruir el objeto barrio correctamente, tanto si es un objeto estático, como si es dinámico.
	 *PRE: Tener un objeto barrio que no nos haga ya falta por alguna causa.
	 *POST: Destruye correctamente el objeto barrio.
	 *Parametros: No hay.
	 *Complejidad: O(1).
	 */
	~Barrio();

	//Introduce la Via a la lista de Vias del Barrio,en orden alfabetico-------para la carga
	/*
	 *PRE: Es necesario tener un barrio valido, y tener un objeto via vacio.
	 *POST: Añade una via, al barrio en el que estamos utilizando este metodo.
	 *
	 *Parametros:
	 *-Via *v: es un objeto dinamico(puntero) hacia una via.
	 *
	 *Complejidad: O(1).
	 */
	void introducirVia(Via *v);

	//Este metodo devuelve en la lista de vias dada las Vias del Barrio con el que hemos accedido a este metodo.
	/*
	 *PRE: Es necesario tener un barrio valido, y una lista de vias vacia correctamente creada.
	 *POST: Devuelve la lista de vias que se ha pasado en un principio llena de las vias contenidas en ese barrio.
	 *Parametros:
	 *ListaPI<Via*>*&pViaAux: se trata de una lista de vias.
	 *
	 *Complejidad:O(1)
	 */
	void devolverVias(ListaPI<Via*>*&pViaAux);

	//algoritmo3
	/*Metodo que esta accediendo a la lista de vias, creada en el gestor general en la carga, y devuelve una lista con aquellas vias que pertenecen a varios barrios.
	 *PRE: El barrio utilizado debe ser valido, y la lista auxiliar debe haber sido inicialiada correctamente, y vacia.
	 *POST: Devuelve una lista llena de vias, según la condición establecida en el modulo.
	 *Parametros:
	 *ListaPI<Via*>*&auxv: se trata de una lista de via, utilizada para devolver aquellas vias que cumplan la condicion.
	 *
	 *Complejidad:O(1)
	 */
	void algoritmo3(ListaPI<Via*>*&auxv);

	//ALGORITMO 5
	/*Metodo utilizado en el algoritmo 5 para insertar las correspondientes nacionalidades en una lista auxiliar.
	 *PRE: Utilizar un barrio valido, y haber creado la lista auxiliar correctamente y vacia.
	 *POST: Devuelve una lista auxiliar llena de nacionalidades.
	 *Parametros:
	 *-ListaPI<Nacionalidad*>*&pNacionalidades: se trata de una lista auxiliar de nacionalidades.
	 *
	 *Complejidad: O(1).
	 */
	void insertarNacionalidades(ListaPI<Nacionalidad*>*&pNacionalidades);

	//ALGORITMO 6
	/*Metodo utilizado en el algoritmo 6 que se encarga de insertar los lugares de nacimiento correspondientes en una lista auxiliar.
	 *PRE: Utilizar el barrio correcto, y haber inicializado la lista auxliar correctamente y vacia.
	 *POST: Devuelve una lista con los lugares de nacimiento, segun condicion en el metodo.
	 *Parametros:
	 *-ListaPI<LugarNacimiento*>*&pLugNac: se trata de una lista auxiliar de lugares de nacimiento.
	 *
	 *Complejidad:O(1)
	 */
	void insertarLugarNacimiento(ListaPI<LugarNacimiento*>*&pLugNac);

	//ALGORITMO 7
	/*Metodo utilizado en el algoritmo 7 que se encarga de devolver el numero total de habitantes segun un rango de edad determinado por el usuario.
	 *PRE: Utilizar el barrio correcto, e introducir un valor de rango de edad valido.
	 *POST: Devuelve el numero total de habitantes segun el rango de edad indicado previamente.
	 *Parametros:
	 *-int &limInf: parametro tipo int, parametro de entrada-salida, utilizado para establecer el limite inferior.
	 *-int &limSup: parametro tipo int, parametro de entrada-salida, utilizado para establecer el limite superior.
	 *-int &Habitantes: parametro tipo int, parametro de entrada-salida, utlizado para devolver el numero total de habitantes.
	 *Complejidad: O(1).
	 */
	void getTotalHabitantesRangoEdadDado(int &limInf,int &limSup,int &Habitantes);

	//ALGORITMO 8
	/* Metodo utilizado en el algoritmo 8 que se encarga de insertar el nivel de estudios en una lista auxiliar, segun la condicion.
	 *PRE: Utilizar el barrio correcto, y haber inicializado la lista auxiliar correctamente y vacia.
	 *POST: Devuelve la lista auxiliar llena de niveles de estudio, segun condiciones.
	 *Parametros:
	 *-ListaPI<Estudios*>*&pEstudiosAux: lista auxiliar empleada para insertar los niveles de estudio, segun corresponda.
	 *
	 *Complejidad: O(1).
	 */
	void InsertarEstudios(ListaPI<Estudios*>*&pEstudiosAux);

	//ALGORITMO 9
	/*Metodo que devuelve el total de los hombres del Barrio----algoritmo 9
	 *PRE: Utilizar el barrio correcto.
	 *POST: Devuelve el total de hombres del barrio utilizado.
	 *Parametros:
	 *-int &hom: parametro tipo int, parametro tipo entrada-salida, utilizado para devolver el total de hombres de un barrio.
	 *
	 *Complejidad:O(1).
	 */
	void getTotalHombres(int &hom);

	/*Metodo que devuelve el total de las mujeres del Barrio----algoritmo 9
	 *PRE: Utilizar el barrio correcto.
	 *POST: Devuelve el total de mujeres del barrio utilizado.
	 *Parametros:
	 *int &muj: parametro tipo int, parametro tipo entrada-salida, utilizado para devolver el total de mujeres de un barrio.
	 *
	 *Complejidad: O(1).
	 */
	void getTotalMujeres(int &muj);

	//algoritmo11
	/*Metodo empleado en el algoritmo 11 encargado de devolver una via segun el nombreVia introducido.
	 *PRE: Dar un nombreVia valido.
	 *POST: Devuelve una via segun el nombreVia introducido.
	 *Parametros:
	 *-string &nombreVia: parametro tipo string, de entrada-salida, utilizado para devolver la via correspondiente.
	 *-Via *v: parametro dinamico(tipo puntero), utilizado para devolver aquella via que se indica en nombreVia.
	 *Complejidad:O(1).
	 */
	void algoritmo11(string &nombreVia,Via *&vaux);

	/*Metodo empleado en el algoritmo 11 encargado de devolver una via segun el nombreVia introducido(caso arbol).
	 *PRE: Dar un nombreVia valido.
	 *POST: Devuelve una via segun el nombreVia introducido.
	 *Parametros:
	 *-string &nombreVia: parametro tipo string, de entrada-salida, utilizado para devolver la via correspondiente.
	 *-Via *v: parametro dinamico(tipo puntero), utilizado para devolver aquella via que se indica en nombreVia.
	 *Complejidad:O(1).
	 */
	void algoritmo11Arbol(string &nombreViaArbol,Via *&vArbol);

	//algoritmo12
	/*Metodo utilizado en el algoritmo 12 para devolver una lista auxiliar de vias segun el nombreVia dado.
	 *PRE: Dar un nombreVia valido.
	 *POST: Devuelve una lista de vias segun el nombreVia introducido.
	 *Parametros:
	 *-string &nombreVia: parametro tipo string, de entrada-salida, utilizado para devolver la lista de vias correspondiente.
	 *-ListaPI<Via*>*&pViaAux: lista auxiliar tipo entrada-salida empleada para devolver las vias que corresponden a ese nombreVia.
	 *Complejidad:O(1).
	 */
	void algoritmo12(string nombreVia,ListaPI<Via*>*&pViaAux);

	/*Metodo utilizado en el algoritmo 12 para devolver un arbol auxiliar de vias segun el nombreVia dado(caso arbol).
	 *PRE: Dar un nombreVia valido.
	 *POST: Devuelve un arbol de vias segun el nombreVia introducido.
	 *Parametros:
	 *-string &nombreVia: parametro tipo string, de entrada-salida, utilizado para devolver arbol de vias correspondiente.
	 *-:Arbol<Via*, CompararPtrVias>  *&ArbolAux: arbol auxiliar tipo entrada-salida empleada para devolver las vias que corresponden a ese nombreVia.
	 *Complejidad:O(1).
	 */
    void algoritmo12Arbol(string nombreVia,Arbol<Via*, CompararPtrVias>  *&ArbolAux );
	//SETTER
    /*Metodo para introducir un nombreBarrio en el barrio que se utilice.
     *PRE: Tener un barrio correctamente inicializado, ya sea vacio o no.
     *POST: introduce el nombre de barrio en ese barrio.
     *Parametros:
     *-string nombreBarrio: parametro de tipo string que contiene el nombre de Barrio
     *
     *Complejidad: O(1)
     */
	void setnombreBarrio(string nombreBarrio);

    /*Metodo para introducir un distrito en el barrio que se utilice.
     *PRE: Tener un barrio correctamente inicializado, ya sea vacio o no.
     *POST: introduce el nombre de distrito en ese barrio.
     *Parametros:
     *-string nombreDistrito: parametro de tipo string que contiene el nombre de distrito.
     *
     *Complejidad: O(1)
     */
	void setnombreDistrito(string nombreDistrito);

	//GETTER
    /*Metodo para devolver un nombreBarrio en el barrio que se utilice.
     *PRE: Tener un barrio con informacion valida en él.
     *POST: devuelve el nombre de barrio de ese barrio.
     *Parametros:
     *
     *
     *Complejidad: O(1)
     */
	string getnombreBarrio() const;

    /*Metodo para devolver un nombreBarrio en el barrio que se utilice.
     *PRE: Tener un barrio con informacion valida en él.
     *POST: devuelve el nombre de barrio de ese barrio.
     *Parametros:
     *-string nombreBarrio: parametro de tipo string que va a contener el nombre de Barrio.
     *
     *Complejidad: O(1)
     */
	void getnombreBarrio(string &nombreBarrio) const;

    /*Metodo para devolver un distrito en el barrio que se utilice.
     *PRE: Tener un barrio con informacion valida.
     *POST: devuelve el nombre de distrito en ese barrio.
     *Parametros:
     *
     *
     *Complejidad: O(1)
     */
	string getnombreDistrito() const;

    /*Metodo para devolver un distrito en el barrio que se utilice.
     *PRE: Tener un barrio con informacion valida.
     *POST: devuelve el nombre de distrito en ese barrio.
     *Parametros:
     *-string nombreDistrito: parametro de tipo string que contiene el nombre de distrito.
     *
     *Complejidad: O(1)
     */
	void getnombreDistrito(string &nombreDistrito) const;

	//Show
	//Muestra el Barrio y su Distrito
	/*
	 *PRE: El barrio debe contener informacion.
	 *POST: Muestra por consola la informacion de ese barrio.
	 *Parametros:
	 *
	 *
	 *Complejidad:O(1).
	 */
	void mostrar();

	//Muestra las Vias del Barrio junto su Distrito
	/*
	 *PRE: El barrio debe contener informacion suya y de las vias.
	 *POST: Muestra la informacion del barrio y de las vias.
	 *Parametros:
	 *
	 *
	 *Complejidad:O(n).
	 */
	void mostrarViasdeBarrio();

	//Devuelve si se ha encontrado la via o no
	/*
	 *PRE: Se debe introducir una via con su informacion.
	 *POST: Devuelve si se encuentra en ese barrio.
	 *Parametros:
	 *-Via *v:parametro dinamico(tipo puntero), utilizado para comprobar la informacion de esa via.
	 *
	 *Complejidad:O(n).
	 */
	bool buscarViaRepe(Via *v);

	//Sobrecarga de operadores
	/*
	 *PRE: Tener un barrio con informacion.
	 *POST: Determinan si los barrios son iguales, mayor o menor que.
	 *Parametros:
	 *const Barrio &b: parametro de entrada-salida, tipo objeto, que sera comparado con el barrio local.
	 *
	 *Complejidad:O(1).
	 */
	bool operator == (const Barrio &b);
	bool operator > (const Barrio &b);
	bool operator < (const Barrio &b);


};

#endif /* BARRIO_H_ */
