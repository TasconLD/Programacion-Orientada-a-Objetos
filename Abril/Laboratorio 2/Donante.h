    /*Proyecto: BloodDatabase (Adaptado)
    Curso: Fundamentos de Programación Orientada a Objetos (FPOO)
    Universidad del Valle
    Estudiantes: Laura Dayana Tascon Velasco - 2438545
                 Daniel Escobar Escobar - 2437924
                 Elbert Moreno Castillo - 2436884
                 Jesus Giovanny Mora Segura -  2439620
    Fecha: Abril 2025
    */

#ifndef DONANTE_H
#define DONANTE_H

#include <string>
#include "sangre.h"

//Clase del donante
class Donante {
private:
    std::string cedula;
    std::string nombre;
    std::string direccion;
    Sangre tipoSangre;
    std::string telefono;

public:

     //Constructor
    Donante();

    Donante(const std::string& cedula, const std::string& nombre,
            const std::string& direccion, const Sangre& tipoSangre,
            const std::string& telefono);

    // Getters y setters
    std::string getCedula() const;
    void setCedula(const std::string& cedula);

    std::string getNombre() const;
    void setNombre(const std::string& nombre);

    std::string getDireccion() const;
    void setDireccion(const std::string& direccion);

    Sangre getTipoSangre() const;
    void setTipoSangre(const Sangre& tipoSangre);

    std::string getTelefono() const;
    void setTelefono(const std::string& telefono);


     //Validaciones de datos utilizando expresiones regulares
    static bool validarCedula(const std::string& cedula);
    static bool validarNombre(const std::string& nombre);
    static bool validarDireccion(const std::string& direccion);
    static bool validarTelefono(const std::string& telefono);
};

#endif // DONANTE_H
