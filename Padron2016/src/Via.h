/*
 *
 * Via.h
 *  Created on: 19 feb. 2018
 *      Author: mario
 */

#ifndef VIA_H_
#define VIA_H_

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "datosDemograficos.h"
using namespace std;

/*Realizado por Mario Bermejo y Enrique Moreno
 *
 * Esta clase controla que se pueda almacenar una via del archivo csv, asi como devolver la informacion contenida en ella. Cabe destacar que de cada via se recoge un dato demografico, que contiene datos como el nivel de estudio, lugar de nacimiento,etc.
 * Como atributos tiene varios strings, del nombre del barrio, del nombre de la via y del tipo de via, contiene un float de la longitud de la via y un int para almacenar el codigo de la via ,y un objeto dato demografico.
 *
 *
 */

class Via {

private:

	//Atributos de la clase
	datos_Demograficos *dd;
	string nombreBarrio;
	string nombreVia;
	float longitudVia;
	string tipoVia;
	int codigoVia;

public:

	//Metodos de la clase
	//Constructores
	/*Se encarga de crear un objeto via vacio.
	 *PRE: No tiene precondiciones.
	 *POST: Crea un objeto via vacio.
	 *Parametros:
	 *
	 *
	 *Complejidad:O(1).
	 */
	Via();
	/*Se encarga de crear un objeto via con su informacion correspondiente.
	 *PRE: No tiene precondiciones.
	 *POST: Crea un objeto via lleno.
	 *Parametros:
	 *-datos_Demograficos *dd:objeto dato demografico, guarda la informacion de datos demograficos que pertenece a la via.
	 *-string nombreBarrio: parametro tipo string que contiene el nombre de barrio al que pertenece dicha via.
	 *-string nombreVia: parametro tipo string que contiene el nombre de la via.
	 *-float longitudVia: parametro tipo float que contiene la longitud de via.
	 *-string tipoVia: parametro tipo string que contiene el tipo de la via.
	 *-int codigoVia parametro tipo int que contiene el codigo de la via.
	 *
	 *Complejidad: O(1).
	 */
	Via(string nombreBarrio,string nombreVia,float longitudVia,string tipoVia,int codigoVia);

	//Destructores
	/*Se encarga de destruir completamente el objeto
	 *PRE: Que exista dicho objeto via.
	 *POST: Destruye completamente el objeto via.
	 *Parametros:
	 *
	 *
	 *Complejidad:O(1)
	 */
	~Via();


	//Carga los Datos Demograficos pertenecientes a la Via.
	/*
	 *PRE:Haber creado el objeto dinamico datos_Demograficos y agregarle la informacion correspondiente.
	 *POST:Agrega la informacion del dato demografico introducido al que posee la via.
	 *Parametros:
	 *datos_Demograficos *dd= parametro tipo objeto dinamico que contiene la informacion del dato demografico perteneciente a esa via.
	 *
	 *Complejidad:O(1).
	 */
	void introducirDatosDemograficos(datos_Demograficos *dd);

	//ALGORITMO 5
	/*Metodo utilizado en el algoritmo 5 para insertar las nacionalidades en la lista auxiliar introducida.
	 *PRE: Haber creado una lista auxiliar de nacionalidades vacia.
	 *POST: Rellena dicha lista auxiliar con las nacionalidades que cumplan la condicion.
	 *Parametros:
	 *ListaPI<Nacionalidad*>*&pNacionalidades: lista de objetos nacionalidades rellenada de los objetos correspondientes segun condicion.
	 *
	 *Complejidad:O(1)
	 */
	void insertarNacionalidades(ListaPI<Nacionalidad*>*&pNacionalidades);

	//ALGORITMO 6
	/*Metodo utilizado en el algoritmo 6 que se encarga de insertar los lugares de nacimiento correspondientes en una lista auxiliar.
	 *PRE: haber inicializado la lista auxliar correctamente y vacia.
	 *POST: Devuelve una lista con los lugares de nacimiento, segun condicion en el metodo.
	 *Parametros:
	 *-ListaPI<LugarNacimiento*>*&pLugNac: se trata de una lista auxiliar de lugares de nacimiento.
	 *
	 *Complejidad:O(1)
	 */
	void insertarLugarNacimiento(ListaPI<LugarNacimiento*>*&pLugNac);

	//ALGORITMO 7
	/*Metodo utilizado en el algoritmo 7 que se encarga de devolver el numero total de habitantes segun un rango de edad determinado por el usuario.
	 *PRE: introducir un valor de rango de edad valido.
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
	 *PRE: haber inicializado la lista auxiliar correctamente y vacia.
	 *POST: Devuelve la lista auxiliar llena de niveles de estudio, segun condiciones.
	 *Parametros:
	 *-ListaPI<Estudios*>*&pEstudiosAux: lista auxiliar empleada para insertar los niveles de estudio, segun corresponda.
	 *
	 *Complejidad: O(1).
	 */
	void InsertarEstudios(ListaPI<Estudios*>*&pEstudiosAux);

