#include "TablaGrafos.h"

TablaGrafos::TablaGrafos(bool visitado, int distancia, int anterior)
{
	Visitado = visitado;
	Distancia = distancia;
	Anterior = anterior;
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
	return 42;
}

int TablaGrafos::ValorDistanciaInfinita()
{
	//TODO: Devuelve el Valor que van a usar para representar el infinito dentro de la tabla. 
	// No, no es un 42. Piensen en algo y elijanlo
	return 42;
}
