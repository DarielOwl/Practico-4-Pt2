#ifndef DTRELACIONLABORAL_H
#define DTRELACIONLABORAL_H

#include "DtFecha.hpp"

//Datatype de RelacionesLaborales 
//Lo usaremos para guardar y mostrar informacion
class DtRelacionLaboral
{
	
private:
	int id;
	float sueldo;
	DtFecha *fDesvinculacion = new DtFecha(); //Seteamos una fecha Predeterminada
	
public:
	
	DtRelacionLaboral(){} //Constructor por Defecto	
	
	//Constructor por asignacion
	DtRelacionLaboral(int id,float sueldo) 
	{
		this->id = id;
		this->sueldo = sueldo;
	}
	
	~DtRelacionLaboral(){} //Destructor	
	
	//Getters
	int getID()
	{
		return id; 
	}
	
	float getSueldo()
	{
		return sueldo; 
	}
	
	DtFecha* getFechaDesvinculacion()
	{
		return fDesvinculacion; 
	}
};

#endif
