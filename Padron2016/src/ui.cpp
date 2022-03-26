//============================================================================
// Name        : UI.cpp
// Author      : Profesores de la asignatura EDI
// Version     : Curso 17/18
// Copyright   :
// Description : Interfaz de usuario
//============================================================================

#include <fstream>
#include <iostream>
#include "ui.h"
#include "timer.h"


using namespace std;

UI::UI() {
	// TODO
	this->gg=NULL;
	//pruebasTiempo(); //Para ejecutarlas,descomentar esta linea y comentar la linea siguiente.
	ejecutar();
}

void UI::ejecutar() {


	double t_start, t_end;
	int opcion;

	bool salir = false;
	do {
		opcion = menu();
		switch (opcion) {
		case 1:


			t_start = Time::getTime();
			cout << "Cargando datos ... " << endl;

			algoritmo_1();

			cout << "Carga finalizada ... " << endl;
			t_end = Time::getTime();
			cout << "Time: " << t_end - t_start << "  " << endl;
			break;
		case 2:

			t_start = Time::getTime();

			algoritmo_2();

			t_end = Time::getTime();

			cout << "Time: " << t_end - t_start << "  " << endl;
			break;
		case 3:

			t_start = Time::getTime();

			algoritmo_3();

			t_end = Time::getTime();
			cout << "Time: " << t_end - t_start << "  " << endl;
			break;
		case 4:

			t_start = Time::getTime();

			algoritmo_4();

			t_end = Time::getTime();
			cout << "Time: " << t_end - t_start << "  " << endl;
			break;
		case 5:
			t_start = Time::getTime();

			algoritmo_5();

			t_end = Time::getTime();
			cout << "Time: " << t_end - t_start << "  " << endl;

			break;
		case 6:
			t_start = Time::getTime();

			algoritmo_6();

			t_end = Time::getTime();
			cout << "Time: " << t_end - t_start << "  " << endl;

			break;
		case 7:

			t_start = Time::getTime();

			algoritmo_7();

			t_end = Time::getTime();
			cout << "Time: " << t_end - t_start << "  " << endl;

			break;
		case 8:

			t_start = Time::getTime();

			algoritmo_8();

			t_end = Time::getTime();
			cout << "Time: " << t_end - t_start << "  " << endl;

			break;
		case 9:
			t_start = Time::getTime();

			algoritmo_9();

			t_end = Time::getTime();
			cout << "Time: " << t_end - t_start << "  " << endl;

			break;
		case 10:

			t_start = Time::getTime();

			algoritmo_10();

			t_end = Time::getTime();
			cout << "Time: " << t_end - t_start << "  " << endl;

			break;
		case 11:

			t_start = Time::getTime();

			algoritmo_11();

			t_end = Time::getTime();
			cout << "Time: " << t_end - t_start << "  " << endl;

			break;
		case 12:
			t_start = Time::getTime();

			algoritmo_12();

			t_end = Time::getTime();
			cout << "Time: " << t_end - t_start << "  " << endl;
			break;
		case 0:
			salir = true;
			break;
		default:
			cout << "ERROR en la opcion de menu" << endl;
			break;
		}

	} while (!salir);
}

int UI::menu() {

	int opcion;

	do {
		cout << endl;
		cout << "_________________________________ MENU PRINCIPAL __________________________________"<< endl << endl;

		cout << "   1. Carga de datos                                                               "<< endl;
		cout << "   2. Mostrar vías de un barrio                                                    "<< endl;
		cout << "   3. Mostrar las vías que pertenecen a varios barrios                             "<< endl;
		cout << "   4. Mostrar el número de habitantes de Cáceres agrupados por rango de edad       "<< endl;
		cout << "   5. Listado por nacionalidades                                                   "<< endl;
		cout << "   6. Número de habitantes por provincia de nacimiento                             "<< endl;
		cout << "   7. Barrio con mayor número de habitantes para un rango de edad                  "<< endl;
		cout << "   8. Fichero por nivel de estudios de todos los ciudadanos de un barrio           "<< endl;
		cout << "   9. Barrio con mayor porcentaje de hombres/mujeres.                              "<< endl;
		cout << "  10. Fichero con los habitantes nacidos en los pueblos de una provincia           "<< endl;
		cout << "  11. Fichero por lugar de nacimiento de una determinada vía (Alg. crítico)        "<< endl;
		cout << "  12. Listado nº de personas nacidas en una provincia de las vias que comiencen por...(Alg.crítico)"<< endl;

		cout << endl;
		cout << "   0. Finalizar. " << endl;
		cout << " Opcion:  ";
		cin >> opcion;
		cin.ignore();

	} while ((opcion < 0) || (opcion > 13));

	return opcion;
}

