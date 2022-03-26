/*
 * AnoNacimiento.cpp
 *
 *  Created on: 9 may. 2018
 *      Author: mario
 */

#include "AnoNacimiento.h"

AnoNacimiento::AnoNacimiento() {
	this->ano=0;
	this->numPersonas=0;
}

AnoNacimiento::AnoNacimiento(int ano,int numPersonas){
	this->ano=ano;
	this->numPersonas=numPersonas;
}

AnoNacimiento::~AnoNacimiento() {

}

void AnoNacimiento::setano(int ano){
	this->ano=ano;
}

void AnoNacimiento::setnumPersonas(int numPersonas){
	this->numPersonas=numPersonas;
}

int AnoNacimiento::getano(){
	return this->ano;
}

int AnoNacimiento::getnumPersonas(){
	return this->numPersonas;
}

void AnoNacimiento::mostrar(){
	cout<<"Ano de Nacimiento: "<<this->ano<<endl;
	cout<<"Numero de Personas: "<<this->numPersonas<<endl;
	cout<<endl;
}





