#ifndef RED_H
#define RED_H

#include <map>
#include <string>
#include <iostream>
#include "Enrutador.h"

using namespace std;

class Red {
private:
    map<string, Enrutador> enrutadores;  // Mapa de enrutadores por su ID

public:
    // Constructor por defecto
    Red();

    // Métodos para gestión de enrutadores
    void agregarEnrutador(const string& id);
    void removerEnrutador(const string& id);
    void actualizarTopologia(const string& origen, const string& destino, int costo);

    // Métodos para obtener información
    int costoPaquete(const string& origen, const string& destino);
    list<string> caminoOptimo(const string& origen, const string& destino);

    // Acceso a los enrutadores
    const map<string, Enrutador>& obtenerEnrutadores() const;
};

#endif // RED_H
