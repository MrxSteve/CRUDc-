#include <iostream>
#include "Persona.h"
// #include "Persona.cpp"
using namespace std;

int main() {

    int opcion = 0;

    do {
        cout << "1. Crear persona" << endl;
        cout << "2. Leer personas" << endl;
        cout << "3. Actualizar persona" << endl;
        cout << "4. Borrar persona" << endl;
        cout << "5. Buscar por ID" << endl;
        cout << "6. Buscar por nombre" << endl;
        cout << "7. Salir" << endl;
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                crearPersona();
                break;
            case 2:
                leerPersona();
                break;
            case 3:
                // actualizarPersona();
                break;
            case 4:
                // borrarPersona();
                break;
            case 5: {
                int id;
                cout << "Ingrese el ID: " << endl;
                cin >> id;
                // buscarPorId(id);
                break;
            }
            case 6: {
                string nombre;
                cout << "Ingrese el nombre: " << endl;
                cin.ignore();
                getline(cin, nombre);
                // buscarPorNombre(nombre);
                break;
            }
            case 7:
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opcion no valida" << endl;
        }

    } while (opcion != 7);

    return 0;
}
