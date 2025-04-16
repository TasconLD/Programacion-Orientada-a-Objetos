#ifndef DONOR_H
#define DONOR_H

#include <string>
using namespace std;

// Clase del donante de sangre
class Donor {
private:
    // Atributos privados para aplicar el encapsulamiento
    string name;
    string bloodType;
    string id;
    string phone;

public:
    // Constructor que recibe todos los datos del donante
    Donor(string name, string bloodType, string id, string phone);

    // Métodos getters para acceder a los datos del donante
    string getName() const;
    string getBloodType() const;
    string getId() const;
    string getPhone() const;
};

#endif

