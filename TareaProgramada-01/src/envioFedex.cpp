#include "envioFedex.h"

EnvioFedex::EnvioFedex(int km, int kg){
    this->kilometros = km;
    this->kilogramos = kg;
}

float EnvioFedex::calculoEnvio(){

    if(this->kilometros < 500 && this->kilogramos < 10){
        return this->costoBase;

    }else if(this->kilometros > 500 && this->kilogramos < 10){
        return this->costoBase += 15.00;

    }else if (this->kilometros < 500 && this->kilogramos > 10){
        return this->costoBase += 10.00;

    }else if (this->kilometros > 500 && this->kilogramos > 10){
        return this->costoBase += (15.00 + 10.00);
    }
    
    return -1;
}