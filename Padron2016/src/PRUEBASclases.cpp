/*
 * PRUEBASclases.cpp
 *
 *  Created on: 26 may. 2018
 *      Author: enrique
 */

#include "PRUEBASclases.h"


void pruebaconstructorvacioBarrio(){
	cout<<"SE ESTA REALIZANDO LA PRUEBA DE CONSTRUCTOR VACIO DE BARRIO"<<endl;
	Barrio *b;
	b= new Barrio();
	string cad[2];
	cad[0]=b->getnombreBarrio(); cad[1]=b->getnombreDistrito();

	if(cad[0]==""){
		if(cad[1]==""){
			cout<<"SE HA EJECUTADO CORRECTAMENTE LA PRUEBA DE CONSTRUCTOR VACIO DE BARRIO"<<endl;
		}
		else{
			cout<<"FALLO EN DISTRITO_VACIO(BARRIO)"<<endl;
		}
	}
	else{
		cout<<"FALLO EN BARRIO_VACIO(BARRIO)"<<endl;
	}
	delete b;
	cout<<"SE HA REALIZADO LA PRUEBA DE CONSTRUCTOR VACIO DE BARRIO"<<endl;
}


void pruebaconstructorparametrizadoBarrio(){
	cout<<"SE ESTA REALIZANDO LA PRUEBA DE CONSTRUCTOR PARAMETRIZADO DE BARRIO"<<endl;
	Barrio *b;
	b= new Barrio("Canovas","Centro");
	string cad[2];
	cad[0]=b->getnombreBarrio(); cad[1]=b->getnombreDistrito();

	if(cad[0]=="Canovas"){
		if(cad[1]=="Centro"){
			cout<<"SE HA EJECUTADO CORRECTAMENTE LA PRUEBA DE CONSTRUCTOR PARAMETRIZADO DE BARRIO"<<endl;
		}
		else{
			cout<<"FALLO EN DISTRITO_PARAMETRIZADO(BARRIO)"<<endl;
		}
	}
	else{
		cout<<"FALLO EN BARRIO_PARAMETRIZADO(BARRIO)"<<endl;
	}
	delete b;
	cout<<"SE HA REALIZADO LA PRUEBA DE CONSTRUCTOR PARAMETRIZADO DE BARRIO"<<endl;
}


void pruebasetnameBarrio(){
	cout<<"SE ESTA REALIZANDO LA PRUEBA DE SETNAME DE BARRIO"<<endl;
	Barrio *b;
	b= new Barrio;
	b->setnombreBarrio("Mejostilla");
	b->setnombreDistrito("Centro");
	string cad[2];
	cad[0]=b->getnombreBarrio(); cad[1]=b->getnombreDistrito();

	if(cad[0]=="Mejostilla"){
		if(cad[1]=="Centro"){
			cout<<"SE HA EJECUTADO CORRECTAMENTE LA PRUEBA DE SETNAME DE BARRIO"<<endl;
		}
		else{
			cout<<"FALLO EN DISTRITO_SETNAME(BARRIO)"<<endl;
		}
	}
	else{
		cout<<"FALLO EN BARRIO_SETNAME(BARRIO)"<<endl;
	}
	delete b;
	cout<<"SE HA REALIZADO LA PRUEBA DE SETNAME DE BARRIO"<<endl;
}


void pruebagetnameBarrio(){
	cout<<"SE ESTA REALIZANDO LA PRUEBA DE SETNAME DE BARRIO"<<endl;
	Barrio *b;
	b= new Barrio;
	b->setnombreBarrio("Argentina");
	b->setnombreDistrito("Centro");

	if(b->getnombreBarrio()=="Argentina"){
		if(b->getnombreDistrito()=="Centro"){
			cout<<"SE HA EJECUTADO CORRECTAMENTE LA PRUEBA DE GETNAME DE BARRIO"<<endl;
		}
		else{
			cout<<"FALLO EN DISTRITO_GETNAME(BARRIO)"<<endl;
		}
	}
	else{
		cout<<"FALLO EN BARRIO_GETNAME(BARRIO)"<<endl;
	}
	delete b;
	cout<<"SE HA REALIZADO LA PRUEBA DE GETNAME DE BARRIO"<<endl;
}


