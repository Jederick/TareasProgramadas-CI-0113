#ifndef ARBOL_H
#define ARBOL_H

#include "tipoEmpleado.h"
#include <map>

using namespace std;

class Arbol{

    private:    
        map<int, TipoEmpleado*> indiceEmpleados;
        TipoEmpleado *empleadoRaiz;
        
    public:
    Arbol(TipoEmpleado *empleadoRaiz);

    ~Arbol();

    void agregarEmpleado(TipoEmpleado *nuevoEmpleado);

    TipoEmpleado* obtenerEmpleado(int idEmpleado);
};

#endif