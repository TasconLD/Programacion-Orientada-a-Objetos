    /*Proyecto: BloodDatabase (Adaptado)
    Curso: Fundamentos de Programación Orientada a Objetos (FPOO)
    Universidad del Valle
    Estudiantes: Laura Dayana Tascon Velasco - 2438545
                 Daniel Escobar Escobar - 2437924
                 Elbert Leandro Moreno Castillo - 2436884
                 Jesus Giovanny Mora Segura -  2439620
    Fecha: Abril 2025
    */

#ifndef SANGRE_H
#define SANGRE_H

#include <string>
#include <vector>

//Clase de la sangre del donante
class Sangre {
private:
    std::string tipo; // Tipo de sangre (A+, A-, B+, B-, AB+, AB-, O+, O-)

public:

    //Constructor 
    Sangre();

    Sangre(const std::string& tipo);


     //Obtiene el tipo de sangre
    std::string getTipo() const;


    //Establece el tipo de sangre
    void setTipo(const std::string& tipo);

    //Verifica si el tipo de sangre es válido
    static bool esValido(const std::string& tipo);

    //Obtiene todos los tipos de sangre válidos
    static std::vector<std::string> getTiposValidos();
};

#endif // SANGRE_H
