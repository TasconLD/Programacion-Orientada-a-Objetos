#ifndef VEHICULO_H
#define VEHICULO_H

#include <string>
#include "Sangre.h"
using namespace std;

//Clase del donante
class Vehiculo {
private:
    string placa;
    string marca;
    string color;
    

public:

     //Constructor
    Vehiculo();

    Vehiculo(const string& marca, const string& marca,
            const string& color);

    // Getters y setters
    string getPlaca() const;
    void setPlaca(const string& placa);

    string getMarca() const;
    void setMarca(const string& Marca);

    string getColor() const;
    void setColor(const string& color);



     //Validaciones de datos utilizando expresiones regulares
    static bool validarPlaca(const string& placa);
    static bool validarMarca(const string& marca);
    static bool validarColor(const string& color);
    
};

#endif // DONANTE_H
