/*
 * GestorGeneral.cpp
 *
 *  Created on: 23 abr. 2018
 *      Author: mario
 */

#include "GestorGeneral.h"

using namespace std;

GestorGeneral::GestorGeneral() {
	this->gp = new gestorPadron();
	this->gb = new gestorBarrios();
	carga();

}

GestorGeneral::~GestorGeneral() {
	delete gp;
	delete gb;
}

void GestorGeneral::carga(){
	cargarBarrios();
	cargarDatosdemograficos();
	cargarViasYPadron();
}

void GestorGeneral::cargarBarrios(){
	gb->cargarBarrios();
}

void GestorGeneral::cargarDatosdemograficos(){
	gp->cargarDatos_Demograficos();
}

void GestorGeneral::cargarViasYPadron(){

	ifstream fent;
	string cad[6];
	Via *v;
	datos_Demograficos *dd;
	Barrio *b;

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

          gb->buscarBarrio(v->getnombreBarrio(),b);
          gp->buscarDatosDemografico(v->getcodigoVia(),dd);
          v->introducirDatosDemograficos(dd);
          b->introducirVia(v);
		  }
		}
	fent.close();
	}
}

void GestorGeneral::mostrarListaBarrios(){
	gb->mostrarBarrios();
}

void GestorGeneral::mostrarListaPadron(){
	gp->mostrargestorPadron();
}

void GestorGeneral::algoritmo_2(){
	string Barrio;
	cout<<endl;
	cout << "Introduce un Barrio: " << endl;
	cout<<endl;
	getline(cin, Barrio);
	gb->mostrarViasdeUnBarrio(Barrio);
	cout<<endl;
}

void GestorGeneral::algoritmo_3(){
	ListaPI<Via*>*auxv; auxv= new ListaPI<Via*>; int contador=0;  string nombreBarrioAux="";

	Via *v;

	gb->devolverVias(auxv);
	cout<<"Las vias que pertenecen a varios barrios son: "<<endl;
	if(!auxv->estaVacia()){
	auxv->moverInicio();
	while(!auxv->finLista()){
		contador=0;
		auxv->consultar(v);
		gb->compararBarriosalgt(contador,nombreBarrioAux,v);
        auxv->avanzar();
	}
	}
 cout<<"Estas son todas las vias."<<endl;
 auxv->~ListaPI();
	}

void GestorGeneral::algoritmo_4(){

	gp->algoritmo4MuestraPersonas();

}

void GestorGeneral::algoritmo_5(){

	ListaPI<Nacionalidad*>*pNacionalidades;
	pNacionalidades = new ListaPI<Nacionalidad*>;


	ListaPI<Nacionalidad*>*pNacionalidadesAux;
	pNacionalidadesAux = new ListaPI<Nacionalidad*>;

	Nacionalidad *n,*nac;

	gb->insertarNacionalidades(pNacionalidades);

	pNacionalidades->moverInicio();
	while(!pNacionalidades->finLista()){
		pNacionalidades->consultar(n);
		nac = new Nacionalidad (n->getPais(),n->getnumPersonas());
		pNacionalidades->borrar();
		insertarNacionalidadEnOrden(pNacionalidadesAux,nac);
	}
	pNacionalidadesAux->moverInicio();
	while(!pNacionalidadesAux->finLista()){
		pNacionalidadesAux->consultar(n);
		pNacionalidadesAux->avanzar();
		n->mostrar();
	}
	delete pNacionalidades;
	delete pNacionalidadesAux;
}

void GestorGeneral::insertarNacionalidadEnOrden(ListaPI<Nacionalidad*>*&pNacionalidades,Nacionalidad *n){
	bool enc=false;
	Nacionalidad *nAux;

	pNacionalidades->moverInicio();
	while(!pNacionalidades->finLista() && !enc){
		pNacionalidades->consultar(nAux);
		if(nAux->getnumPersonas()<n->getnumPersonas()){
			enc = true;
		}else{
			pNacionalidades->avanzar();
			}
		}
	pNacionalidades->insertar(n);
}


