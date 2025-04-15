#include "BloodDatabase.h"
#include <iostream>
#include <fstream>
#include <limits>

// Método para registrar los detalles del donante
void BloodDatabase::getDonorDetails() {
    std::string name, bloodType;
    int age;

    // Se solicita el nombre del donante
    std::cout << "Ingrese el nombre del donante: ";
    std::getline(std::cin, name);

    // Se solicita el tipo de sangre
    std::cout << "Ingrese el tipo de sangre: ";
    std::getline(std::cin, bloodType);

    // Se solicita la edad del donante
    std::cout << "Ingrese la edad del donante: ";
    std::cin >> age;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Limpiar buffer de entrada

    // Se crea un objeto Donor con los datos proporcionados
    Donor newDonor(name, bloodType, age);

    // Se añade el nuevo donante al vector de donantes
    donors.push_back(newDonor);
}

// Método para guardar los datos de los donantes en un archivo de texto
void BloodDatabase::writeDataToFile() {
    std::ofstream outFile("donors.txt"); // Archivo de salida

    // Escribimos cada donante en el archivo
    for (const Donor& donor : donors) {
        outFile << donor.getName() << "\n" 
                << donor.getBloodType() << "\n" 
                << donor.getAge() << "\n";
    }

    outFile.close(); // Cerramos el archivo
}

// Método para buscar y mostrar los detalles de un donante por nombre
void BloodDatabase::searchAndDisplay() const {
    std::string name;
    std::cout << "Ingrese el nombre del donante a buscar: ";
    std::getline(std::cin, name);

    bool found = false;
    // Recorremos la lista de donantes para encontrar el que coincide con el nombre
    for (const Donor& donor : donors) {
        if (donor.getName() == name) {
            donor.printDonorDetails(); // Si lo encontramos, mostramos sus detalles
            found = true;
            break;
        }
    }

    // Si no se encuentra al donante, mostramos un mensaje
    if (!found) {
        std::cout << "Donante no encontrado." << std::endl;
    }
}

// Método para eliminar un donante de la base de datos por nombre
void BloodDatabase::deleteDonor(const std::string& donorName) {
    // Buscamos y eliminamos al donante con el nombre dado
    auto it = std::remove_if(donors.begin(), donors.end(), 
        [&donorName](const Donor& donor) { return donor.getName() == donorName; });

    // Si encontramos al donante, lo eliminamos
    if (it != donors.end()) {
        donors.erase(it, donors.end());
        std::cout << "Donante eliminado correctamente." << std::endl;
    } else {
        std::cout << "Donante no encontrado." << std::endl;
    }
}

// Método para mostrar todos los donantes registrados en la base de datos
void BloodDatabase::showAllDonors() const {
    if (donors.empty()) {
        std::cout << "No hay donantes registrados." << std::endl;
    } else {
        std::cout << "Lista de Donantes Registrados:" << std::endl;
        // Recorremos el vector de donantes y mostramos sus detalles
        for (const Donor& donor : donors) {
            donor.printDonorDetails(); // Mostramos los detalles del donante
        }
    }
}

// Método para limpiar la consola de la pantalla
void BloodDatabase::clearConsole() {
    // Dependiendo del sistema operativo, se usa un comando diferente para limpiar la pantalla
    // Para Windows:
    std::system("cls");
    // Para sistemas Unix/Linux:
    // std::system("clear");
}

// Método para esperar a que el usuario presione una tecla antes de continuar
void BloodDatabase::waitForKeyPress() {
    std::cout << "Presiona cualquier tecla para continuar...";
    std::cin.get(); // Espera por la entrada de una tecla
}
