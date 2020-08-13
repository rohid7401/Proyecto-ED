#include "Prim.h"
#include <priority_queue>

typedef pair<double, int> di;
typedef pair<int, int> ii;

vector<pair<int, int> > Prim(Grafo& grafo)
{

	vector<pair <int, int> > res;
	vector<int> padre(grafo.NumeroVertices, -1);
	priority_queue < pair <double, int>, vector< pair <double, int> >, greater < pair <double, int> > > q;
	vector<bool> seen(grafo.NumeroVertices, false);
	q.push(di(0, 0));
	int restantes = grafo.NumeroVertices - 1;

	while (restantes) {

		di actual = q.top(); q.pop();
		int nodoActual = actual.second;

		if (seen[nodoActual]) {
			continue;
		}

		res.push_back(ii(nodoActual, padre[nodoActual]));
		seen[nodoActual] = true;
		restantes--;

		for (auto i : grafo.Vertices[nodoActual].Vecinos) {

			int vecino = i.VerticeAdyacente;

			if (!seen[vecino]) {

				q.push(di(i.Tiempo, vecino));

			}
		}
	}
	return res;
}

std::string RutaMasCortaA(Grafo& grafo, int destino)
{
	stringstream res;
	vector<pair<int, int> > Prim(grafo);

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