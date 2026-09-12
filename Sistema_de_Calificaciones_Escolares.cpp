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
    if (edad < 0 || edad > 120) {
        cout << "Edad invalida" << endl;
        return 1;
    }

    cout << "Calificacion 1: ";
    cin >> calificacion1;
    if (calificacion1 < 0 || calificacion1 > 10) {
        cout << "Calificacion invalida" << endl;
        return 1;
    }

    cout << "Calificacion 2: ";
    cin >> calificacion2;
    if (calificacion2 < 0 || calificacion2 > 10) {
        cout << "Calificacion invalida" << endl;
        return 1;
    }

    cout << "Calificacion 3: ";
    cin >> calificacion3;
    if (calificacion3 < 0 || calificacion3 > 10) {
        cout << "Calificacion invalida" << endl;
        return 1;
    }

    promedio = (calificacion1 + calificacion2 + calificacion3) / 3;

    string estado;
    if (promedio >= 9) {
        estado = "EXCELENTE";
    } else if (promedio >= 7) {
        estado = "APROBADO";
    } else if (promedio >= 6) {
        estado = "REGULAR (aprobado con lo minimo)";
    } else {
        estado = "REPROBADO";
    }

    cout << "\nResumen del estudiante" << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Edad: " << edad << endl;
    cout << "Promedio: " << promedio << endl;
    cout << "Estado: " << estado << endl;

    return 0;
}