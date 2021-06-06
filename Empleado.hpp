#ifndef EMPLEADO_H
#define EMPLEADO_H

#include <iostream>
#include <vector>
#include "RelacionLaboral.h"
using namespace std;

class Empleado
{
private:
	string ci,nombre,apellido,direccion; //Datos del Empleado
	
	//Cada Empleado puede tener 0..50 relaciones laborales
	//Para esto generamos un vector dinamico
	vector<RelacionLaboral*> relacionLab;
	
public:
	Empleado(){} //Constructor por Defecto
	~Empleado(){} //Destructor por Defecto
	
	Empleado(string ci,string nombre,string apellido,string direccion) //Constructor Definido
	{
		this->ci = ci;
		this->nombre = nombre;
		this->apellido = apellido;
		this->direccion = direccion;
	}
	
	//Setters
	void setCi(string ci);
	void setNombre(string nombre);
	void setApellido(string apellido);
	void setDireccion(string direccion);
	
	//Getters
	string getCi();
	string getNombre();
	string getApellido();
	string getDireccion();
	
	void mostrarDatos()
	{
		cout<<"\nCI: "<<ci<<endl;
		cout<<"NOMBRE: "<<nombre<<endl;
		cout<<"APELLIDO: "<<apellido<<endl;
		cout<<"DIRECCION: "<<direccion<<endl;
	}
	
	//Settiar Relacion Laboral
	void setRelacionLaboral(float);
	
	//Mostrar las Relaciones del Empleado
	void mostrarRelacionesLaborales();
	
	//Desvincular un empleado
	void desvincularEmpleado(int);
	
};

#endif
