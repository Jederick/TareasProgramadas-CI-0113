#ifndef TIENDA_H
#define TIENDA_H

#include <string>
#include <vector>
#include <iostream>

#include "producto.h"

using namespace std;

class Tienda{
        
    private:        
    char nombre[15];
    char direccionInternet[24];
    char direccionFisica[24];
    char telefono[8];

    vector<Producto *> inventario;

    public:
    Tienda(string nombre, string direccionInternet, string direccionFisica, string telefono);
    Tienda();
    ~Tienda();
    
    void agregarProducto(Producto *nuevoProducto);
    void modificarProducto(int idAModificar, int nuevaId, string nuevoNombre, int nuevasExistencias);
    void eliminarProducto(int idAEliminar);
    
    void exportarEnStreamBinario(ostream *streamSalida);
    void cargarDesdeStreamBinario(istream *streamEntrada);

    friend ostream& operator << (ostream &salida, const Tienda *tienda);
};




#endif 