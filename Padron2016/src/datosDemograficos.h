/*
 * datosDemograficos.h
 *
 *  Created on: 21 abr. 2018
 *      Author: mario
 */

#ifndef DATOSDEMOGRAFICOS_H_
#define DATOSDEMOGRAFICOS_H_
#include <iostream>
#include <string>
#include "gestorLugardeNacimiento.h"
#include "gestorAnoNacimiento.h"
#include "gestorEstudios.h"
#include "gestorNacionalidad.h"
using namespace std;

/*Realizado por Mario Bermejo y Enrique Moreno
 *
 * Esta clase se encarga de almacenar las informaciones de demograficas que hay en el archivo csv, asi como devolver la informacion demografica de una via.
 * Como atributos tiene de strings del año y lugar de nacimiento, del nivel de estudio y de la nacionalidad. Y varios enteros del codigo de la via, del numero de hombres y mujeres que hay en esa via, y el año de creacion.
 * Tambien destacar las listas de los años de nacimiento, lugar de nacimiento, nivel de estudios, y nacionalidad.
 */

class datos_Demograficos {

private:

	int codigovia;
	string anonacim;
	string lugnac;
	string nivest;
	int muj;
	int hom;
	string nacional;
	int anocr;

	gestorAnoNacimiento *ga;
	gestorLugardeNacimiento *gln;
	gestorEstudios *ge;
	gestorNacionalidad *gn;

public:
	//Constructores
	/* Este metodo crea un objeto datos demograficos vacio.
	 *PRE: no es necesaria ninguna precondicion.
	 *POST: Crea un objeto demografico vacio.
	 *Parametros:
	 *
	 *
	 *Complejidad:O(1).
	 */
	datos_Demograficos();

	/* Este metodo crea un objeto datos demograficos lleno.
	 *PRE: Tener toda la informacion valida del objeto dato demografico.
	 *POST: Crea un objeto demografico lleno.
	 *Parametros:
	 *-int codigovia:tipo int que contiene el codigo de via.
	 *-string anonacim: tipo string que contiene el año de nacimiento.
	 *string lugnac: tipo string que contiene el lugar de nacimiento.
	 *string nivest: tipo string que contiene el nivel de estudio.
	 *int muj: tipo int que contiene el numero de mujeres.
	 *int hom: tipo int que contiene el numero de hombres.
	 *string nacional: tipo string que contiene la nacionalidad.
	 *int anocr: tipo int que contiene el año de creacion del archivo.
	 *
	 *Complejidad:O(1).
	 */
    datos_Demograficos(int codigovia,string anonacim,string lugnac,string nivest,
    		int hom,int muj,string nacional,int anocr);

	/* Este metodo destruye un objeto datos demograficos.
	 *PRE: Tener un objeto datos demograficos.
	 *POST: destruye un objeto dato demografico .
	 *Parametros:
	 *
	 *
	 *Complejidad:O(1).
	 */
    ~datos_Demograficos();

    //algoritmo4
	/* Este metodo se utiliza en el algoritmo 4 para obtener el numero de habitantes segun la edad.
	 *PRE: Crear un vector e inicializarlo.
	 *POST: Devuelve un vector con las edades de los habitantes.
	 *Parametros:
	 *int (&v)[11]: se trata de un vector que va a contener las edades.
	 *
	 *Complejidad:O(1).
	 */
    void algoritmo4Edad(int (&v)[11]);

    //ALGORITMO 5
	/*Metodo utilizado en el algoritmo 5 para insertar las correspondientes nacionalidades en una lista auxiliar.
	 *PRE: Haber creado la lista auxiliar correctamente y vacia.
	 *POST: Devuelve una lista auxiliar llena de nacionalidades.
	 *Parametros:
	 *-ListaPI<Nacionalidad*>*&pNacionalidades: se trata de una lista auxiliar de nacionalidades.
	 *
	 *Complejidad: O(1).
	 */
    void insertarNacionalidades(ListaPI<Nacionalidad*>*&pNacionalidades);

    //ALGORITMO 6
	/*Metodo utilizado en el algoritmo 6 que se encarga de insertar los lugares de nacimiento correspondientes en una lista auxiliar.
	 *PRE: Haber inicializado la lista auxiliar correctamente y vacia.
	 *POST: Devuelve una lista con los lugares de nacimiento, segun condicion en el metodo.
	 *Parametros:
	 *-ListaPI<LugarNacimiento*>*&pLugNac: se trata de una lista auxiliar de lugares de nacimiento.
	 *
	 *Complejidad:O(1)
	 */
    void insertarLugarNacimiento(ListaPI<LugarNacimiento*>*&pLugNac);

