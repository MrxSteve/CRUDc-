#include <iostream>
#include <fstream>
#include <sstream>
#include "Persona.h"

using namespace std;

void crearPersona() {
    Persona persona;

    cout << "Ingrese el ID: " << endl;
    cin >> persona.idPersona;

    cout << "Ingrese el nombre: " << endl;
    cin.ignore();
    getline(cin, persona.nombreCompleto);

    cout << "Ingrese la edad: " << endl;
    cin >> persona.edad;

    cout << "Ingrese la direccion: " << endl;
    cin.ignore();
    getline(cin, persona.direccion);

    ofstream archivo("personas.txt", ios::app);
    if (archivo) {
        archivo << persona.idPersona << " - " << persona.nombreCompleto << " - " <<
            persona.edad << " - " << persona.direccion << endl;
        cout << "Persona agregada correctamente" << endl;
        archivo.close();
    } else {
        cout << "No se pudo abrir el archivo" << endl;
    }
}

void leerPersona() {
    ifstream archivo("personas.txt");
    if (!archivo) {
        cout << "No se pudo abrir el archivo" << endl;
        return;
    }

    Persona persona;
    string linea;

    cout << "Lista de personas: " << endl;
    while (getline(archivo, linea)) {
        istringstream  stream(linea);
        string atributo;

        getline(stream, atributo, '-');
        persona.idPersona = stoi(atributo);

        getline(stream, persona.nombreCompleto, '-');
        getline(stream, atributo, '-');

        persona.edad = stoi(atributo);

        getline(stream, persona.direccion, '-');

        cout << "ID: " << persona.idPersona << endl;
        cout << "Nombre: " << persona.nombreCompleto << endl;
        cout << "Edad: " << persona.edad << endl;
        cout << "Direccion: " << persona.direccion << endl;
    }
    archivo.close();
}

void actualizarPersona() {
    int id;
    cout << "Ingrese el ID de la persona a actualizar: " << endl;
    cin >> id;

    ifstream archivo("personas.txt");
    ofstream archivoTemp("temp.txt");

    if (!archivo || !archivoTemp) {
        cout << "No se pudo abrir el archivo" << endl;
        return;
    }

    Persona persona;
    string linea;
    bool encontrado = false;

    while (getline(archivo, linea)) {
        istringstream stream(linea);
        string atributo;

        getline(stream, atributo, '-');
        persona.idPersona = stoi(atributo);

        getline(stream, persona.nombreCompleto, '-');
        getline(stream, atributo, '-');
        persona.edad = stoi(atributo);
        getline(stream, persona.direccion, '-');

        if (persona.idPersona == id) {
            cout << "Ingrese el nuevo nombre: " << endl;
            cin.ignore();
            getline(cin, persona.nombreCompleto);

            cout << "Ingrese la nueva edad: " << endl;
            cin >> persona.edad;

            cout << "Ingrese la nueva direccion: " << endl;
            cin.ignore();
            getline(cin, persona.direccion);

            encontrado = true;
        }

        archivoTemp << persona.idPersona << " - " << persona.nombreCompleto << " - " <<
            persona.edad << " - " << persona.direccion << endl;
    }

    archivo.close();
    archivoTemp.close();

    remove("personas.txt");
    rename("temp.txt", "personas.txt");

    if (encontrado) {
        cout << "Persona actualizada correctamente" << endl;
    } else {
        cout << "Persona con ID " << id << " no encontrada" << endl;
    }

}

void borrarPersona() {
    int id;
    cout << "Ingrese el ID de la persona a borrar: " << endl;
    cin >> id;

    ifstream archivo("personas.txt");
    ofstream archivoTemp("temp.txt");

    if (!archivo || !archivoTemp) {
        cout << "No se pudo abrir el archivo" << endl;
        return;
    }

    Persona persona;
    string linea;
    bool encontrado = false;

    while (getline(archivo, linea)) {
        istringstream stream(linea);
        string atributo;

        getline(stream, atributo, '-');
        persona.idPersona = stoi(atributo);

        getline(stream, persona.nombreCompleto, '-');
        getline(stream, atributo, '-');
        persona.edad = stoi(atributo);
        getline(stream, persona.direccion, '-');

        if (persona.idPersona != id) {
            archivoTemp << persona.idPersona << " - " << persona.nombreCompleto << " - " <<
                persona.edad << " - " << persona.direccion << endl;
        } else {
            encontrado = true;
        }
    }

    archivo.close();
    archivoTemp.close();

    remove("personas.txt");
    rename("temp.txt", "personas.txt");

    if (encontrado) {
        cout << "Persona borrada correctamente" << endl;
    } else {
        cout << "Persona con ID " << id << " no encontrada" << endl;
    }

}

void buscarPorId(int id) {
    ifstream archivo("personas.txt");
    if (!archivo) {
        cout << "No se pudo abrir el archivo" << endl;
        return;
    }

    Persona persona;
    string linea;
    bool encontrado = false;

    while (getline(archivo, linea)) {
        istringstream stream(linea);
        string atributo;

        getline(stream, atributo, '-');
        persona.idPersona = stoi(atributo);

        getline(stream, persona.nombreCompleto, '-');
        getline(stream, atributo, '-');
        persona.edad = stoi(atributo);
        getline(stream, persona.direccion, '-');

        if (persona.idPersona == id) {
            cout << "ID: " << persona.idPersona << endl;
            cout << "Nombre: " << persona.nombreCompleto << endl;
            cout << "Edad: " << persona.edad << endl;
            cout << "Direccion: " << persona.direccion << endl;
            encontrado = true;
            break;
        }
    }

    if (!encontrado) {
        cout << "Persona con ID " << id << " no encontrada" << endl;
    }

    archivo.close();
}

// Función para buscar personas por nombre y mostrar todas las coincidencias
void buscarPorNombre(const string &nombre) {
    ifstream archivo("personas.txt");
    if (!archivo) {
        cout << "No se pudo abrir el archivo.\n";
        return;
    }

    Persona persona;
    string linea;
    bool encontrado = false;

    // Leemos cada línea del archivo y buscamos coincidencias con el nombre especificado
    while (getline(archivo, linea)) {
        istringstream stream(linea);
        string atributo;

        getline(stream, atributo, '-');
        persona.idPersona = stoi(atributo);

        getline(stream, persona.nombreCompleto, '-');
        getline(stream, atributo, '-');
        persona.edad = stoi(atributo);
        getline(stream, persona.direccion, '-');

        // Si el nombre coincide, mostramos la información de la persona
        if (persona.nombreCompleto == nombre) {
            cout << "ID: " << persona.idPersona << endl;
            cout << "Nombre: " << persona.nombreCompleto << endl;
            cout << "Edad: " << persona.edad << endl;
            cout << "Direccion: " << persona.direccion << endl;
            cout << "----------------------------------\n";
            encontrado = true;
        }
    }

    if (!encontrado) {
        cout << "No se encontraron personas con el nombre \"" << nombre << "\".\n";
    }

    archivo.close();
}

