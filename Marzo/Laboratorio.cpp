//CLIENTE H

#include <iostream>
#include "Banco.h"

using namespace std;

int main() {
    Banco banco; // Crear una instancia de Banco

    // Crear algunos clientes
    banco.crearCliente(1, "Juan Perez", "123456789");
    banco.crearCliente(2, "Maria Gomez", "987654321");

    // Crear una cuenta
    banco.crearCuenta("001");
    
    // Agregar clientes a la cuenta
    banco.cuentas[0]->agregarCliente(banco.clientes[0]); // Agregar Juan a la cuenta
    banco.cuentas[0]->agregarCliente(banco.clientes[1]); // Agregar Maria a la cuenta

    // Realizar operaciones en la cuenta
    banco.cuentas[0]->consignar(1000); // Consigna 1000 en la cuenta
    banco.cuentas[0]->retirar(200);     // Retira 200 de la cuenta

    // Imprimir informes de las cuentas
    banco.imprimirInformes();

    // Calcular el promedio de saldo
    double totalSaldo = 0; // Variable para almacenar el total de saldo
    for (Cuenta* cuenta : banco.cuentas) { // Itera sobre todas las cuentas
        totalSaldo += cuenta->getSaldo(); // Suma el saldo de cada cuenta
    }
    
    // Evitar división por cero
    double promedioSaldo = banco.cuentas.empty() ? 0 : totalSaldo / banco.cuentas.size(); // Calcula el promedio
    cout << "Promedio de saldo de las cuentas: " << promedioSaldo << endl; // Imprime el promedio

    return 0; // Fin del programa
}

//CLIENTE CPP

#include "Cliente.h"

// Constructor de la clase Cliente
Cliente::Cliente(int id, std::string nombre, std::string telefono) {
    this->id = id;
    this->nombre = nombre;
    this->telefono = telefono;
}

Cliente::~Cliente() {
    // Destructor vacío
}


//CUENTA H

#ifndef CUENTA_H
#define CUENTA_H

#include <string>
#include <vector>
#include "Cliente.h"

class Cuenta {
public:
    std::string numeroCuenta;
    double saldo;
    std::vector<Cliente*> clientes;

    // Constructor de la clase Cuenta
    Cuenta(std::string numeroCuenta);

    // Métodos
    void agregarCliente(Cliente* cliente);
    void consignar(double monto);
    bool retirar(double monto);
    double getSaldo() const;
    void imprimirInforme() const;

    virtual ~Cuenta(); // Destructor

protected:

private:
};

#endif // CUENTA_H

//CUENTA CPP

#include "Cuenta.h"
#include <iostream>

// Constructor de la clase Cuenta
Cuenta::Cuenta(std::string numeroCuenta) {
    this->numeroCuenta = numeroCuenta;
    this->saldo = 0.0;
}

// Método para agregar un cliente a la cuenta
void Cuenta::agregarCliente(Cliente* cliente) {
    clientes.push_back(cliente);
}

// Método para consignar dinero en la cuenta
void Cuenta::consignar(double monto) {
    saldo += monto;
}

// Método para retirar dinero de la cuenta
bool Cuenta::retirar(double monto) {
    if (monto > saldo) { // Verifica si hay suficiente saldo
        std::cout << "No hay suficiente saldo para retirar." << std::endl;
        return false; // Retorno falso si no hay suficiente saldo
    }
    saldo -= monto; // Resta el monto del saldo
    return true;    // Retorno verdadero si la operación fue exitosa
}

// Método para obtener el saldo
double Cuenta::getSaldo() const {
    return saldo; // Retorna el saldo actual
}

// Método para imprimir el informe de la cuenta
void Cuenta::imprimirInforme() const {
    std::cout << "Numero de Cuenta: " << numeroCuenta << std::endl;
    std::cout << "Saldo: " << saldo << std::endl;
    std::cout << "Clientes asociados: ";
    for (Cliente* cliente : clientes) {
        std::cout << cliente->nombre << " ";
    }
    std::cout << std::endl;
}

// Destructor de la clase Cuenta
Cuenta::~Cuenta() {
    // Destructor vacío
}

//BANCO H

#ifndef BANCO_H
#define BANCO_H

#include <vector>
#include "Cliente.h"
#include "Cuenta.h"

class Banco {
public:
    std::vector<Cliente*> clientes;
    std::vector<Cuenta*> cuentas;

    // Métodos de la clase Banco
    void crearCliente(int id, std::string nombre, std::string telefono);
    void crearCuenta(std::string numeroCuenta);
    void imprimirInformes();

    ~Banco(); // Destructor
};

#endif // BANCO_H


//BANCO CPP

#include "Banco.h"
#include <iostream>

// Método para crear un cliente
void Banco::crearCliente(int id, std::string nombre, std::string telefono) {
    Cliente* nuevoCliente = new Cliente(id, nombre, telefono);
    clientes.push_back(nuevoCliente); //
}

// Método para crear una cuenta
void Banco::crearCuenta(std::string numeroCuenta) {
    Cuenta* nuevaCuenta = new Cuenta(numeroCuenta);
    cuentas.push_back(nuevaCuenta);
}

// Método para imprimir informes de todas las cuentas
void Banco::imprimirInformes() {
    for (Cuenta* cuenta : cuentas) {
        cuenta->imprimirInforme();
    }
}

// Destructor de la clase Banco
Banco::~Banco() {
    // Liberar memoria de clientes
    for (Cliente* cliente : clientes) {
        delete cliente;
    }
    // Liberar memoria de cuentas
    for (Cuenta* cuenta : cuentas) {
        delete cuenta;
    }
}

//MAIN CPP

#include <iostream>
#include "Banco.h"

using namespace std;

int main() {
    Banco banco;

    // Crear clientes
    banco.crearCliente(1, "Jose Campo", "8239423");
    banco.crearCliente(2, "Pedro Diaz", "1237892");

    // Crear una cuenta
    banco.crearCuenta("001");

    // Agregar clientes a la cuenta
    banco.cuentas[0]->agregarCliente(banco.clientes[0]);
    banco.cuentas[0]->agregarCliente(banco.clientes[1]);

    // Realizar operaciones en la cuenta
    banco.cuentas[0]->consignar(1000);
    banco.cuentas[0]->retirar(300);

    // Imprimir informes de las cuentas
    banco.imprimirInformes();

    // Calcular el promedio de saldo
    double totalSaldo = 0;
    for (Cuenta* cuenta : banco.cuentas) {
        totalSaldo += cuenta->getSaldo();
    }

    // Evitar división por cero
    double promedioSaldo = banco.cuentas.empty() ? 0 : totalSaldo / banco.cuentas.size(); // Calcula el promedio
    cout << "Promedio de saldo de las cuentas: " << promedioSaldo << endl; // Imprime el promedio

    return 0;
}
