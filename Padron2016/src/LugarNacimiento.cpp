/*
 * LugarNacimiento.cpp
 *
 *  Created on: 9 abr. 2018
 *      Author: enrique
 */

#include "LugarNacimiento.h"

LugarNacimiento::LugarNacimiento() {
	this->poblacion="";
	this->provincia="";
	this->personas=0;

}

LugarNacimiento::LugarNacimiento(string poblacion1,string provincia1,int personas1){
	this->poblacion=poblacion1;
	this->provincia=provincia1;
	this->personas=personas1;
}

LugarNacimiento::~LugarNacimiento() {

}


void LugarNacimiento::setpoblacion(string poblacion){
	this->poblacion=poblacion;
}

void LugarNacimiento::setprovincia(string provincia){
	this->provincia=provincia;
}

void LugarNacimiento::setpersonas(int personas){
	this->personas=personas;
}


string LugarNacimiento::getpoblacion(){
	return this->poblacion;
}

string LugarNacimiento::getprovincia(){
	return this->provincia;
}

int LugarNacimiento::getpersonas(){
	return this->personas;
}

void LugarNacimiento::mostrarAlg6(){
	cout<<"Provincia: "<<this->provincia<<endl;
	cout<<"Personas: "<<this->personas<<endl;
	cout<<endl;
}

void LugarNacimiento::show(){
	cout<<"Poblacion: "<<this->poblacion<<endl;
	cout<<"Provincia: "<<this->provincia<<endl;
	cout<<"Personas: "<<this->personas<<endl;
	cout<<endl;
}


