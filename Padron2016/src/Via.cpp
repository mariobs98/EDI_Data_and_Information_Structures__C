/*
 * Via.cpp
 *
 *  Created on: 19 feb. 2018
 *      Author: mario
 */

#include "Via.h"

Via::Via() {
	nombreBarrio="";
	nombreVia="";
	longitudVia=0;
	tipoVia="";
	codigoVia=0;
	dd = new datos_Demograficos;
}

Via::Via(string nombreBarrio,string nombreVia,float longitudVia,string tipoVia,int codigoVia){
	this->nombreBarrio=nombreBarrio;
	this->nombreVia=nombreVia;
	this->longitudVia=longitudVia;
	this->tipoVia=tipoVia;
	this->codigoVia=codigoVia;
	dd = new datos_Demograficos;

}


Via::~Via() {

}


void Via::introducirDatosDemograficos(datos_Demograficos *dd){
	this->dd = dd;
}

void Via::insertarNacionalidades(ListaPI<Nacionalidad*>*&pNacionalidades){
	dd->insertarNacionalidades(pNacionalidades);
}

void Via::insertarLugarNacimiento(ListaPI<LugarNacimiento*>*&pLugNac){
	dd->insertarLugarNacimiento(pLugNac);
}

void Via::getTotalHabitantesRangoEdadDado(int &limInf,int &limSup,int &Habitantes){
	dd->getTotalHabitantesRangoEdadDado(limInf,limSup,Habitantes);
}

void Via::InsertarEstudios(ListaPI<Estudios*>*&pEstudiosAux){
 dd->InsertarEstudios(pEstudiosAux);
}

void Via::gethombresDeLaVia(int &hom){
	hom = dd->gethom();
}

void Via::getmujeresDeLaVia(int &muj){
	muj = dd->getmuj();
}


void Via::algoritmo11(ListaPI<LugarNacimiento*>*&LNAux){
    dd->algoritmo11(LNAux);
}


void Via::algoritmo12(ListaPI<LugarNacimiento*>*&LNAux){
  dd->algoritmo12MuestraPersonasProvincia(LNAux);
}

void Via::setnombreBarrio(string nombreBarrio){
	this->nombreBarrio=nombreBarrio;
}

void Via::setnombreVia(string nombreVia){
	this->nombreVia=nombreVia;
}

void Via::setlongitudVia(float longitudVia){
	this->longitudVia=longitudVia;
}

void Via::settipoVia(string tipoVia){
	this->tipoVia=tipoVia;
}

void Via::setcodigoVia(int codigoVia){
	this->codigoVia=codigoVia;
}

string Via::getnombreBarrio()const{
	return nombreBarrio;
}

void Via::getnombreBarrio(string &nombreBarrio)const{
	nombreBarrio=this->nombreBarrio;
}

string Via::getnombreVia()const{
	return nombreVia;
}

void Via::getnombreVia(string &nombreVia)const{
	nombreVia=this->nombreVia;
}

float Via::getlongitudVia()const{
	return longitudVia;
}

void Via::getlongitudVia(float &longitudVia)const{
	longitudVia=this->longitudVia;
}

string Via::gettipoVia()const{
	return tipoVia;
}

void Via::gettipoVia(string &tipoVia)const{
	tipoVia=this->tipoVia;
}

int Via::getcodigoVia()const{
	return codigoVia;
}

void Via::getcodigoVia(int &codigoVia)const{
	codigoVia=this->codigoVia;
}

void Via::mostrar(){
	cout<<"Barrio: "<<nombreBarrio<<"---"<<" Via: "<<nombreVia<<"---"<<" longitud de Via: "<<longitudVia
			<<"---"<<" tipo de via: "<<tipoVia<<"---"<<" codigo de via: "<<codigoVia<<endl;
}

void Via::mostrarJuntoDatosDemograficos(){
	cout<<"Barrio: "<<nombreBarrio<<"---"<<" Via: "<<nombreVia<<"---"<<" longitud de Via: "<<longitudVia
				<<"---"<<" tipo de via: "<<tipoVia<<"---"<<" codigo de via: "<<codigoVia<<endl;
		cout<<endl;
		cout<<"Los Datos Demograficos son : "<<endl;
		dd->show();
}

bool Via::operator ==(const Via &v){
	bool enc=false;
	if(nombreBarrio==v.nombreBarrio){
		if(nombreVia==v.nombreVia){
			if(longitudVia==v.longitudVia){
				if(tipoVia==v.tipoVia){
					if(codigoVia==v.codigoVia){
						enc=true;
					}
							}
			}

		}
	}
	return enc;
}

bool Via::operator >(const Via &v){
	return (nombreVia>v.nombreVia);
}

bool Via::operator <(const Via &v){
	return (nombreVia<v.nombreVia);
}

bool Via::empiezaPor (string str, string substr) {
	bool siEmpieza = false;
	if (str.find(substr) == 0)
		siEmpieza =  true;
	return siEmpieza;
}


