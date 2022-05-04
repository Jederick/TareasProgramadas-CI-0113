#ifndef TIPOENVIO_H
#define TIPOENVIO_H
#include <string>

using namespace std;

class TipoEnvio{

    protected:
    int kilometros;
    int kilogramos;

    public:
    virtual float calculoEnvio() = 0;
};

#endif