#include "Enrutador.h"

// Constructor por defecto
Enrutador::Enrutador() : id("") {}

// Constructor con ID
Enrutador::Enrutador(const string& id) : id(id) {}

// Agregar o actualizar un enlace directo
void Enrutador::agregarEnlace(const string& destino, int costo) {
    enlaces[destino] = costo;
    actualizarTabla();
}

// Eliminar un enlace directo
void Enrutador::eliminarEnlace(const string& destino) {
    enlaces.erase(destino);
    actualizarTabla();
}

// Obtener el camino óptimo hacia un destino
list<string> Enrutador::obtenerCamino(const string& destino) {
    list<string> camino;
    string actual = destino;

    while (actual != id && tablaEnrutamiento.find(actual) != tablaEnrutamiento.end()) {
        camino.push_front(actual);
        actual = tablaEnrutamiento[actual].first;
    }

    if (actual == id) camino.push_front(id);
    return camino;
}

// Devolver el costo mínimo hacia un destino
int Enrutador::costoEnvio(const string& destino) {
    if (tablaEnrutamiento.find(destino) != tablaEnrutamiento.end()) {
        return tablaEnrutamiento[destino].second;
    }
    return numeric_limits<int>::max();  // Infinito si no hay camino
}

// Algoritmo de Dijkstra para actualizar la tabla de enrutamiento
void Enrutador::actualizarTabla() {
    map<string, int> distancias;
    map<string, string> previo;

    for (const auto& [vecino, costo] : enlaces) {
        distancias[vecino] = numeric_limits<int>::max();
    }
    distancias[id] = 0;

    list<string> pendientes = {id};
    while (!pendientes.empty()) {
        string nodoActual = pendientes.front();
        pendientes.pop_front();

        for (const auto& [vecino, costo] : enlaces) {
            int nuevaDistancia = distancias[nodoActual] + costo;
            if (nuevaDistancia < distancias[vecino]) {
                distancias[vecino] = nuevaDistancia;
                previo[vecino] = nodoActual;
                pendientes.push_back(vecino);
            }
        }
    }

    tablaEnrutamiento.clear();
    for (const auto& [destino, distancia] : distancias) {
        string siguienteSalto = (previo.find(destino) != previo.end()) ? previo[destino] : "-";
        tablaEnrutamiento[destino] = {siguienteSalto, distancia};
    }
}

// Obtener una referencia a la tabla de enrutamiento
const map<string, pair<string, int>>& Enrutador::obtenerTablaEnrutamiento() const {
    return tablaEnrutamiento;
}
