#include <iostream>
#include <stdlib.h>
#include "RelacionLaboral.h"
#include <ctime> //Para obtener la Fecha
using namespace std;

//Setters
void RelacionLaboral::setId(int id)
{
	this->id = id;
}

void RelacionLaboral::setSueldo(float sueldo)
{
	this->sueldo = sueldo;
}

void RelacionLaboral::setfechaDesvinculacion()
{
	//Primeros borramos la Fecha setiar por defecto
	delete fechaDesvinculacion;
	
	/* fecha/hora actual basado en el sistema actual */
	time_t now = time(0);

	/* Objeto de una estructura tm con fecha/hora local */
	tm * time = localtime(&now); 
	
	//Dias del mes desde el 1 al 31
	int dia = time->tm_mday;
	
	//Meses del año desde el 0 al 11
	int mes = 1 + time->tm_mon;
	
	//Años desde despues de 1900
	int anio = 1900 + time->tm_year;
	
	//Y por ultimo creamos la nueva fecha especificada
	this->fechaDesvinculacion = new Fecha(dia, mes, anio);
}


//Getters
int RelacionLaboral::RelacionLaboral::getId()
{
	return id;
}

float RelacionLaboral::RelacionLaboral::getSueldo()
{
	return sueldo;
}


//Mostramos las Relaciones Laborales
void RelacionLaboral::mostrarRL()
{
	cout<<"\nID: "<<id<<endl;
	cout<<"SUELDO: "<<sueldo<<endl;
	cout<<fechaDesvinculacion->getDia()<<"/"<<fechaDesvinculacion->getMes()<<"/"<<fechaDesvinculacion->getAnio()<<endl;
}
