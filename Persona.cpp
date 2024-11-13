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