#ifndef RELACIONLABORAL_H
#define RELACIONLABORAL_H

#include <iostream>
#include "Fecha.hpp" //Estructura Fecha
using namespace std;

class RelacionLaboral
{	
private:
	int id = 0;
	float sueldo = 0;
	Fecha *fechaDesvinculacion = new Fecha();

public:
	RelacionLaboral(){} //Constructor por Defecto
	
	RelacionLaboral(int id,float sueldo)	//Constructor por Asignacion
	{
		this->id = id;
		this->sueldo = sueldo;
	} 
	
	~RelacionLaboral(){} //Constructor por Defecto

	//Setters
	void setId(int);
	void setSueldo(float);
	void setfechaDesvinculacion();
	
	//Getters
	int getId();
	float getSueldo();
	
	//Mostramos las Relaciones Laborales
	void mostrarRL();
};

#endif

