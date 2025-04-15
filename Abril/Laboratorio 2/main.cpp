#include "BloodDatabase.h"
#include "Donor.h"
#include <iostream>
#include <limits>
#include <string>
using namespace std;

int main() {
    string donorName;
    BloodDatabase database;
    int choice;

    while (true) {
        BloodDatabase::clearConsole();

        cout << " ░█████╗░██████╗░██╗░░░██╗███████╗  ██████╗░░█████╗░░░░░░██╗░█████╗░\n"
             " ██╔══██╗██╔══██╗██║░░░██║╚════██║  ██╔══██╗██╔══██╗░░░░░██║██╔══██╗\n"
             " ██║░░╚═╝██████╔╝██║░░░██║░░███╔═╝  ██████╔╝██║░░██║░░░░░██║███████║\n"
             " ██║░░██╗██╔══██╗██║░░░██║██╔══╝░░  ██╔══██╗██║░░██║██╗░░██║██╔══██║\n"
             " ╚█████╔╝██║░░██║╚██████╔╝███████╗  ██║░░██║╚█████╔╝╚█████╔╝██║░░██║\n"
             " ░╚════╝░╚═╝░░╚═╝░╚═════╝░╚══════╝  ╚═╝░░╚═╝░╚════╝░░╚════╝░╚═╝░░╚═╝\n";

        cout << "1. Registrar donante\n";
        cout << "2. Buscar donante\n";
        cout << "3. Eliminar donante\n";
        cout << "4. Ver todos los donantes\n";  // Opción para ver todos los donantes
        cout << "5. Salir\n";
        cout << "Ingrese su elección: ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpiar el buffer

        switch (choice) {
            case 1:
                database.getDonorDetails();
                database.writeDataToFile();
                break;
            case 2:
                database.searchAndDisplay();
                break;
            case 3:
                cout << "Ingrese el nombre del donante a eliminar: ";
                getline(cin, donorName);
                database.deleteDonor(donorName);
                BloodDatabase::waitForKeyPress();
                break;
            case 4:
                database.showAllDonors(); // Llamar a la nueva función para mostrar todos los donantes
                break;
            case 5:
                cout << "Gracias por usar el Sistema de la Cruz Roja" << endl;
                return 0;
            default:
                cout << "Opción no válida. Inténtalo de nuevo.\n";
                BloodDatabase::waitForKeyPress();
                break;
        }
    }

    return 0;
}