void GestorGeneral::algoritmo_6(){
	ListaPI<LugarNacimiento*>*pLugNac;
	pLugNac = new ListaPI<LugarNacimiento*>;

	ListaPI<LugarNacimiento*>*pLugNacAux;
	pLugNacAux = new ListaPI<LugarNacimiento*>;

	LugarNacimiento *ln,*lnAux;

	gb->insertarLugarNacimiento(pLugNac);

	pLugNac->moverInicio();
	while(!pLugNac->finLista()){
		pLugNac->consultar(ln);
		lnAux = new LugarNacimiento(ln->getpoblacion(),ln->getprovincia(),ln->getpersonas());
		pLugNac->borrar();
		insertarLugarNacimientoEnOrden(pLugNacAux,lnAux);
	}

	pLugNacAux->moverInicio();
	while(!pLugNacAux->finLista()){
		pLugNacAux->consultar(ln);
		pLugNacAux->avanzar();
		ln->mostrarAlg6();
	}
	delete pLugNac;
	delete pLugNacAux;
}

void GestorGeneral::insertarLugarNacimientoEnOrden(ListaPI<LugarNacimiento*>*&pLugNacAux,LugarNacimiento *ln){
	bool enc=false;
	LugarNacimiento *lnAux;

	pLugNacAux->moverInicio();
	while(!pLugNacAux->finLista() && !enc){
		pLugNacAux->consultar(lnAux);
		if(lnAux->getprovincia()>ln->getprovincia()){
			enc = true;
		}else{
			pLugNacAux->avanzar();
			}
		}
	pLugNacAux->insertar(ln);
}

void GestorGeneral::algoritmo_7(){
	int limInf=0,limSup=0,totalHabitantes=0;
	string nombreBarrio = "";
	cout<<endl;
	cout<<"Intruce el rango de edad(primero el limite inferior)"<<endl;
	cout<<"Edad entre: "<<endl;
	cin>>limInf;
	cout<<" Y "<<endl;
	cin>>limSup;
	gb->barrioMayorNumHabitantes(nombreBarrio,limInf,limSup,totalHabitantes);
	cout<<endl;
	cout<<"El Barrio con mayor numero de habitantes para ese rango de edad es: "<<nombreBarrio<<" con "<<totalHabitantes<<" habitantes."<<endl;

}

void GestorGeneral::algoritmo_8(){
	string nombreBarrio,estudios,cad,nivelEstudios,numPersonas2;
	int numPersonas;
	Estudios *e,*eAux;

	ifstream fEnt;
	ofstream fSal;

	ListaPI<Estudios*>*pEstudiosAux;
	pEstudiosAux = new ListaPI<Estudios*>;

	ListaPI<Estudios*>*pEstudiosAux2;
	pEstudiosAux2 = new ListaPI<Estudios*>;


	cout<<endl;
	cout<<"Intruce el Barrio para crear el fichero: "<<endl;
	getline(cin,nombreBarrio);

	gb->InsertarEstudios(pEstudiosAux,nombreBarrio);

	pEstudiosAux->moverInicio();
	while(!pEstudiosAux->finLista()){
		pEstudiosAux->consultar(e);

		eAux = new Estudios(e->getnivelEstudios(),e->getNumPersonas());
		pEstudiosAux->borrar();
		insertarEstudiosEnOrden(pEstudiosAux2,eAux);
	}

	cad="Estudios"+nombreBarrio+".txt";
	fSal.open(cad.c_str(),ios::out);
	if(fSal.is_open()){
	pEstudiosAux2->moverInicio();
		while(!pEstudiosAux2->finLista()){
			pEstudiosAux2->consultar(e);
			nivelEstudios=e->getnivelEstudios();
			numPersonas=e->getNumPersonas();
			estudios = nivelEstudios + " ";
			estudios.c_str();
			pEstudiosAux2->avanzar();
			fSal<<estudios<<numPersonas<<endl;
			}
		}else{
		cout<<"Error en la apertura del fichero"<<endl;
	}
		fSal.close();

//PARA MOSTRARLO POR CONSOLA
/*
	pEstudiosAux2->moverInicio();
	while(!pEstudiosAux2->finLista()){
		pEstudiosAux2->consultar(e);
		pEstudiosAux2->avanzar();
		e->mostrar();
	}
*/
	delete pEstudiosAux;
	delete pEstudiosAux2;
}

