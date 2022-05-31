#ifndef EMPLEADO_NOMINA_H
#define EMPLEADO_NOMINA_H

#include "tipoEmpleado.h"

class EmpleadoNomina : public TipoEmpleado{
    
    private:
        float pagoBruto;
        float impuestoRetencion;
    public:
        EmpleadoNomina(int idEmpleado, string nombre, string apellido, string email, int tipoEmpleado, int idSupervisor, float pagoBruto);
        EmpleadoNomina();
        ~EmpleadoNomina();

        virtual void calculoPago();
        friend istream& operator >> (istream &entrada, EmpleadoNomina *empleado);

};
#endif  