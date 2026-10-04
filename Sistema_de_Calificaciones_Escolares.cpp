#include <iostream>
#include <limits>
#include <cmath>
#include <string>
#include <vector>
using namespace std;

struct Estudiante {
    string nombre;
    int edad;
    float promedio;
    string estado;
};

vector<Estudiante> estudiantes;

void mostrarMenu();
int leerEntero(string mensaje, int min, int max);
float leerCalificacion(int numero);
float calcularPromedio(float suma, int n);
string obtenerEstado(float promedio);
void registrarEstudiante();
void mostrarEstudiantes();
void mostrarDespedida();

int main() {
    int opcion;

    do {
        mostrarMenu();
        opcion = leerEntero("Opcion: ", 1, 4);

        switch (opcion) {
        case 1:
        case 3:
            registrarEstudiante();
            break;
        case 2:
            mostrarEstudiantes();
            break;
        case 4:
            mostrarDespedida();
            break;
        }
    } while (opcion != 4);

    return 0;
}

void mostrarMenu() {
    cout << "\n===== SISTEMA DE CALIFICACIONES =====" << endl;
    cout << "1. Registrar estudiante" << endl;
    cout << "2. Ver informacion de los estudiantes" << endl;
    cout << "3. Registrar otro estudiante" << endl;
    cout << "4. Salir" << endl;
}

int leerEntero(string mensaje, int min, int max) {
    int valor;
    cout << mensaje;

    while (!(cin >> valor) || valor < min || valor > max) {
        if (cin.fail()) {
            cin.clear();
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Valor invalido. Ingresa un entero entre " << min << " y " << max << ": ";
    }

    return valor;
}

float leerCalificacion(int numero) {
    float calificacion;
    cout << "Calificacion " << numero << ": ";

    while (!(cin >> calificacion) || !isfinite(calificacion) ||
           calificacion < 0 || calificacion > 10) {
        if (cin.fail()) {
            cin.clear();
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Calificacion invalida. Ingresa una calificacion entre 0 y 10: ";
    }

    return calificacion;
}

float calcularPromedio(float suma, int n) {
    return suma / n;
}

string obtenerEstado(float promedio) {
    if (promedio >= 9) {
        return "EXCELENTE";
    } else if (promedio >= 7) {
        return "APROBADO";
    } else if (promedio >= 6) {
        return "REGULAR (aprobado con lo minimo)";
    }
    return "REPROBADO";
}

void registrarEstudiante() {
    string nombre;
    int aprobadas = 0;
    int reprobadas = 0;
    float suma = 0;
    float calificacionMayor = 0;
    float calificacionMenor = 10;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Nombre del estudiante: ";
    getline(cin, nombre);
    int edad = leerEntero("Edad: ", 0, 120);
    int cantidadCalificaciones = leerEntero(
        "Cuantas calificaciones deseas registrar? ", 1, numeric_limits<int>::max());

    for (int i = 0; i < cantidadCalificaciones; i++) {
        float calificacion = leerCalificacion(i + 1);
        suma += calificacion;
        if (calificacion >= 6) {
            aprobadas++;
        } else {
            reprobadas++;
        }
        if (calificacion > calificacionMayor) {
            calificacionMayor = calificacion;
        }
        if (calificacion < calificacionMenor) {
            calificacionMenor = calificacion;
        }
    }

    float promedio = calcularPromedio(suma, cantidadCalificaciones);
    string estado = obtenerEstado(promedio);
    estudiantes.push_back({nombre, edad, promedio, estado});

    cout << "\nResumen del estudiante" << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Edad: " << edad << endl;
    cout << "Promedio: " << promedio << endl;
    cout << "Estado: " << estado << endl;
    cout << "Calificaciones aprobatorias: " << aprobadas << endl;
    cout << "Calificaciones reprobatorias: " << reprobadas << endl;
    cout << "Calificacion mas alta: " << calificacionMayor << endl;
    cout << "Calificacion mas baja: " << calificacionMenor << endl;
}

void mostrarEstudiantes() {
    if (estudiantes.empty()) {
        cout << "\nNo hay estudiantes registrados." << endl;
        return;
    }

    cout << "\n===== ESTUDIANTES REGISTRADOS =====" << endl;
    for (size_t i = 0; i < estudiantes.size(); i++) {
        cout << "\nEstudiante " << i + 1 << endl;
        cout << "Nombre: " << estudiantes[i].nombre << endl;
        cout << "Edad: " << estudiantes[i].edad << endl;
        cout << "Promedio: " << estudiantes[i].promedio << endl;
        cout << "Estado: " << estudiantes[i].estado << endl;
    }
}

void mostrarDespedida() {
    cout << "Saliendo del programa..." << endl;
}