void GestorGeneral::insertarEstudiosEnOrden(ListaPI<Estudios*>*&pEstudiosAux,Estudios *e){
	bool enc=false;
	Estudios *eAux;

	pEstudiosAux->moverInicio();
	while(!pEstudiosAux->finLista() && !enc){
		pEstudiosAux->consultar(eAux);
		if(eAux->getNumPersonas()<e->getNumPersonas()){
			enc = true;
		}else{
			pEstudiosAux->avanzar();
			}
		}
	pEstudiosAux->insertar(e);
}

void GestorGeneral::algoritmo_9(){
	int hom = 0,muj = 0;
	string nombreBarriohom = "",nombreBarriomuj = "";
	gb->algoritmo_9hom(nombreBarriohom,hom);
	gb->algoritmo_9muj(nombreBarriomuj,muj);
	cout<<endl;
	cout<<"El Barrio con mayor numero de hombres es: "<<nombreBarriohom<<" -- Con "<<hom<<" hombres."<<endl;
	cout<<"El Barrio con mayor numero de mujeres es: "<<nombreBarriomuj<<" -- Con "<<muj<<" mujeres."<<endl;
	cout<<endl;
}

void GestorGeneral::algoritmo_10(){
	ListaPI<LugarNacimiento*>*LNAux; ofstream fsal; LugarNacimiento *LN;
	LNAux=new ListaPI<LugarNacimiento*>;
	string provincia;
	cout<<"Dime una provincia: "<<endl;
	cin>>provincia;
	gp->algoritmo10(LNAux, provincia);
	provincia+="_Personas(provincia).txt";
	fsal.open(provincia.c_str(),ios::trunc);
	LNAux->moverInicio();
	if(fsal.is_open()){
		while(!LNAux->finLista()){
		LNAux->consultar(LN);
		fsal<<"--Numero_de_personas:"<<LN->getpersonas()<< "    --Nombre_de_la_poblacion:"<<LN->getpoblacion()<<"       --Nombre_de_la_provincia:"<<LN->getprovincia()<<endl;
		LNAux->avanzar();
		cout<<"Linea_añadida"<<endl;
		}
		fsal.close();

	}
cout<<"Archivo_creado"<<endl;
   LNAux->~ListaPI();
}


void GestorGeneral::algoritmo_11(){
   string nombreVia="";   string nombreViaArbol;Via *vArbol;
   ListaPI<LugarNacimiento*>*LNAux; LNAux=new ListaPI<LugarNacimiento*>;
   ofstream fsal; LugarNacimiento *LN; Via *vaux;
   double t_start, t_end;
   cout<<"Dime una via: "<<endl;
   getline(cin,nombreVia);

   t_start = Time::getTime();
   gb->algoritmo11(nombreVia,vaux);
   t_end = Time::getTime();
   cout << "El tiempo que tarda en buscar en la lista es Time: " << t_end - t_start << "  " << endl;


   t_start = Time::getTime();
   gb->algoritmo11Arbol(nombreViaArbol,vArbol);
   t_end = Time::getTime();
   cout << "El tiempo que tarda en buscar en el arbol es Time: " << t_end - t_start << "  " << endl;

    vaux->algoritmo11(LNAux);


    nombreVia+="_LugarNacimiento.txt";
    fsal.open(nombreVia.c_str(),ios::trunc);
    LNAux->moverInicio();
    if(fsal.is_open()){
    		while(!LNAux->finLista()){
    		LNAux->consultar(LN);
    		fsal<<"--Numero_de_personas:"<<LN->getpersonas()<< "      --Nombre_de_la_poblacion:"<<LN->getpoblacion()<<"         --Nombre_de_la_provincia:"<<LN->getprovincia()<<endl;
    		LNAux->avanzar();
    		cout<<"Linea_añadida"<<endl;
    		}
    		fsal.close();

    	}
    cout<<"Archivo_creado"<<endl;
       LNAux->~ListaPI();


}


