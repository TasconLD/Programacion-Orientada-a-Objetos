#ifndef BLOODDATABASE_H
#define BLOODDATABASE_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Donor.h"

class BloodDatabase {
private:
    const std::string fileName = "data.txt";  // Nombre del archivo donde se guardan los datos
    std::vector<Donor> donors;  // Lista de donantes

    // Muestra las opciones de departamentos
    static void displayProvinces();

public:
    // Métodos estáticos para interactuar con la consola
    static void clearConsole();
    static void waitForKeyPress();
    static int getValidatedInput(const std::string& prompt);

    // Métodos para gestionar donantes y guardar los datos
    void getDonorDetails();
    void writeDataToFile();
    void searchAndDisplay() const;
    void deleteDonor(const std::string& donorName);
};

#endif // BLOODDATABASE_H
