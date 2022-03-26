/*
 * Nacionalidad.cpp
 *
 *  Created on: 9 may. 2018
 *      Author: mario
 */

#include "Nacionalidad.h"

Nacionalidad::Nacionalidad() {
	this->pais = "";
	this->numPersonas = 0;
}

Nacionalidad::Nacionalidad(string pais,int numPersonas){
	this->pais = pais;
	this->numPersonas = numPersonas;
}

Nacionalidad::~Nacionalidad() {

}


void Nacionalidad::setPais(string pais){
	this->pais = pais;
}

void Nacionalidad::setnumPersonas(int numPersonas){
	this->numPersonas = numPersonas;
}

string Nacionalidad::getPais(){
	return this->pais;
}

int Nacionalidad::getnumPersonas (){
	return this->numPersonas;
}

void Nacionalidad::mostrar(){
	cout<<"Pais: "<<this->pais<<endl;
	cout<<"Numero de Personas: "<<this->numPersonas<<endl;
	cout<<endl;
}




