#ifndef EMPLEADO_NOMINA_H
#define EMPLEADO_NOMINA_H

#include "tipoEmpleado.h"

class EmpleadoNomina : public TipoEmpleado{
    
    private:
        float pagoBruto;

    public:
        EmpleadoNomina();
        //~EmpleadoNomina();

        friend istream& operator >> (istream &entrada, EmpleadoNomina *empleado);

};
#endif  