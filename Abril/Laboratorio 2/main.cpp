#include "BloodDatabase.h"
#include "Donor.h"
#include <iostream>
#include <limits>
#include <string>
using namespace std;

int main() {
    std::string donorName;
    BloodDatabase database; // Creamos un objeto de la clase BloodDatabase para gestionar la base de datos
    int choice; // Variable para almacenar la elección del usuario

    // Ciclo principal del programa
    while (true) {
        BloodDatabase::clearConsole(); // Limpiar la consola al inicio de cada ciclo

        // Menú de opciones para el usuario
        std::cout <<
             " ░█████╗░██████╗░██╗░░░██╗███████╗  ██████╗░░█████╗░░░░░░██╗░█████╗░\n"
             " ██╔══██╗██╔══██╗██║░░░██║╚════██║  ██╔══██╗██╔══██╗░░░░░██║██╔══██╗\n"
             " ██║░░╚═╝██████╔╝██║░░░██║░░███╔═╝  ██████╔╝██║░░██║░░░░░██║███████║\n"
             " ██║░░██╗██╔══██╗██║░░░██║██╔══╝░░  ██╔══██╗██║░░██║██╗░░██║██╔══██║\n"
             " ╚█████╔╝██║░░██║╚██████╔╝███████╗  ██║░░██║╚█████╔╝╚█████╔╝██║░░██║\n"
             " ░╚════╝░╚═╝░░╚═╝░╚═════╝░╚══════╝  ╚═╝░░╚═╝░╚════╝░░╚════╝░╚═╝░░╚═╝\n";

        // Mostramos las opciones del menú
        std::cout << "1. Registrar donante\n";
        std::cout << "2. Buscar donante\n";
        std::cout << "3. Eliminar donante\n";
        std::cout << "4. Salir\n";
        std::cout << "5. Ver registro de donantes\n"; // Opción para ver todos los donantes
        std::cout << "Ingrese su elección: ";
        std::cin >> choice; // Se guarda la elección del usuario
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Limpiamos cualquier entrada extra

        switch (choice) {
        case 1:
            try {
                database.getDonorDetails(); // Llamamos a la función para ingresar un nuevo donante
                database.writeDataToFile(); // Guardamos los datos en un archivo
            } catch (const std::exception& e) {
                std::cout << "Error al registrar el donante: " << e.what() << std::endl;
            }
            break;
        case 2:
            try {
                database.searchAndDisplay(); // Llamamos a la función para buscar un donante
            } catch (const std::exception& e) {
                std::cout << "Error al buscar donantes: " << e.what() << std::endl;
            }
            break;
        case 3:
            std::cout << "Ingrese el nombre del donante a eliminar: ";
            std::getline(std::cin, donorName); // Obtenemos el nombre del donante a eliminar
            try {
                database.deleteDonor(donorName); // Llamamos a la función para eliminar un donante
            } catch (const std::exception& e) {
                std::cout << "Error al eliminar el donante: " << e.what() << std::endl;
            }
            BloodDatabase::waitForKeyPress(); // Esperamos a que el usuario presione una tecla
            break;
        case 4:
            std::cout << "Gracias por usar el Sistema de la Cruz Roja" << std::endl;
            return 0; // Terminamos el programa
        case 5:
            database.showAllDonors(); // Llamamos al método para mostrar todos los donantes
            BloodDatabase::waitForKeyPress(); // Esperamos a que el usuario presione una tecla
            break;
        default:
            std::cout << "Opción no válida. Inténtalo de nuevo.\n"; // Si la opción no es válida, mostramos un mensaje
            BloodDatabase::waitForKeyPress();
            break;
        }
    }
}
