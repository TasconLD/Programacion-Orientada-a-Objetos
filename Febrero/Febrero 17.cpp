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