void pruebaconstructorvacioVia(){
	cout<<"SE ESTA REALIZANDO LA PRUEBA DE CONSTRUCTOR VACIO DE VIA"<<endl;
	Via *v;
	v= new Via();
	string cad[3];
	float longitudVia=0;
	int codigoVia=0;
	cad[0]=v->getnombreBarrio(); cad[1]=v->getnombreVia(); longitudVia=v->getlongitudVia(); cad[2]=v->gettipoVia(); codigoVia=v->getcodigoVia();

	if(cad[0]==""){
		if(cad[1]==""){
			if(longitudVia==0){
				if(cad[2]==""){
					if(codigoVia==0){
						cout<<"SE HA EJECUTADO CORRECTAMENTE LA PRUEBA DE CONSTRUCTOR VACIO DE VIA"<<endl;
					}
					else{
						cout<<"FALLO EN CODIGO_VACIO(VIA)"<<endl;
					}
				}
				else{
					cout<<"FALLO EN TIPO_VACIO(VIA)"<<endl;
				}
			}
			else{
				cout<<"FALLO EN LONGITUD_VACIO(VIA)"<<endl;
			}
		}
		else{
			cout<<"FALLO EN NOMBREVIA_VACIO(VIA)"<<endl;
		}
	}
	else{
		cout<<"FALLO EN NOMBREBARRIO_VACIO(VIA)"<<endl;
	}
	delete v;
	cout<<"SE HA REALIZADO LA PRUEBA DE CONSTRUCTOR VACIO DE VIA"<<endl;
}


void pruebaconstructorparametrizadoVia(){
	cout<<"SE ESTA REALIZANDO LA PRUEBA DE CONSTRUCTOR PARAMETRIZADO DE VIA"<<endl;
	Via *v;
	v= new Via("Canovas","De España",1100.5,"Avda",3048);
	string cad[3];
	float longitudVia=0;
	int codigoVia=0;
	cad[0]=v->getnombreBarrio(); cad[1]=v->getnombreVia();  cad[2]=v->gettipoVia(); codigoVia=v->getcodigoVia();
	longitudVia=v->getlongitudVia();
	cout<<longitudVia<<endl;
	if(cad[0]=="Canovas"){
		if(cad[1]=="De España"){
			if(longitudVia==1100.5){
				if(cad[2]=="Avda"){
					if(codigoVia==3048){
						cout<<"SE HA EJECUTADO CORRECTAMENTE LA PRUEBA DE CONSTRUCTOR PARAMETRIZADO DE VIA"<<endl;
					}
					else{
						cout<<"FALLO EN CODIGO_PARAMETRIZADO(VIA)"<<endl;
					}
				}else{
					cout<<"FALLO EN TIPO_PARAMETRIZADO(VIA)"<<endl;
				}
			}else{
				cout<<"FALLO EN LONGITUD_PARAMETRIZADO(VIA)"<<endl;
			}
		}else{
			cout<<"FALLO EN NOMBREVIA_PARAMETRIZADO(VIA)"<<endl;
		}
	}else{
		cout<<"FALLO EN NOMBREBARRIO_PARAMETRIZADO(VIA)"<<endl;
	}
	delete v;
	cout<<"SE HA REALIZADO LA PRUEBA DE CONSTRUCTOR PARAMETRIZADO DE VIA"<<endl;
}


void pruebasetnameVia(){
	cout<<"SE ESTA REALIZANDO LA PRUEBA DE SETNAME DE VIA"<<endl;
	Via *v;
	v= new Via();
	v->setnombreBarrio("Huertas");v->setnombreVia("De La Universidad");v->setlongitudVia(2606);v->settipoVia("Avda");v->setcodigoVia(3425);
	string cad[3];
	float longitudVia=0;
	int codigoVia=0;
	cad[0]=v->getnombreBarrio(); cad[1]=v->getnombreVia();  cad[2]=v->gettipoVia(); codigoVia=v->getcodigoVia();
	longitudVia=v->getlongitudVia();
	if(cad[0]=="Huertas"){
		if(cad[1]=="De La Universidad"){
			if(longitudVia==2606){
				if(cad[2]=="Avda"){
					if(codigoVia==3425){
						cout<<"SE HA EJECUTADO CORRECTAMENTE LA PRUEBA DE SETNAME VIA"<<endl;
					}
					else{
						cout<<"FALLO EN CODIGO_SETNAME(VIA)"<<endl;
					}
				}else{
					cout<<"FALLO EN TIPO_SETNAME(VIA)"<<endl;
				}
			}else{
				cout<<"FALLO EN LONGITUD_SETNAME(VIA)"<<endl;
			}
		}else{
			cout<<"FALLO EN NOMBREVIA_SETNAME(VIA)"<<endl;
		}
	}else{
		cout<<"FALLO EN NOMBREBARRIO_SETNAME(VIA)"<<endl;
	}
	delete v;
	cout<<"SE HA REALIZADO LA PRUEBA DE SETNAME DE VIA"<<endl;
}