    //ALGORITMO 7
	/*Metodo utilizado en el algoritmo 7 que se encarga de devolver el numero total de habitantes segun un rango de edad determinado por el usuario.
	 *PRE: Introducir un valor de rango de edad valido.
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
	 *PRE: Haber inicializado la lista auxiliar correctamente y vacia.
	 *POST: Devuelve la lista auxiliar llena de niveles de estudio, segun condiciones.
	 *Parametros:
	 *-ListaPI<Estudios*>*&pEstudiosAux: lista auxiliar empleada para insertar los niveles de estudio, segun corresponda.
	 *
	 *Complejidad: O(1).
	 */
    void InsertarEstudios(ListaPI<Estudios*>*&pEstudiosAux);

    //algoritmo10
	/* Metodo utilizado en el algoritmo 10 que se encarga de insertar el lugar de nacimiento en una lista auxiliar, segun la provincia.
	 *PRE: Haber inicializado la lista auxiliar correctamente y vacia, y tener una provincia correcta.
	 *POST: Devuelve la lista auxiliar llena de lugares de nacimiento, segun condiciones.
	 *Parametros:
	 *-ListaPI<LugarNacimiento*>*&LNAux: lista auxiliar empleada para insertar los lugares de nacimiento, segun corresponda.
	 *-string provincia: tipo string que contiene la provincia.
	 *Complejidad: O(1).
	 */
    void algoritmo10LN(ListaPI<LugarNacimiento*>*&LNAux,string provincia);

    //algoritmo11
	/*Metodo empleado en el algoritmo 11 encargado de devolver una via segun el nombreVia introducido.
	 *PRE: Dar un nombreVia valido.
	 *POST: Devuelve una lista de vias segun el nombreVia introducido.
	 *Parametros:
	 *-ListaPI<LugarNacimiento*>*&LNAux: lista auxiliar empleada para insertar los lugares de nacimiento, segun corresponda.
	 *Complejidad:O(1).
	 */
    void algoritmo11(ListaPI<LugarNacimiento*>*&LNAux);

    //algoritmo12
	/*Metodo utilizado en el algoritmo 12 para devolver una lista auxiliar de lugares de nacimiento segun el nombreVia dado.
	 *PRE: Dar un nombreVia valido e inicializar la lista vacia.
	 *POST: Devuelve una lista de lugares de nacimiento segun el nombreVia introducido.
	 *Parametros:
	 *-ListaPI<LugarNacimiento*>*&LNAux: lista auxiliar empleada para insertar los lugares de nacimiento, segun corresponda.
	 *Complejidad:O(1).
	 */
    void algoritmo12MuestraPersonasProvincia(ListaPI<LugarNacimiento*>*&LNAux);

    /*Metodo para introducir un codigoVia en el dato demografico que se utilice.
     *PRE: Tener un codigo Via.
     *POST: introduce el codigo de via en ese dato demografico.
     *Parametros:
     *-int codigoVia: parametro de tipo int que contiene el codigo de la Via.
     *
     *Complejidad: O(1)
     */
    void setCodigovia(int codigovia);

    /*Metodo para introducir un lugar nacimiento en el dato demografico que se utilice.
     *PRE: Tener un lugar nacimiento.
     *POST: introduce el lugar de nacimiento en ese dato demografico.
     *Parametros:
     *-string lugnac: parametro de tipo string que contiene el lugar de nacimiento.
     *
     *Complejidad: O(1)
     */
    void setlugnac(string lugnac);

    /*Metodo para introducir un año nacimiento en el dato demografico que se utilice.
     *PRE: Tener un año nacimiento.
     *POST: introduce el año de nacimiento en ese dato demografico.
     *Parametros:
     *-string anonacim: parametro de tipo string que contiene el año de nacimiento.
     *
     *Complejidad: O(1)
     */
    void setanonacimiento(string anonacim);

    /*Metodo para introducir un nivel de estudios en el dato demografico que se utilice.
     *PRE: Tener un nivel de estudios.
     *POST: introduce el nivel de estudios en ese dato demografico.
     *Parametros:
     *-string nivest: parametro de tipo string que contiene el nivel de estudios.
     *
     *Complejidad: O(1)
     */
    void setnivest(string nivest);

