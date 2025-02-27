//ARCHIVO OPERACIONESM.H

#ifndef OPERACIONESM_H
#define OPERACIONESM_H

#include <stdexcept>

class OperacionesM {
public:
    // Constructor
    OperacionesM();

    // Destructor
    ~OperacionesM();

    double sumar(double a, double b);
    double restar(double a, double b);
    double multiplicar(double a, double b);
    double dividir(double a, double b);
};

#endif // OPERACIONESM_H

//////////___________________________________________________//////////

//ARCHIVO OPERACIONESM.CPP

#include "OperacionesM.h"

// Constructor
OperacionesM::OperacionesM() {
    // Inicialización si es necesario
}

// Destructor
OperacionesM::~OperacionesM() {
    // Liberar recursos si es necesario
}

// Método para sumar dos números
double OperacionesM::sumar(double a, double b) {
    return a + b;
}

// Método para restar dos números
double OperacionesM::restar(double a, double b) {
    return a - b;
}

// Método para multiplicar dos números
double OperacionesM::multiplicar(double a, double b) {
    return a * b;
}

// Método para dividir dos números
double OperacionesM::dividir(double a, double b) {
    if (b == 0) {
        throw std::invalid_argument("Error: Division por cero.");
    }
    return a / b; // Retorna el resultado de la división
}

/////////////////////__________________________________________////////////////////////

//ARCHIVO MAIN.CPP

#include <iostream>
#include "OperacionesM.h"

using namespace std;

int main() {
    OperacionesM calc;
    double num1, num2;
    char operacion;

    cout << "Ingrese el primer numero: ";
    cin >> num1;

    cout << "Ingrese el segundo numero: ";
    cin >> num2;

    cout << "Ingrese la operacion (+, -, *, /): ";
    cin >> operacion;

    try {
        switch (operacion) {
            case '+':
                cout << "Resultado: " << calc.sumar(num1, num2) << endl;
                break;
            case '-':
                cout << "Resultado: " << calc.restar(num1, num2) << endl;
                break;
            case '*':
                cout << "Resultado: " << calc.multiplicar(num1, num2) << endl;
                break;
            case '/':
                cout << "Resultado: " << calc.dividir(num1, num2) << endl;
                break;
            default:
                cout << "Operacion no valida" << endl;
                break;
        }
    } catch (const std::invalid_argument& e) {
        cout << e.what() << endl;
    }

    return 0; // Retorna 0 para indicar que todo salió bien
}
