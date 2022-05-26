#include <gtest/gtest.h>

#include "../src/tipoEmpleado.h"
#include "../src/profesionalPorHoras.h"

namespace{

   TEST(TipoEmpleado_Tests, Test_Obtener_ID_Empleados){
        
        ProfesionalPorHoras *empleadoEjemplo = new ProfesionalPorHoras("Tyler Denis", "denis_tyler@biz.com", 1, 1, 1, 10, 10.5);
        
        int idEmpleadoEsperada = 1;
        int idActual = empleadoEjemplo->obtenerIdEmpleado();

        EXPECT_EQ(idEmpleadoEsperada, idActual);
        delete empleadoEjemplo;
    }

    TEST(TipoEmpleado_Tests, Test_Obtener_Tipo_Empleado){
        
        ProfesionalPorHoras *empleadoEjemplo = new ProfesionalPorHoras("Tyler Denis", "denis_tyler@biz.com", 1, 1, 1, 10, 10.5);
        
        int tipoEmpleadoEsperado = 1;
        int tipoEmpleadoActual = empleadoEjemplo->obtenerTipoEmpleado();

        EXPECT_EQ(tipoEmpleadoEsperado, tipoEmpleadoActual);
        delete empleadoEjemplo;
    }

    TEST(TipoEmpleado_Tests, Test_Obtener_ID_Supervisor){
        
        ProfesionalPorHoras *ejemploSupervisor = new ProfesionalPorHoras("Tyler Denis", "denis_tyler@biz.com", 1, 1, 1, 10, 10.5);
        ProfesionalPorHoras *ejemploSupervisado = new ProfesionalPorHoras("Clarissa Parker", "clarissa_parker@biz.com", 2, 1, 1, 12, 12.3);

        int idSupervisorEsperado = 1;
        int idSupervisorActual = ejemploSupervisado->obtenerIdSupervisor();

        EXPECT_EQ(idSupervisorEsperado, idSupervisorActual);

        delete ejemploSupervisado;
        delete ejemploSupervisor;
    }

    TEST(TipoEmpleado_Tests, Test_Obtener_Nombre_Empleado){
        
        ProfesionalPorHoras *empleadoEjemplo = new ProfesionalPorHoras("Tyler Denis", "denis_tyler@biz.com", 1, 1, 1, 10, 10.5);
        
        string nombreEsperado = "Tyler Denis";
        string nombreActual = empleadoEjemplo->obtenerNombreCompleto();

        EXPECT_EQ(nombreEsperado, nombreActual);
        delete empleadoEjemplo;
    }

    TEST(TipoEmpleado_Tests, Test_Obtener_Email){
        
        ProfesionalPorHoras *empleadoEjemplo = new ProfesionalPorHoras("Tyler Denis", "denis_tyler@biz.com", 1, 1, 1, 10, 10.5);
        
        string emailEsperado = "denis_tyler@biz.com";
        string emailActual = empleadoEjemplo->obtenerEmail();

        EXPECT_EQ(emailEsperado, emailActual);
        delete empleadoEjemplo;
    }

}