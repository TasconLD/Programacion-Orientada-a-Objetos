    /*Proyecto: BloodDatabase (Adaptado)
    Curso: Fundamentos de Programación Orientada a Objetos (FPOO)
    Universidad del Valle
    Estudiantes: Laura Dayana Tascon Velasco - 2438545
                 Daniel Escobar Escobar - 2437924
                 Elbert Leandro Moreno Castillo - 2436884
                 Jesus Giovanny Mora Segura -  2439620
    Fecha: Abril 2025
    */

#include "sangre.h"
#include <algorithm>

Sangre::Sangre() : tipo("") {
}

Sangre::Sangre(const std::string& tipo) : tipo(tipo) {
}

std::string Sangre::getTipo() const {
    return tipo;
}

void Sangre::setTipo(const std::string& tipo) {
    this->tipo = tipo;
}

bool Sangre::esValido(const std::string& tipo) {
    std::vector<std::string> tiposValidos = getTiposValidos();
    return std::find(tiposValidos.begin(), tiposValidos.end(), tipo) != tiposValidos.end();
}

std::vector<std::string> Sangre::getTiposValidos() {
    return {"A+", "A-", "B+", "B-", "AB+", "AB-", "O+", "O-"};
}