	//ALGORITMO 9
	/*Devuelve la cantidad de hombres de la via.
	 *PRE: acceder a la via valida.
	 *POST: Devuelve el total de hombres del barrio utilizado.
	 *Parametros:
	 *-int &hom: parametro tipo int, parametro tipo entrada-salida, utilizado para devolver el total de hombres de un barrio.
	 *
	 *Complejidad:O(1).
	 */
	void gethombresDeLaVia(int &hom);
	/*Devuelve la cantidad de mujeres de la via

	 *PRE: Acceder a la via correcta.
	 *POST: Devuelve el total de mujeres del barrio utilizado.
	 *Parametros:
	 *int &muj: parametro tipo int, parametro tipo entrada-salida, utilizado para devolver el total de mujeres de un barrio.
	 *
	 *Complejidad: O(1).
	 */
	void getmujeresDeLaVia(int &muj);

	//SETTER
    /*Metodo para introducir un nombreBarrio en la via que se utilice.
     *PRE: Tener un nombre Barrio.
     *POST: introduce el nombre de barrio en esa via.
     *Parametros:
     *-string nombreBarrio: parametro de tipo string que contiene el nombre de Barrio
     *
     *Complejidad: O(1)
     */
	void setnombreBarrio(string nombreBarrio);
    /*Metodo para introducir un nombreVia en la via que se utilice.
     *PRE: Tener un nombre Via.
     *POST: introduce el nombre de via en esa via.
     *Parametros:
     *-string nombreVia: parametro de tipo string que contiene el nombre de Via.
     *
     *Complejidad: O(1)
     */
	void setnombreVia(string nombreVia);

    /*Metodo para introducir una longitudVia en la via que se utilice.
     *PRE: Tener una longitud Via.
     *POST: introduce la longitud de via en esa via.
     *Parametros:
     *-float longitudVia: parametro de tipo float que contiene la longitud de la Via.
     *
     *Complejidad: O(1)
     */
	void setlongitudVia(float longitudVia);

    /*Metodo para introducir un tipoVia en la via que se utilice.
     *PRE: Tener una tipo Via.
     *POST: introduce el tipo de via en esa via.
     *Parametros:
     *-string tipoVia: parametro de tipo string que contiene el tipo de la Via.
     *
     *Complejidad: O(1)
     */
	void settipoVia(string tipoVia);

    /*Metodo para introducir un codigoVia en la via que se utilice.
     *PRE: Tener un codigo Via.
     *POST: introduce el codigo de via en esa via.
     *Parametros:
     *-int codigoVia: parametro de tipo int que contiene el codigo de la Via.
     *
     *Complejidad: O(1)
     */
	void setcodigoVia(int codigoVia);
	//GETTER
    /*Metodo para devolver un nombreBarrio en el barrio que se utilice.
     *PRE: Tener un nombrebarrio valido.
     *POST: devuelve el nombre de barrio de esa via.
     *Parametros:
     *
     *
     *Complejidad: O(1)
     */
	string getnombreBarrio()const;

    /*Metodo para devolver un nombreBarrio en el barrio que se utilice.
     *PRE: Tener un nombrebarrio valido.
     *POST: devuelve el nombre de barrio de esa via.
     *Parametros:
     *-string nombreBarrio: parametro de tipo string entrada-salida que va a contener el nombre de Barrio.
     *
     *Complejidad: O(1)
     */
	void getnombreBarrio(string &nombreBarrio)const;

    /*Metodo para devolver un nombrevia en la via que se utilice.
     *PRE: Tener un nombre Via valido.
     *POST: devuelve el nombre de via de esa via.
     *Parametros:
     *
     *
     *Complejidad: O(1)
     */
	string getnombreVia()const;

    /*Metodo para devolver un nombrevia en la via que se utilice.
     *PRE: Tener un nombre Via valido.
     *POST: devuelve el nombre de via de esa via.
     *Parametros:
     *-string nombreVia: parametro de tipo string entrada-salida  que va a contener el nombre de Via.
     *
     *Complejidad: O(1)
     */
	void getnombreVia(string &nombreVia)const;

    /*Metodo para devolver un longitudvia en la via que se utilice.
     *PRE: Tener un longitudvia valido.
     *POST: devuelve la longitud de via de esa via.
     *Parametros:
     *
     *
     *Complejidad: O(1)
     */
	float getlongitudVia()const;

    /*Metodo para devolver un longitudvia en la via que se utilice.
     *PRE: Tener un longitudvia valido.
     *POST: devuelve la longitud de via de esa via.
     *Parametros:
     *-float longitudVia: parametro de tipo float entrada-salida que va a contener la longitud de Via.
     *
     *Complejidad: O(1)
     */
	void getlongitudVia(float &longitudVia)const;

