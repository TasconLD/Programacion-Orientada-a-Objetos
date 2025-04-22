#ifndef CAMION_H
#define CAMION_H

#include "Vehiculo.h"

class Camion : public Vehiculo {
public:
    // Constructor
    Camion(const std::string& placa, const std::string& marca, 
          const std::string& color, int horaEntrada);
    
    // Calcular tarifa basada en la hora de salida
    double calcularTarifa(int horaSalida) const override;
    
    // Retornar tipo de vehículo
    std::string getTipo() const override;
};

#endif // CAMION_H
