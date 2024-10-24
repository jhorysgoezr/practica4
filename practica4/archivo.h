#ifndef ARCHIVO_H
#define ARCHIVO_H

#include <string>
#include <map>
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

class Archivo {
public:
    // Cargar topología de la red desde un archivo
    static map<string, map<string, int>> leerTopologia(const string& nombreArchivo);

    // Guardar la topología de la red en un archivo
    static void guardarTopologia(const string& nombreArchivo, const map<string, map<string, int>>& topologia);
};

#endif // ARCHIVO_H
