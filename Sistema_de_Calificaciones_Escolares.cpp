#include <iostream>
#include <string>
#include <vector>
using namespace std;   

struct Estudiante {
    string nombre;
    int edad;
    float promedio;
    string estado;
};

int main() {
    int opcion;
    vector<Estudiante> estudiantes;

    do {
        cout << "\n===== SISTEMA DE CALIFICACIONES =====" << endl;
        cout << "1. Registrar estudiante" << endl;
        cout << "2. Ver informacion de los estudiantes" << endl;
        cout << "3. Salir" << endl;
        cout << "4. Registrar otro estudiante" << endl;
        cout << "Opcion: ";
        do {
            cin >> opcion;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(10000, '\n');
                opcion = 0;
            }
            if (opcion < 1 || opcion > 4) {
                cout << "Opcion invalida. Ingresa una opcion del 1 al 4: ";
            }
        } while (opcion < 1 || opcion > 4);

        switch (opcion) {
        case 4:
        case 1: {
            string nombre;
            int edad;
            int cantidadCalificaciones;
            int aprobadas = 0;
            int reprobadas = 0;
            float suma = 0;
            float calificacion;
            float calificacionMayor = 0;
            float calificacionMenor = 10;
            float promedio;

            cin.ignore();
            cout << "Nombre del estudiante: ";
            getline(cin, nombre);
            cout << "Edad: ";
            cin >> edad;
            while (edad < 0 || edad > 120) {
                cout << "Edad invalida. Ingresa una edad entre 0 y 120: ";
                cin >> edad;
            }

            cout << "Cuantas calificaciones deseas registrar? ";
            cin >> cantidadCalificaciones;
            if (cantidadCalificaciones <= 0) {
                cout << "La cantidad de calificaciones debe ser mayor que cero" << endl;
                break;
            }

            for (int i = 0; i < cantidadCalificaciones; i++) {
                cout << "Calificacion " << i + 1 << ": ";
                cin >> calificacion;
                while (calificacion < 0 || calificacion > 10) {
                    cout << "Calificacion invalida. Ingresa una calificacion entre 0 y 10: ";
                    cin >> calificacion;
                }

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

            promedio = suma / cantidadCalificaciones;

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
            break;
        }
        case 2:
            if (estudiantes.empty()) {
                cout << "\nNo hay estudiantes registrados." << endl;
                break;
            }

            cout << "\n===== ESTUDIANTES REGISTRADOS =====" << endl;
            for (size_t i = 0; i < estudiantes.size(); i++) {
                cout << "\nEstudiante " << i + 1 << endl;
                cout << "Nombre: " << estudiantes[i].nombre << endl;
                cout << "Edad: " << estudiantes[i].edad << endl;
                cout << "Promedio: " << estudiantes[i].promedio << endl;
                cout << "Estado: " << estudiantes[i].estado << endl;
            }
            break;
        case 3:
            cout << "Saliendo del programa..." << endl;
            break;
        }
    } while (opcion != 3);

    return 0;
}