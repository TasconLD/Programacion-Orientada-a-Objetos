#ifndef MOTO_H
#define MOTO_H

#include "Vehiculo.h"

class Moto : public Vehiculo {
public:
    // Constructor
    Moto(const std::string& placa, const std::string& marca, 
         const std::string& color, int horaEntrada);
    
    // Calcular tarifa basada en la hora de salida
    double calcularTarifa(int horaSalida) const override;
    
    // Retornar tipo de vehículo
    std::string getTipo() const override;
};

#endif // MOTO_H