UI::~UI() {
	delete gg;
	cout << "Finalizado....";
}

void UI::algoritmo_1(){
	this->gg = new GestorGeneral();
}
void UI::algoritmo_2(){
	this->gg->algoritmo_2();
}
void UI::algoritmo_3(){
	this->gg->algoritmo_3();
}
void UI::algoritmo_4(){
	this->gg->algoritmo_4();
}
void UI::algoritmo_5(){
	this->gg->algoritmo_5();
}
void UI::algoritmo_6(){
	this->gg->algoritmo_6();
}
void UI::algoritmo_7(){
	this->gg->algoritmo_7();
}
void UI::algoritmo_8(){
	this->gg->algoritmo_8();
}
void UI::algoritmo_9(){
	this->gg->algoritmo_9();
}
void UI::algoritmo_10(){
	this->gg->algoritmo_10();
}
void UI::algoritmo_11(){
	this->gg->algoritmo_11();
}
void UI::algoritmo_12(){
	this->gg->algoritmo_12();
}


void UI::pruebasTiempo(){

	Listapruebas();

	double t_start, t_end;

	t_start = Time::getTime();

	algoritmo_1();

	t_end = Time::getTime();
	cout << "Ha tardado en el Algoritmo 1 (carga) Time: " << t_end - t_start << "  " << endl;

	t_start = Time::getTime();

	gg->algoritmoP_2();

	t_end = Time::getTime();

	cout << "Ha tardado en el Algoritmo 2 Time: " << t_end - t_start << "  " << endl;

	t_start = Time::getTime();

	gg->algoritmoP_3();

	t_end = Time::getTime();
	cout << "Ha tardado en el Algoritmo 3 Time: " << t_end - t_start << "  " << endl;

	t_start = Time::getTime();

	gg->algoritmoP_4();

	t_end = Time::getTime();
	cout << "Ha tardado en el Algoritmo 4 Time: " << t_end - t_start << "  " << endl;

	t_start = Time::getTime();

	gg->algoritmoP_5();

	t_end = Time::getTime();
	cout << "Ha tardado en el Algoritmo 5 Time: " << t_end - t_start << "  " << endl;

	t_start = Time::getTime();

	gg->algoritmoP_6();

	t_end = Time::getTime();
	cout << "Ha tardado en el Algoritmo 6 Time: " << t_end - t_start << "  " << endl;

	t_start = Time::getTime();

	gg->algoritmoP_7();

	t_end = Time::getTime();
	cout << "Ha tardado en el Algoritmo 7 Time: " << t_end - t_start << "  " << endl;

	t_start = Time::getTime();

	gg->algoritmoP_8();

	t_end = Time::getTime();
	cout << "Ha tardado en el Algoritmo 8 Time: " << t_end - t_start << "  " << endl;

	t_start = Time::getTime();

	gg->algoritmoP_9();

	t_end = Time::getTime();
	cout << "Ha tardado en el Algoritmo 9 Time: " << t_end - t_start << "  " << endl;

	t_start = Time::getTime();

	gg->algoritmoP_10();

	t_end = Time::getTime();
	cout << "Ha tardado en el Algoritmo 10 Time: " << t_end - t_start << "  " << endl;

	t_start = Time::getTime();

	gg->algoritmoP_11();

	t_end = Time::getTime();
	cout << "Ha tardado en el Algoritmo 11 Time: " << t_end - t_start << "  " << endl;

	t_start = Time::getTime();

	gg->algoritmoP_12();

	t_end = Time::getTime();
	cout << "Ha tardado en el Algoritmo 12 Time: " << t_end - t_start << "  " << endl;

}

int main() {

	UI ui;

	return 0;
}



