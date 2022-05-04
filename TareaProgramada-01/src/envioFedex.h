#ifndef ENVIOFEDEX_H
#define ENVIOFEDEX_H
#include "tipoEnvio.h"

class EnvioFedex : public TipoEnvio{

    private:
    float costoBase = 35.00;

    public:
    EnvioFedex(int kilometros, int kilogramos);
    virtual float calculoEnvio();
    
};
#endif