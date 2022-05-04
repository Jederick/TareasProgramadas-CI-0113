#include "./../src/envioPostal.h"
#include "./../src/tipoEnvio.h"
#include <gtest/gtest.h>

namespace{
    TEST(Test_EnvioPostal_CalculoEnvio, CeroTres_PimeraClase){
        /// AAA

        // Arrange - configurar el escenario
        EnvioPostal* envioPostal = new EnvioPostal(0, 50, 1);

        // Act - ejecute la operación
        float actual = envioPostal->calculoEnvio();
        float esperada = 15;
    
        // Assert - valide los resultados
        EXPECT_FLOAT_EQ(esperada, actual);
    }
/**
    TEST(Test_EnvioPostal_CalculoEnvio, CeroTres_SegundaClase){
        /// AAA

        // Arrange - configurar el escenario
        int calculadora;

        // Act - ejecute la operación
        int actual = 0;
        int esperada = 1;

        // Assert - valide los resultados
        EXPECT_EQ(esperada, actual);

    }
    TEST(Test_EnvioPostal_CalculoEnvio, CeroTres_TerceraClase){
        /// AAA

        // Arrange - configurar el escenario
        int calculadora;

        // Act - ejecute la operación
        int actual = 0;
        int esperada = 1;

        // Assert - valide los resultados
        EXPECT_EQ(esperada, actual);

    }

    TEST(Test_EnvioPostal_CalculoEnvio, CuatroOcho_PrimeraClase){

        /// AAA

        // Arrange - configurar el escenario
        int calculadora;

        // Act - ejecute la operación
        int actual = 0;
        int esperada = 1;

        // Assert - valide los resultados
        EXPECT_EQ(esperada, actual);

    }
    TEST(Test_EnvioPostal_CalculoEnvio, CuatroOcho_SegundaClase){

        /// AAA

        // Arrange - configurar el escenario
        int calculadora;

        // Act - ejecute la operación
        int actual = 0;
        int esperada = 1;

        // Assert - valide los resultados
        EXPECT_EQ(esperada, actual);

    }
    TEST(Test_EnvioPostal_CalculoEnvio, CuatroOcho_TerceraClase){

        /// AAA

        // Arrange - configurar el escenario
        int calculadora;

        // Act - ejecute la operación
        int actual = 0;
        int esperada = 1;

        // Assert - valide los resultados
        EXPECT_EQ(esperada, actual);

    }

    TEST(Test_EnvioPostal_CalculoEnvio, NueveoMas_primeraClase){

        /// AAA

        // Arrange - configurar el escenario
        int calculadora;

        // Act - ejecute la operación
        int actual = 0;
        int esperada = 1;

        // Assert - valide los resultados
        EXPECT_EQ(esperada, actual);

    }
    TEST(Test_EnvioPostal_CalculoEnvio, NueveoMas_segundaClase){

        /// AAA

        // Arrange - configurar el escenario
        int calculadora;

        // Act - ejecute la operación
        int actual = 0;
        int esperada = 1;

        // Assert - valide los resultados
        EXPECT_EQ(esperada, actual);

    }
    TEST(Test_EnvioPostal_CalculoEnvio, NueveoMas_terceraClase){

        /// AAA

        // Arrange - configurar el escenario
        int calculadora;

        // Act - ejecute la operación
        int actual = 0;
        int esperada = 1;

        // Assert - valide los resultados
        EXPECT_EQ(esperada, actual);

    }
    **/
}