    /*Metodo para devolver un tipovia en la via que se utilice.
     *PRE: Tener un tipovia valido.
     *POST: devuelve un tipo de via de esa via.
     *Parametros:
     *
     *
     *Complejidad: O(1)
     */
	string gettipoVia()const;

    /*Metodo para devolver un tipovia en la via que se utilice.
     *PRE: Tener un tipovia valido.
     *POST: devuelve un tipo de via de esa via.
     *Parametros:
     *-string tipoVia: parametro de tipo string entrada-salida que va a contener el tipo de Via.
     *
     *Complejidad: O(1)
     */
	void gettipoVia(string &tipoVia)const;

    /*Metodo para devolver un codigovia en la via que se utilice.
     *PRE: Tener un codigo valido.
     *POST: devuelve un codigo de via de esa via.
     *Parametros:
     *
     *
     *Complejidad: O(1)
     */
	int getcodigoVia()const;

    /*Metodo para devolver un codigovia en la via que se utilice.
     *PRE: Tener un codigo valido.
     *POST: devuelve un codigo de via de esa via.
     *Parametros:
     *-int codigoVia: parametro de tipo int entrada-salida que va a contener el codigo de Via.
     *
     *Complejidad: O(1)
     */
	void getcodigoVia(int &codigoVia)const;

	//Show
	//Muestra la informacion de via sin datos demograficos
	/*
	 *PRE: La via debe contener informacion.
	 *POST: Muestra por consola la informacion de esa via.
	 *Parametros:
	 *
	 *
	 *Complejidad:O(1).
	 */
	void mostrar();

	//Muestra la informacion de via con datos demograficos
	/*
	 *PRE: La via debe contener informacion.
	 *POST: Muestra por consola la informacion de esa via y sus datos demograficos.
	 *Parametros:
	 *
	 *
	 *Complejidad:O(1).
	 */
	void mostrarJuntoDatosDemograficos();

	//algoritmo11
	/*Metodo empleado en el algoritmo 11 encargado de devolver una via segun el nombreVia introducido.
	 *PRE: Dar un nombreVia valido.
	 *POST: Devuelve una lista de vias segun el nombreVia introducido.
	 *Parametros:
	 *
	 *-ListaPI<LugarNacimiento*>*&LNAux: lista auxiliar de lugares nacimiento que contiene lugares de nacimiento segun condiciones.
	 *Complejidad:O(1).
	 */
	void algoritmo11(ListaPI<LugarNacimiento*>*&LNAux);

    //algoritmo12
	/*Metodo utilizado en el algoritmo 12 para devolver una lista auxiliar de vias segun el nombreVia dado.
	 *PRE: Dar un nombreVia valido.
	 *POST: Devuelve una lista de vias segun el nombreVia introducido.
	 *Parametros:
	 *
	 *-ListaPI<LugarNacimiento*>*&LNAux: lista auxiliar de lugares nacimiento que contiene lugares de nacimiento segun condiciones.
	 *Complejidad:O(1).
	 */
	void algoritmo12(ListaPI<LugarNacimiento*>*&LNAux);

	//Sobrecarga de operadores
	/*
	 *PRE: Tener una via con informacion.
	 *POST: Determinan si las vias son iguales, mayor o menor que.
	 *Parametros:
	 *const Via &v: parametro de entrada-salida, tipo objeto, que sera comparado con la via local.
	 *
	 *Complejidad:O(1).
	 */
	bool operator ==(const Via &v);
	bool operator >(const Via &v);
	bool operator <(const Via &v);

    //Metodo que se encarga de substraer y comparar
	/*
	 *PRE: Pasar dos parametros uno que es el que se compara, y otro que es el que se va a sustraer una parte para comparar si son iguales o no.
	 *POST: Determinan si los parametros introducidos son iguales.
	 *Parametros:
	 *-string str: tipo string que es la parte que se quiere comprobar.
	 *-string substr: tipo string que contiene la palabra a comparar la parte.
	 *
	 *Complejidad:O(1).
	 */
	bool empiezaPor (string str, string substr);

};

/*Realizado por Mario Bermejo y Enrique Moreno
 *
 * Esta clase esta hecha para poder realizar una comparacion de vias por sus nombres, y comprobar si son iguales o no.
 *
 *
 */

class CompararPtrVias {

public:

	int operator() (const Via *v1, const Via *v2) {
		int resul;
		if      (v1->getnombreVia() == v2->getnombreVia())     resul =  0;
		else if (v1->getnombreVia() <  v2->getnombreVia())     resul = -1;
		else /* (v1->getnombreVia() >  v2->getnombreVia()) */  resul =  1;
		return resul;
	}
};

#endif /* VIA_H_ */