void pruebagetnameVia(){
	cout<<"SE ESTA REALIZANDO LA PRUEBA DE GETNAME DE VIA"<<endl;
	Via *v;
	v= new Via();
	v->setnombreBarrio("Huertas");v->setnombreVia("De La Universidad"); v->settipoVia("Avda");v->setcodigoVia(3425);
	v->setlongitudVia(2606);

	if(v->getnombreBarrio()=="Huertas"){
		if(v->getnombreVia()=="De La Universidad"){
			if(v->getlongitudVia()==2606){
				if(v->gettipoVia()=="Avda"){
					if(v->getcodigoVia()==3425){
						cout<<"SE HA EJECUTADO CORRECTAMENTE LA PRUEBA DE GETNAME VIA"<<endl;
					}
					else{
						cout<<"FALLO EN CODIGO_GETNAME(VIA)"<<endl;
					}
				}else{
					cout<<"FALLO EN TIPO_GETNAME(VIA)"<<endl;
				}
			}else{
				cout<<"FALLO EN LONGITUD_GETNAME(VIA)"<<endl;
			}
		}else{
			cout<<"FALLO EN NOMBREVIA_GETNAME(VIA)"<<endl;
		}
	}else{
		cout<<"FALLO EN NOMBREBARRIO_GETNAME(VIA)"<<endl;
	}
	delete v;
	cout<<"SE HA REALIZADO LA PRUEBA DE GETNAME DE VIA"<<endl;
}


