#include "Parqueadero.h"
#include "Auto.h"
#include "Camion.h"
#include "Moto.h"
#include <iostream>
#include <iomanip>
#include <algorithm>

// Constructor
Parqueadero::Parqueadero() 
    : ingresoAutos(0.0), ingresoCamiones(0.0), ingresoMotos(0.0) {}

// Agregar un vehículo al parqueadero
void Parqueadero::agregarVehiculo(std::unique_ptr<Vehiculo> vehiculo) {
    vehiculos.push_back(std::move(vehiculo));
}

// Retirar un vehículo del parqueadero y calcular tarifa
double Parqueadero::retirarVehiculo(const std::string& placa, int horaSalida) {
    auto it = std::find_if(vehiculos.begin(), vehiculos.end(), 
                          [&placa](const std::unique_ptr<Vehiculo>& v) {
                              return v->getPlaca() == placa;
                          });
    
    if (it == vehiculos.end()) {
        return -1.0; // Vehículo no encontrado
    }
    
    // Calcular tarifa
    double tarifa = (*it)->calcularTarifa(horaSalida);
    
    // Actualizar ingresos basados en el tipo de vehículo
    std::string tipoVehiculo = (*it)->getTipo();
    if (tipoVehiculo == "Auto") {
        ingresoAutos += tarifa;
    } else if (tipoVehiculo == "Camion") {
        ingresoCamiones += tarifa;
    } else if (tipoVehiculo == "Moto") {
        ingresoMotos += tarifa;
    }
    
    // Retirar vehículo del parqueadero
    vehiculos.erase(it);
    
    return tarifa;
}

// Buscar un vehículo por placa
const Vehiculo* Parqueadero::buscarVehiculo(const std::string& placa) const {
    auto it = std::find_if(vehiculos.begin(), vehiculos.end(), 
                          [&placa](const std::unique_ptr<Vehiculo>& v) {
                              return v->getPlaca() == placa;
                          });
    
    if (it == vehiculos.end()) {
        return nullptr; // Vehículo no encontrado
    }
    
    return it->get();
}

// Mostrar ingresos por tipo de vehículo
void Parqueadero::mostrarIngresos() const {
    std::cout << "\n===== INFORME DE INGRESOS =====\n";
    std::cout << std::fixed << std::setprecision(0);
    std::cout << "Ingresos Autos     : $" << ingresoAutos << std::endl;
    std::cout << "Ingresos Camiones  : $" << ingresoCamiones << std::endl;
    std::cout << "Ingresos Motos     : $" << ingresoMotos << std::endl;
    std::cout << "Ingresos Totales   : $" << ingresoAutos + ingresoCamiones + ingresoMotos << std::endl;
    std::cout << "===============================\n";
}

// Mostrar todos los vehículos en el parqueadero
void Parqueadero::mostrarTodosLosVehiculos() const {
    if (vehiculos.empty()) {
        std::cout << "\nNo hay vehículos en el parqueadero.\n";
        return;
    }
    
    std::cout << "\n===== VEHÍCULOS ACTUALMENTE ESTACIONADOS =====\n";
    for (const auto& vehiculo : vehiculos) {
        std::cout << "\n---------------------------\n";
        vehiculo->mostrarInfo();
    }
    std::cout << "\n===========================================\n";
}

// Verificar si el parqueadero está vacío
bool Parqueadero::estaVacio() const {
    return vehiculos.empty();
}
