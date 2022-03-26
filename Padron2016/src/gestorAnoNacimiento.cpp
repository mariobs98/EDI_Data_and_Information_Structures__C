/*
 * gestorAnoNacimiento.cpp
 *
 *  Created on: 9 may. 2018
 *      Author: mario
 */

#include "gestorAnoNacimiento.h"

using namespace std;

gestorAnoNacimiento::gestorAnoNacimiento() {
	pAnoNacim=new ListaPI<AnoNacimiento*>;
}

gestorAnoNacimiento::gestorAnoNacimiento(string anonacim){
	pAnoNacim=new ListaPI<AnoNacimiento*>;
	AnoNacimiento *an;
	char delim = ';';
		vector<string> vText = splitStringToVector(anonacim, delim);
		for (int i = 0; i < static_cast<int>(vText.size()); i++) {
			vector<string> vString = splitString(vText[i]);

			an = new AnoNacimiento(atoi(vString[0].c_str()),atoi(vString[1].c_str()));

			pAnoNacim->moverFinal();
			pAnoNacim->avanzar();
			pAnoNacim->insertar(an);
		}
}

gestorAnoNacimiento::~gestorAnoNacimiento() {
	AnoNacimiento *an;
	   pAnoNacim->moverInicio();
	   while(!pAnoNacim->estaVacia()){
		   pAnoNacim->consultar(an);
		   delete an;
		   pAnoNacim->borrar();//el borrar ya avanza al siguiente
	   }
		delete pAnoNacim;
}

void gestorAnoNacimiento::algoritmo4Edad(int (&v)[11]){
     AnoNacimiento *an; int resultsAnos[3];
     pAnoNacim->moverInicio();
     while(!pAnoNacim->finLista()){
    	 pAnoNacim->consultar(an);
    	 resultsAnos[0]=an->getano();
    	 resultsAnos[1]=2018-resultsAnos[0];
    	 resultsAnos[2]=resultsAnos[1]/10;
    	 v[resultsAnos[2]]=v[resultsAnos[2]]+(an->getnumPersonas());
    	 pAnoNacim->avanzar();
     }
}

void gestorAnoNacimiento::getTotalHabitantesRangoEdadDado(int &limInf,int &limSup,int &Habitantes){
	AnoNacimiento *an;
	Habitantes= 0;
	int AnoNacim=0;
	int comprobar=0;
	pAnoNacim->moverInicio();
	while(!pAnoNacim->finLista()){
		pAnoNacim->consultar(an);
		pAnoNacim->avanzar();
		AnoNacim = an->getano();
		comprobar = 2018-AnoNacim;
		if(comprobar>=limInf && comprobar<=limSup){
			Habitantes = an->getnumPersonas();
		}
	}
}

void gestorAnoNacimiento::mostrar(){
	AnoNacimiento *an;
		pAnoNacim->moverInicio();
			while(!pAnoNacim->enFin()){
				pAnoNacim->consultar(an);
				pAnoNacim->avanzar();
				an->mostrar();
				}
}


