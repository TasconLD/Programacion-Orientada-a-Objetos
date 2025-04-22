
#include "Vehiculo.h"
#include <regex>
using namespace std;

Vehiculo::Vehiculo() : tipoAuto(Auto()),placa(""), marca(""), color(""), hora("") {
}

Vehiculo::Vehiculo(const Auto& tipoAuto,const string& placa, const string& marca, const string& color)
    : tipoAuto(tipoAuto), placa(placa), marca(marca), color(color), hora(hora) {
}

Auto Vehiculo::getTipoSangre() const {
    return tipoAuto;
}

void Vehiculo::setTipoAuto(const Auto& tipoAuto) {
    this->tipoAuto = tipoAuto;
}

string Vehiculo::getPlaca() const {
    return placa;
}

void Vehiculo::setPlaca(const string& placa) {
    this->cedula = cedula;
}

string Vehiculo::getMarca() const {
    return marca;
}

void Vehiculo::setMarca(const string& marca) {
    this->marca = marca;
}

string Vehiculo::getColor() const {
    return color;
}

void Vehiculo::setColor(const string& color) {
    this->color = color;
}

string Vehiculo:getHora()const {
    return hora;
}

void Vehiculo::setHora(const string& hora){
    this->hora = hora;
}


bool Vehiculo::validarPlaca(const string& placa) {
    // Valida la placa
    regex placaRegex("");
    return regex_match(placa, placaRegex);
}

bool Vehiculo::validarMarca(const string& marca) {
    // Valida la marca
    regex MarcaRegex("");
    return regex_match(marca, marcaRegex);
}

bool Vehiculo::validarColor(const string& color) {
    // Valida el color
    regex colorRegex("");
    return regex_match(color, colorRegex);
}

bool Vehiculo::validarHora(const string& hora) {
    // Valida la hora
    regex horaRegex("");
    return regex_match(hora, horaRegex);
}
