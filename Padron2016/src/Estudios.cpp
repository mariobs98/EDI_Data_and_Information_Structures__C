/*
 * Estudios.cpp
 *
 *  Created on: 9 may. 2018
 *      Author: enrique
 */

#include "Estudios.h"

Estudios::Estudios() {
	this->nivelEstudios="";
	this->NumPersonas=0;
}

Estudios::Estudios(string nivelEstudios, int NumPersonas) {
	this->nivelEstudios=nivelEstudios;
	this->NumPersonas=NumPersonas;
}


Estudios::~Estudios() {

}


void Estudios::setnivelEstudios(string nivelEstudios){
	this->nivelEstudios=nivelEstudios;
}

void Estudios::setNumPersonas(int NumPersonas){
		this->NumPersonas=NumPersonas;
}


string Estudios::getnivelEstudios(){
	return this->nivelEstudios;
}

int Estudios::getNumPersonas(){
   return this->NumPersonas;
}


void Estudios::mostrar(){
	cout<<"Nivel de Estudios: "<<this->nivelEstudios<<endl;
	cout<<"Numero de Personas: "<<this->NumPersonas<<endl;
	cout<<endl;
}
