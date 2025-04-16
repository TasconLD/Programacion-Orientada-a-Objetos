#ifndef BLOODDATABASE_H
#define BLOODDATABASE_H

#include "Donor.h"
#include <vector>
#include <string>

class BloodDatabase {
private:
    std::vector<Donor> donors; // Lista para almacenar los donantes

    // Métodos privados
    void readDataFromFile();           // Lee datos desde el archivo
    void validateInput(std::string& input, const std::string& pattern, const std::string& errorMessage); // Validación con regex

public:
    BloodDatabase(); // Constructor

    // Funciones principales del sistema
    void getDonorDetails();           // Solicita los datos del donante
    void writeDataToFile() const;     // Escribe los datos al archivo
    void searchAndDisplay() const;    // Busca y muestra datos del donante
    void deleteDonor(const std::string& name); // Elimina un donante por el nombre
    void displayAllDonors() const;    // Muestra todos los donantes registrados

    // Utilidades estáticas
    static void clearConsole();       // Limpia la consola
    static void waitForKeyPress();    // Espera que el usuario presione una tecla
};

#endif
