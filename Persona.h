#ifndef PERSONA_H
#define PERSONA_H
#include <string>
using namespace std;

// Estructura
struct Persona {
    int idPersona;
    string nombreCompleto;
    int edad;
    string direccion;
};

// Prototipos de funciones
// CRUD
void crearPersona();
void leerPersona();
void actualizarPersona();
void borrarPersona();

// Funciones para buscar
void buscarPorId(int id);
void buscarPorNombre(const string &nombre);


#endif //PERSONA_H
