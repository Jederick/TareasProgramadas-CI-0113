#include <gtest/gtest.h>
#include <sstream>
#include <fstream>

#include "../src/tienda.h"
#include "../src/excepcionIdInexistente.h"
#include "../src/excepcionLimiteChar.h"

using namespace std;

namespace{
    TEST(Tienda_tests, consultarYAgregarProductos_tests){
        
        Tienda *tienda = new Tienda("Papayaparaya", "frutilla.com", "frente de pollolandia", "27951413");
        Producto *producto1 = new Producto(1, "aguacate", 50);
        Producto *producto2 = new Producto(2, "papaya", 95);
        tienda->agregarProducto(producto1);
        tienda->agregarProducto(producto2);

        ostringstream streamSalida;
        streamSalida << tienda;

        string salidaEsperada = "Tienda Papayaparaya\nId: 1. Nombre: aguacate. Existencias en la tienda: 50\nId: 2. Nombre: papaya. Existencias en la tienda: 95\n";
        string salidaActual = streamSalida.str();

        EXPECT_EQ(salidaEsperada, salidaActual);

    }

    TEST(Tienda_tests, modificarProductos_tests){
        
        Tienda *tienda = new Tienda("Papayaparaya", "ice", "frente de pollolandia", "27951413");
        Producto *producto1 = new Producto(1, "aguacate", 35);
        Producto *producto2 = new Producto(2, "papaya", 78);
        tienda->agregarProducto(producto1);
        tienda->agregarProducto(producto2);
        tienda->modificarProducto(1, 5, "fanta", 27);
        tienda->modificarProducto(2, 97, "taza", 50);

        ostringstream streamSalida;
        streamSalida << tienda;

        string salidaEsperada = "Tienda Papayaparaya\nId: 5. Nombre: fanta. Existencias en la tienda: 27\nId: 97. Nombre: taza. Existencias en la tienda: 50\n";
        string salidaActual = streamSalida.str();

        EXPECT_EQ(salidaEsperada, salidaActual);

    }

    TEST(Tienda_tests, eliminarProducto_tests){
                
        Tienda *tienda = new Tienda("Papayaparaya", "frutilla.com", "frente de pollolandia", "27951413");
        Producto *producto1 = new Producto(1, "aguacate", 100);
        Producto *producto2 = new Producto(2, "papaya", 75);
        tienda->agregarProducto(producto1);
        tienda->agregarProducto(producto2);
        tienda->eliminarProducto(1);

        ostringstream streamSalida;
        streamSalida << tienda;

        string salidaEsperada = "Tienda Papayaparaya\nId: 2. Nombre: papaya. Existencias en la tienda: 75\n";
        string salidaActual = streamSalida.str();

        EXPECT_EQ(salidaEsperada, salidaActual);
    }

    TEST(Tienda_tests, excepcionIdInexistente_test){

        Tienda *tienda = new Tienda("Papayaparaya", "frutilla.com", "frente de pali", "27951413");
        Producto *producto1 = new Producto(1, "aguacate", 250);
        tienda->agregarProducto(producto1);
        
          EXPECT_THROW({
            tienda->modificarProducto(5, 7, "cuchara", 100);
        }, ExcepcionIdInexistente);

        EXPECT_THROW({
            tienda->eliminarProducto(4);
        }, ExcepcionIdInexistente);  
    }

    TEST(Tienda_tests, excepcionLimiteChar_test){

        EXPECT_THROW({
            Tienda *tienda = new Tienda("Papayaparayaasdasdasdasdasdasd", "frutilla.com", "frente de pollolandia", "27951413");
        }, ExcepcionLimiteChar);        
    }

    TEST(Tienda_tests, exportarYCargarArchivoBinario_test){

        Tienda *tiendaAExportar = new Tienda("Papayaparaya", "frutilla.com", "frente de pollolandia", "27951413");
        Producto *producto1 = new Producto(1, "aguacate", 50);
        Producto *producto2 = new Producto(2, "papaya", 95);
        tiendaAExportar->agregarProducto(producto1);
        tiendaAExportar->agregarProducto(producto2);

        //Exportar archivo binario
        ofstream archivoSalida;
        archivoSalida.open("tienda_test.dat", ios::out|ios::binary);
        if(!archivoSalida.is_open()){
            cerr << "No se pudo abrir el archivo tienda_test.dat";
        }
        
        tiendaAExportar->exportarEnStreamBinario(&archivoSalida);
        archivoSalida.close();
        //Cargar archivo binario
        Tienda *tiendaACargar = new Tienda();

        ifstream archivoEntrada;
        archivoEntrada.open("tienda_test.dat", ios::in|ios::binary);
        if(!archivoEntrada.is_open()){
            cerr << "No se pudo abrir el archivo tienda_test.dat";
        }
        tiendaACargar->cargarDesdeStreamBinario(&archivoEntrada);
        archivoEntrada.close();


        //DELETESSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS TIENDASSS

        //Probar resultados
        ostringstream streamTiendaAExportar;
        streamTiendaAExportar << tiendaAExportar;

        ostringstream streamTiendaACargar;
        streamTiendaACargar << tiendaACargar;

        string salidaEsperada = "Tienda Papayaparaya\nId: 1. Nombre: aguacate. Existencias en la tienda: 50\nId: 2. Nombre: papaya. Existencias en la tienda: 95\n";
        string actualExportado = streamTiendaAExportar.str();
        string actualCargado = streamTiendaACargar.str();
        

        
        EXPECT_EQ(salidaEsperada, actualExportado);
        EXPECT_EQ(salidaEsperada, actualCargado);
        
    }
}