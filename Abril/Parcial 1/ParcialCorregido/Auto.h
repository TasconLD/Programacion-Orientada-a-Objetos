#ifndef AUTO_H
#define AUTO_H

#include "Vehiculo.h"

class Auto : public Vehiculo {
public:
    // Constructor
    Auto(const std::string& placa, const std::string& marca, 
        const std::string& color, int horaEntrada);
    
    // Calcular tarifa basada en la hora de salida
    double calcularTarifa(int horaSalida) const override;
    
    // Retornar tipo de vehículo
    std::string getTipo() const override;
};

#endif // AUTO_H
