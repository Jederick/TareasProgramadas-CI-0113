#include <gtest/gtest.h>
#include "../src/empleadoNomina.h"
#include "../src/planilla.h"

namespace{

   TEST(Planilla_Tests, Test_Inicializar_Planilla){

        EmpleadoNomina *empleadoEjemplo = new EmpleadoNomina("Tyler Denis", "denis_tyler@biz.com", 1, 1, 1, 10);
        Planilla *planillaEmpleados = new Planilla(empleadoEjemplo); 

        TipoEmpleado *empleadoEsperado = empleadoEjemplo;
        TipoEmpleado *empleadoActual = planillaEmpleados->obtenerEmpleado(1);

        EXPECT_EQ(empleadoEsperado, empleadoActual);
    }

    /*TEST(Arbol_test, Test_Agregar_Nodo){
        
        Arbol *arbol = new Arbol(2, 1);

        arbol->insertarValor(5,2,1);
        
        int esperado = 5;
        int actual = arbol->obtenerValor(2);

        EXPECT_EQ(esperado, actual);
    }*/
}