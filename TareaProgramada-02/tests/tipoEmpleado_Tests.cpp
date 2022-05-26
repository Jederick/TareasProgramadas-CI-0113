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
}