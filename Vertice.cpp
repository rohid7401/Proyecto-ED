#include "Vertice.h"

Vertice::Vertice(int id, std::string nombre,  double latitud, double longitud)
{
	Id = id;
	Nombre = nombre;
	Latitud = latitud;
	Longitud = longitud;
}

Vertice::~Vertice()
{
}
