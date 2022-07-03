#ifndef ExcepcionLimiteChar_H
#define ExcepcionLimiteChar_H

#include <exception>

using namespace std;

class ExcepcionLimiteChar : public exception{

    public:
    ExcepcionLimiteChar() noexcept = default;;
    ~ExcepcionLimiteChar() = default;

    virtual const char* what() const noexcept{
        return "En la declaracion algun objeto se ha superado la cantidad maxima de caracteres permitidos en alguno de sus atributos";
    }
};

#endif