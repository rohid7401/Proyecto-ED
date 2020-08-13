#pragma once
#include "TablaGrafos.h"
#include "Grafo.h"
#include <stack>
#include <vector>
#include <sstream>

class Astar
{
public:

	std::vector<TablaGrafos> Tabla;

	void Inicializar(Grafo& grafo, int fuente);

	void Ejecutar(Grafo& grafo, int fuente);

	int EncontrarMinimioSinVisitar();

	std::string RutaMasCortaA(Grafo& grafo, int destino);

	int RutaAstar(double lat1, double lat2, double long1, double long2);

};