void pruebaconstructorvacioDatosdemograficos(){
	cout<<"SE ESTA REALIZANDO LA PRUEBA DE CONSTRUCTOR VACIO DE DATOS_DEMOGRAFICOS"<<endl;
	datos_Demograficos *dd;
	dd= new datos_Demograficos();
	string cad[4];
    int datos[4];
	cad[0]=dd->getnivest(); cad[1]=dd->getlugnac(); cad[2]=dd->getnacional(); cad[3]=dd->getanonacim(); datos[0]=dd->getCodigovia(); datos[1]=dd->getanocr(); datos[2]=dd->gethom(); datos[3]=dd->getmuj();

	if(cad[0]==""){
		if(cad[1]==""){
			if(cad[2]==""){
				if(cad[3]==""){
					if(datos[0]==0){
						if(datos[1]==0){
							if(datos[2]==0){
								if(datos[3]==0){
									cout<<"SE HA EJECUTADO CORRECTAMENTE LA PRUEBA DE CONSTRUCTOR VACIO DE DATOS_DEMOGRAFICOS"<<endl;
								}
								else{
									cout<<"FALLO EN MUJER_VACIO(DATOS_DEMOGRAFICOS)"<<endl;
								}

							}else{
								cout<<"FALLO EN HOMBRE_VACIO(DATOS_DEMOGRAFICOS)"<<endl;
							}

						}else{
							cout<<"FALLO EN AÑO_CREACION_VACIO(DATOS_DEMOGRAFICOS)"<<endl;
						}

					}else{
						cout<<"FALLO EN CODIGO_VACIO(DATOS_DEMOGRAFICOS)"<<endl;
					}

			}else{
				cout<<"FALLO EN AÑO_NACIMIENTO_VACIO(DATOS_DEMOGRAFICOS)"<<endl;
			}

			}	else{
				cout<<"FALLO EN NACIONALIDAD_VACIO(DATOS_DEMOGRAFICOS)"<<endl;
			}



		}
		else{
			cout<<"FALLO EN LUGAR_NACIMIENTO_VACIO(DATOS_DEMOGRAFICOS)"<<endl;
		}
	}
	else{
		cout<<"FALLO EN NIVEL_ESTUDIOS_VACIO(DATOS_DEMOGRAFICOS)"<<endl;
	}


	delete dd;
	cout<<"SE HA REALIZADO LA PRUEBA DE CONSTRUCTOR VACIO DE DATOS_DEMOGRAFICOS"<<endl;
}
void pruebaconstructorparametrizadoDatosdemograficos(){
	cout<<"SE ESTA REALIZANDO LA PRUEBA DE CONSTRUCTOR PARAMETRIZADO DE DATOS_DEMOGRAFICOS"<<endl;
	datos_Demograficos *dd;
	dd= new datos_Demograficos(3394,"1947","Valencia de Alcantara(Caceres)","Oficialia Industrial",43,48,"España",2016);
	string cad[4];
    int datos[4];
	cad[0]=dd->getnivest(); cad[1]=dd->getlugnac(); cad[2]=dd->getnacional(); cad[3]=dd->getanonacim(); datos[0]=dd->getCodigovia(); datos[1]=dd->getanocr(); datos[2]=dd->gethom(); datos[3]=dd->getmuj();

	if(cad[0]=="Oficialia Industrial"){
		if(cad[1]=="Valencia de Alcantara(Caceres)"){
			if(cad[2]=="España"){
				if(cad[3]=="1947"){
					if(datos[0]==3394){
						if(datos[1]==2016){
							if(datos[2]==43){
								if(datos[3]==48){
									cout<<"SE HA EJECUTADO CORRECTAMENTE LA PRUEBA DE CONSTRUCTOR PARAMETRIZADO DE DATOS_DEMOGRAFICOS"<<endl;
								}
								else{
									cout<<"FALLO EN MUJER_PARAMETRIZADO(DATOS_DEMOGRAFICOS)"<<endl;
								}

							}else{
								cout<<"FALLO EN HOMBRE_PARAMETRIZADO(DATOS_DEMOGRAFICOS)"<<endl;
							}

						}else{
							cout<<"FALLO EN AÑO_CREACION_PARAMETRIZADO(DATOS_DEMOGRAFICOS)"<<endl;
						}

					}else{
						cout<<"FALLO EN CODIGO_PARAMETRIZADO(DATOS_DEMOGRAFICOS)"<<endl;
					}

			}else{
				cout<<"FALLO EN AÑO_NACIMIENTO_PARAMETRIZADO(DATOS_DEMOGRAFICOS)"<<endl;
			}

			}	else{
				cout<<"FALLO EN NACIONALIDAD_PARAMETRIZADO(DATOS_DEMOGRAFICOS)"<<endl;
			}

		}
		else{
			cout<<"FALLO EN LUGAR_NACIMIENTO_PARAMETRIZADO(DATOS_DEMOGRAFICOS)"<<endl;
		}
	}
	else{
		cout<<"FALLO EN NIVEL_ESTUDIOS_PARAMETRIZADO(DATOS_DEMOGRAFICOS)"<<endl;
	}


	delete dd;
	cout<<"SE HA REALIZADO LA PRUEBA DE CONSTRUCTOR PARAMETRIZADO DE DATOS_DEMOGRAFICOS"<<endl;
}
void pruebasetnameDatosdemograficos(){
	cout<<"SE ESTA REALIZANDO LA PRUEBA DE SETNAME DE DATOS_DEMOGRAFICOS"<<endl;
	datos_Demograficos *dd;
	dd= new datos_Demograficos();
	dd->setCodigovia(3944); dd->setanonacimiento("1956"); dd->setlugnac("Caceres(Caceres)"); dd->setnivest("Profesorado Egb"); dd->setmuj(20); dd->sethom(14); dd->setanocr(2016); dd->setnacional("España");
	string cad[4];
    int datos[4];
	cad[0]=dd->getnivest(); cad[1]=dd->getlugnac(); cad[2]=dd->getnacional(); cad[3]=dd->getanonacim(); datos[0]=dd->getCodigovia(); datos[1]=dd->getanocr(); datos[2]=dd->gethom(); datos[3]=dd->getmuj();

	if(cad[0]=="Profesorado Egb"){
		if(cad[1]=="Caceres(Caceres)"){
			if(cad[2]=="España"){
				if(cad[3]=="1956"){
					if(datos[0]==3944){
						if(datos[1]==2016){
							if(datos[2]==14){
								if(datos[3]==20){
									cout<<"SE HA EJECUTADO CORRECTAMENTE LA PRUEBA DE SETNAME DE DATOS_DEMOGRAFICOS"<<endl;
								}
								else{
									cout<<"FALLO EN MUJER_SETNAME(DATOS_DEMOGRAFICOS)"<<endl;
								}

							}else{
								cout<<"FALLO EN HOMBRE_SETNAME(DATOS_DEMOGRAFICOS)"<<endl;
							}

						}else{
							cout<<"FALLO EN AÑO_CREACION_SETNAME(DATOS_DEMOGRAFICOS)"<<endl;
						}

					}else{
						cout<<"FALLO EN CODIGO_SETNAME(DATOS_DEMOGRAFICOS)"<<endl;
					}

			}else{
				cout<<"FALLO EN AÑO_NACIMIENTO_SETNAME(DATOS_DEMOGRAFICOS)"<<endl;
			}

			}	else{
				cout<<"FALLO EN NACIONALIDAD_SETNAME(DATOS_DEMOGRAFICOS)"<<endl;
			}



		}
		else{
			cout<<"FALLO EN LUGAR_NACIMIENTO_SETNAME(DATOS_DEMOGRAFICOS)"<<endl;
		}
	}
	else{
		cout<<"FALLO EN NIVEL_ESTUDIOS_SETNAME(DATOS_DEMOGRAFICOS)"<<endl;
	}


	delete dd;
	cout<<"SE HA REALIZADO LA PRUEBA DE SETNAME DE DATOS_DEMOGRAFICOS"<<endl;
}
void pruebagetnameDatosdemograficos(){
	cout<<"SE ESTA REALIZANDO LA PRUEBA DE GETNAME DE DATOS_DEMOGRAFICOS"<<endl;
	datos_Demograficos *dd;
	dd= new datos_Demograficos();
	dd->setCodigovia(3944); dd->setanonacimiento("1956"); dd->setlugnac("Caceres(Caceres)"); dd->setnivest("Profesorado Egb"); dd->setmuj(20); dd->sethom(14); dd->setanocr(2016); dd->setnacional("España");

	if(dd->getnivest()=="Profesorado Egb"){
		if(dd->getlugnac()=="Caceres(Caceres)"){
			if(dd->getnacional()=="España"){
				if(dd->getanonacim()=="1956"){
					if(dd->getCodigovia()==3944){
						if(dd->getanocr()==2016){
							if(dd->gethom()==14){
								if(dd->getmuj()==20){
									cout<<"SE HA EJECUTADO CORRECTAMENTE LA PRUEBA DE GETNAME DE DATOS_DEMOGRAFICOS"<<endl;
								}
								else{
									cout<<"FALLO EN MUJER_GETNAME(DATOS_DEMOGRAFICOS)"<<endl;
								}

							}else{
								cout<<"FALLO EN HOMBRE_GETNAME(DATOS_DEMOGRAFICOS)"<<endl;
							}

						}else{
							cout<<"FALLO EN AÑO_CREACION_GETNAME(DATOS_DEMOGRAFICOS)"<<endl;
						}

					}else{
						cout<<"FALLO EN CODIGO_GETNAME(DATOS_DEMOGRAFICOS)"<<endl;
					}

			}else{
				cout<<"FALLO EN AÑO_NACIMIENTO_GETNAME(DATOS_DEMOGRAFICOS)"<<endl;
			}

			}	else{
				cout<<"FALLO EN NACIONALIDAD_GETNAME(DATOS_DEMOGRAFICOS)"<<endl;
			}



		}
		else{
			cout<<"FALLO EN LUGAR_NACIMIENTO_GETNAME(DATOS_DEMOGRAFICOS)"<<endl;
		}
	}
	else{
		cout<<"FALLO EN NIVEL_ESTUDIOS_GETNAME(DATOS_DEMOGRAFICOS)"<<endl;
	}


	delete dd;
	cout<<"SE HA REALIZADO LA PRUEBA DE GETNAME DE DATOS_DEMOGRAFICOS"<<endl;
}





