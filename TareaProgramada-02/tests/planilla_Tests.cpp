#include <gtest/gtest.h>
#include "../src/empleadoNomina.h"
#include "../src/planilla.h"

namespace{

   TEST(Planilla_Tests, Test_Inicializar_Planilla){

        EmpleadoNomina *empleadoEjemplo = new EmpleadoNomina("Tyler", "Denis", "denis_tyler@biz.com", 1, 1, 1, 10);
        Planilla *planillaEmpleados = new Planilla(empleadoEjemplo); 

        TipoEmpleado *empleadoEsperado = empleadoEjemplo;
        TipoEmpleado *empleadoActual = planillaEmpleados->obtenerEmpleado(1);

        EXPECT_EQ(empleadoEsperado, empleadoActual);

        //delete empleadoEjemplo;
        //delete planillaEmpleados;
    }

    TEST(Planilla_Tests, Test_Obtener_Empleado_De_Planilla){

        EmpleadoNomina *empleadoEjemplo = new EmpleadoNomina("Tyler", "Denis", "denis_tyler@biz.com", 1, 1, 1, 10);
        Planilla *planillaEmpleados = new Planilla(empleadoEjemplo); 

        TipoEmpleado *empleadoEsperado = empleadoEjemplo;
        TipoEmpleado *empleadoActual = planillaEmpleados->obtenerEmpleado(1);

        EXPECT_EQ(empleadoEsperado, empleadoActual);

        //delete empleadoEjemplo;
        //delete planillaEmpleados;
    }

    TEST(Planilla_Tests, Test_Agregar_Empleado_A_Planilla){

        EmpleadoNomina *empleadoSupervisor = new EmpleadoNomina("Tyler", "Denis", "denis_tyler@biz.com", 1, 1, 1, 10);
        EmpleadoNomina *empleadoSupervisado = new EmpleadoNomina("Clarissa", "Parker", "clarissa_parker@biz.com", 2, 1, 1, 1005);
    
        Planilla *planillaEmpleados = new Planilla(empleadoSupervisor); 

        planillaEmpleados->agregarEmpleado(empleadoSupervisado);
        TipoEmpleado *empleadoEsperado = empleadoSupervisado;
        TipoEmpleado *empleadoActual = planillaEmpleados->obtenerEmpleado(2);

        EXPECT_EQ(empleadoEsperado, empleadoActual);

        //delete empleadoSupervisado;
        //delete empleadoSupervisor;
        //delete planillaEmpleados;
    }
    
}