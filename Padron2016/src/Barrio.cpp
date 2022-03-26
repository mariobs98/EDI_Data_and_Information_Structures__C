/*
 * ClaseBarrio.cpp
 *
 *  Created on: 19 feb. 2018
 *      Author: mario
 */

#include "Barrio.h"

Barrio::Barrio() {
	nombreBarrio="";
	nombreDistrito="";
	gv = new gestorVias();
	}


Barrio::Barrio(string nombreBarrio,string nombreDistrito){
		this->nombreBarrio=nombreBarrio;
		this->nombreDistrito=nombreDistrito;
		gv = new gestorVias();
	}

Barrio::~Barrio() {
    gv->~gestorVias();
	}

void Barrio::introducirVia(Via *v){
	gv->insertarEnOrdenViaABarrio(v);
}

void Barrio::devolverVias(ListaPI<Via*>*&pViaAux){
	gv->devolverVias(pViaAux);
}

void Barrio::algoritmo3(ListaPI<Via*>*&auxv){
    gv->devolverUnaViayComparar(auxv);
}

void Barrio::insertarNacionalidades(ListaPI<Nacionalidad*>*&pNacionalidades){
	gv->insertarNacionalidades(pNacionalidades);
}

void Barrio::insertarLugarNacimiento(ListaPI<LugarNacimiento*>*&pLugNac){
	gv->insertarLugarNacimiento(pLugNac);
}

void Barrio::getTotalHabitantesRangoEdadDado(int &limInf,int &limSup,int &Habitantes){
	gv->getTotalHabitantesRangoEdadDado(limInf,limSup,Habitantes);
}

void Barrio::InsertarEstudios(ListaPI<Estudios*>*&pEstudiosAux){
	gv->InsertarEstudios(pEstudiosAux);
}

void Barrio::getTotalHombres(int &hom){
	gv->getNumHombres(hom);
}

void Barrio::getTotalMujeres(int &muj){
	gv->getNumMujeres(muj);
}

void Barrio::algoritmo11(string &nombreVia,Via *&vaux){
    gv->devolverViasCorrespondientes(nombreVia, vaux);
}

void Barrio::algoritmo11Arbol(string &nombreViaArbol,Via *&vArbol){
	gv->buscar(nombreViaArbol,vArbol);
}

void Barrio::algoritmo12(string nombreVia,ListaPI<Via*>*&pViaAux){
	gv->viasEmpiezanPor(nombreVia,pViaAux);
}

void Barrio::algoritmo12Arbol(string nombreVia,Arbol<Via*, CompararPtrVias>  *&ArbolAux ){
	gv->algoritmo12Arbol(nombreVia,ArbolAux);
}

void Barrio::setnombreBarrio(string nombreBarrio){
	this->nombreBarrio=nombreBarrio;
}

void Barrio::setnombreDistrito(string nombreDistrito){
	this->nombreDistrito=nombreDistrito;
}

string Barrio::getnombreBarrio()const{
	return nombreBarrio;
}

void Barrio::getnombreBarrio(string &nombreBarrio)const{
	nombreBarrio=this->nombreBarrio;
}

string Barrio::getnombreDistrito()const{
	return nombreDistrito;
}

void Barrio::getnombreDistrito(string &nombreDistrito)const{
	nombreDistrito=this->nombreDistrito;
}

void Barrio::mostrar(){
	cout<<"Barrio: "<<nombreBarrio<<" --- "<<"Distrito: "<<nombreDistrito<<endl;
	cout<<"------------------------------------------------------------------"<<endl;
}

void Barrio::mostrarViasdeBarrio(){
	cout<<"Para el Barrio: "<<this->getnombreBarrio()<<" y Distrito: "<<this->getnombreDistrito()
			<<" se encuentran las siguientes Vias: "<<endl;
			gv->mostrariterativo();
}


bool Barrio::buscarViaRepe(Via *v){
	bool enc=false;
	enc=gv->buscarViaRepe(v);
	return enc;
}


bool Barrio::operator ==(const Barrio & b){
	return (nombreBarrio==b.nombreBarrio);
}

bool Barrio::operator > (const Barrio &b){
	return (nombreBarrio > b.nombreBarrio);
}

bool Barrio::operator < (const Barrio &b){
	return (nombreBarrio < b.nombreBarrio);
}


