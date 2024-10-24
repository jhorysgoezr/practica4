#include "Red.h"

// Constructor por defecto
Red::Red() {}

// Agregar un enrutador a la red
void Red::agregarEnrutador(const string& id) {
    enrutadores.emplace(id, Enrutador(id));
}

// Remover un enrutador de la red
void Red::removerEnrutador(const string& id) {
    enrutadores.erase(id);
}

// Actualizar la topología agregando o modificando un enlace
void Red::actualizarTopologia(const string& origen, const string& destino, int costo) {
    if (enrutadores.find(origen) != enrutadores.end()) {
        enrutadores[origen].agregarEnlace(destino, costo);
    }
}

// Calcular el costo de enviar un paquete desde origen a destino
int Red::costoPaquete(const string& origen, const string& destino) {
    if (enrutadores.find(origen) != enrutadores.end()) {
        return enrutadores[origen].costoEnvio(destino);
    }
    return -1;  // Retorna -1 si el enrutador de origen no existe
}

// Obtener el camino óptimo desde origen hasta destino
list<string> Red::caminoOptimo(const string& origen, const string& destino) {
    if (enrutadores.find(origen) != enrutadores.end()) {
        return enrutadores[origen].obtenerCamino(destino);
    }
    return {};  // Devuelve lista vacía si el enrutador de origen no existe
}

// Acceso a los enrutadores de la red
const map<string, Enrutador>& Red::obtenerEnrutadores() const {
    return enrutadores;
}
