

#ifndef VEHICULO_H
#define VEHICULO_H

#include <string>
#include "Auto.h"
using namespace std;

//Clase del donante
class Vehiculo {
private:
    Auto tipoAuto;
    string placa;
    string marca;
    string color;
    string hora;
    

public:

     //Constructor
    Vehiculo();

    Vehiculo(const string& marca, const string& marca,
            const string& color, const string& hora, const Auto& tipoAuto );

    // Getters y setters
    string getPlaca() const;
    void setPlaca(const string& placa);

    string getMarca() const;
    void setMarca(const string& Marca);

    string getColor() const;
    void setColor(const string& color);

    string getHora() const;
    void setHora(const string& hora);

    string getTipoAuto() const;
    void setTipoAuto(const Auto& tipoAuto);


     //Validaciones de datos utilizando expresiones regulares
    static bool validarPlaca(const string& placa);
    static bool validarMarca(const string& marca);
    static bool validarColor(const string& color);
    static bool validarHora(const string& hora);
    
    
};

#endif // VEHICULO_H
