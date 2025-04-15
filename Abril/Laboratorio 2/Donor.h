#ifndef DONOR_H
#define DONOR_H

#include <iostream>
#include <string>
#include <regex> // Librería para expresiones regulares

class Donor {
public:
    int donorId;
    std::string name;
    std::string address;
    int district;
    std::string bloodType;
    int number;

    // Método para validar el nombre con regex
    static bool validateName(const std::string& name);
    
    // Método para validar el tipo de sangre con regex
    static bool validateBloodType(const std::string& bloodType);
    
    // Método para validar el número de teléfono con regex
    static bool validatePhoneNumber(int number);

    // Método para parsear la línea de texto del archivo
    static Donor parseLine(const std::string& line);
};

#endif // DONOR_H
