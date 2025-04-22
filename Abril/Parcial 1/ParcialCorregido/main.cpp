#include <iostream>
#include <string>
#include <limits>
#include <memory>
#include "Vehiculo.h"
#include "Auto.h"
#include "Camion.h"
#include "Moto.h"
#include "Parqueadero.h"

// Función para limpiar el buffer de entrada
void limpiarBufferEntrada() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// Función para validar entrada de hora (0-23)
int obtenerHoraValida() {
    int hora;
    while (true) {
        std::cin >> hora;
        if (std::cin.fail() || hora < 0 || hora > 23) {
            std::cout << "Hora inválida. Por favor ingrese un valor entre 0 y 23: ";
            limpiarBufferEntrada();
        } else {
            limpiarBufferEntrada();
            return hora;
        }
    }
}

// Función para mostrar el menú
void mostrarMenu() {
    std::cout << "\n===== SISTEMA DE GESTIÓN DE PARQUEADERO =====\n";
    std::cout << "1. Ingresar Vehículo\n";
    std::cout << "2. Retirar Vehículo\n";
    std::cout << "3. Buscar Vehículo por Placa\n";
    std::cout << "4. Mostrar Ingresos por Tipo de Vehículo\n";
    std::cout << "5. Mostrar Todos los Vehículos\n";
    std::cout << "0. Salir\n";
    std::cout << "Ingrese su opción: ";
}

// Función para agregar un vehículo
void agregarVehiculo(Parqueadero& parqueadero) {
    std::string placa, marca, color;
    int tipoVehiculo, horaEntrada;
    
    std::cout << "\n===== INGRESAR VEHÍCULO =====\n";
    
    // Obtener tipo de vehículo
    std::cout << "Tipo de Vehículo (1: Auto, 2: Camión, 3: Moto): ";
    while (true) {
        std::cin >> tipoVehiculo;
        if (std::cin.fail() || tipoVehiculo < 1 || tipoVehiculo > 3) {
            std::cout << "Opción inválida. Por favor ingrese 1, 2, o 3: ";
            limpiarBufferEntrada();
        } else {
            limpiarBufferEntrada();
            break;
        }
    }
    
    // Obtener placa
    std::cout << "Placa: ";
    std::getline(std::cin, placa);
    
    // Verificar si ya existe un vehículo con la misma placa
    if (parqueadero.buscarVehiculo(placa) != nullptr) {
        std::cout << "¡Ya existe un vehículo con esta placa en el parqueadero!\n";
        return;
    }
    
    // Obtener otros detalles del vehículo
    std::cout << "Marca: ";
    std::getline(std::cin, marca);
    
    std::cout << "Color: ";
    std::getline(std::cin, color);
    
    std::cout << "Hora de Entrada (0-23): ";
    horaEntrada = obtenerHoraValida();
    
    // Crear el tipo apropiado de vehículo
    std::unique_ptr<Vehiculo> vehiculo;
    
    switch (tipoVehiculo) {
        case 1:
            vehiculo.reset(new Auto(placa, marca, color, horaEntrada));
            break;
        case 2:
            vehiculo.reset(new Camion(placa, marca, color, horaEntrada));
            break;
        case 3:
            vehiculo.reset(new Moto(placa, marca, color, horaEntrada));
            break;
    }
    
    // Agregar vehículo al parqueadero
    parqueadero.agregarVehiculo(std::move(vehiculo));
    std::cout << "¡Vehículo agregado exitosamente!\n";
}

// Función para retirar un vehículo
void retirarVehiculo(Parqueadero& parqueadero) {
    if (parqueadero.estaVacio()) {
        std::cout << "\nNo hay vehículos en el parqueadero.\n";
        return;
    }
    
    std::string placa;
    int horaSalida;
    
    std::cout << "\n===== RETIRAR VEHÍCULO =====\n";
    
    // Obtener placa
    std::cout << "Placa: ";
    std::getline(std::cin, placa);
    
    // Verificar si existe el vehículo
    const Vehiculo* vehiculo = parqueadero.buscarVehiculo(placa);
    if (vehiculo == nullptr) {
        std::cout << "¡No se encontró ningún vehículo con esta placa!\n";
        return;
    }
    
    // Obtener hora de salida
    std::cout << "Hora de Salida (0-23): ";
    horaSalida = obtenerHoraValida();
    
    // Retirar vehículo y calcular tarifa
    double tarifa = parqueadero.retirarVehiculo(placa, horaSalida);
    
    if (tarifa >= 0) {
        std::cout << "Vehículo retirado.\n";
        std::cout << "Tarifa de Estacionamiento: $" << tarifa << std::endl;
    } else {
        std::cout << "¡Error al retirar el vehículo!\n";
    }
}

// Función para buscar un vehículo por placa
void buscarVehiculo(const Parqueadero& parqueadero) {
    if (parqueadero.estaVacio()) {
        std::cout << "\nNo hay vehículos en el parqueadero.\n";
        return;
    }
    
    std::string placa;
    
    std::cout << "\n===== BUSCAR VEHÍCULO =====\n";
    
    // Obtener placa
    std::cout << "Placa: ";
    std::getline(std::cin, placa);
    
    // Buscar vehículo
    const Vehiculo* vehiculo = parqueadero.buscarVehiculo(placa);
    
    if (vehiculo != nullptr) {
        std::cout << "\n¡Vehículo encontrado!\n";
        vehiculo->mostrarInfo();
    } else {
        std::cout << "¡No se encontró ningún vehículo con esta placa!\n";
    }
}

int main() {
    Parqueadero parqueadero;
    int opcion;
    
    std::cout << "Bienvenido al Sistema de Gestión de Parqueadero\n";
    
    while (true) {
        mostrarMenu();
        
        // Obtener opción del usuario
        if (!(std::cin >> opcion)) {
            std::cout << "Entrada inválida. Por favor ingrese un número.\n";
            limpiarBufferEntrada();
            continue;
        }
        limpiarBufferEntrada();
        
        // Procesar opción del usuario
        switch (opcion) {
            case 0:
                std::cout << "Gracias por usar el Sistema de Gestión de Parqueadero. ¡Hasta pronto!\n";
                return 0;
            
            case 1:
                agregarVehiculo(parqueadero);
                break;
            
            case 2:
                retirarVehiculo(parqueadero);
                break;
            
            case 3:
                buscarVehiculo(parqueadero);
                break;
            
            case 4:
                parqueadero.mostrarIngresos();
                break;
            
            case 5:
                parqueadero.mostrarTodosLosVehiculos();
                break;
            
            default:
                std::cout << "Opción inválida. Por favor intente de nuevo.\n";
        }
    }
    
    return 0;
}
