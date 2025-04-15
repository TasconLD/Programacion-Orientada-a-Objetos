#include "Donor.h"
#include <regex> // Para las expresiones regulares
#include <iostream>
#include <sstream>

using namespace std;

// Método para validar el nombre del donante
bool Donor::validateName(const string& name) {
    // Expresión regular para permitir letras y espacios
    regex nameRegex("^[A-Za-záéíóúÁÉÍÓÚ ]+$");
    return regex_match(name, nameRegex);
}

// Método para validar el tipo de sangre
bool Donor::validateBloodType(const string& bloodType) {
    // Expresión regular para validar tipos de sangre como A+, B-, AB+, O-
    regex bloodTypeRegex("^(A|B|AB|O)(\\+|\\-)$");
    return regex_match(bloodType, bloodTypeRegex);
}

// Método para validar el número de teléfono
bool Donor::validatePhoneNumber(int number) {
    // Convertir el número en cadena para validar con regex
    string phoneNumber = to_string(number);
    regex phoneRegex("^\\d{10}$"); // Verificar que tenga exactamente 10 dígitos
    return regex_match(phoneNumber, phoneRegex);
}

Donor Donor::parseLine(const string& line) {
    stringstream ss(line);
    Donor donor;

    // Lectura del donante desde la línea
    string id, name, address, district, bloodType, number;
    getline(ss, id, ',');
    getline(ss, name, ',');
    getline(ss, address, ',');
    getline(ss, district, ',');
    getline(ss, bloodType, ',');
    getline(ss, number);

    donor.donorId = stoi(id);
    donor.name = name;
    donor.address = address;
    donor.district = stoi(district);
    donor.bloodType = bloodType;
    donor.number = stoi(number);

    return donor;
}
