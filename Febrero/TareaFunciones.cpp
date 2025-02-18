#include <iostream>

/*
Este codigo contiene funciones para operar dos variables, a y b.
Calcula la suma, resta, multiplicacion y division.
Ademas, la sumatoria, el numero mas grande entre a y b, y cuantos pares hay entre estas dos variables.
Se hace uso de for para iterar sobre las variables.
Se usa swap para intercambiar las variables y que el primer valor siempre sea menor.
Se usa static_cast<double> para cambiar un int por un double.
*/

using namespace std;

int sumar(int a, int b) {  //funcion para sumar dos numeros enteros
    int suma = a + b;
    return suma;
}

int restar(int a, int b) { //funcion para restar dos numeros enteros
    int resta = a - b;
    return resta;
}

int multiplicar(int a, int b) { //funcion para multiplicar dos numeros enteros
    int multiplicacion = a * b;
    return multiplicacion;
}

double dividir(double a, double b) { //funcion para dividir dos numeros reales
    if (b != 0) {        //con if verifico que no vaya a dar error por dividir 0
        double division = a / b;
        return division;
    } else {
        cout << "Error: Division por cero." << endl;
        return 0;
    }
}

int sumatoria(int n) {  //funcion para calcular sumatoria
    int suma = 0;
    for (int i = 1; i <= n; i++) {  //inicia en 1 y sumara hasta que sea menor o igual al numero n, i++ sumara cada que itera
        suma += i;
    }
    return suma;
}

int maximo(int a, int b){ //funcion para ver entre los dos numeros cual es el mayor
    return (a > b) ? a : b;  //si a es mayor que b se muestra, sino a : b entonces b sera el mayor
}

double promedio(int a, int b){   //funcion para ver el promedio entre dos numeros-
    return static_cast<double>(sumar(a,b))/2; //statis_cast<double> cambia el entero por un real de la funcion sumar y se divide en los 2 numeros
}

int contarPares(int a, int b){  //funcion para contar cuantos pares hay entre a y b
    int contador = 0;      //inicializa en un contador para guardar los valores

    if (a > b){
        swap(a,b); //swap intercambia los valores de las variables, para que el primer valor siempre sea el menor
    }
    for (int i = a; i <= b; i++){  // este for intera sobre a y b
        if (i % 2 == 0){  //esto verifica si el numero es par, debe ser divisible por 2 y dar 0
            contador++;
        }
    }
    return contador;
}

int main() {
    int a, b;
    cout << "Ingrese numero 1: " << endl;
    cin >> a;
    cout << "Ingrese numero 2: " << endl;
    cin >> b;

    int resultadoSuma = sumar(a, b);
    cout << "La suma es: " << resultadoSuma << endl;

    int resultadoResta = restar(a, b);
    cout << "La resta es: " << resultadoResta << endl;

    int resultadoMultiplicacion = multiplicar(a, b);
    cout << "La multiplicacion es: " << resultadoMultiplicacion << endl;

    double resultadoDivision = dividir(a, b);
    cout << "La division: " << resultadoDivision << endl;

    // Calcular la sumatoria de 'a'
    int resultadoSumatoria = sumatoria(a);
    cout << "La sumatoria de los numeros desde 1 hasta " << a << " es: " << resultadoSumatoria << endl;

    int resultadoMaximo = maximo(a,b);
    cout << "El numero mayor entre: " << a << " y " << b << " es: " << resultadoMaximo <<endl;

    int resultadoPares = contarPares(a,b);
    cout << "La cantidad de numeros pares entre " << a << " y " << b << " es: " << resultadoPares << endl;
    return 0;
}
