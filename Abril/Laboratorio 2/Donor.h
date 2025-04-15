#ifndef DONOR_H
#define DONOR_H

#include <string>

class Donor {
public:
    // Atributos públicos, pero pueden ser modificados según el encapsulamiento
    int donorId, district, number;
    std::string name, address, bloodType;

    // Método que muestra los detalles del donante
    void donorDetails() const;

    // Método estático para parsear una línea de texto y convertirla en un objeto Donor
    static Donor parseLine(const std::string& line);

private:
    // Método privado para eliminar los espacios en blanco antes y después de un string
    static std::string trim(const std::string& str);
};

#endif // DONOR_H

