#include "Donor.h"
#include <sstream>
#include <iostream>
#include <algorithm>

// Muestra los detalles del donante
void Donor::donorDetails() const {
    std::cout << "Nombre del donante: " << name << std::endl;
    std::cout << "Distrito del donante: " << district << std::endl;
    std::cout << "Tipo de sangre del donante: " << bloodType << std::endl;
}

// Convierte una línea del archivo de texto en un objeto Donor
Donor Donor::parseLine(const std::string& line) {
    Donor d;
    std::stringstream ss(line);
    std::string token;

    // Parsear cada parte de la línea y asignar valores a los atributos
    getline(ss, token, ','); d.donorId = std::stoi(trim(token));
    getline(ss, token, ','); d.name = trim(token);
    getline(ss, token, ','); d.address = trim(token);
    getline(ss, token, ','); d.district = std::stoi(trim(token));
    getline(ss, token, ','); d.bloodType = trim(token);
    getline(ss, token, ','); d.number = std::stoi(trim(token));

    return d;
}

// Elimina los espacios en blanco antes y después de un string
std::string Donor::trim(const std::string& str) {
    size_t first = str.find_first_not_of(' ');
    if (first == std::string::npos) return "";  // Si no hay caracteres, retornar vacío
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, (last - first + 1));
}
