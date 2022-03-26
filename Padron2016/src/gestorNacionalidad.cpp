/*
 * gestorNacionalidad.cpp
 *
 *  Created on: 9 may. 2018
 *      Author: mario
 */

#include "gestorNacionalidad.h"

gestorNacionalidad::gestorNacionalidad() {
	pNacionalidad = new ListaPI<Nacionalidad*>;
}

gestorNacionalidad::gestorNacionalidad(string nacional){
	pNacionalidad=new ListaPI<Nacionalidad*>;
	Nacionalidad *n;
    char delim = ';';
	vector<string> vText = splitStringToVector(nacional, delim);
	for (int i = 0; i < static_cast<int>(vText.size()); i++) {
		vector<string> vString = splitString(vText[i]);

		n = new Nacionalidad (vString[0],atoi(vString[1].c_str()));

		pNacionalidad->moverFinal();
		pNacionalidad->avanzar();
		pNacionalidad->insertar(n);
	}
}

gestorNacionalidad::~gestorNacionalidad() {

}

void gestorNacionalidad::insertarNacionalidades(ListaPI<Nacionalidad*>*&pNacionalidades){
	Nacionalidad *n,*nac;
	bool enc=false;
	int sumador=0;
	if(!pNacionalidad->estaVacia()){
		pNacionalidad->moverInicio();
		while(!pNacionalidad->finLista()){
			pNacionalidad->consultar(n);
			pNacionalidad->avanzar();

			pNacionalidades->moverInicio();
			enc=false;
			while(!pNacionalidades->finLista() && !enc){
				pNacionalidades->consultar(nac);
				if(nac->getPais() == n->getPais()){
					enc=true;
					sumador = nac->getnumPersonas() + n->getnumPersonas();
					nac->setnumPersonas(sumador);
				}else{
					pNacionalidades->avanzar();
				}
			}
			if(enc==false){
				nac = new Nacionalidad(n->getPais(),n->getnumPersonas());
				pNacionalidades->insertar(nac);
			}
		}
	}
}


void gestorNacionalidad::mostrar(){
	Nacionalidad *n;
		pNacionalidad->moverInicio();
			while(!pNacionalidad->enFin()){
				pNacionalidad->consultar(n);
				pNacionalidad->avanzar();
				n->mostrar();
				}
}