void GestorGeneral::algoritmo_12(){

	ListaPI<Via*>*pViaAux; pViaAux = new ListaPI<Via*>; Via *v; string nombreVia=""; string provincia="";
	Arbol<Via*, CompararPtrVias>  *ArbolAux; ArbolAux = new Arbol<Via*, CompararPtrVias> ();
	ListaPI<LugarNacimiento*>*LNAux; LNAux=new ListaPI<LugarNacimiento*>;
    cout<<"Dime por donde quieres que empiece "<<endl;
    cin>>nombreVia;
    cout<<"Ahora dime la provincia que quieres que te muestre"<<endl;
    cin>>provincia;
	LugarNacimiento *LN;
	double t_start, t_end;

	t_start = Time::getTime();
	gb->algoritmo12(nombreVia,pViaAux);
     t_end = Time::getTime();
	 cout << "El tiempo que tarda en buscar en la lista es Time: " << t_end - t_start << "  " << endl;

	 t_start = Time::getTime();
	 gb->algoritmo12Arbol(nombreVia,ArbolAux);
     t_end = Time::getTime();
	 cout << "El tiempo que tarda en buscar en el Arbol es Time: " << t_end - t_start << "  " << endl;

	if(!pViaAux->estaVacia()){
     pViaAux->moverInicio();
     while(!pViaAux->finLista()){
    	 pViaAux->consultar(v);
    	 v->algoritmo12(LNAux);
    	 pViaAux->avanzar();
     }
	}
	cout<<"Este es el listado: "<<endl;
	if(!LNAux->estaVacia()){
	LNAux->moverInicio();
	while(!LNAux->finLista()){
		LNAux->consultar(LN);
		if(LN->getprovincia()==provincia){
		cout<<"NOMBRE DE PROVINCIA:  "<< LN->getprovincia()<<"  NUMERO DE PERSONAS:   "<< LN->getpersonas()<<endl;
		}
		LNAux->avanzar();
	}
	}
	cout<<"LISTADO_COMPLETO"<<endl;
	pViaAux->~ListaPI();
	LNAux->~ListaPI();
	delete ArbolAux;
}

