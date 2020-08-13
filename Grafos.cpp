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
    std::string archivoEstaciones = "C:\\Users\\Rohi\\Documents\\GitHub\\Proyecto-3-ED\\london.stations.csv";
    std::string archivoConexiones = "C:\\Users\\Rohi\\Documents\\GitHub\\Proyecto-3-ED\\london.connections.csv";
    CargarLondres cargador(archivoEstaciones, archivoConexiones);
    cargador.Cargar(londres);

    /*Dijkstra dijk;
    Prim prim;*/
    Astar astar;

    int fuente = londres.EncontrarVerticePorNombre("Westminster");
    int destino  = londres.EncontrarVerticePorNombre("Covent Garden");
    /*
    dik.dijkstra(londres, fuente);
    std::cout << "\n" << dik.RutaMasCortaA(londres, destino) << std::endl;

    dik.Ejecutar(londres, fuente);
    std::cout << "\n" << dik.RutaMasCortaA(londres, destino) << std::endl;
    */

    astar.Ejecutar(londres, fuente);
    std::cout << "\n" << astar.RutaMasCortaA(londres, destino) << std::endl;
}
