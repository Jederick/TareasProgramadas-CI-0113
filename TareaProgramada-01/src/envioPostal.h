#ifndef ENVIOPOSTAL_H
#define ENVIOPOSTAL_H

#include "tipoEnvio.h"

class EnvioPostal : public TipoEnvio{
    
    private:
    int clase;

    public:
    ~EnvioPostal();
    EnvioPostal(int kilogramos, int kilometros, int clase);
    virtual float calculoEnvio();

};
#endif  