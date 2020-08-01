#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include <string>
#include <algorithm>

// Esta libreria boost les puede ser util para partir un string en varios usando un delimitador
#include <boost/algorithm/string.hpp>
class LectorCSV
{
private:
	std::string Archivo;
	std::string Delimitador;
public:
	LectorCSV(std::string archivo, std::string delimitador = ",");
	std::vector<std::vector<std::string> > getData();
};