void GestorGeneral::algoritmoP_2(){
	string Barrio="Residencial Universidad";
	cout<<endl;
	gb->mostrarViasdeUnBarrio(Barrio);
	cout<<endl;
}
void GestorGeneral::algoritmoP_3(){
	ListaPI<Via*>*auxv; auxv= new ListaPI<Via*>; int contador=0;  string nombreBarrioAux="";

	Via *v;

	gb->devolverVias(auxv);
	cout<<"Las vias que pertenecen a varios barrios son: "<<endl;
	if(!auxv->estaVacia()){
	auxv->moverInicio();
	while(!auxv->finLista()){
		contador=0;
		auxv->consultar(v);
		gb->compararBarriosalgt(contador,nombreBarrioAux,v);
        auxv->avanzar();
	}
	}
 cout<<"Estas son todas las vias."<<endl;
 auxv->~ListaPI();
}
void GestorGeneral::algoritmoP_4(){
	gp->algoritmo4MuestraPersonas();
}
void GestorGeneral::algoritmoP_5(){
	ListaPI<Nacionalidad*>*pNacionalidades;
	pNacionalidades = new ListaPI<Nacionalidad*>;
	ListaPI<Nacionalidad*>*pNacionalidadesAux;
	pNacionalidadesAux = new ListaPI<Nacionalidad*>;

	Nacionalidad *n,*nac;

	gb->insertarNacionalidades(pNacionalidades);

	pNacionalidades->moverInicio();
	while(!pNacionalidades->finLista()){
		pNacionalidades->consultar(n);
		nac = new Nacionalidad (n->getPais(),n->getnumPersonas());
		pNacionalidades->borrar();
		insertarNacionalidadEnOrden(pNacionalidadesAux,nac);
	}
	pNacionalidadesAux->moverInicio();
	while(!pNacionalidadesAux->finLista()){
		pNacionalidadesAux->consultar(n);
		pNacionalidadesAux->avanzar();
		n->mostrar();
	}
	delete pNacionalidades;
	delete pNacionalidadesAux;
}
void GestorGeneral::algoritmoP_6(){
	ListaPI<LugarNacimiento*>*pLugNac;
	pLugNac = new ListaPI<LugarNacimiento*>;

	ListaPI<LugarNacimiento*>*pLugNacAux;
	pLugNacAux = new ListaPI<LugarNacimiento*>;

	LugarNacimiento *ln,*lnAux;

	gb->insertarLugarNacimiento(pLugNac);

	pLugNac->moverInicio();
	while(!pLugNac->finLista()){
		pLugNac->consultar(ln);
		lnAux = new LugarNacimiento(ln->getpoblacion(),ln->getprovincia(),ln->getpersonas());
		pLugNac->borrar();
		insertarLugarNacimientoEnOrden(pLugNacAux,lnAux);
	}

	pLugNacAux->moverInicio();
	while(!pLugNacAux->finLista()){
		pLugNacAux->consultar(ln);
		pLugNacAux->avanzar();
		ln->mostrarAlg6();
	}
	delete pLugNac;
	delete pLugNacAux;
}
void GestorGeneral::algoritmoP_7(){
	int limInf=50,limSup=60,totalHabitantes=0;
	string nombreBarrio = "";
	cout<<endl;
	gb->barrioMayorNumHabitantes(nombreBarrio,limInf,limSup,totalHabitantes);
	cout<<endl;
	cout<<"El Barrio con mayor numero de habitantes para el rango de edad 50-60 es: "<<nombreBarrio<<" con "<<totalHabitantes<<" habitantes."<<endl;
}
void GestorGeneral::algoritmoP_8(){
	string nombreBarrio="Residencial Universidad",estudios,cad,nivelEstudios,numPersonas2;
	int numPersonas;
	Estudios *e,*eAux;

	ifstream fEnt;
	ofstream fSal;

	ListaPI<Estudios*>*pEstudiosAux;
	pEstudiosAux = new ListaPI<Estudios*>;

	ListaPI<Estudios*>*pEstudiosAux2;
	pEstudiosAux2 = new ListaPI<Estudios*>;

	gb->InsertarEstudios(pEstudiosAux,nombreBarrio);

	pEstudiosAux->moverInicio();
	while(!pEstudiosAux->finLista()){
		pEstudiosAux->consultar(e);

		eAux = new Estudios(e->getnivelEstudios(),e->getNumPersonas());
		pEstudiosAux->borrar();
		insertarEstudiosEnOrden(pEstudiosAux2,eAux);
	}

	cad="EstudiosPRUEBA"+nombreBarrio+".txt";
	fSal.open(cad.c_str(),ios::out);
	if(fSal.is_open()){
	pEstudiosAux2->moverInicio();
		while(!pEstudiosAux2->finLista()){
			pEstudiosAux2->consultar(e);
			nivelEstudios=e->getnivelEstudios();
			numPersonas=e->getNumPersonas();
			estudios = nivelEstudios + " ";
			estudios.c_str();
			pEstudiosAux2->avanzar();
			fSal<<estudios<<numPersonas<<endl;
			}
		}else{
		cout<<"Error en la apertura del fichero"<<endl;
	}
		fSal.close();
	delete pEstudiosAux;
	delete pEstudiosAux2;
}
void GestorGeneral::algoritmoP_9(){
	int hom = 0,muj = 0;
	string nombreBarriohom = "",nombreBarriomuj = "";
	gb->algoritmo_9hom(nombreBarriohom,hom);
	gb->algoritmo_9muj(nombreBarriomuj,muj);
	cout<<endl;
	cout<<"El Barrio con mayor numero de hombres es: "<<nombreBarriohom<<" -- Con "<<hom<<" hombres."<<endl;
	cout<<"El Barrio con mayor numero de mujeres es: "<<nombreBarriomuj<<" -- Con "<<muj<<" mujeres."<<endl;
	cout<<endl;
}
void GestorGeneral::algoritmoP_10(){
	ListaPI<LugarNacimiento*>*LNAux; ofstream fsal; LugarNacimiento *LN;
	LNAux=new ListaPI<LugarNacimiento*>;
	string provincia="Caceres";
	gp->algoritmo10(LNAux, provincia);
	provincia+="_Personas(provincia)PRUEBAS.txt";
	fsal.open(provincia.c_str(),ios::trunc);
	LNAux->moverInicio();
	if(fsal.is_open()){
		while(!LNAux->finLista()){
		LNAux->consultar(LN);
		fsal<<"--Numero_de_personas:"<<LN->getpersonas()<< "    --Nombre_de_la_poblacion:"<<LN->getpoblacion()<<"       --Nombre_de_la_provincia:"<<LN->getprovincia()<<endl;
		LNAux->avanzar();
		}
		fsal.close();

	}
cout<<"Archivo_creado"<<endl;
   LNAux->~ListaPI();
}
void GestorGeneral::algoritmoP_11(){
	   string nombreVia="Antonio Hernandez Gil"; ListaPI<LugarNacimiento*>*LNAux; LNAux=new ListaPI<LugarNacimiento*>;
	   ofstream fsal; LugarNacimiento *LN; Via *vaux;

	   gb->algoritmo11(nombreVia,vaux);
	    vaux->algoritmo11(LNAux);


	    nombreVia+="_LugarNacimientoPRUEBAS.txt";
	    fsal.open(nombreVia.c_str(),ios::trunc);
	    LNAux->moverInicio();
	    if(fsal.is_open()){
	    		while(!LNAux->finLista()){
	    		LNAux->consultar(LN);
	    		fsal<<"--Numero_de_personas:"<<LN->getpersonas()<< "      --Nombre_de_la_poblacion:"<<LN->getpoblacion()<<"         --Nombre_de_la_provincia:"<<LN->getprovincia()<<endl;
	    		LNAux->avanzar();
	    		}
	    		fsal.close();
	    	}
	    cout<<"Archivo_creado"<<endl;
	       LNAux->~ListaPI();
}
void GestorGeneral::algoritmoP_12(){

	ListaPI<Via*>*pViaAux; pViaAux = new ListaPI<Via*>; Via *v; string nombreVia="Antonio"; string provincia="Caceres";

	ListaPI<LugarNacimiento*>*LNAux; LNAux=new ListaPI<LugarNacimiento*>;

	LugarNacimiento *LN;
	gb->algoritmo12(nombreVia,pViaAux);
	if(!pViaAux->estaVacia()){
     pViaAux->moverInicio();
     while(!pViaAux->finLista()){
    	 pViaAux->consultar(v);
    	 v->algoritmo12(LNAux);
    	 pViaAux->avanzar();
     }
	}
	cout<<"Este es el listado: "<<endl;
	if(!LNAux->estaVacia()){
	LNAux->moverInicio();
	while(!LNAux->finLista()){
		LNAux->consultar(LN);
		if(LN->getprovincia()==provincia){
		cout<<"NOMBRE DE PROVINCIA:  "<< LN->getprovincia()<<"  NUMERO DE PERSONAS:   "<< LN->getpersonas()<<endl;
		}
		LNAux->avanzar();
	}
	}
	cout<<"LISTADO_COMPLETO"<<endl;
	pViaAux->~ListaPI();
	LNAux->~ListaPI();
}





