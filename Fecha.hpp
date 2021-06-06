#ifndef FECHA_H
#define FECHA_H

//Estructura Fecha
class Fecha
{
private://Atributos
	int dia = 0,mes = 0,anio = 0;

public://Operaciones
	
	Fecha(){}; //Contructor por defecto
	
	~Fecha(){};  //Destructor
	
	Fecha(int dia, int mes, int anio) //Constructor por asignacion
	{
		this->dia = dia;
		this->mes = mes;
		this->anio = anio;
	}
	
	//Getter
	int getDia();
	int getMes();
	int getAnio();
};
#endif
