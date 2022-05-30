#ifndef TIPO_EMPLEADO_H
#define TIPO_EMPLEADO_H
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class TipoEmpleado{

    protected:
    int pagoNeto = 0;
    int idEmpleado;
    int tipoEmpleado;
    int idSupervisor;
    string nombre;
    string apellido;
    string email;
    string nombreSupervisor;
    vector<TipoEmpleado*> supervisados;
    

    public:
    //virtual int calculoPago();

    int obtenerIdEmpleado();
    int obtenerTipoEmpleado();
    int obtenerIdSupervisor();

    string obtenerNombreCompleto();
    string obtenerNombreSupervisor();
    string obtenerEmail();

    void asignarNombreSupervisor(string nombreSupervisor);
    void insertarSupervisado(TipoEmpleado *nuevoSupervisado);

    vector<TipoEmpleado *> obtenerSupervisados();
    

    friend ostream& operator << (ostream &entrada, TipoEmpleado *empleado);

};

#endif