#include "BloodDatabase.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <limits>
#include <stdexcept>
#include <cctype>
#include <algorithm>

using namespace std;

// Muestra la lista de provincias para seleccionar
void BloodDatabase::displayProvinces() {
    std::cout << "Elige el departamento:\n";
    std::cout << "1. Putumayo\n";
    std::cout << "2. Cauca\n";
    std::cout << "3. Valle del Cauca\n";
    std::cout << "4. Amazonas\n";
    std::cout << "5. Risaralda\n";
    std::cout << "6. Antioquia\n";
    std::cout << "7. Norte de Santander\n";
}

// Limpia la consola (para Windows)
void BloodDatabase::clearConsole() {
#ifdef _WIN32
    system("cls");
#else
    //   system("clear");  // Para Linux/Mac, descomentando si es necesario
#endif
}

// Pausa y espera que el usuario presione una tecla
void BloodDatabase::waitForKeyPress() {
    std::cout << "Presiona cualquier tecla para continuar...";
    std::cin.ignore();
    std::cin.get();
}

// Método para pedir y validar la entrada numérica del usuario
int BloodDatabase::getValidatedInput(const std::string& prompt) {
    int value;
    std::string input;
    while (true) {
        std::cout << prompt;
        std::getline(std::cin, input);
        try {
            if (!std::all_of(input.begin(), input.end(), ::isdigit)) {
                throw std::invalid_argument("La entrada contiene caracteres no numéricos");
            }
            value = std::stoi(input);
            break; // si la conversión es exitosa, salir del bucle
        } catch (const std::invalid_argument& e) {
            std::cout << "Entrada no válida: " << e.what() << ". Por favor ingrese un número válido." << std::endl;
        } catch (const std::out_of_range&) {
            std::cout << "Entrada fuera de rango. Por favor ingrese un número válido." << std::endl;
        }
    }
    return value;
}

// Permite al usuario ingresar los detalles de un donante
void BloodDatabase::getDonorDetails() {
    clearConsole();
    std::cout << "Ingrese los detalles del donante\n";

    Donor newDonor;
    newDonor.donorId = getValidatedInput("Id: ");
    std::cout << "Nombre: ";
    std::getline(std::cin, newDonor.name);
    std::cout << "Dirección: ";
    std::getline(std::cin, newDonor.address);

    displayProvinces();
    newDonor.district = getValidatedInput("departamento (ingrese el número correspondiente): ");
    std::cout << "Tipo de sangre: ";
    std::getline(std::cin, newDonor.bloodType);
    newDonor.number = getValidatedInput("Número: ");

    donors.push_back(newDonor);
}

// Escribe los datos del último donante al archivo
void BloodDatabase::writeDataToFile() {
    std::ofstream outfile(fileName, std::ios::app);

    if (!outfile) {
        std::cout << "Error al abrir el archivo para escribir." << std::endl;
        return;
    }

    Donor newDonor = donors.back();
    outfile << newDonor.donorId << ",    " << newDonor.name << ",    " << newDonor.address << ",    " << newDonor.district << ",    " << newDonor.bloodType << ",    " << newDonor.number << std::endl;

    outfile.close();
}

// Permite buscar y mostrar los donantes de un departamento
void BloodDatabase::searchAndDisplay() const {
    clearConsole();
    displayProvinces();
    int provinceName = getValidatedInput("Ingrese el número de la departamento: ");

    std::cout << "Ingrese la dirección (dejar en blanco para omitir): ";
    std::string addressFilter;
    std::getline(std::cin, addressFilter);

    std::cout << "Ingrese el tipo de sangre (dejar en blanco para omitir): ";
    std::string bloodTypeFilter;
    std::getline(std::cin, bloodTypeFilter);

    std::ifstream inFile(fileName);

    if (!inFile) {
        std::cout << "Error al abrir el archivo para leer." << std::endl;
        return;
    }

    std::vector<Donor> donors;
    std::string line;
    bool found = false;

    while (std::getline(inFile, line)) {
        Donor d = Donor::parseLine(line);
        bool match = d.district == provinceName &&
            (addressFilter.empty() || d.address.find(addressFilter) != std::string::npos) &&
            (bloodTypeFilter.empty() || d.bloodType == bloodTypeFilter);

        if (match) {
            donors.push_back(d);
            found = true;
        }
    }

    if (!found) {
        std::cout << "No se encontraron personas de la departamento " << provinceName;
        if (!addressFilter.empty()) {
            std::cout << " con dirección que contiene '" << addressFilter << "'\n";
        }
        if (!bloodTypeFilter.empty()) {
            std::cout << " y tipo de sangre '" << bloodTypeFilter << "'\n";
        }
        std::cout << "." << std::endl;
    } else {
        std::cout << "Personas de la departamento " << provinceName;
        if (!addressFilter.empty()) {
            std::cout << " con dirección que contiene '" << addressFilter << "'\n";
        }
        if (!bloodTypeFilter.empty()) {
            std::cout << " y tipo de sangre '" << bloodTypeFilter << "'\n";
        }
        std::cout << ":" << std::endl;
        for (const auto& d : donors) {
            std::cout << "Nombre: " << d.name << std::endl;
            std::cout << "Dirección: " << d.address << std::endl;
            std::cout << "Tipo de sangre: " << d.bloodType << std::endl;
            std::cout << "Número: " << d.number << std::endl;
            std::cout << "----------------------------------------\n";
        }
    }
}

// Elimina un donante por nombre (si existe)
void BloodDatabase::deleteDonor(const std::string& donorName) {
    auto it = std::find_if(donors.begin(), donors.end(),
        [&donorName](const Donor& d) { return d.name == donorName; });

    if (it != donors.end()) {
        donors.erase(it);
        std::cout << "Donante " << donorName << " eliminado correctamente.\n";
    } else {
        std::cout << "Donante no encontrado.\n";
    }
}

