#ifndef TIPO_EMPLEADO_H
#define TIPO_EMPLEADO_H
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class TipoEmpleado{

    protected:
    float impuestoRetencion;
    float pagoNeto;
    int idEmpleado;
    int tipoEmpleado;
    int idSupervisor;
    string nombre;
    string apellido;
    string email;
    string nombreSupervisor;
    vector<TipoEmpleado*> supervisados;
    

    public:
    virtual void calculoPago() = 0;

    int obtenerIdEmpleado();
    int obtenerIdSupervisor();

    string obtenerNombreCompleto();
    string obtenerNombreSupervisor();

    void asignarNombreSupervisor(string nombreSupervisor);
    void insertarSupervisado(TipoEmpleado *nuevoSupervisado);

    float obtenerPagoNeto();
    float obtenerImpuestoRetencion();

    friend ostream& operator << (ostream &entrada, TipoEmpleado *empleado);

};

#endif