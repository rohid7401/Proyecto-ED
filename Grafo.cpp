#include "Grafo.h"

Grafo::Grafo()
{
	Vertices.reserve(500);
	NumeroVertices = 1;
}

Grafo::~Grafo()
{
}

void Grafo::AgregarVertice(int id, std::string nombre, double latitud, double longitud)
{
	Vertices.emplace_back(id, nombre, latitud, longitud);
	NumeroVertices++;
}

void Grafo::AgregarArista(int estacion1, int estacion2, int tiempo)
{
	Vertices[estacion1].Vecinos.emplace_back(estacion2, tiempo);

	Vertices[estacion2].Vecinos.emplace_back(estacion1, tiempo);


}

int Grafo::EncontrarVerticePorNombre(std::string nombre)
{
	//TODO: deben completar este método, a partir del nombre devolver su id. 

	for (int i = 0; i < Vertices.size(); i++) {
		if (Vertices[i].Nombre == nombre) {
			return Vertices[i].Id;
		}
	}
	return -1;
}

void Grafo::InfoVerticePorNombre(std::string nombre)
{	
	bool flag = false;
	for (int i = 0; i < Vertices.size(); i++) {
		if (Vertices[i].Nombre == nombre) {
			flag = true;
			std::cout << "|Estación " << Vertices[i].Nombre << "|\nLat:" << Vertices[i].Latitud << "\nLon:" << Vertices[i].Longitud << std::endl;
			std::cout << "Vecinos: ";
			for (Arista ari : Vertices[i].Vecinos) {
				std::cout << Vertices[ari.VerticeAdyacente].Nombre << ", " << std::endl;
			}
		}
	}

	if (!flag) {
		std::cout << "Estacion no registrada" << std::endl;
	}
}