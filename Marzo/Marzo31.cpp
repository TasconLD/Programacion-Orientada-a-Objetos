/*despues de semana santa parcial 1
taller 2 lunes 07 de abril
temas:
lenguaje c++
que son los archivos .h: estructura o defincion del objeto, atributos y metodos, .cpp: metodos del codigo, main: llamar los objetos
que es abstracion, encapsulamiento, polimorfismo, herencia
atributos privados y metodos publicos
para que clase hija herede atributos deben estar en protect y no en privado, y hereda tanto atributos como metodos
crear diagramas de clases
diferenciar: 
-if(p) o bien if(p != nullptr) que son equivalentes
-if(not p) o bien if(p == nullptr) que son equivalentes
diferenciar:
- si son entrada, salida o entrada-salida


_________________________________________________
Clase
-Referencias: &
int valor=5;
int &meses = valor; // meses es un nuevo nombre para valor, es una referencia, todo lo que le pasa a valor le pasa a meses
- Punteros: *
los punteros son las variables
donde guardas direcciones, no variables
Se declaran así:
int *p; 
*/
//_______________________

//Codigo en clase

#include <iostream>

using namespace std;

int main()
{
    int salario = 5000000;
    int *pagar;
    pagar = &salario;
    pagar = 2345; //La variable pagar es puntero y no recibe valores

    cout << "El salario es: "<<salario<<endl;
    cout << "Direccion de memoria: "<<&salario<<endl;
    cout << "Pagar: "<<pagar<<endl;
    cout << "Pagar puntero: "<<*pagar<<endl;

    cout << pagar<<endl;
    return 0;
}

/*
Clase
A veces necesitamos un puntero que no apunta a
nada. Para eso existe la palabra clave nullptr  (sirve pa hacer un virus)

https://replit.com/



*/





