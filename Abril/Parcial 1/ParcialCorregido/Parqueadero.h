#ifndef PARQUEADERO_H
#define PARQUEADERO_H

#include <vector>
#include <memory>
#include "Vehiculo.h"

class Parqueadero {
private:
    std::vector<std::unique_ptr<Vehiculo>> vehiculos;
    double ingresoAutos;
    double ingresoCamiones;
    double ingresoMotos;
    
public:
    // Constructor
    Parqueadero();
    
    // Agregar un vehículo al parqueadero
    void agregarVehiculo(std::unique_ptr<Vehiculo> vehiculo);
    
    // Retirar un vehículo del parqueadero y calcular tarifa
    double retirarVehiculo(const std::string& placa, int horaSalida);
    
    // Buscar un vehículo por placa
    const Vehiculo* buscarVehiculo(const std::string& placa) const;
    
    // Mostrar ingresos por tipo de vehículo
    void mostrarIngresos() const;
    
    // Mostrar todos los vehículos en el parqueadero
    void mostrarTodosLosVehiculos() const;
    
    // Verificar si el parqueadero está vacío
    bool estaVacio() const;
};

#endif // PARQUEADERO_H
