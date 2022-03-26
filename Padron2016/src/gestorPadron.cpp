/*
 * gestorPadron.cpp
 *
 *  Created on: 22 abr. 2018
 *      Author: mario
 */

#include "gestorPadron.h"

gestorPadron::gestorPadron() {
	pPadron = new ListaPI<datos_Demograficos*>;
}

gestorPadron::~gestorPadron() {
	pPadron->moverInicio();
		datos_Demograficos *d;

		while(!pPadron->enFin()){
			pPadron->consultar(d);
			delete d;
			pPadron->borrar();
		}
}

void gestorPadron::cargarDatos_Demograficos(){
	datos_Demograficos *d;
	ifstream fent; string cad[8];
    fent.open("InformacionPadron.csv");
    if(fent.is_open()){
    	pPadron->moverInicio();
    	getline(fent,cad[0]);
    	while(!fent.eof()){
    	int i=0;
    	while(i<7){
    		getline(fent,cad[i],'#');
    		i++;
    	}
    	if(!fent.eof()){
    	getline(fent,cad[i]);
    	d= new datos_Demograficos(atoi(cad[0].c_str()),cad[1],cad[2],cad[3],
    			atoi(cad[4].c_str()),atoi(cad[5].c_str()),cad[6],atoi(cad[7].c_str()));

		pPadron->insertar(d);
    	pPadron->avanzar();
    	}
    	}
    	fent.close();
    }
}

void gestorPadron::buscarDatosDemografico(int codigoVia,datos_Demograficos *&dd){
	datos_Demograficos *ddAux;
			bool enc=false;
			pPadron->moverInicio();
			while(!pPadron->finLista() && !enc){
				pPadron->consultar(ddAux);
				if(ddAux->getCodigovia() == codigoVia){
					enc=true;
					dd = ddAux;
				}
				pPadron->avanzar();
			}
}

int gestorPadron::numeroTotalHabitantes(){
	int numTotal=0;
	int hom=0,muj=0;

	datos_Demograficos *d;
	pPadron->moverInicio();

	while(!pPadron->finLista()){
		pPadron->consultar(d);
		hom=d->gethom();
		muj=d->getmuj();
		numTotal=hom+muj+numTotal;
		pPadron->avanzar();
		}

	return numTotal;
}


void gestorPadron::mostrargestorPadron(){
	datos_Demograficos *d;
	pPadron->moverInicio();
	pPadron->consultar(d);
	d->show();
	while(!pPadron->enFin()){
		pPadron->avanzar();
		pPadron->consultar(d);
		d->show();
	}
}

void gestorPadron::algoritmo4MuestraPersonas(){
	int vectoredad[11];
	int i=0;
		while(i<11){
			vectoredad[i]=0;
			i++;
		}
	datos_Demograficos *dd;
    pPadron->moverInicio();
    	while(!pPadron->finLista()){
    	pPadron->consultar(dd);
    	dd->algoritmo4Edad(vectoredad);
    	pPadron->avanzar();
    	}

    	cout<<"Las edades de las personas son :"<<endl;
    		cout<<"De 0 a 9: "<<vectoredad[0]<<endl;
    		cout<<"De 10 a 19: "<<vectoredad[1]<<endl;
    		cout<<"De 20 a 29: "<<vectoredad[2]<<endl;
    		cout<<"De 30 a 39: "<<vectoredad[3]<<endl;
    		cout<<"De 40 a 49: "<<vectoredad[4]<<endl;
    		cout<<"De 50 a 59: "<<vectoredad[5]<<endl;
    		cout<<"De 60 a 69: "<<vectoredad[6]<<endl;
    		cout<<"De 70 a 79: "<<vectoredad[7]<<endl;
    		cout<<"De 80 a 89: "<<vectoredad[8]<<endl;
    		cout<<"De 90 a 99: "<<vectoredad[9]<<endl;
    		cout<<"De 100 a 109: "<<vectoredad[10]<<endl;

}

void gestorPadron::algoritmo10(ListaPI<LugarNacimiento*>*&LNAux,string provincia){
	datos_Demograficos *dd;
	pPadron->moverInicio();
	if(!pPadron->estaVacia()){
		while(!pPadron->finLista()){
			pPadron->consultar(dd);
			dd->algoritmo10LN(LNAux,provincia);
			pPadron->avanzar();
		}
	}
}