    /*Metodo para introducir una nacionalidad en el dato demografico que se utilice.
     *PRE: Tener una nacionalidad.
     *POST: introduce la nacionalidad en ese dato demografico.
     *Parametros:
     *-string nacional: parametro de tipo string que contiene la nacionalidad.
     *
     *Complejidad: O(1)
     */
    void setnacional( string nacional);

    /*Metodo para introducir un numero de hombres en el dato demografico que se utilice.
     *PRE: Tener un numero de hombres.
     *POST: introduce un numero de hombres en ese dato demografico.
     *Parametros:
     *-int hom: parametro de tipo int que contiene el numero de hombres.
     *
     *Complejidad: O(1)
     */
    void sethom( int hom);

    /*Metodo para introducir un numero de mujeres en el dato demografico que se utilice.
     *PRE: Tener un numero de mujeres.
     *POST: introduce un numero de mujeres en ese dato demografico.
     *Parametros:
     *-int muj: parametro de tipo int que contiene el numero de mujeres.
     *
     *Complejidad: O(1)
     */
    void setmuj( int muj);

    /*Metodo para introducir un año de nacimiento en el dato demografico que se utilice.
     *PRE: Tener un año de nacimiento.
     *POST: introduce un año de nacimiento en ese dato demografico.
     *Parametros:
     *-int anocr: parametro de tipo int que contiene el año de creacion.
     *
     *Complejidad: O(1)
     */
    void setanocr(int anocr);

    /*Metodo para devolver un codigoVia en el dato demografico que se utilice.
     *PRE: Que datos demograficos debe contener un codigo Via.
     *POST: devuelve el codigo de via en ese dato demografico.
     *Parametros:
     *
     *
     *Complejidad: O(1)
     */
    int getCodigovia();

    /*Metodo para devolver un año de creacion en el dato demografico que se utilice.
     *PRE: Que datos demograficos debe contener un año de creacion.
     *POST: Devuelve el año de creacion en ese dato demografico.
     *Parametros:
     *
     *
     *Complejidad: O(1)
     */
    int getanocr();

    /*Metodo para devolver un lugar de nacimiento en el dato demografico que se utilice.
     *PRE: Que datos demograficos debe contener un lugar de nacimiento.
     *POST: Devuelve el lugar de nacimiento en ese dato demografico.
     *Parametros:
     *
     *
     *Complejidad: O(1)
     */
    string getlugnac();

    /*Metodo para devolver un nivel de estudios en el dato demografico que se utilice.
     *PRE: Que datos demograficos debe contener un nivel de estudios.
     *POST: Devuelve el nivel de estudios en ese nivel de estudios.
     *Parametros:
     *
     *
     *Complejidad: O(1)
     */
    string getnivest();

    /*Metodo para devolver una nacionalidad en el dato demografico que se utilice.
     *PRE: Que datos demograficos debe contener un nivel de estudios.
     *POST: Devuelve el nivel de estudios en ese nivel de estudios.
     *Parametros:
     *
     *
     *Complejidad: O(1)
     */
    string getnacional( );

    /*Metodo para devolver un año de nacimiento en el dato demografico que se utilice.
     *PRE: Que datos demograficos debe contener un año de nacimiento.
     *POST: Devuelve el año de nacimiento en ese nivel de estudios.
     *Parametros:
     *
     *
     *Complejidad: O(1)
     */
    string getanonacim();

    /*Metodo para devolver el numero de hombres en el dato demografico que se utilice.
     *PRE: Que datos demograficos debe contener el numero de hombres.
     *POST: Devuelve el numero de hombres en ese nivel de estudios.
     *Parametros:
     *
     *
     *Complejidad: O(1)
     */
    int gethom( );

    /*Metodo para devolver el numero de mujeres en el dato demografico que se utilice.
     *PRE: Que datos demograficos debe contener el numero de mujeres.
     *POST: Devuelve el numero de mujeres en ese nivel de estudios.
     *Parametros:
     *
     *
     *Complejidad: O(1)
     */
    int getmuj( );

	//Muestra la informacion de datos demograficos
	/*
	 *PRE: Datos demograficos debe contener informacion.
	 *POST: Muestra por consola datos demograficos.
	 *Parametros:
	 *
	 *
	 *Complejidad:O(1).
	 */
    void show();

};

#endif /* DATOSDEMOGRAFICOS_H_ */