void pruebaconstructorvacioAnoNacimiento(){
	cout<<"SE ESTA REALIZANDO LA PRUEBA DE CONSTRUCTOR VACIO DE ANONACIMIENTO"<<endl;
	AnoNacimiento *an;
	an= new AnoNacimiento();
	int ano=0,numpersonas=0;
	ano=an->getano(); numpersonas=an->getnumPersonas();

	if(ano==0){
		if(numpersonas==0){
			cout<<"SE HA EJECUTADO CORRECTAMENTE LA PRUEBA DE CONSTRUCTOR VACIO DE ANONACIMIENTO"<<endl;
		}
		else{
			cout<<"FALLO EN NUMPERSONAS"<<endl;
		}
	}
	else{
		cout<<"FALLO EN ANO"<<endl;
	}
	delete an;
	cout<<"SE HA REALIZADO LA PRUEBA DE CONSTRUCTOR VACIO DE ANONACIMIENTO"<<endl;
}
void pruebaconstructorparametrizadoAnoNacimiento(){
	cout<<"SE ESTA REALIZANDO LA PRUEBA DE CONSTRUCTOR PARAMETRIZADO DE ANONACIMIENTO"<<endl;
	AnoNacimiento *an;
	an= new AnoNacimiento(1980,20);
	int ano=0,numpersonas=0;
	ano=an->getano(); numpersonas=an->getnumPersonas();

	if(ano==1980){
		if(numpersonas==20){
			cout<<"SE HA EJECUTADO CORRECTAMENTE LA PRUEBA DE CONSTRUCTOR PARAMETRIZADO DE ANONACIMIENTO"<<endl;
		}
		else{
			cout<<"FALLO EN NUMPERSONAS"<<endl;
		}
	}
	else{
		cout<<"FALLO EN ANO"<<endl;
	}
	delete an;
	cout<<"SE HA REALIZADO LA PRUEBA DE CONSTRUCTOR PARAMETRIZADO DE ANONACIMIENTO"<<endl;
}
void pruebasetnameAnoNacimiento(){
	cout<<"SE ESTA REALIZANDO LA PRUEBA DE SETNAME DE ANONACIMIENTO"<<endl;
	AnoNacimiento *an;
	an= new AnoNacimiento();
	an->setano(1990);
	an->setnumPersonas(20);
	int ano=0,numpersonas=0;
	ano=an->getano(); numpersonas=an->getnumPersonas();

	if(ano==1990){
		if(numpersonas==20){
			cout<<"SE HA EJECUTADO CORRECTAMENTE LA PRUEBA DE SETNAME DE ANONACIMIENTO"<<endl;
		}
		else{
			cout<<"FALLO EN NUMPERSONAS"<<endl;
		}
	}
	else{
		cout<<"FALLO EN ANO"<<endl;
	}
	delete an;
	cout<<"SE HA REALIZADO LA PRUEBA DE SETNAME DE ANONACIMIENTO"<<endl;
}
void pruebagetnameAnoNacimiento(){
	cout<<"SE ESTA REALIZANDO LA PRUEBA DE GETNAME DE ANONACIMIENTO"<<endl;
	AnoNacimiento *an;
	an= new AnoNacimiento();
	an->setano(1990);
	an->setnumPersonas(20);

	if(an->getano()==1990){
		if(an->getnumPersonas()==20){
			cout<<"SE HA EJECUTADO CORRECTAMENTE LA PRUEBA DE GETNAME DE ANONACIMIENTO"<<endl;
		}
		else{
			cout<<"FALLO EN NUMPERSONAS"<<endl;
		}
	}
	else{
		cout<<"FALLO EN ANO"<<endl;
	}
	delete an;
	cout<<"SE HA REALIZADO LA PRUEBA DE GETNAME DE ANONACIMIENTO"<<endl;
}


