#ifndef DONOR_H
#define DONOR_H

#include <string>

/// 🧠 Esta clase representa a un Donante.
/// Antes, todos los datos estaban públicos (¡uy!), pero ahora los protegemos
/// con el concepto de ENCAPSULAMIENTO (solo accesibles con métodos especiales).
class Donor {
private:
    // 🔐 Estos son los atributos privados (nadie los puede tocar directamente)
    int donorId;
    int district;
    int number;
    std::string name;
    std::string address;
    std::string bloodType;

public:
    // 🧱 Constructor vacío (por si queremos crear un donante sin datos aún)
    Donor();

    // ✍️ SETTERS → sirven para modificar los datos de forma controlada
    void setDonorId(int id);
    void setName(const std::string& n);
    void setAddress(const std::string& addr);
    void setBloodType(const std::string& bt);
    void setDistrict(int dist);
    void setNumber(int num);

    // 👀 GETTERS → sirven para obtener los datos de manera segura
    int getDonorId() const;
    std::string getName() const;
    std::string getAddress() const;
    std::string getBloodType() const;
    int getDistrict() const;
    int getNumber() const;

    // 📋 Muestra por pantalla los datos del donante
    void donorDetails() const;

    // 🧩 Convierte una línea de texto (por ejemplo, desde un archivo) en un objeto Donor
    static Donor parseLine(const std::string& line);

private:
    // 🧽 Limpia espacios en blanco de un string (por ejemplo: "  Ana  " → "Ana")
    static std::string trim(const std::string& str);
};

#endif // DONOR_H
