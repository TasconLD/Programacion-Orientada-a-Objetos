#include "Vehiculo.h"
#include <iostream>

// Constructor
Vehiculo::Vehiculo(const std::string& placa, const std::string& marca, 
                 const std::string& color, int horaEntrada)
    : placa(placa), marca(marca), color(color), horaEntrada(horaEntrada) {}

// Destructor
Vehiculo::~Vehiculo() {}

// Implementación de Getters
std::string Vehiculo::getPlaca() const {
    return placa;
}

std::string Vehiculo::getMarca() const {
    return marca;
}

std::string Vehiculo::getColor() const {
    return color;
}

int Vehiculo::getHoraEntrada() const {
    return horaEntrada;
}

// Mostrar información del vehículo
void Vehiculo::mostrarInfo() const {
    std::cout << "Tipo: " << getTipo() << std::endl;
    std::cout << "Placa: " << placa << std::endl;
    std::cout << "Marca: " << marca << std::endl;
    std::cout << "Color: " << color << std::endl;
    std::cout << "Hora de Entrada: " << horaEntrada << std::endl;
}