void pruebaconstructorvacioEstudios(){
	cout<<"SE ESTA REALIZANDO LA PRUEBA DE CONSTRUCTOR VACIO DE ESTUDIOS"<<endl;
	Estudios *e;
	e= new Estudios();
	string nivEstudios="";
	int numpersonas=0;
	nivEstudios=e->getnivelEstudios(); numpersonas=e->getNumPersonas();

	if(nivEstudios==""){
		if(numpersonas==0){
			cout<<"SE HA EJECUTADO CORRECTAMENTE LA PRUEBA DE CONSTRUCTOR VACIO DE ESTUDIOS"<<endl;
		}
		else{
			cout<<"FALLO EN NUMPERSONAS"<<endl;
		}
	}
	else{
		cout<<"FALLO EN NIVELESTUDIOS"<<endl;
	}
	delete e;
	cout<<"SE HA REALIZADO LA PRUEBA DE CONSTRUCTOR VACIO DE ESTUDIOS"<<endl;
}
void pruebaconstructorparametrizadoEstudios(){
	cout<<"SE ESTA REALIZANDO LA PRUEBA DE CONSTRUCTOR PARAMETRIZADO DE ESTUDIOS"<<endl;
	Estudios *e;
	e= new Estudios("Bachillerato",20);
	string nivEstudios="";
	int numpersonas=0;
	nivEstudios=e->getnivelEstudios(); numpersonas=e->getNumPersonas();

	if(nivEstudios=="Bachillerato"){
		if(numpersonas==20){
			cout<<"SE HA EJECUTADO CORRECTAMENTE LA PRUEBA DE CONSTRUCTOR PARAMETRIZADO DE ESTUDIOS"<<endl;
		}
		else{
			cout<<"FALLO EN NUMPERSONAS"<<endl;
		}
	}
	else{
		cout<<"FALLO EN NIVELESTUDIOS"<<endl;
	}
	delete e;
	cout<<"SE HA REALIZADO LA PRUEBA DE CONSTRUCTOR PARAMETRIZADO DE ESTUDIOS"<<endl;
}
void pruebasetnameEstudios(){
	cout<<"SE ESTA REALIZANDO LA PRUEBA DE SETNAME DE ESTUDIOS"<<endl;
	Estudios *e;
	e= new Estudios();
	e->setnivelEstudios("Bachillerato");
	e->setNumPersonas(20);
	string nivEstudios="";
	int numpersonas=0;
	nivEstudios=e->getnivelEstudios(); numpersonas=e->getNumPersonas();

	if(nivEstudios=="Bachillerato"){
		if(numpersonas==20){
			cout<<"SE HA EJECUTADO CORRECTAMENTE LA PRUEBA DE SETNAME DE ESTUDIOS"<<endl;
		}
		else{
			cout<<"FALLO EN NUMPERSONAS"<<endl;
		}
	}
	else{
		cout<<"FALLO EN NIVELESTUDIOS"<<endl;
	}
	delete e;
	cout<<"SE HA REALIZADO LA PRUEBA DE SETNAME DE ESTUDIOS"<<endl;
}
void pruebagetnameEstudios(){
	cout<<"SE ESTA REALIZANDO LA PRUEBA DE GETNAME DE ESTUDIOS"<<endl;
	Estudios *e;
	e= new Estudios();
	e->setnivelEstudios("Bachillerato");
	e->setNumPersonas(20);

	if(e->getnivelEstudios()=="Bachillerato"){
		if(e->getNumPersonas()==20){
			cout<<"SE HA EJECUTADO CORRECTAMENTE LA PRUEBA DE GETNAME DE ESTUDIOS"<<endl;
		}
		else{
			cout<<"FALLO EN NUMPERSONAS"<<endl;
		}
	}
	else{
		cout<<"FALLO EN NIVELESTUDIOS"<<endl;
	}
	delete e;
	cout<<"SE HA REALIZADO LA PRUEBA DE GETNAME DE ESTUDIOS"<<endl;
}


