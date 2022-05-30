#include <gtest/gtest.h>

#include "../src/tipoEmpleado.h"
#include "../src/profesionalPorHoras.h"

namespace{

   TEST(TipoEmpleado_Tests, Test_Obtener_ID_Empleado){
        
        ostringstream streamSalidaEmpleado;
        streamSalidaEmpleado << "24 Deborah Nurton deborah_nurton@biz.com 1 6";
        string empleado = streamSalidaEmpleado.str();

        istringstream streamEntradaEmpleado(empleado);
        
        ProfesionalPorHoras *empleadoEjemplo = new ProfesionalPorHoras();
        streamEntradaEmpleado >> empleadoEjemplo;
        
        int idEsperada = 24;
        int idActual = empleadoEjemplo->obtenerIdEmpleado();

        EXPECT_EQ(idEsperada, idActual);
        delete empleadoEjemplo;
    }

    TEST(TipoEmpleado_Tests, Test_Obtener_ID_Supervisor){

        ostringstream streamSalidaEmpleado;
        streamSalidaEmpleado << "199 Remy Bryson remy_bryson@biz.com 1 95";
        string empleado = streamSalidaEmpleado.str();

        istringstream streamEntradaEmpleado(empleado);
        
        ProfesionalPorHoras *empleadoEjemplo = new ProfesionalPorHoras();
        streamEntradaEmpleado >> empleadoEjemplo;
        
        int idEsperada = 95;
        int idActual = empleadoEjemplo->obtenerIdSupervisor();

        EXPECT_EQ(idEsperada, idActual);
        delete empleadoEjemplo;
    }

    TEST(TipoEmpleado_Tests, Test_Obtener_Nombre_Empleado){

        ostringstream streamSalidaEmpleado;
        streamSalidaEmpleado << "15 Stella Rossi stella_rossi@biz.com 1 4";
        string empleado = streamSalidaEmpleado.str();

        istringstream streamEntradaEmpleado(empleado);
        
        ProfesionalPorHoras *empleadoEjemplo = new ProfesionalPorHoras();
        streamEntradaEmpleado >> empleadoEjemplo;
        
        string nombreEsperado = "Stella Rossi";
        string nombreActual = empleadoEjemplo->obtenerNombreCompleto();

        EXPECT_EQ(nombreEsperado, nombreActual);
        delete empleadoEjemplo;
    }

    TEST(TipoEmpleado_Tests, Test_Obtener_Asignar_Nombre_Supervisor){
        ProfesionalPorHoras *empleadoEjemplo = new ProfesionalPorHoras();
        empleadoEjemplo->asignarNombreSupervisor("Denis Tyler");
        
        string nombreEsperado = "Denis Tyler";
        string nombreActual = empleadoEjemplo->obtenerNombreSupervisor();

        EXPECT_EQ(nombreEsperado, nombreActual);
        delete empleadoEjemplo;
    }
}