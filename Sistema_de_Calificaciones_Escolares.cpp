#include <iostream>
#include <string>
using namespace std;   

int main() {
    string nombre;
    int edad;
    float calificacion1, calificacion2, calificacion3;
    float promedio;

    cout << "Nombre del estudiante: ";
    getline(cin, nombre);
    cout << "Edad: ";
    cin >> edad;
    cout << "Calificacion 1: ";
    cin >> calificacion1;
    cout << "Calificacion 2: ";
    cin >> calificacion2;
    cout << "Calificacion 3: ";
    cin >> calificacion3;

    promedio = (calificacion1 + calificacion2 + calificacion3) / 3;

    cout << "\nResumen del estudiante" << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Edad: " << edad << endl;
    cout << "Promedio: " << promedio << endl;

    return 0;
}