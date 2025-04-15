#ifndef DONOR_H
#define DONOR_H

#include <string>

class Donor {
public:
    // Setters y Getters para cada atributo privado
    void setDonorId(int id) { donorId = id; }
    int getDonorId() const { return donorId; }

    void setName(const std::string& n) { name = n; }
    std::string getName() const { return name; }

    void setAddress(const std::string& a) { address = a; }
    std::string getAddress() const { return address; }

    void setDistrict(int d) { district = d; }
    int getDistrict() const { return district; }

    void setBloodType(const std::string& b) { bloodType = b; }
    std::string getBloodType() const { return bloodType; }

    void setNumber(int n) { number = n; }
    int getNumber() const { return number; }

    // Método para mostrar detalles del donante
    void donorDetails() const;

    // Método estático para analizar una línea de texto y convertirla en un objeto Donor
    static Donor parseLine(const std::string& line);

private:
    // Atributos privados para el donante
    int donorId, district, number;
    std::string name, address, bloodType;

    // Método privado para limpiar espacios extra
    static std::string trim(const std::string& str);
};

#endif // DONOR_H

