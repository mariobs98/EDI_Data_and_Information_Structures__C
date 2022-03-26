/*
 * gestorVias.cpp
 *
 *  Created on: 22 abr. 2018
 *      Author: mario
 */

#include "gestorVias.h"

gestorVias::gestorVias() {
	pVia=new ListaPI<Via*>;
	aVias = new Arbol<Via*, CompararPtrVias> ();

}

void gestorVias::cargarVias(){
	pVia->moverInicio();
	ifstream fent;
	string cad[6];
	Via *v;
	fent.open("Via.csv");
	if(fent.is_open()){
        getline(fent,cad[0]);
		while(!fent.eof()){
          int i=0;
			while(i<4){
            getline(fent,cad[i],'#');
            i++;
			}
		  if(!fent.eof()){
          getline(fent,cad[i]);
          v=new Via(cad[0],cad[1],atof(cad[2].c_str()),cad[3],atof(cad[4].c_str()));
          pVia->insertar(v);
          pVia->avanzar();
          aVias->insertar(v);
		}
		}
	fent.close();
	}
}

gestorVias::~gestorVias(){
	Via *v;
	delete this->aVias;
		pVia->moverInicio();
		while(!pVia->enFin()){
			pVia->consultar(v);
			delete v;
			pVia->borrar();
		}

}

void gestorVias::mostrarEnOrden (Arbol<Via *, CompararPtrVias> *arbolVias) {

	Arbol<Via *, CompararPtrVias> *aux;

    if (!arbolVias->vacio()) {

    	aux = arbolVias->hijoIzq();
        if (aux != NULL) {
        	mostrarEnOrden(aux);
        }

        arbolVias->raiz()->mostrar();

        aux = arbolVias->hijoDer();
        if (aux != NULL) {
        	mostrarEnOrden(aux);
        }

    }
}
void gestorVias::mostrarArbol () {
	mostrarEnOrden(this->aVias);
}

bool gestorVias::buscarEnArbol (Arbol<Via *, CompararPtrVias> *arbolVias, string nombre, Via* &v) {

	Arbol<Via *, CompararPtrVias> *aux;
	Via *vAux = NULL;
	bool enc = false;

	if(!arbolVias->vacio()){
		vAux = arbolVias->raiz();
		if(nombre == vAux->getnombreVia()){
			enc = true;
			v = vAux;
		}else {
			if(nombre < vAux->getnombreVia()){
				aux = arbolVias->hijoIzq();
				if(aux != NULL){
				enc = buscarEnArbol(aux,nombre,v);
				}
			}else {
				aux = arbolVias->hijoDer();
				if(aux != NULL){
				enc = buscarEnArbol(aux,nombre,v);
				}
			}
		}
	}

	return enc;
}

bool gestorVias::buscar (string nombre, Via* &v) {
	v = NULL;
	bool enc = false;
	if (this->aVias != NULL)
		enc = buscarEnArbol (this->aVias, nombre, v);
	return enc;
}

void gestorVias::insertarEnOrdenViaABarrio(Via *v){
	bool enc = false;
	Via *vAux;
	pVia->moverInicio();
	while(!pVia->finLista() && !enc){
		pVia->consultar(vAux);
		if(vAux->getnombreVia()>v->getnombreVia()){
			enc = true;
		}else {
			pVia->avanzar();
		}
	}

	pVia->insertar(v);
	//ar
	aVias->insertar(v);
}

void gestorVias::insertarViasaBarrio(string nombreBarrio){
	pVia->moverInicio();
	ifstream fent;
	string cad[6];
	Via *v;
	fent.open("Via.csv");
	if(fent.is_open()){
        getline(fent,cad[0]);
		while(!fent.eof()){
          int i=0;
			while(i<4){
            getline(fent,cad[i],'#');
            i++;
			}
		  if(!fent.eof()){
          getline(fent,cad[i]);
          if(nombreBarrio == cad[0]){
          v=new Via(cad[0],cad[1],atof(cad[2].c_str()),cad[3],atof(cad[4].c_str()));
          pVia->insertar(v);
          pVia->avanzar();
          }
		}
		}
	fent.close();
	}
}


bool gestorVias::buscarViaRepe(Via *v){
	bool enc=false; Via *v2;
    pVia->moverInicio();
    while(!pVia->finLista()&& !enc){
    	pVia->consultar(v2);
    	if(v->getnombreVia()==v2->getnombreVia()){
    		enc=true;
    	}
    	pVia->avanzar();
    }
	return enc;
}


void gestorVias::devolverVias(ListaPI<Via*>*&pViaAux){
	Via *v[2]; bool enc=false;

	if (!pVia->estaVacia()){
	pVia->moverInicio();
	while(!pVia->finLista()){
		pVia->consultar(v[0]);
		{
			pViaAux->moverInicio();
			enc=false;
			while(!pViaAux->finLista() && !enc){
			pViaAux->consultar(v[1]);

               if(v[0]->getnombreVia()==v[1]->getnombreVia()){
				enc=true;

               }

			pViaAux->avanzar();
			}
			if(enc==false){
			pViaAux->insertar(v[0]);
			}
		}
		pVia->avanzar();
	}
	}
}

