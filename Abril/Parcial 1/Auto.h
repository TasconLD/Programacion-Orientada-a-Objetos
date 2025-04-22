
#ifndef AUTO_H
#define AUTO_H

#include <string>
#include <vector>
using namespace std;

//Clase de vehiculo
class Auto {
private:
    string tipo; // Tipo de vehiculo

public:

    //Constructor 
    Auto();

    Auto(const string& tipo);


     //Obtiene el tipo de vehiculo
    string getTipo() const;


    //Establece el tipo vehiculo
    void setTipo(const string& tipo);

    //Verifica si el tipo de vehiculo es válido
    static bool esValido(const string& tipo);

    //Obtiene todos los tipos de vehiculos válidos
    static vector<string> getTiposValidos();
};

#endif // AUTO_H
