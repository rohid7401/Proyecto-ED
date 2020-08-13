// Grafos.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "Grafo.h"
#include "CargarLondres.h"
#include "Dijkstra.h"
#include "Prim.h"
#include "Astar.h"

int main()
{
    Grafo londres;
    std::string archivoEstaciones = "C:\\Users\\rafa\\source\\repos\\Progra3\\london.stations.csv";
    std::string archivoConexiones = "C:\\Users\\rafa\\source\\repos\\Progra3\\london.connections.csv";
    CargarLondres cargador(archivoEstaciones, archivoConexiones);
    cargador.Cargar(londres);

    Dijkstra dijk;
    Prim prim;
    Astar astar;

    int fuente = londres.EncontrarVerticePorNombre("Westminster");
    int destino  = londres.EncontrarVerticePorNombre("Covent Garden");

    dijk.dijkstra(londres, fuente);
    std::cout << "\n" << dijk.RutaMasCortaA(londres, destino) << std::endl;

    prim.Prim(londres);
    std::cout << "\n" << prim.RutaMasCortaA(londres, destino) << std::endl;


    astar.Ejecutar(londres, fuente);
    std::cout << "\n" << astar.RutaMasCortaA(londres, destino) << std::endl;
}
