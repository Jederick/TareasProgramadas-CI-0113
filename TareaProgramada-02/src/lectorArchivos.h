#ifndef LECTOR_ARCHIVOS
#define LECTOR_ARCHIVOS

#include <istream>
#include <sstream>

#include "profesionalPorHoras.h"
#include "empleadoNomina.h"
#include "planilla.h"

using namespace std;

class LectorArchivos{

    private:
        istream *archivoPersonas;
        istream *archivoNomina;
        istream *archivoHorasTrabajadas;

    public:
        LectorArchivos(istream *archivoPersonas, istream *archivoNomina, istream *archivoHorasTrabajadas);
        ~LectorArchivos();

        string imprimirResumen(Planilla *planilla);
        void llenarPlanilla(Planilla *planilla);
};

#endif