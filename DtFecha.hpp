#ifndef DTFECHA_H
#define DTFECHA_H

class DtFecha
{
	
private://Atributos
	int dia = 0,mes = 0,anio = 0;
	
public://Operaciones
	
	DtFecha(){}; //Contructor por defecto

	DtFecha(int dia, int mes, int anio) //Constructor por asignacion
	{
		this->dia = dia;
		this->mes = mes;
		this->anio = anio;
	}
	
	~DtFecha(){};  //Destructor
	
	//Getter
	int getDia()
	{
		return dia;
	}
	
	int getMes()
	{
		return mes;
	}
	
	int getAnio()
	{
		return anio;
	}
	
};

#endif
