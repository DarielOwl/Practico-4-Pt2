#include <iostream>
#include <stdlib.h>
#include "Empleado.hpp"
#include "RelacionLaboral.h"
using namespace std;

//Setters
void Empleado::setCi(string ci)
{
	this->ci = ci;
}	
	
void Empleado::setNombre(string nombre)
{
	this->nombre = nombre;
}

void Empleado::setApellido(string apellido)
{
	this->apellido = apellido;
}

void Empleado::setDireccion(string direccion)
{
	this->direccion = direccion;
}

//Getters
string Empleado::getCi()
{
	return ci;
}

string Empleado::getNombre()
{
	return nombre;
}

string Empleado::getApellido()
{
	return apellido;
}

string Empleado::getDireccion()
{
	return direccion;
}

void Empleado::setRelacionLaboral(float sueldo)	
{
	//Hacer que el ID de RelacionLaboral sea autoincrementado
	int incrementID = relacionLab.size()+1; 
	
	//Agregamos la Relacion Laboral del Empleado Especificado
	relacionLab.push_back(new RelacionLaboral(incrementID,sueldo));
}

void Empleado::mostrarRelacionesLaborales()
{
	//Mostramos todas las Relaciones Empleados 
	for(unsigned int i = 0; i < relacionLab.size(); i++)
	{
		relacionLab[i]->mostrarRL();
	}
}

void Empleado::desvincularEmpleado(int id)
{
	int posicionRL = 0;
	
	//1) Buscar la relacionLab en el array
	for(unsigned int i = 0; i < relacionLab.size(); i++)
	{
		if(relacionLab[i]->getId() == id) //Si se encuentra la id de la RelacionLaboral
		{
			posicionRL = i; //Guardamos donde esta
			break;
		}	
	}
	
	//Setiamos la fecha cual se desvincula el Empleado
	relacionLab[posicionRL]->setfechaDesvinculacion();
}
