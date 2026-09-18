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
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion) {
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
            if (edad < 0 || edad > 120) {
                cout << "Edad invalida" << endl;
                break;
            }

            cout << "Cuantas calificaciones deseas registrar? ";
            cin >> cantidadCalificaciones;
            if (cantidadCalificaciones <= 0) {
                cout << "La cantidad de calificaciones debe ser mayor que cero" << endl;
                break;
            }

            bool calificacionesValidas = true;
            for (int i = 0; i < cantidadCalificaciones; i++) {
                cout << "Calificacion " << i + 1 << ": ";
                cin >> calificacion;
                if (calificacion < 0 || calificacion > 10) {
                    cout << "Calificacion invalida" << endl;
                    calificacionesValidas = false;
                    break;
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

            if (!calificacionesValidas) {
                break;
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
        default:
            cout << "Opcion invalida. Intente nuevamente." << endl;
        }
    } while (opcion != 3);

    return 0;
}