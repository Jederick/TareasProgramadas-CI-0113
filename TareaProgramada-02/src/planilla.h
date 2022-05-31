#ifndef PLANILLA_H
#define PLANILLA_H

#include <map>
#include <istream>
#include <sstream>

#include "tipoEmpleado.h"

using namespace std;

class Planilla{

    private:    
        map<int, TipoEmpleado*> indiceEmpleados;
        TipoEmpleado *empleadoRaiz;

    public:
        Planilla(TipoEmpleado* empleadoRaiz);
        Planilla();
        ~Planilla();

        void agregarEmpleado(TipoEmpleado *nuevoEmpleado);

        float obtenerTotalPagosNetos();
        void obtenerPagosBrutosTotales();
        float obtenerImpuestosTotales();

        TipoEmpleado* obtenerEmpleado(int idEmpleado);
        
        friend istream& operator >> (istream &entrada, Planilla *Planilla);
        friend ostream& operator << (ostream &salida, const Planilla *planilla);
};

#endif