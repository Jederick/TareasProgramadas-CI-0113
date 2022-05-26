#include "empleadoNomina.h"

EmpleadoNomina::EmpleadoNomina(string _nombreCompleto, string _email, int _idEmpleado, int _tipoEmpleado, int _idSupervisor, int _pagoBruto, float _PagoBruto){
    this->nombreCompleto = _nombreCompleto;
    this->email = _email;
    this->idEmpleado = _idEmpleado;
    this->tipoEmpleado = _tipoEmpleado;
    this->idSupervisor = _idSupervisor;
    this->pagoBruto = _pagoBruto;
}
