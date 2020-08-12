#pragma once
#include <string>
#include <list>
#include "Arista.h"
#include "string"
class Vertice
{
public:
	int Id;
	std::string Nombre;
	double Latitud;
	double Longitud;
	std::list<Arista> Vecinos;
	Vertice(int id, std::string nombre, double latitud, double longitud);
	~Vertice();

};

