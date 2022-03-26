/*
 * gestorBarrios.cpp
 *
 *  Created on: 12 mar. 2018
 *      Author: mario
 */

#include "gestorBarrios.h"

gestorBarrios::gestorBarrios() {
	pBarrio = new ListaPI<Barrio*>;
}

gestorBarrios::~gestorBarrios() {
	Barrio *b;
	pBarrio->moverInicio();
	while(!pBarrio->enFin()){
		pBarrio->consultar(b);
		delete b;
		pBarrio->borrar();
	}
}

void gestorBarrios::cargarBarrios(){
	ifstream fEnt;
	string Cad[2];
	Barrio *b;
	fEnt.open("Barrio.csv");
	if(fEnt.is_open()){
		getline(fEnt,Cad[0]);
		while(!fEnt.eof()){
		getline(fEnt,Cad[0],'#');
		if(!fEnt.eof()){
		getline(fEnt,Cad[1]);
		b=new Barrio(Cad[0],Cad[1]);
		pBarrio->insertar(b);
		pBarrio->avanzar();
		}
		}
		fEnt.close();
	}
}

void gestorBarrios::mostrarBarrios(){
	Barrio *b;
	pBarrio->moverInicio();
	pBarrio->consultar(b);
	b->mostrar();
	while(!pBarrio->enFin()){
		pBarrio->avanzar();
		pBarrio->consultar(b);
		b->mostrar();
	}
}

void gestorBarrios::devolverVias(ListaPI<Via*>*&pViaAux){
	Barrio *b;
	pBarrio->moverInicio();
	if(!pBarrio->estaVacia()){

		while(!pBarrio->finLista()){
			pBarrio->consultar(b);
			b->devolverVias(pViaAux);
			pBarrio->avanzar();
		}
	}
}

void gestorBarrios::mostrarViasdeUnBarrio(string nombreBarrio){
	Barrio *b;
	bool enc=false;
	pBarrio->moverInicio();
	while(!pBarrio->finLista() && !enc){
		pBarrio->consultar(b);
		if(b->getnombreBarrio() == nombreBarrio){
			enc=true;
			b->mostrarViasdeBarrio();
		}
		pBarrio->avanzar();
	}
}

void gestorBarrios::algoritmo3(ListaPI<Via*>*&auxv){

	Barrio *b;
	while(!pBarrio->finLista()){
		pBarrio->moverInicio();
		pBarrio->consultar(b);
		b->algoritmo3(auxv);
		pBarrio->avanzar();

	}
}


void gestorBarrios::compararBarriosalgt(int &contador,string nombreBarrioAux,Via *v){
	Barrio *b; bool enc=false;
	pBarrio->moverInicio();
	while(!pBarrio->finLista()){
		enc=false;
		pBarrio->consultar(b);
		enc=b->buscarViaRepe(v);
		if(enc==true){
			if(contador==0){
				nombreBarrioAux=b->getnombreBarrio();
			}


			if(contador==1){
				cout<<"Para la via: "<<v->getnombreVia()<<"  pertenece a los barrios:  "<<endl;
            cout<<nombreBarrioAux<<endl;
            cout<<b->getnombreBarrio()<<endl;

			}
			if(contador>1){
				cout<<b->getnombreBarrio()<<endl;
			}

			contador++;





		}

		pBarrio->avanzar();
	}
}

void gestorBarrios::buscarBarrio(string nombreBarrio,Barrio *&b){
	Barrio *bAux;
		bool enc=false;
		pBarrio->moverInicio();
		while(!pBarrio->finLista() && !enc){
			pBarrio->consultar(bAux);
			if(bAux->getnombreBarrio() == nombreBarrio){
				enc=true;
				b = bAux;
			}
			pBarrio->avanzar();
		}
}

void gestorBarrios::insertarNacionalidades(ListaPI<Nacionalidad*>*&pNacionalidades){
	Barrio *b;
	if(!pBarrio->estaVacia()){
		pBarrio->moverInicio();
		while(!pBarrio->finLista()){
			pBarrio->consultar(b);
			pBarrio->avanzar();
			b->insertarNacionalidades(pNacionalidades);
		}
	}
}

void gestorBarrios::insertarLugarNacimiento(ListaPI<LugarNacimiento*>*&pLugNac){
	Barrio *b;
	if(!pBarrio->estaVacia()){
		pBarrio->moverInicio();
		while(!pBarrio->finLista()){
			pBarrio->consultar(b);
			pBarrio->avanzar();
			b->insertarLugarNacimiento(pLugNac);
		}
	}
}

