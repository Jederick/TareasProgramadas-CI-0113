#ifndef PROFESIONAL_POR_HORAS_H
#define PROFESIONAL_POR_HORAS_H

#include "tipoEmpleado.h"

class ProfesionalPorHoras : public TipoEmpleado{
    
    private:
    float montoPorHora;
    int horasEnMes;

    public:
    ProfesionalPorHoras(string nombreCompleto, string email, int idEmpleado, int tipoEmpleado, int idSupervisor, int horasEnMesfloat, float montoPorHora);

  
};
#endif  