#include "Dijkstra.h"


void Dijkstra::Inicializar(Grafo& grafo, int fuente)
{
	for (Vertice ver : Vertices) {
		if(ver.Id != fuente){
			Tabla.emplace_back(false, TablaGrafos::ValorDistanciaInfinita, TablaGrafos::ValorVacio(), ver.Id, ver.Vecinos);
		}
		else {
			Tabla.emplace_back(false, 0, TablaGrafos::ValorVacio(), fuente, ver.Vecinos);
		}
	}
}

void Dijkstra::Ejecutar(Grafo& grafo, int fuente)
{
	Inicializar(grafo, fuente);
	for (TablaGrafos ver : Tabla) {
		if (ver.Id == fuente) {
			ver.Visitado = true;
			ver.Anterior = NULL;
			for (Arista ari : ver.Adyacente) {
				if ()
				{

				}
			}
		}
	}

	// ver https://docs.google.com/presentation/d/1rQUVSyaPVH2wMr4b_5EBHQ5BGrf8sJ1h/edit#slide=id.p187
}

int Dijkstra::EncontrarMinimioSinVisitar(  )
{
	// ver https://docs.google.com/presentation/d/1rQUVSyaPVH2wMr4b_5EBHQ5BGrf8sJ1h/edit#slide=id.p187

	//Esta es la parte de "Encontramos vértice v sin visitar con la  minima distancia"
}

std::string Dijkstra::RutaMasCortaA(Grafo& grafo,int destino)
{


	std::stringstream ss;
	
	// https://docs.google.com/presentation/d/1rQUVSyaPVH2wMr4b_5EBHQ5BGrf8sJ1h/edit#slide=id.p234

	// vean la tabla. tienen que comenzar del destino,
	// e "ir hacia atras" hasta que lleguen a la fuente.
	// debe imprimirse en orden (es decir, Fuente, vertice1, vertice2, ... destino)


	return ss.str();
}