void gestorBarrios::barrioMayorNumHabitantes(string &nombreBarrio,int &limInf,int &limSup,int &totalHabitantes){
	Barrio *b;
	int Habitantes=0;
	if(!pBarrio->estaVacia()){
		pBarrio->moverInicio();
		pBarrio->consultar(b);
		nombreBarrio = b->getnombreBarrio();
		b->getTotalHabitantesRangoEdadDado(limInf,limSup,totalHabitantes);
		while(!pBarrio->finLista()){
			pBarrio->avanzar();
			pBarrio->consultar(b);
			b->getTotalHabitantesRangoEdadDado(limInf,limSup,Habitantes);
			if(Habitantes>totalHabitantes){
				nombreBarrio = b->getnombreBarrio();
				totalHabitantes = Habitantes;
			}

		}
	}
}

void gestorBarrios::InsertarEstudios(ListaPI<Estudios*>*&pEstudiosAux,string nombreBarrio){
	Barrio *b;
	bool enc=false;
	pBarrio->moverInicio();
	while(!pBarrio->finLista() && !enc){
		pBarrio->consultar(b);
		if(b->getnombreBarrio() == nombreBarrio){
			enc=true;
			b->InsertarEstudios(pEstudiosAux);
		}
		pBarrio->avanzar();
	}
}


void gestorBarrios::algoritmo_9hom(string &nombreBarriohom,int &hom){
	Barrio *b;
	int homaux;
	if(!pBarrio->estaVacia()){
	pBarrio->moverInicio();
	pBarrio->consultar(b);
	nombreBarriohom = b->getnombreBarrio();
	b->getTotalHombres(hom);
	while(!pBarrio->finLista()){
		pBarrio->consultar(b);
		b->getTotalHombres(homaux);
		pBarrio->avanzar();
		if(homaux>hom){
			nombreBarriohom = b->getnombreBarrio();
			hom = homaux;
		}
		}
	}
}

void gestorBarrios::algoritmo_9muj(string &nombreBarriomuj,int &muj){
	Barrio *b;
	int mujaux;
	if(!pBarrio->estaVacia()){
	pBarrio->moverInicio();
	pBarrio->consultar(b);
	nombreBarriomuj = b->getnombreBarrio();
	b->getTotalMujeres(muj);
	while(!pBarrio->finLista()){
		pBarrio->consultar(b);
		b->getTotalMujeres(mujaux);
		pBarrio->avanzar();
		if(mujaux>muj){
			nombreBarriomuj = b->getnombreBarrio();
			muj = mujaux;
		}
		}
	}
}

void gestorBarrios::algoritmo11(string &nombreVia,Via *&vaux){
     Barrio *b;

     if(!pBarrio->estaVacia()){
    	 pBarrio->moverInicio();
    	 while(!pBarrio->finLista()){
    		 pBarrio->consultar(b);
    		 b->algoritmo11( nombreVia, vaux);
    		 pBarrio->avanzar();
    	 }
     }
}

void gestorBarrios::algoritmo11Arbol(string &nombreViaArbol,Via *&vArbol){
    Barrio *b;

    if(!pBarrio->estaVacia()){
   	 pBarrio->moverInicio();
   	 while(!pBarrio->finLista()){
   		 pBarrio->consultar(b);
   		 b->algoritmo11Arbol( nombreViaArbol, vArbol);
   		 pBarrio->avanzar();
   	 }
    }
}

void gestorBarrios::algoritmo12(string nombreVia,ListaPI<Via*>*&pViaAux){
	Barrio *b;
          if(!pBarrio->estaVacia()){
	    	 pBarrio->moverInicio();
	    	 while(!pBarrio->finLista()){
	    		 pBarrio->consultar(b);
	    		 b->algoritmo12( nombreVia, pViaAux);
	    		 pBarrio->avanzar();
	    	 }
	     }
}

void gestorBarrios::algoritmo12Arbol(string nombreVia,Arbol<Via*, CompararPtrVias>  *&ArbolAux ){
	Barrio *b;
          if(!pBarrio->estaVacia()){
	    	 pBarrio->moverInicio();
	    	 while(!pBarrio->finLista()){
	    		 pBarrio->consultar(b);
	    		 b->algoritmo12Arbol( nombreVia,ArbolAux);
	    		 pBarrio->avanzar();
	    	 }
	     }
}

void gestorBarrios::mostrarvias(ListaPI<Barrio*>*barrios, string nombreBarrio,bool enc){
	Barrio *barrio;
	barrios->consultar(barrio);

	if(!pBarrio->enFin()&&!enc){
		if((barrio->getnombreBarrio())==nombreBarrio){
			barrio->mostrarViasdeBarrio();
			enc=true;
		}
		else{
			barrios->avanzar();
			mostrarvias(barrios,nombreBarrio,enc);
		}
	}
}

void gestorBarrios::mostrarviaspublico(string nombreBarrio,bool enc){
	pBarrio->moverInicio();
	this->mostrarvias(this->pBarrio,nombreBarrio,enc);
}




