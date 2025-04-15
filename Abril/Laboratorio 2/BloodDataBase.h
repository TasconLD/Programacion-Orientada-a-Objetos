#ifndef BLOODDATABASE_H
#define BLOODDATABASE_H

#include <vector>
#include "Donor.h"
#include <string>
#include <iostream>

class BloodDatabase {
private:
    // Vector que almacena los donantes
    std::vector<Donor> donors;
    
public:
    // Métodos públicos para interactuar con la base de datos de donantes
    void getDonorDetails(); // Método para ingresar los detalles del donante
    void writeDataToFile(); // Método para guardar los datos en un archivo
    void searchAndDisplay() const; // Método para buscar y mostrar detalles de un donante
    void deleteDonor(const std::string& donorName); // Método para eliminar un donante
    void showAllDonors() const; // Método para mostrar todos los donantes registrados

    // Métodos estáticos
    static void clearConsole(); // Método para limpiar la pantalla de la consola
    static void waitForKeyPress(); // Método para esperar que el usuario presione una tecla
};

#endif // BLOODDATABASE_H

