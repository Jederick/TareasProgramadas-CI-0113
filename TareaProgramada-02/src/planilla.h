#ifndef PLANILLA_H
#define PLANILLA_H

#include <map>
#include <istream>

#include "tipoEmpleado.h"


using namespace std;

class Planilla{

    private:    
        map<int, TipoEmpleado*> indiceEmpleados;
        TipoEmpleado *empleadoRaiz;
        
        istream *archivoPersonas;
        istream *archivoNomina;
        istream *archivoHorasTrabajadas;

    public:
        Planilla(TipoEmpleado *empleadoRaiz);
        Planilla(istream *archivoPersonas, istream *archivoNomina, istream *archivoHorasTrabajadas);

        ~Planilla();

        void agregarEmpleado(TipoEmpleado *nuevoEmpleado);

        TipoEmpleado* obtenerEmpleado(int idEmpleado);

        
};

#endif