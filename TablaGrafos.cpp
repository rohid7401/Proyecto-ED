#include "TablaGrafos.h"

TablaGrafos::TablaGrafos(bool visitado, int distancia, int anterior, int id, std::list<Arista>* adyacente)
{
	Visitado = visitado;
	Distancia = distancia;
	Anterior = anterior;
	Id = id;
	Adyacente = adyacente;
}

void TablaGrafos::PilaPrioridad(bool visitado, int distancia, int anterior, int id, double latitud, double longitud)
{
	Visitado = visitado;
	Distancia = distancia;
	Anterior = anterior;
	Id = id;
	Latitud = latitud;
	Longitud = longitud;
}

bool TablaGrafos::AnteriorVacio()
{
	return Anterior == ValorVacio();
}

bool TablaGrafos::DistanciaInfinita()
{
	return Distancia == ValorDistanciaInfinita();
}

int TablaGrafos::ValorVacio()
{
	//TODO: Devuelve el Valor que van a usar para representar el vacío dentro de la tabla
	// No, no es un 42. Piensen en algo y elijanlo

	return std::numeric_limits<int>::max();
}

int TablaGrafos::ValorDistanciaInfinita()
{
	//TODO: Devuelve el Valor que van a usar para representar el infinito dentro de la tabla. 
	// No, no es un 42. Piensen en algo y elijanlo

	return std::numeric_limits<int>::max();
}