void gestorVias::insertarNacionalidades(ListaPI<Nacionalidad*>*&pNacionalidades){
	Via *v;
	if(!pVia->estaVacia()){
		pVia->moverInicio();
		while(!pVia->finLista()){
			pVia->consultar(v);
			pVia->avanzar();
			v->insertarNacionalidades(pNacionalidades);
		}
	}
}

void gestorVias::insertarLugarNacimiento(ListaPI<LugarNacimiento*>*&pLugNac){
	Via *v;
	if(!pVia->estaVacia()){
		pVia->moverInicio();
		while(!pVia->finLista()){
			pVia->consultar(v);
			pVia->avanzar();
			v->insertarLugarNacimiento(pLugNac);
		}
	}
}

void gestorVias::getTotalHabitantesRangoEdadDado(int &limInf,int &limSup,int &totalHabitantes){
	Via *v;
	int habitantes=0;
	totalHabitantes=0;
	pVia->moverInicio();
	if(!pVia->estaVacia()){
		while(!pVia->finLista()){
			pVia->consultar(v);
			v->getTotalHabitantesRangoEdadDado(limInf,limSup,habitantes);
			totalHabitantes = totalHabitantes + habitantes;
			pVia->avanzar();
		}
	}
}

void gestorVias::InsertarEstudios(ListaPI<Estudios*>*&pEstudiosAux){
	Via *v;
	pVia->moverInicio();
	if(!pVia->estaVacia()){
		while(!pVia->finLista()){
			pVia->consultar(v);
			pVia->avanzar();
			v->InsertarEstudios(pEstudiosAux);
		}
	}
}

void gestorVias::getNumHombres(int &totalhom){
	totalhom = 0;
	int hom = 0;
	Via *v;
	pVia->moverInicio();
	if(!pVia->estaVacia()){
		while(!pVia->finLista()){
		pVia->consultar(v);
		v->gethombresDeLaVia(hom);
		totalhom = totalhom + hom;
		pVia->avanzar();
		}
	}
}

void gestorVias::getNumMujeres(int &totalmuj){
	totalmuj = 0;
	int muj = 0;
	Via *v;
	pVia->moverInicio();
	if(!pVia->estaVacia()){
		while(!pVia->finLista()){
		pVia->consultar(v);
		v->getmujeresDeLaVia(muj);
		totalmuj = totalmuj + muj;
		pVia->avanzar();
		}
	}
}

void gestorVias::mostrariterativo(){
	Via *v;
	pVia->moverInicio();
	while(!pVia->enFin()){
		pVia->consultar(v);

		//Muestra los datos de la Via junto los Demograficos
		//v->mostrarJuntoDatosDemograficos();

		//Muestra los datos de la Via
		v->mostrar();

		pVia->avanzar();
	}
}

void gestorVias::devolverUnaViayComparar(ListaPI<Via*>*&auxv){
	Via *v[2];
	if(!pVia->estaVacia()){
		pVia->moverInicio();
		 while(!pVia->finLista()){
			 pVia->consultar(v[0]);
			 if(!auxv->estaVacia()){
				auxv->moverInicio();
				 while(!auxv->finLista()){
					auxv->consultar(v[1]);
					if(v[0]->getnombreBarrio()!=v[1]->getnombreBarrio()){
						auxv->insertar(v[0]);
					}
					auxv->avanzar();
				 }

		 }else{//caso de lista auxiliar vacia
			 auxv->insertar(v[0]);
		 }
			 pVia->avanzar();
	}

   }
}


void gestorVias::devolverViasCorrespondientes(string &nombreVia, Via *&vaux){
    Via *v; bool enc=false;
    if(!pVia->estaVacia()){
    	pVia->moverInicio();
    	while(!pVia->finLista()&& !enc){
    		pVia->consultar(v);
    		if(v->getnombreVia()==nombreVia){
    			vaux=v;
                enc=true;
                nombreVia=v->getnombreVia();
    		}
    		pVia->avanzar();
    	}
    }
}


void gestorVias::viasEmpiezanPor(string nombreVia, ListaPI<Via*>*&pViaAux){
	Via *v;

    if(!pVia->estaVacia()){
    	pVia->moverInicio();
    	while(!pVia->finLista()){
    		pVia->consultar(v);
    		if(v->empiezaPor(v->getnombreVia(),nombreVia)){
    			pViaAux->insertar(v);


    		}
    		pVia->avanzar();
    	}
    }
}

void gestorVias::algoritmo12(Arbol<Via *, CompararPtrVias> *arbolVias,string nombreVia,Arbol<Via*, CompararPtrVias>  *&ArbolAux ){

	Arbol<Via *, CompararPtrVias> *aux;

    if (!arbolVias->vacio()) {

    	aux = arbolVias->hijoIzq();
        if (aux != NULL) {
        	algoritmo12(aux,nombreVia,ArbolAux);
        }
        if(arbolVias->raiz()->empiezaPor(arbolVias->raiz()->getnombreVia(),nombreVia)){
        ArbolAux->insertar(arbolVias->raiz());

        }
        aux = arbolVias->hijoDer();
        if (aux != NULL) {
        	algoritmo12(aux,nombreVia,ArbolAux);
        }

    }

}


void gestorVias::algoritmo12Arbol(string nombreVia,Arbol<Via*, CompararPtrVias>  *&ArbolAux){
	algoritmo12(this->aVias,nombreVia,ArbolAux);
}



