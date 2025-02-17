#include <iostream>

using namespace std;


int sumar (int a, int b){  //funcion sumar 
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
