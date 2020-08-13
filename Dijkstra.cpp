#include "Dijkstra.h"
#include <priority_queue>
#include <iostream>
#include <sstream>
#include <algorithm>


using namespace std;

typedef pair<double, int> di;
typedef pair<int, int> ii;

vector<int> dijkstra(Grafo& grafo, int fuente)
{

	vector<double> distancia(grafo.NumeroVertices, 1e12);
	vector<int> padre(grafo.NumeroVertices, -1);
	priority_queue < pair <double, int>, vector< pair <double, int> >, greater < pair <double, int> > > q;
	vector<bool> seen(grafo.NumeroVertices, false);
	q.push(di(0, fuente));
	distancia[fuente] = 0;

	while (q.size()) {

		di actual = q.top(); q.pop();
		int nodoActual = actual.second;

		seen[nodoActual] = true;

		for (auto i : grafo.Vertices[nodoActual].Vecinos) {

			int vecino = i.VerticeAdyacente;
			double distanciaNueva = distancia[nodoActual] + i.Tiempo;

			if (distancia[vecino] > distanciaNueva) {

				distancia[vecino] = distanciaNueva;
				q.push(di(distanciaNueva, vecino));
				padre[vecino] = nodoActual;

			}
		}
	}
	return padre;
}



std::string RutaMasCortaA(Grafo& grafo, int destino, vector<int> padre)
{
	stringstream res;
	vector<int> pasos;

	while (padre[destino] != -1) {

		pasos.push_back(destino);
		destino = padre[destino];
	}

	reverse(pasos.begin(), pasos.end());
	res << grafo.Vertices[destino].Nombre;

	for (auto i : pasos) {

		res << " -> " << grafo.Vertices[i].Nombre;
	}

	return res.str;
}