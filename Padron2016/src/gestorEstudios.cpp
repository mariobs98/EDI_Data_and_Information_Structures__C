/*
 * gestorEstudios.cpp
 *
 *  Created on: 9 may. 2018
 *      Author: enrique
 */

#include "gestorEstudios.h"

gestorEstudios::gestorEstudios() {
	pEstudios=new ListaPI<Estudios*>;
}

gestorEstudios::gestorEstudios(string nivest) {
	pEstudios=new ListaPI<Estudios*>;
	Estudios *e;
    char delim = ';';
	vector<string> vText = splitStringToVector(nivest, delim);
	for (int i = 0; i < static_cast<int>(vText.size()); i++) {
		vector<string> vString = splitString(vText[i]);
		e= new Estudios(vString[0],atoi(vString[1].c_str()));
		        pEstudios->moverFinal();
		        pEstudios->avanzar();
		        pEstudios->insertar(e);
		}
}

gestorEstudios::~gestorEstudios() {
	Estudios *e;
		   pEstudios->moverInicio();
		   	   while(!pEstudios->estaVacia()){
		   		   pEstudios->consultar(e);
		   		   delete e;
		   		   pEstudios->borrar();//el borrar ya avanza al siguiente
		   	   	   }
		   	   delete pEstudios;
}

void gestorEstudios::InsertarEstudios(ListaPI<Estudios*>*&pEstudiosAux){
	Estudios *e,*eAux;
	bool enc=false;
	int sumador = 0;

	pEstudios->moverInicio();
	if(!pEstudios->estaVacia()){
		while(!pEstudios->finLista()){
			pEstudios->consultar(e);
			pEstudios->avanzar();

			pEstudiosAux->moverInicio();
			enc=false;
			while(!pEstudiosAux->finLista() && !enc){
				pEstudiosAux->consultar(eAux);
				if(eAux->getnivelEstudios() == e->getnivelEstudios()){
					enc=true;
					sumador = eAux->getNumPersonas() + e->getNumPersonas();
					eAux->setNumPersonas(sumador);
				}else{
					pEstudiosAux->avanzar();
				}
			}
			if(enc==false){
				eAux = new Estudios (e->getnivelEstudios(),e->getNumPersonas());
				pEstudiosAux->insertar(eAux);
			}
		}
	}

}


void gestorEstudios::mostrar(){
	     Estudios *e;
	     pEstudios->moverInicio();
	         while(!pEstudios->enFin()){
	        	 pEstudios->consultar(e);
	        	 pEstudios->avanzar();
	        	 e->mostrar();
	         	 }
}
