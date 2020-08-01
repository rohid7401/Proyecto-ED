#pragma once
#include <vector>
#include <string>
#include "Vertice.h"
#include "Arista.h"
class Grafo
{	
	public:
		int NumeroVertices;
		std::vector<Vertice> Vertices;
		Grafo();
		~Grafo();
		void AgregarVertice(int id, std::string nombre, double latitud, double longitud);
		void AgregarArista(int estacion1, int estacion2, int tiempo);
		// Devuelve el Id de la estación. Si no está, devuelve un -1.
		int EncontrarVerticePorNombre(std::string nombre);
};

