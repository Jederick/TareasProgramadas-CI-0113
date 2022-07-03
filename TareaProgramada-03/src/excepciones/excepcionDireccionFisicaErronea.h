#ifndef ExcepcionDireccionFisicaErronea_H
#define ExcepcionDireccionFisicaErronea_H

#include <exception>

using namespace std;

class ExcepcionDireccionFisicaErronea : public exception{

    public:
    ExcepcionDireccionFisicaErronea() noexcept = default;;
    ~ExcepcionDireccionFisicaErronea() = default;

    virtual const char* what() const noexcept{        
        return "La direccion fiísica de una tienda no puede superar los 24 caractéres";
    }
};

#endif