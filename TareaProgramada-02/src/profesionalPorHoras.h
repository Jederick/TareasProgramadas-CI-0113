#ifndef PROFESIONAL_POR_HORAS_H
#define PROFESIONAL_POR_HORAS_H

#include "tipoEmpleado.h"

class ProfesionalPorHoras : public TipoEmpleado{
    
    private:
    float montoPorHora;
    int horasEnMes;

    public:
    ProfesionalPorHoras();
    //~ProfesionalPorHoras();

    friend istream& operator >> (istream &entrada, ProfesionalPorHoras *empleado);
    


  
};
#endif  