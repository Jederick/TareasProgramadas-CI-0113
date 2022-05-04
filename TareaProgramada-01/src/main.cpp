#include "envioPostal.h"
#include "envioFedex.h"
#include <vector>
#include <iostream>

int main(){

    vector<TipoEnvio*> listaEnvios;
    float totalMontoEnvios = 0;

    EnvioPostal* envioPostal1 = new EnvioPostal(8, 50, 1); //22.5
    EnvioPostal* envioPostal2 = new EnvioPostal(4, 500, 2); // 26.5
    EnvioPostal* envioPostal3 = new EnvioPostal(15, 500, 2); //37.5

    EnvioFedex* envioFedex1 = new EnvioFedex(200, 15); //45.00
    EnvioFedex* envioFedex2 = new EnvioFedex(600,15); //60.00
    EnvioFedex* envioFedex3 = new EnvioFedex(600,5); //50.00
    
    listaEnvios.push_back(envioPostal1);
    listaEnvios.push_back(envioPostal2);
    listaEnvios.push_back(envioPostal3);

    listaEnvios.push_back(envioFedex1);
    listaEnvios.push_back(envioFedex2);
    listaEnvios.push_back(envioFedex3);

    for(TipoEnvio* tipoEnvio : listaEnvios){
        totalMontoEnvios += tipoEnvio->calculoEnvio();
    }

    std::cout << "El monto total de los envios es de: " << totalMontoEnvios << std::endl;

    return 0;
}