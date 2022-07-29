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
    bool esNumero(const string& variable);

    public:
    Tienda(string nombre, string direccionInternet, string direccionFisica, string telefono);
    Tienda();
    ~Tienda();

    void agregarProducto(Producto *nuevoProducto);
    void modificarProducto(int idAModificar, int nuevaId, string nuevoNombre, int nuevasExistencias);
    void eliminarProducto(Producto *productoAEliminar);

    void exportarEnStreamBinario(ostream *streamSalida);
    void cargarDesdeStreamBinario(istream *streamEntrada);

    Producto* obtenerProducto(int idProducto);

    vector<Producto *> obtenerInventario();

    string obtenerNombre();
    string obtenerDireccionInternet();
    string obtenerDireccionFisica();
    string obtenerTelefono();

    /*void establecerNombre(string nombre);
    void establecerDireccionInternet(string direccionInternet);
    void establecerDireccionFisica(string direccionFisica);
    void establecerTelefono(string telefono);*/

    friend ostream& operator << (ostream &salida, const Tienda *tienda);
};

#endif