void pruebaconstructorvacioLugarNacimiento(){
	cout<<"SE ESTA REALIZANDO LA PRUEBA DE CONSTRUCTOR VACIO DE LUGARNACIMIENTO"<<endl;
	LugarNacimiento *ln;
	ln= new LugarNacimiento();
	string poblacion="",provincia="";int numpersonas=0;
	poblacion=ln->getpoblacion(); provincia=ln->getprovincia(); numpersonas=ln->getpersonas();
	if(poblacion==""){
	if(provincia==""){
		if(numpersonas==0){
			cout<<"SE HA EJECUTADO CORRECTAMENTE LA PRUEBA DE CONSTRUCTOR VACIO DE LUGARNACIMIENTO"<<endl;
		}
		else{
			cout<<"FALLO EN NUMPERSONAS"<<endl;
		}
	}
	else{
		cout<<"FALLO EN PROVINCIA"<<endl;
		}
	}
	else{
		cout<<"FALLO EN POBLACION"<<endl;
	}
	delete ln;
	cout<<"SE HA REALIZADO LA PRUEBA DE CONSTRUCTOR VACIO DE LUGARNACIMIENTO"<<endl;
}
void pruebaconstructorparametrizadoLugarNacimiento(){
	cout<<"SE ESTA REALIZANDO LA PRUEBA DE CONSTRUCTOR PARAMETRIZADO DE LUGARNACIMIENTO"<<endl;
	LugarNacimiento *ln;
	ln= new LugarNacimiento("Caceres","Caceres",20);
	string poblacion="",provincia="";int numpersonas=0;
	poblacion=ln->getpoblacion(); provincia=ln->getprovincia(); numpersonas=ln->getpersonas();
	if(poblacion=="Caceres"){
	if(provincia=="Caceres"){
		if(numpersonas==20){
			cout<<"SE HA EJECUTADO CORRECTAMENTE LA PRUEBA DE CONSTRUCTOR PARAMETRIZADO DE LUGARNACIMIENTO"<<endl;
		}
		else{
			cout<<"FALLO EN NUMPERSONAS"<<endl;
		}
	}
	else{
		cout<<"FALLO EN PROVINCIA"<<endl;
		}
	}
	else{
		cout<<"FALLO EN POBLACION"<<endl;
	}
	delete ln;
	cout<<"SE HA REALIZADO LA PRUEBA DE CONSTRUCTOR PARAMETRIZADO DE LUGARNACIMIENTO"<<endl;
}
void pruebasetnameLugarNacimiento(){
	cout<<"SE ESTA REALIZANDO LA PRUEBA DE SETNAME DE LUGARNACIMIENTO"<<endl;
	LugarNacimiento *ln;
	ln= new LugarNacimiento();
	ln->setpoblacion("Caceres");
	ln->setprovincia("Caceres");
	ln->setpersonas(20);
	string poblacion="",provincia="";int numpersonas=0;
	poblacion=ln->getpoblacion(); provincia=ln->getprovincia(); numpersonas=ln->getpersonas();
	if(poblacion=="Caceres"){
	if(provincia=="Caceres"){
		if(numpersonas==20){
			cout<<"SE HA EJECUTADO CORRECTAMENTE LA PRUEBA DE SETNAME DE LUGARNACIMIENTO"<<endl;
		}
		else{
			cout<<"FALLO EN NUMPERSONAS"<<endl;
		}
	}
	else{
		cout<<"FALLO EN PROVINCIA"<<endl;
		}
	}
	else{
		cout<<"FALLO EN POBLACION"<<endl;
	}
	delete ln;
	cout<<"SE HA REALIZADO LA PRUEBA DE SETNAME DE LUGARNACIMIENTO"<<endl;
}
void pruebagetnameLugarNacimiento(){
	cout<<"SE ESTA REALIZANDO LA PRUEBA DE GETNAME DE LUGARNACIMIENTO"<<endl;
	LugarNacimiento *ln;
	ln= new LugarNacimiento();
	ln->setpoblacion("Caceres");
	ln->setprovincia("Caceres");
	ln->setpersonas(20);

	if(ln->getpoblacion()=="Caceres"){
	if(ln->getprovincia()=="Caceres"){
		if(ln->getpersonas()==20){
			cout<<"SE HA EJECUTADO CORRECTAMENTE LA PRUEBA DE GETNAME DE LUGARNACIMIENTO"<<endl;
		}
		else{
			cout<<"FALLO EN NUMPERSONAS"<<endl;
		}
	}
	else{
		cout<<"FALLO EN PROVINCIA"<<endl;
		}
	}
	else{
		cout<<"FALLO EN POBLACION"<<endl;
	}
	delete ln;
	cout<<"SE HA REALIZADO LA PRUEBA DE GETNAME DE LUGARNACIMIENTO"<<endl;
}


