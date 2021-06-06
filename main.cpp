#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <vector> //Ya genera arrays dinamicos
#include "Empleado.hpp"
#include "DtEmpleado.hpp"
#include "DtRelacionLaboral.hpp"
using namespace std;

//Variables Globales
vector<Empleado*> empleados;	//Crear array de Empleados dinamicos

//Crear Menu
void menu()
{
	cout<<"\t Menu"<<endl;
	cout<<"1) Agregar Empleado"<<endl;
	cout<<"2) Agregar Relacion Laboral del Empleado"<<endl;
	cout<<"3) Listar Empleados"<<endl;
	cout<<"4) Listar las Relaciones Laborales de los Empleados"<<endl;
	cout<<"5) Disvincular la Relacion Laboral de un Empleado"<<endl;
	cout<<"0) Salir"<<endl;
	cout<<"Opcion: ";
}

int buscarEmpleado(vector<Empleado*> empleados,string ci)
{
	int posicionEMP = -1;
	
	//1) Buscar el Empleado en el array
	for(unsigned int i = 0; i < empleados.size(); i++)
	{
		if(empleados[i]->getCi() == ci) //Si la CI a buscar coincide a la del array
		{
			posicionEMP = i; //Guardamos donde esta
			break;
		}	
	} 
	
	return posicionEMP; //si retorna -1, no se encontro el Empleado
}


//Recibimos como parametro un datatype DtEmpleado y guardamos los datos
//En el objeto principal Empleado
void agregarEmpleado(DtEmpleado* nuevoEMP){
	//Con el Datatype empleado guardamos en el objeto principal
	empleados.push_back(new Empleado(nuevoEMP->getCI(),nuevoEMP->getNombre(),nuevoEMP->getApellido(),nuevoEMP->getDireccion()));
}


void agregarRelacionLaboral(DtRelacionLaboral* nuevoRL)
{
	string empCI = to_string(nuevoRL->getID()); //Obtenemos la CI del empleado a buscar
	
	//Buscamos el empleado que retornara la pisicion de memoria en donde esta 
	int buscarEMP = buscarEmpleado(empleados,empCI);
	
	if(buscarEMP == -1) //Si retorna -1 entonces no hay empleado con esa CI
	{
		cout<<"NO existe el Empleado: "<<empCI<<endl;
	}
	else	//De caso contrario se ingresa uno nuevo
	{	
		//Luego de obtener el empleado que necesitamos, creamos el array de RelacionLaboral
		empleados[buscarEMP]->setRelacionLaboral(nuevoRL->getSueldo());	
	}
}

void listarEmpleados()
{
	//Mostramos todos los Empleados 
	cout<<"\t\nLista de Empleados"<<endl;
	for(unsigned int i = 0; i < empleados.size(); i++)
	{
		empleados[i]->mostrarDatos();
	}
}

void listarRelacionesLaborales(string ci)
{
	//Buscamos el empleado que retornara la pisicion de memoria en donde esta 
	int buscarEMP = buscarEmpleado(empleados,ci);
	
	if(buscarEMP == -1) //Si retorna -1 entonces no hay empleado con esa CI
	{
		cout<<"NO existe el Empleado: "<<ci<<endl;
	}
	else	//Mostramos todas las relaciones laborales
	{	
		//Despues de encontrar dicho empleado mostramos sus Relaciones Laborales
		cout<<"\nEmpleado:  "<<empleados[buscarEMP]->getNombre()<<" "<<empleados[buscarEMP]->getApellido()<<endl;
		empleados[buscarEMP]->mostrarRelacionesLaborales();	
	}
}

void desvincularRelacionesLaborales(string ci,int id)
{
	//Buscamos el empleado que retornara la pisicion de memoria en donde esta 
	int buscarEMP = buscarEmpleado(empleados,ci);
	
	if(buscarEMP == -1) //Si retorna -1 entonces no hay empleado con esa CI
	{
		cout<<"NO existe el Empleado: "<<ci<<endl;
	}
	else //De otro modo desvincular el empleado
	{	
		//Desvinculamos el Empleado Especificado
		empleados[buscarEMP]->desvincularEmpleado(id);
	}
}

int main()
{
	string ci,nombre,apellido,direccion; //Datos de los Empleados 
	int opc; 
	
	do
	{
		menu(); //Mostramos el menu 
		cin>>opc;
		
		switch(opc)
		{
		case 1: //Agregar 1 Empleado
		{	
			cout<<"\t\nEmpleado "<<empleados.size()<<endl;
			
			fflush(stdin); //Vaciamos el buffer de teclado
			cout<<"Ingrese la Cedula de Identidad: ";
			getline(cin,ci);
			
			cout<<"Ingrese el Nombre: ";
			getline(cin,nombre);	
			
			cout<<"Ingrese el Apellido: ";
			getline(cin,apellido);	
			
			cout<<"Ingrese la Direccion: ";
			getline(cin,direccion);	
			
			//Creamos el DtEmpleado 
			DtEmpleado* nuevoEmpleado = new DtEmpleado(ci,nombre,apellido,direccion);
			
			//Llamamos la funcion para agregar el empleado en el array
			agregarEmpleado(nuevoEmpleado);		
			
			//Luego de usar el Datatype lo eliminamos para no ocupar memoria
			delete nuevoEmpleado; 
			break;
		}	
		case 2: //Agregar Relacion Laboral del Empleado
		{	
			float sueldo = 0;
			
			fflush(stdin); 
			cout<<"Ingrese la Cedula de Identidad: ";
			getline(cin,ci);
			
			cout<<"Ingrese el sueldo: ";
			cin>>sueldo;
			
			//Creamos el DtRelacionLaboral
			DtRelacionLaboral* nuevoRL = new DtRelacionLaboral(stoi(ci),sueldo);
			
			//Llamamos la funcion para agregar la relacion laboral 
			agregarRelacionLaboral(nuevoRL);
			
			//Luego de usar el Datatype lo eliminamos para no ocupar memoria
			delete nuevoRL; 
			break;
		}
		case 3: //Mostrar Lista de Empleados
		{	
			listarEmpleados(); 
			break;
		}	
		case 4: //Listar las Relaciones Laborales de los Empleados
			fflush(stdin); 
			cout<<"Ingrese la Cedula de Identidad: ";
			getline(cin,ci);
			
			//Mostrar las Relaciones Laborales del empleado especificado
			listarRelacionesLaborales(ci);
			break;
			
		case 5: //Disvincular la Relacion Laboral de un Empleado
		{	
			float id = 0;
			
			fflush(stdin); 
			cout<<"Ingrese la Cedula de Identidad: ";
			getline(cin,ci);
			
			cout<<"Ingrese la ID del Empleado: ";
			cin>>id;
			
			//Desvinculamos la Relacion Laboral del Empleado
			desvincularRelacionesLaborales(ci,id);
			break;
		}
		default: break; //Salir
		}
		system("pause");
		system("cls");
	}while(opc != 0);
	
	system("pause");
	return 0;
}

