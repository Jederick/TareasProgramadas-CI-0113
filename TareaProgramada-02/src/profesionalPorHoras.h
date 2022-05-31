#ifndef PROFESIONAL_POR_HORAS_H
#define PROFESIONAL_POR_HORAS_H

#include "tipoEmpleado.h"

class ProfesionalPorHoras : public TipoEmpleado{
    
    private:
    float montoPorHora;
    int horasEnMes;

    public:
    ProfesionalPorHoras(int _idEmpleado, string _nombre, string _apellido, string _email, int _tipoEmpleado, int _idSupervisor, float _montoPorHora, float _horasEnMes);
    ProfesionalPorHoras();
    ~ProfesionalPorHoras();

    virtual void calculoPago();
    friend istream& operator >> (istream &entrada, ProfesionalPorHoras *empleado);
    


  
};
#endif  