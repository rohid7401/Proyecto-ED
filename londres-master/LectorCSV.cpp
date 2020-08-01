#include "LectorCSV.h"

LectorCSV::LectorCSV(std::string archivo, std::string delimitador)
{
	Archivo = archivo;
	Delimitador = delimitador;
}

std::vector<std::vector<std::string>> LectorCSV::getData()
{
    std::ifstream archivo(Archivo);
    std::vector<std::vector<std::string> > resultado;
    // TODO: leer archivo CSV y devolver vector de vector de strings
    // lean linear por linea y agreguen al vector resultado
    // deben separar las lineas por Delimitador para obtener las columnas
    return resultado;
}
