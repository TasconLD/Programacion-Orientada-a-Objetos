#ifndef VEHICULO_H
#define VEHICULO_H

#include <string>

class Vehiculo {
protected:
    std::string placa;
    std::string marca;
    std::string color;
    int horaEntrada;
    
public:
    // Constructor
    Vehiculo(const std::string& placa, const std::string& marca, 
            const std::string& color, int horaEntrada);
    
    // Destructor virtual
    virtual ~Vehiculo();
    
    // Getters
    std::string getPlaca() const;
    std::string getMarca() const;
    std::string getColor() const;
    int getHoraEntrada() const;
    
    // Calcular tarifa basada en la hora de salida - será sobrescrito por las subclases
    virtual double calcularTarifa(int horaSalida) const = 0;
    
    // Retornar el tipo de vehículo como string - será sobrescrito por las subclases
    virtual std::string getTipo() const = 0;
    
    // Mostrar información del vehículo
    virtual void mostrarInfo() const;
};

#endif // VEHICULO_H
