#pragma once
#include <limits>

class TablaGrafos
{
public:
	bool Visitado;
	int Distancia;
	int Anterior;
	TablaGrafos(bool visitado, int distancia, int anterior);
	bool AnteriorVacio();
	bool DistanciaInfinita();
	static int ValorVacio();
	static int ValorDistanciaInfinita();
};

