#include "Moto.h"
#include <algorithm>

// Constructor
Moto::Moto(const std::string& placa, const std::string& marca, 
           const std::string& color, int horaEntrada)
    : Vehiculo(placa, marca, color, horaEntrada) {}

// Calcular tarifa basada en la hora de salida
double Moto::calcularTarifa(int horaSalida) const {
    // Calcular duración del estacionamiento en horas
    int horasEstacionado = horaSalida - horaEntrada;
    
    // Manejar caso donde el vehículo se queda durante la noche
    if (horasEstacionado < 0) {
        horasEstacionado += 24;
    }
    
    // Calcular tarifa según la tabla proporcionada
    double tarifa = 0.0;
    if (horasEstacionado <= 1) {
        // Primera hora o fracción: 2,000
        tarifa = 2000;
    } else if (horasEstacionado <= 12) {
        // De 2 a 12 horas: 2,000 para la primera hora + 1,000 por cada hora adicional
        tarifa = 2000 + (horasEstacionado - 1) * 1000;
    } else {
        // Más de 12 horas: 2,000 para la primera hora + 1,000 para las horas 2-12 + 500 por cada hora adicional
        tarifa = 2000 + 11 * 1000 + (horasEstacionado - 12) * 500;
    }
    
    return tarifa;
}

// Retornar tipo de vehículo
std::string Moto::getTipo() const {
    return "Moto";
}
