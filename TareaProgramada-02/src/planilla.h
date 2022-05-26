#ifndef PLANILLA_H
#define PLANILLA_H

#include "tipoEmpleado.h"
#include <map>

using namespace std;

class Planilla{

    private:    
        map<int, TipoEmpleado*> indiceEmpleados;
        TipoEmpleado *empleadoRaiz;
        
    public:
        Planilla(TipoEmpleado *empleadoRaiz);

        ~Planilla();

        void agregarEmpleado(TipoEmpleado *nuevoEmpleado);

        TipoEmpleado* obtenerEmpleado(int idEmpleado);
};

#endif