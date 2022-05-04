#include "envioPostal.h"

EnvioPostal::EnvioPostal(int kg, int km, int _clase){
    this->kilogramos = kg;
    this->kilometros = km;
    this->clase = _clase;

}

float EnvioPostal::calculoEnvio(){
    float precioEnvio;

    //Envio de 0 a 3 kilogramos en 1°, 2° o 3° clase
    if(this->kilogramos >= 0 && this->kilogramos <= 3){
        if(clase == 1){
            precioEnvio = 0.300 * this->kilometros;
            return precioEnvio;

        }else if(clase == 2){
            precioEnvio = 0.0280 * this->kilometros;
            return precioEnvio;
            
        }else if(clase == 3){
            precioEnvio = 0.0120 * this->kilometros;
            return precioEnvio;
        }

        //Envio de 4 a 8 kilogramos en 1°, 2° o 3° clase
    }else if(kilogramos >= 4 && kilogramos <= 8){
        if(clase == 1){
            precioEnvio = 0.450 * this->kilometros;
            return precioEnvio;

        }else if (clase == 2){
            precioEnvio = 0.0530 * this->kilometros;
            return precioEnvio;
            
        }else if(clase == 3){
            precioEnvio = 0.0120 * this->kilometros;
            return precioEnvio;
        }
    //Envio de 9 kilogramos o mas en 1°, 2° o 3° clase
    }else if(kilogramos >= 9){
        if(clase == 1){
            precioEnvio = 0.600 * this->kilometros;
            return precioEnvio;

        }else if (clase == 2){
            precioEnvio = 0.0750 * this->kilometros;
            return precioEnvio;
            
        }else if(clase == 3){
            precioEnvio = 0.0120 * this->kilometros;
            return precioEnvio;
        }
    }

    return -1;
}