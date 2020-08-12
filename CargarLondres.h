#pragma once
#include <string>
#include "LectorCSV.h"
#include "Grafo.h"
class CargarLondres
{
private:
	std::string ArchivoEstaciones;
	std::string ArchivoConexiones;
public:
	CargarLondres(std::string archivoEstaciones, std::string archivoConexiones);
	void Cargar(Grafo& londres);
};

