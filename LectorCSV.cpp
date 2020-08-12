#include "LectorCSV.h"

LectorCSV::LectorCSV(std::string archivo, std::string delimitador)
{
	Archivo = archivo;
	Delimitador = delimitador;
}

std::vector<std::vector<std::string>> LectorCSV::getData()
{

    // TODO: leer archivo CSV y devolver vector de vector de strings
    // lean linear por linea y agreguen al vector resultado
    // deben separar las lineas por Delimitador para obtener las columnas

    std::ifstream archivo(Archivo);
    std::vector<std::vector<std::string> > resultado;
    std::string line = "";
    while (getline(archivo, line)) {
        std::vector<std::string> vec;
        boost::algorithm::split(vec, line, boost::is_any_of(Delimitador));
        resultado.push_back(vec);
    }
    archivo.close();

    return resultado;
}
