#include "Donor.h"
#include <sstream>
#include <iostream>
#include <algorithm>

// Muestra detalles del donante en consola
void Donor::donorDetails() const {
    std::cout << "Nombre del donante: " << name << std::endl;
    std::cout << "Distrito del donante: " << district << std::endl;
    std::cout << "Tipo de sangre del donante: " << bloodType << std::endl;
}

// Método que toma una línea de texto con datos separados por coma
// y la convierte en un objeto Donor con sus datos asignados
Donor Donor::parseLine(const std::string& line) {
    Donor d;
    std::stringstream ss(line);
    std::string token;

    // Por cada dato, lo limpiamos con trim y lo convertimos si es necesario,
    // luego lo colocamos dentro del objeto usando setters
    getline(ss, token, ','); d.setDonorId(std::stoi(trim(token)));
    getline(ss, token, ','); d.setName(trim(token));
    getline(ss, token, ','); d.setAddress(trim(token));
    getline(ss, token, ','); d.setDistrict(std::stoi(trim(token)));
    getline(ss, token, ','); d.setBloodType(trim(token));
    getline(ss, token, ','); d.setNumber(std::stoi(trim(token)));

    return d;
}

// Método auxiliar para limpiar espacios en blanco al inicio y al final
std::string Donor::trim(const std::string& str) {
    size_t first = str.find_first_not_of(' ');
    if (first == std::string::npos) return "";
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, (last - first + 1));
}
