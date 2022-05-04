#include "./../src/envioPostal.h"
#include "./../src/tipoEnvio.h"
#include <gtest/gtest.h>

namespace{
    TEST(Test_EnvioPostal_CalculoEnvio, CeroTres_PimeraClase){

        // Arrange - configurar el escenario
        EnvioPostal* envioPostal = new EnvioPostal(1, 50, 1);

        // Act - ejecute la operación
        float actual = envioPostal->calculoEnvio();
        float esperada = 15;
        delete envioPostal;
        // Assert - valide los resultados
        EXPECT_FLOAT_EQ(esperada, actual);
    }
    TEST(Test_EnvioPostal_CalculoEnvio, CeroTres_SegundaClase){

        // Arrange - configurar el escenario
        EnvioPostal* envioPostal = new EnvioPostal(2, 500, 2);

        // Act - ejecute la operación
        float actual = envioPostal->calculoEnvio();
        float esperada = 14;
        delete envioPostal;
    
        // Assert - valide los resultados
        EXPECT_FLOAT_EQ(esperada, actual);

    }  
    TEST(Test_EnvioPostal_CalculoEnvio, CeroTres_TerceraClase){

        // Arrange - configurar el escenario
        EnvioPostal* envioPostal = new EnvioPostal(3, 700, 3);

        // Act - ejecute la operación
        float actual = envioPostal->calculoEnvio();
        float esperada = 8.4;
        delete envioPostal;
    
        // Assert - valide los resultados
        EXPECT_FLOAT_EQ(esperada, actual);

    }
    
    TEST(Test_EnvioPostal_CalculoEnvio, CuatroOcho_PrimeraClase){

        // Arrange - configurar el escenario
        EnvioPostal* envioPostal = new EnvioPostal(4, 50, 1);

        // Act - ejecute la operación
        float actual = envioPostal->calculoEnvio();
        float esperada = 22.5;
        delete envioPostal;
    
        // Assert - valide los resultados
        EXPECT_FLOAT_EQ(esperada, actual);
    }
    TEST(Test_EnvioPostal_CalculoEnvio, CuatroOcho_SegundaClase){

        // Arrange - configurar el escenario
        EnvioPostal* envioPostal = new EnvioPostal(5, 500, 2);

        // Act - ejecute la operación
        float actual = envioPostal->calculoEnvio();
        float esperada = 26.5;
        delete envioPostal;
    
        // Assert - valide los resultados
        EXPECT_FLOAT_EQ(esperada, actual);

    }
    TEST(Test_EnvioPostal_CalculoEnvio, CuatroOcho_TerceraClase){

        // Arrange - configurar el escenario
        EnvioPostal* envioPostal = new EnvioPostal(8, 700, 3);

        // Act - ejecute la operación
        float actual = envioPostal->calculoEnvio();
        float esperada = 8.4;
        delete envioPostal;
    
        // Assert - valide los resultados
        EXPECT_FLOAT_EQ(esperada, actual);

    }

    TEST(Test_EnvioPostal_CalculoEnvio, NueveoMas_primeraClase){

        // Arrange - configurar el escenario
        EnvioPostal* envioPostal = new EnvioPostal(9, 50, 1);

        // Act - ejecute la operación
        float actual = envioPostal->calculoEnvio();
        float esperada = 30;
        delete envioPostal;
    
        // Assert - valide los resultados
        EXPECT_FLOAT_EQ(esperada, actual);

    }
    TEST(Test_EnvioPostal_CalculoEnvio, NueveoMas_segundaClase){

        // Arrange - configurar el escenario
        EnvioPostal* envioPostal = new EnvioPostal(15, 500, 2);

        // Act - ejecute la operación
        float actual = envioPostal->calculoEnvio();
        float esperada = 37.5;
        delete envioPostal;
    
        // Assert - valide los resultados
        EXPECT_FLOAT_EQ(esperada, actual);

    }
    TEST(Test_EnvioPostal_CalculoEnvio, NueveoMas_terceraClase){

        // Arrange - configurar el escenario
        EnvioPostal* envioPostal = new EnvioPostal(20, 700, 3);

        // Act - ejecute la operación
        float actual = envioPostal->calculoEnvio();
        float esperada = 8.4;
        delete envioPostal;
    
        // Assert - valide los resultados
        EXPECT_FLOAT_EQ(esperada, actual);

    }

}