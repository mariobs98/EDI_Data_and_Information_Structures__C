/*
 * gestorLugardeNacimiento.cpp
 *
 *  Created on: 9 abr. 2018
 *      Author: enrique
 */

#include "gestorLugardeNacimiento.h"

gestorLugardeNacimiento::gestorLugardeNacimiento() {
	LiN=new ListaPI<LugarNacimiento*>;
}

gestorLugardeNacimiento::gestorLugardeNacimiento(string text){
	LiN=new ListaPI<LugarNacimiento*>;
    LugarNacimiento *lugar;
	char delim = ';';
			vector<string> vText = splitStringToVector(text, delim);
			for (int i = 0; i < static_cast<int>(vText.size()); i++) {
				vector<string> vString = splitString(vText[i]);
				if ( vString.size()== 2)
                  lugar= new LugarNacimiento("", vString[0], atoi(vString[1].c_str()));
				else
					lugar= new LugarNacimiento(vString[0],vString[1],atoi(vString[2].c_str()));

				            LiN->moverFinal();
							LiN->avanzar();
							LiN->insertar(lugar);
					}
}

gestorLugardeNacimiento::~gestorLugardeNacimiento() {
	LugarNacimiento *l1;
   LiN->moverInicio();
   while(!LiN->estaVacia()){
	   LiN->consultar(l1);
	   delete l1;
	   LiN->borrar();//el borrar ya avanza al siguiente
   }
	delete LiN;
}

void gestorLugardeNacimiento::insertarLugarNacimiento(ListaPI<LugarNacimiento*>*&pLugNac){
	string cadenaVacia = "";
	LugarNacimiento *ln,*lnAux;
	int sumador = 0;
	bool enc=false;

	if(!LiN->estaVacia()){
		LiN->moverInicio();
		while(!LiN->finLista()){
			LiN->consultar(ln);
			if(ln->getpoblacion() == ""){
				LiN->avanzar();
			}else{
			LiN->avanzar();

			pLugNac->moverInicio();
			enc=false;
			while(!pLugNac->finLista() && !enc){
				pLugNac->consultar(lnAux);
				if(lnAux->getprovincia() == ln->getprovincia()){
					enc=true;
					sumador = lnAux->getpersonas() + ln->getpersonas();
					lnAux->setpersonas(sumador);
				}else{
					pLugNac->avanzar();
					}
				}
				if(enc==false){
					lnAux = new LugarNacimiento (ln->getpoblacion(),ln->getprovincia(),ln->getpersonas());
					pLugNac->insertar(lnAux);
				}
			}
		}
	}
}

void gestorLugardeNacimiento::algoritmo10provincias(ListaPI<LugarNacimiento*>*&LNAux, string provincia){
	LugarNacimiento *LN[3]; int personas[3]; bool insert=false; string poblacion[2];
	//persona[0]:personas del LN[0],persona[1]: personas del LN[1], persona[2]: calculos realizados de personas
	//poblacion[0]: poblacion del LN[0], poblacion[1]: poblacion del LN[1]
	if(!LiN->estaVacia()){
	LiN->moverInicio();
	while(!LiN->finLista()){
		LiN->consultar(LN[0]);
		if(LN[0]->getprovincia()==provincia){
			if(!LNAux->estaVacia()){
				LNAux->moverInicio();
				insert=false;
				poblacion[0]=LN[0]->getpoblacion();
				while(!LNAux->finLista()){
				LNAux->consultar(LN[1]);
				poblacion[1]=LN[1]->getpoblacion();
				if(poblacion[0]==poblacion[1]){
					insert=true;
					LNAux->borrar();
			     personas[0]=LN[0]->getpersonas(); personas[1]=LN[1]->getpersonas();
			     personas[2]=personas[0]+personas[1];
			     LN[2]= new LugarNacimiento(LN[0]->getpoblacion(),LN[0]->getprovincia(),personas[2]);
                 LNAux->insertar(LN[2]);

				}

				LNAux->avanzar();
				}
				if(insert==false){
					LNAux->insertar(LN[0]);
				}
			}
			else{//caso de vacia
				LNAux->insertar(LN[0]);
			}

		}
		LiN->avanzar();
	}

	}
}


void gestorLugardeNacimiento::obtenerdatosNacimientos(ListaPI<LugarNacimiento*>*&LNAux){
	LugarNacimiento *LN;

	if(!LiN->estaVacia()){
	LiN->moverInicio();
	LNAux->moverInicio();
	while(!LiN->finLista()){
		LiN->consultar(LN);
		LiN->avanzar();
		LNAux->insertar(LN);
		LNAux->avanzar();
		}

	}
}



void gestorLugardeNacimiento::MuestrapersonasProvincia(ListaPI<LugarNacimiento*>*&LNAux){
	LugarNacimiento *LN[3]; int personas[3]; bool insert=false;
	//persona[0]:personas del LN[0],persona[1]: personas del LN[1], persona[2]: calculos realizados de personas

	if(!LiN->estaVacia()){
	LiN->moverInicio();
	while(!LiN->finLista()){
		LiN->consultar(LN[0]);
		if(!LNAux->estaVacia()){
			LNAux->moverInicio();
			insert=false;
			while(!LNAux->finLista()){
				LNAux->consultar(LN[1]);
				if(LN[0]->getprovincia()==LN[1]->getprovincia()){
					LNAux->borrar();
					personas[0]=LN[0]->getpersonas();
					personas[1]=LN[1]->getpersonas();
					personas[2]=personas[0]+personas[1];
					LN[2]= new LugarNacimiento("",LN[0]->getprovincia(),personas[2]);
					LNAux->insertar(LN[2]);
					insert=true;
				}
				LNAux->avanzar();

			}
			if(insert==false){//caso de que dicho elemento no este en la lista auxiliar todavia
				LNAux->insertar(LN[0]);
			}
		}
		else{//caso de vacia
			LNAux->insertar(LN[0]);
		}
		LiN->avanzar();
	}
	}
}

void gestorLugardeNacimiento::mostrar(){
	LugarNacimiento *l;
	LiN->moverInicio();
		while(!LiN->enFin()){
			LiN->consultar(l);
			LiN->avanzar();
			l->show();
			}
}





