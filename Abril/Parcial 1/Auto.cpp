
#include "Auto.h"
#include <algorithm>
using namespace std;

Auto::Auto() : tipo("") {
}

Auto::Auto(const string& tipo) : tipo(tipo) {
}

string Auto::getTipo() const {
    return tipo;
}

void Auto::setTipo(const string& tipo) {
    this->tipo = tipo;
}

bool Auto::esValido(const string& tipo) {
    vector<string> tiposValidos = getTiposValidos();
    return find(tiposValidos.begin(), tiposValidos.end(), tipo) != tiposValidos.end();
}

vector<string> Validos::getTiposValidos() {
    return {"Toyota", "Mercedez-Benz", "BMW", "Audi", "Ford"};
}
