#include <iostream>

using namespace std;


int sumar (int a, int b){  /*funcion sumar: esta funcion realiza la suma de dos numeros, recibe dos enteros y retorna un entero*/
    int suma = a + b;
    return suma;

}


int main (){

    int resultado = sumar (10,20);  //llama a la funcion sumar 
    cout << "resultado de la suma es: "<< resultado <<endl;
    return 0;


}
/* fundamentos de programacion orientada a objetos
    grupo 80
    laboratorio 1
    integrantes: laura dayana tascon (2438545-2724)
    */

//conversiones entre tipos

#include <iostream>
#include <string> using namespace std;
int main()
{
int c = 20;
string s = to_string(c); // Convierte entero a string
int d = stoi(s); // Convierte string a entero
double e = 5.123;
string t = to_string(e); // Convierte double a string
double f = stod(t); // Convierte string a double

//funciones sumar, restar, multiplicar y dividir

#include <iostream>

using namespace std;

int sumar(int a, int b) {
    int suma = a + b;
    return suma;
}

int restar(int a, int b) {
    int resta = a - b;
    return resta;
}

int multiplicar(int a, int b) {
    int multiplicacion = a * b;
    return multiplicacion;
}

double dividir(double a, double b) {
    if (b != 0) { // Verificar que no se divida por cero
        double division = a / b;
        return division;
    } else {
        cout << "Error: Division por cero." << endl;
        return 0; // Retornar 0 o algún valor que indique error
    }
}

int main() {
    int resultadoSuma = sumar(10, 20);
    cout << "Resultado de la suma es: " << resultadoSuma << endl;

    int resultadoResta = restar(10, 20);
    cout << "Resultado de la resta es: " << resultadoResta << endl;

    int resultadoMultiplicacion = multiplicar(10, 20);
    cout << "Resultado de la multiplicacion es: " << resultadoMultiplicacion << endl;

    double resultadoDivision = dividir(10.0, 2.0); // Pasar dos argumentos
    cout << "Resultado de la division es: " << resultadoDivision << endl;

    return 0;
}