void pruebaconstructorvacioNacionalidad(){
	cout<<"SE ESTA REALIZANDO LA PRUEBA DE CONSTRUCTOR VACIO DE NACIONALIDAD"<<endl;
	Nacionalidad *n;
	n= new Nacionalidad();
	string pais="";
	int numpersonas=0;
	pais=n->getPais(); numpersonas=n->getnumPersonas();

	if(pais==""){
		if(numpersonas==0){
			cout<<"SE HA EJECUTADO CORRECTAMENTE LA PRUEBA DE CONSTRUCTOR VACIO DE NACIONALIDAD"<<endl;
		}
		else{
			cout<<"FALLO EN NUMPERSONAS"<<endl;
		}
	}
	else{
		cout<<"FALLO EN PAIS"<<endl;
	}
	delete n;
	cout<<"SE HA REALIZADO LA PRUEBA DE CONSTRUCTOR VACIO DE NACIONALIDAD"<<endl;
}
void pruebaconstructorparametrizadoNacionalidad(){
	cout<<"SE ESTA REALIZANDO LA PRUEBA DE CONSTRUCTOR PARAMETRIZADO DE NACIONALIDAD"<<endl;
	Nacionalidad *n;
	n= new Nacionalidad("España",20);
	string pais="";
	int numpersonas=0;
	pais=n->getPais(); numpersonas=n->getnumPersonas();

	if(pais=="España"){
		if(numpersonas==20){
			cout<<"SE HA EJECUTADO CORRECTAMENTE LA PRUEBA DE CONSTRUCTOR PARAMETRIZADO DE NACIONALIDAD"<<endl;
		}
		else{
			cout<<"FALLO EN NUMPERSONAS"<<endl;
		}
	}
	else{
		cout<<"FALLO EN PAIS"<<endl;
	}
	delete n;
	cout<<"SE HA REALIZADO LA PRUEBA DE CONSTRUCTOR PARAMETRIZADO DE NACIONALIDAD"<<endl;
}
void pruebasetnameNacionalidad(){
	cout<<"SE ESTA REALIZANDO LA PRUEBA DE SETNAME DE NACIONALIDAD"<<endl;
	Nacionalidad *n;
	n= new Nacionalidad();
	n->setPais("España");
	n->setnumPersonas(20);
	string pais="";
	int numpersonas=0;
	pais=n->getPais(); numpersonas=n->getnumPersonas();

	if(pais=="España"){
		if(numpersonas==20){
			cout<<"SE HA EJECUTADO CORRECTAMENTE LA PRUEBA DE SETNAME DE NACIONALIDAD"<<endl;
		}
		else{
			cout<<"FALLO EN NUMPERSONAS"<<endl;
		}
	}
	else{
		cout<<"FALLO EN PAIS"<<endl;
	}
	delete n;
	cout<<"SE HA REALIZADO LA PRUEBA DE SETNAME DE NACIONALIDAD"<<endl;
}
void pruebagetnameNacionalidad(){
	cout<<"SE ESTA REALIZANDO LA PRUEBA DE GETNAME DE NACIONALIDAD"<<endl;
	Nacionalidad *n;
	n= new Nacionalidad();
	n->setPais("España");
	n->setnumPersonas(20);

	if(n->getPais()=="España"){
		if(n->getnumPersonas()==20){
			cout<<"SE HA EJECUTADO CORRECTAMENTE LA PRUEBA DE GETNAME DE NACIONALIDAD"<<endl;
		}
		else{
			cout<<"FALLO EN NUMPERSONAS"<<endl;
		}
	}
	else{
		cout<<"FALLO EN PAIS"<<endl;
	}
	delete n;
	cout<<"SE HA REALIZADO LA PRUEBA DE GETNAME DE NACIONALIDAD"<<endl;
}


void Listapruebas(){
	cout<<"SE ESTA REALIZANDO LAS PRUEBAS DE LAS CLASES"<<endl;

	pruebaconstructorvacioBarrio();
	pruebaconstructorparametrizadoBarrio();
    pruebasetnameBarrio();
	pruebagetnameBarrio();

	pruebaconstructorvacioVia();
	pruebaconstructorparametrizadoVia();
	pruebasetnameVia();
	pruebagetnameVia();

	pruebaconstructorvacioDatosdemograficos();
	//pruebaconstructorparametrizadoDatosdemograficos();
	pruebasetnameDatosdemograficos();
    pruebagetnameDatosdemograficos();

    pruebaconstructorvacioAnoNacimiento();
    pruebaconstructorparametrizadoAnoNacimiento();
    pruebasetnameAnoNacimiento();
    pruebagetnameAnoNacimiento();

    pruebaconstructorvacioEstudios();
    pruebaconstructorparametrizadoEstudios();
    pruebasetnameEstudios();
    pruebagetnameEstudios();

    pruebaconstructorvacioLugarNacimiento();
    pruebaconstructorparametrizadoLugarNacimiento();
    pruebasetnameLugarNacimiento();
    pruebagetnameLugarNacimiento();

    pruebaconstructorvacioNacionalidad();
    pruebaconstructorparametrizadoNacionalidad();
    pruebasetnameNacionalidad();
    pruebagetnameNacionalidad();
	cout<<"SE HAN REALIZADO LAS PRUEBAS DE LAS CLASES"<<endl;
}

