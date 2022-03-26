/*
 * datosDemograficos.cpp
 *
 *  Created on: 21 abr. 2018
 *      Author: mario
 */

#include "datosDemograficos.h"

datos_Demograficos::datos_Demograficos() {
	this->codigovia=0;
	this->lugnac="";
	this->anonacim="";
	this->nivest="";
	this->nacional="";
	this->hom=0;
	this->muj=0;
	this->anocr=0;


	this->gln = new gestorLugardeNacimiento();
	this->ga = new gestorAnoNacimiento ();
	this->ge = new gestorEstudios();
	this->gn = new gestorNacionalidad();
}

datos_Demograficos::datos_Demograficos(int codigovia,string anonacim,string lugnac,string nivest,
		int hom,int muj,string nacional,int anocr){

	this->codigovia=codigovia;
	this->lugnac=lugnac;
	this->anonacim=anonacim;
	this->nivest=nivest;
	this->nacional=nacional;
	this->hom=hom;
	this->muj=muj;
	this->anocr=anocr;

	this->gln = new gestorLugardeNacimiento(lugnac);
	this->ga = new gestorAnoNacimiento (anonacim);
	this->ge = new gestorEstudios(nivest);
	this->gn = new gestorNacionalidad(nacional);
}

datos_Demograficos::~datos_Demograficos(){

}

void datos_Demograficos::algoritmo4Edad(int (&v)[11]){
	ga->algoritmo4Edad(v);
}

void datos_Demograficos::insertarNacionalidades(ListaPI<Nacionalidad*>*&pNacionalidades){
	gn->insertarNacionalidades(pNacionalidades);
}

void datos_Demograficos::insertarLugarNacimiento(ListaPI<LugarNacimiento*>*&pLugNac){
	gln->insertarLugarNacimiento(pLugNac);
}

void datos_Demograficos::getTotalHabitantesRangoEdadDado(int &limInf,int &limSup,int &Habitantes){
	ga->getTotalHabitantesRangoEdadDado(limInf,limSup,Habitantes);
}

void datos_Demograficos::InsertarEstudios(ListaPI<Estudios*>*&pEstudiosAux){
	ge->InsertarEstudios(pEstudiosAux);
}

void datos_Demograficos::algoritmo10LN(ListaPI<LugarNacimiento*>*&LNAux, string provincia){
	gln->algoritmo10provincias(LNAux,provincia);
}


void datos_Demograficos::algoritmo11(ListaPI<LugarNacimiento*>*&LNAux){
	gln->obtenerdatosNacimientos(LNAux);
}


void datos_Demograficos::algoritmo12MuestraPersonasProvincia(ListaPI<LugarNacimiento*>*&LNAux){

     gln->MuestrapersonasProvincia(LNAux);

}

void datos_Demograficos::setCodigovia(int codigovia){
	this->codigovia=codigovia;
}

void datos_Demograficos::setlugnac(string lugnac){
	this->lugnac=lugnac;
}

void datos_Demograficos::setanonacimiento(string anonacim){
	this->anonacim=anonacim;
}

void datos_Demograficos::setnivest(string nivest){
    this->nivest=nivest;
}

void datos_Demograficos::setnacional(string nacional){
   	this->nacional=nacional;
}

void datos_Demograficos::sethom(int hom){
   	this->hom=hom;
}

void datos_Demograficos::setmuj(int muj){
   	this->muj=muj;
}

void datos_Demograficos::setanocr(int anocr){
   	this->anocr=anocr;
}

int datos_Demograficos::getCodigovia(){
	return (this->codigovia);
}

string datos_Demograficos::getlugnac(){
   	return(this->lugnac);
}

string datos_Demograficos::getnivest(){
	return(this->nivest);
}

string datos_Demograficos::getnacional(){
	return(this->nacional);
}

string datos_Demograficos::getanonacim(){
    return(this->anonacim);
}

int datos_Demograficos::gethom(){
    return(this->hom);
}

int datos_Demograficos::getmuj(){
    return(this->muj);
}

int datos_Demograficos::getanocr(){
    return(this->anocr);
}

void datos_Demograficos::show(){
cout<<"Codigo de Via: "<<this->codigovia<<endl;
cout<<"Lugar de nacimiento: "<<this->lugnac<<endl;
cout<<"Anos de nacimiento: "<<this->anonacim<<endl;
cout<<"Nacionalidad: "<<this->nacional<<endl;
cout<<"Nivel de estudios: "<<this->nivest<<endl;
cout<<"Numero de Hombres: "<<this->hom<<endl;
cout<<"Numero de Mujeres: "<<this->muj<<endl;
cout<<"Ano de creacion: "<<this->anocr<<endl;
cout<<"---------------------------------------"<<endl;
}

