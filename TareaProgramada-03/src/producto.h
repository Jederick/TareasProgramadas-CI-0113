#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <string>
#include <cstring>
#include <iostream>

using namespace std;

class Producto{

    private:
    int id;
    char nombre[20];
    int existencias;

    public:
    Producto(int id, string nombre, int cantidad);
    Producto();
    ~Producto();
    
    int obtenerId();
    int obtenerExistencias();

    string obtenerNombre();

    void editar(int nuevaId, string nuevoNombre, int nuevasExistencias);

    friend ostream& operator << (ostream &salida, const Producto *producto);
    
};


#endif