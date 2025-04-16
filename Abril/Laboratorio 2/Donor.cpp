#include "Donor.h"

// Constructor que inicializa todos los atributos de un donante
Donor::Donor(string name, string bloodType, string id, string phone, string city)
    : name(name), bloodType(bloodType), id(id), phone(phone), city(city) {}

// Métodos que devuelven cada uno de los datos del donante

string Donor::getName() const {
    return name;
}

string Donor::getBloodType() const {
    return bloodType;
}

string Donor::getId() const {
    return id;
}

string Donor::getPhone() const {
    return phone;
}

string Donor::getCity() const {
    return city;
}


string Donor::getId() const {
    return id;
}

string Donor::getPhone() const {
    return phone;
}
