#ifndef ENRUTADOR_H
#define ENRUTADOR_H

#include <map>
#include <list>
#include <string>
#include <limits>

using namespace std;

class Enrutador {
private:
    string id;  // Identificador del enrutador
    map<string, pair<string, int>> tablaEnrutamiento;  // Destino -> {Siguiente salto, Costo}
    map<string, int> enlaces;  // Enlaces directos con vecinos y sus costos

public:
    // Constructor por defecto y constructor con ID
    Enrutador();  // Constructor por defecto
    Enrutador(const string& id);  // Constructor con parámetro

    // Métodos para gestión de enlaces
    void agregarEnlace(const string& destino, int costo);
    void eliminarEnlace(const string& destino);

    // Métodos para obtener información
    list<string> obtenerCamino(const string& destino);
    int costoEnvio(const string& destino);

    // Actualiza la tabla de enrutamiento
    void actualizarTabla();

    // Accesor para la tabla de enrutamiento
    const map<string, pair<string, int>>& obtenerTablaEnrutamiento() const;
};

#endif // ENRUTADOR_H
