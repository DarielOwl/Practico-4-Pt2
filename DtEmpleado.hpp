#ifndef DTEMPLEADO_H
#define DTEMPLEADO_H

#include <iostream>
#include <vector>
#include "DtRelacionLaboral.hpp"
using namespace std;

//Datatype de Empleado 
//Lo usaremos para guardar y mostrar informacion
class DtEmpleado
{
	
private:
	string ci,nombre,apellido,direccion;
	vector<DtRelacionLaboral*> DtReLab;
	
public:
	
	DtEmpleado(){} //Constructor por Defecto	
	
	//Constructor por asignacion
	DtEmpleado(string ci,string nombre,string apellido,string direccion) 
	{
		this->ci = ci;
		this->nombre = nombre;
		this->apellido = apellido;
		this->direccion = direccion;
	}
	
	~DtEmpleado(){} //Destructor	
	
	//Getters
	string getCI()
	{
		return ci; 
	}
	
	string getNombre()
	{
		return nombre; 
	}
	
	string getApellido()
	{
		return apellido; 
	}
	
	string getDireccion()
	{
		return direccion; 
	}
};

#endif
