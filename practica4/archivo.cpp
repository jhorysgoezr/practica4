#include "Archivo.h"

// Leer la topología desde un archivo y devolver un mapa con los costos de los enlaces
map<string, map<string, int>> Archivo::leerTopologia(const string& nombreArchivo) {
    map<string, map<string, int>> topologia;
    ifstream archivo(nombreArchivo);

    if (!archivo) {
        cerr << "Error: No se pudo abrir el archivo " << nombreArchivo << endl;
        return topologia;
    }

    string linea;
    while (getline(archivo, linea)) {
        istringstream stream(linea);
        string origen, destino;
        int costo;

        stream >> origen >> destino >> costo;
        topologia[origen][destino] = costo;
    }

    archivo.close();
    return topologia;
}

// Guardar la topología en un archivo
void Archivo::guardarTopologia(const string& nombreArchivo, const map<string, map<string, int>>& topologia) {
    ofstream archivo(nombreArchivo);

    if (!archivo) {
        cerr << "Error: No se pudo crear el archivo " << nombreArchivo << endl;
        return;
    }

    for (const auto& [origen, destinos] : topologia) {
        for (const auto& [destino, costo] : destinos) {
            archivo << origen << " " << destino << " " << costo << endl;
        }
    }

    archivo.close();
}
