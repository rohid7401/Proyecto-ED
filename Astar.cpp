#include "Astar.h"
#include <iostream>
#include <math.h>
using namespace std;



void Astar::Inicializar(Grafo& grafo, int fuente)
{
	for (Vertice ver : grafo.Vertices) {
		if (ver.Id != fuente) {
			Tabla.emplace_back(false, TablaGrafos::ValorDistanciaInfinita, TablaGrafos::ValorVacio(), ver.Id, ver.Vecinos);
		}
		else {
			Tabla.emplace_back(false, 0, TablaGrafos::ValorVacio(), fuente, ver.Vecinos);
		}
	}
}

void Astar::Ejecutar(Grafo& grafo, int fuente)
{
	Inicializar(grafo, fuente);

	int encontrarMinimo = EncontrarMinimioSinVisitar();

	while (encontrarMinimo != -1) {                        // Encontramos un vertice sin visitar con distancia menor a infinito

		Tabla[encontrarMinimo].Visitado = true;            // Lo marcamos como visitado

		list<Arista> vecinos = grafo.Vertices[encontrarMinimo].Vecinos;

		for (auto& i : vecinos) {                                                     // Por cada vecino de w del vertice 

			if (Tabla[i.VerticeAdyacente].Visitado == false) {                     // Sin visitar

				if (Tabla[encontrarMinimo].Distancia + i.Tiempo < Tabla[i.VerticeAdyacente].Distancia) {     // Si distancia(v)  + peso de arista (v, w) < distancia(w):

					Tabla[i.VerticeAdyacente].Distancia = Tabla[encontrarMinimo].Distancia + i.Tiempo;

					if (Tabla[i.VerticeAdyacente].Distancia < RutaAstar(Tabla[encontrarMinimo].Latitud, Tabla[i.VerticeAdyacente].Latitud, Tabla[encontrarMinimo].Longitud, Tabla[i.VerticeAdyacente].Longitud)) {
						Tabla[i.VerticeAdyacente].Anterior = encontrarMinimo;                              // Anterior(w) = v
					}
					else {
						Tabla[i.VerticeAdyacente].Anterior = RutaAstar(Tabla[encontrarMinimo].Latitud, Tabla[i.VerticeAdyacente].Latitud, Tabla[encontrarMinimo].Longitud, Tabla[i.VerticeAdyacente].Longitud);
					}
					       // Distancia(w) = distancia(v) + peso de arista (v, w)										
				}

			}

		}

		encontrarMinimo = EncontrarMinimioSinVisitar();          // Actualizar el minimo para que salga

	}




	// ver https://docs.google.com/presentation/d/1rQUVSyaPVH2wMr4b_5EBHQ5BGrf8sJ1h/edit#slide=id.p187
}

int Astar::EncontrarMinimioSinVisitar()
{
	int distanciaMinima = TablaGrafos::ValorDistanciaInfinita();
	int contadorID = TablaGrafos::ValorVacio();

	for (int i = 0; i < Tabla.size(); i++) {

		if (Tabla[i].Visitado == false && Tabla[i].Distancia < distanciaMinima) {

			distanciaMinima = Tabla[i].Distancia;
			contadorID = i;

		}

	}

	return contadorID;


	// ver https://docs.google.com/presentation/d/1rQUVSyaPVH2wMr4b_5EBHQ5BGrf8sJ1h/edit#slide=id.p187

	//Esta es la parte de "Encontramos vértice v sin visitar con la  minima distancia"
}

std::string Astar::RutaMasCortaA(Grafo& grafo, int destino)
{

	string temp;
	int puntero = destino;

	while (Tabla[puntero].Distancia != 0) {

		temp = " ---> " + grafo.Vertices[puntero].Nombre + temp;
		puntero = Tabla[puntero].Anterior;

	}
	temp = grafo.Vertices[puntero].Nombre + temp;

	std::stringstream ss(temp);

	// https://docs.google.com/presentation/d/1rQUVSyaPVH2wMr4b_5EBHQ5BGrf8sJ1h/edit#slide=id.p234

	// vean la tabla. tienen que comenzar del destino,
	// e "ir hacia atras" hasta que lleguen a la fuente.
	// debe imprimirse en orden (es decir, Fuente, vertice1, vertice2, ... destino)


	return ss.str();
}




int Astar::RutaAstar(double lat1, double lat2, double long1, double long2)
{
	int static R = 6357;
	int static V = 300;

	double latT = lat2 - lat1;																	// latT = lat2 − lat1
	double longT = long2 - long1;																// longT = long2 − long1
	double a = pow(sin(latT / 2), 2) + cos(lat1) * cos(lat2) * pow(sin(longT / 2), 2);			// a = sin^2(latT / 2) + cos(lat1) * cos(lat2) * sin^2(longT / 2)
	double c = 2 * atan2(sqrt(a), sqrt(1 - a));													// c = 2 * atan2(sqrt(a), sqrt(1−a))
	double d = R * c;																			//d = R * c
	int Tiempo = int(d / V);

	return Tiempo;
}