#ifndef ExcepcionIdInexistente_H
#define ExcepcionIdInexistente_H

#include <exception>

using namespace std;

class ExcepcionIdInexistente : public exception{

    public:
    ExcepcionIdInexistente() noexcept = default;;
    ~ExcepcionIdInexistente() = default;

    virtual const char* what() const noexcept{
        return "No existe ningún producto ligado a la id ingresada";
    }
};

#endif