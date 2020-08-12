#include "CargarLondres.h"

CargarLondres::CargarLondres(std::string archivoEstaciones, std::string archivoConexiones)
{
	ArchivoEstaciones = archivoEstaciones;
	ArchivoConexiones = archivoConexiones;
}

void CargarLondres::Cargar(Grafo& londres)
{
	// recorrer las estaciones y agregarlas como vertices
	// recorres las conexiones y agregarlas como aristas

	LectorCSV lectorEstaciones= LectorCSV(ArchivoEstaciones);
	LectorCSV lectorConexiones = LectorCSV(ArchivoConexiones);

	std::vector<std::vector<std::string> > dataEstaciones = lectorEstaciones.getData();
	std::vector<std::vector<std::string> > dataConexiones = lectorConexiones.getData();

	for (std::vector<std::string> vec : dataEstaciones) {
		londres.AgregarVertice(std::stoi(vec[0]), vec[1], std::stod(vec[2]), std::stod(vec[3]));
	}

	for (std::vector<std::string> vect : dataConexiones) {
		londres.AgregarArista(std::stoi(vect[0]), std::stoi(vect[1]), std::stoi(vect[3]));
	}
}
