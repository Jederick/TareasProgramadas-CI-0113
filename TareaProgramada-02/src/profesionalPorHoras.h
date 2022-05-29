#ifndef PROFESIONAL_POR_HORAS_H
#define PROFESIONAL_POR_HORAS_H

#include "tipoEmpleado.h"

class ProfesionalPorHoras : public TipoEmpleado{
    
    private:
    float montoPorHora;
    int horasEnMes;

    public:
    ProfesionalPorHoras(string nombre, string apellido, string email, int idEmpleado, int tipoEmpleado, int idSupervisor, int horasEnMesfloat, float montoPorHora);

    //~ProfesionalPorHoras();


    friend istream& operator >> (istream &entrada, ProfesionalPorHoras *empleado);
    friend ostream& operator << (ostream &salida, const ProfesionalPorHoras *empleado);


  
};
#endif  