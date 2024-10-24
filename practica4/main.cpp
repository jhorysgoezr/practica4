#include <iostream>
#include "Red.h"
#include "Archivo.h"

using namespace std;

void imprimirEnrutadores(const Red& red) {
    const auto& enrutadores = red.obtenerEnrutadores();
    cout << "Enrutadores en la red:\n";
    for (const auto& [id, enrutador] : enrutadores) {
        cout << "- Enrutador: " << id << "\n";
    }
    cout << endl;
}

void imprimirCamino(const list<string>& camino) {
    cout << "Camino óptimo: ";
    for (const auto& salto : camino) {
        cout << salto << " ";
    }
    cout << endl;
}

int main() {
    Red red;

    // Cargar la topología desde un archivo
    auto topologia = Archivo::leerTopologia("topologia.txt");
    for (const auto& [origen, destinos] : topologia) {
        red.agregarEnrutador(origen);
        for (const auto& [destino, costo] : destinos) {
            red.actualizarTopologia(origen, destino, costo);
        }
    }

    // Imprimir los enrutadores cargados
    imprimirEnrutadores(red);

    // Calcular e imprimir camino y costo
    list<string> camino = red.caminoOptimo("A", "C");
    imprimirCamino(camino);

    int costo = red.costoPaquete("A", "C");
    cout << "Costo de enviar paquete de A a C: " << costo << endl;

    // Guardar la topología en un archivo nuevo
    Archivo::guardarTopologia("nueva_topologia.txt", topologia);

    return 0;
}
