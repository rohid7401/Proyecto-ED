#pragma once
#include "Arista.h"
#include <limits>
#include <list>


class TablaGrafos
{
public:
	bool Visitado;
	int Id;
	int Distancia;
	int Anterior;
	std::list<Arista>* Adyacente;
	TablaGrafos(bool visitado, int distancia, int anterior, int id, std::list<Arista>*& adyacente);
	bool AnteriorVacio();
	bool DistanciaInfinita();
	static int ValorVacio();
	static int ValorDistanciaInfinita();
};

