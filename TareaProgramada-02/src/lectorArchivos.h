#ifndef LECTOR_ARCHIVOS
#define LECTOR_ARCHIVOS

#include <istream>
#include <sstream>

#include "profesionalPorHoras.h"
#include "empleadoNomina.h"
#include "planilla.h"

class LectorArchivos{

    private:
        istream *archivoPersonas;
        istream *archivoNomina;
        istream *archivoHorasTrabajadas;

    public:
        LectorArchivos(istream *archivoPersonas, istream *archivoNomina, istream *archivoHorasTrabajadas);
        
        void llenarPlanilla(Planilla* planilla);

};

#endif