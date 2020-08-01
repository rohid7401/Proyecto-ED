// Grafos.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "Grafo.h"
#include "CargarLondres.h"
#include "Dijkstra.h"

int main()
{
    Grafo londres;
    std::string archivoEstaciones = "C:\\Users\\rafa\\source\\repos\\Progra3\\london.stations.csv";
    std::string archivoConexiones = "C:\\Users\\rafa\\source\\repos\\Progra3\\london.connections.csv";
    CargarLondres cargador(archivoEstaciones, archivoConexiones);
    cargador.Cargar(londres);
    Dijkstra dik;
    int fuente = londres.EncontrarVerticePorNombre("Westminster");
    int destino  = londres.EncontrarVerticePorNombre("Covent Garden");
    dik.Ejecutar(londres, fuente);
    std::cout << dik.RutaMasCortaA(londres, destino);
}
