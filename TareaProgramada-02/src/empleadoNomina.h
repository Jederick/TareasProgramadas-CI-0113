#ifndef EMPLEADO_NOMINA_H
#define EMPLEADO_NOMINA_H

#include "tipoEmpleado.h"

class EmpleadoNomina : public TipoEmpleado{
    
    private:
    float pagoBruto;

    public:
    EmpleadoNomina(string nombreCompleto, string email, int idEmpleado, int tipoEmpleado, int idSupervisor, int pagoBruto, float PagoBruto);

    
};
#endif  