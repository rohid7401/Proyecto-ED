#pragma once
#include "Grafo.h"
#include <vector>
#include <pair>

using namespace std;

vector <int> dijkstra(Grafo& grafo, int fuente);

std::string RutaMasCortaA(Grafo& grafo, int destino, vector<int> padre);