#pragma once
#include "TablaGrafos.h"
#include "Grafo.h"
#include "Arista.h"
#include <stack>
#include <vector>
#include <sstream>;
class Dijkstra
{
public:
	std::vector<TablaGrafos> Tabla;

	// Coloca los valores iniciales para la Tabla
	// fuente es el vértice del cual iniciamos
	void Inicializar(Grafo& grafo, int fuente);

	//Ejecutar corre el algoritmo de Dijkstra
	//fuente es el vértice del cual iniciamos

	void Ejecutar(Grafo& grafo, int fuente);

	// va a la Tabla y devuelve la posición del vértice sin visitar con la distancia más pequeña
	int EncontrarMinimioSinVisitar();

	// se corre despues de Ejecutar el algoritmo.
	// Devueve la ruta más corta desde la fuente hacia el destino. Por ejemplo:
	// Fuente -> Estacion1 -> Estacion2 -> Estacion2 -> Destino
	//Nota: devuelve el NOMBRE de la estación.
	//Utilice un stringstream para constuir el resultado

	std::string RutaMasCortaA(Grafo& grafo, int destino);

};

