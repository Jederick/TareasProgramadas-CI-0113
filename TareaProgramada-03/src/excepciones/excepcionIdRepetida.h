#ifndef ExcepcionIdRepetida_H
#define ExcepcionIdRepetida_H

#include <exception>

using namespace std;

class ExcepcionIdRepetida : public exception{

    public:
    ExcepcionIdRepetida() noexcept = default;;
    ~ExcepcionIdRepetida() = default;

    virtual const char* what() const noexcept{
        return "Ya existe un producto con la id ingresada, ingrese otra.";
    }
};

#endif