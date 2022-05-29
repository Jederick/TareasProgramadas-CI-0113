#ifndef EMPLEADO_NOMINA_H
#define EMPLEADO_NOMINA_H

#include "tipoEmpleado.h"

class EmpleadoNomina : public TipoEmpleado{
    
    private:
    float pagoBruto;

    public:
    EmpleadoNomina(string nombre, string apellido, string email, int idEmpleado, int tipoEmpleado, int idSupervisor, float PagoBruto);
    //~EmpleadoNomina();
    friend istream& operator >> (istream &entrada, EmpleadoNomina *empleado);
    friend ostream& operator << (ostream &salida, const EmpleadoNomina *empleado);
};
#endif  