#include "CargarLondres.h"

CargarLondres::CargarLondres(std::string archivoEstaciones, std::string archivoConexiones)
{
	ArchivoEstaciones = archivoEstaciones;
	ArchivoConexiones = archivoConexiones;
}

void CargarLondres::Cargar(Grafo& londres)
{
	LectorCSV lectorEstaciones= LectorCSV(ArchivoEstaciones);
	LectorCSV lectorConexiones = LectorCSV(ArchivoConexiones);


	// recorrer las estaciones y agregarlas como vertices
	// recorres las conexiones y agregarlas como aristas

}
