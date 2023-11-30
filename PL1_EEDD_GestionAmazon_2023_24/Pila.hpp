#include <NodoPila.hpp>

#ifndef PILA_HPP
#define PILA_HPP

class Pila
{
public:
    Pila();
    ~Pila();
    
    void insertar(Paquete* p);
    void mostrar();
    Paquete* extraer();
    
    int getLongitud();
    void setLongitud(int v);
private:

    pnodoPila ultimo;
    int longitud;
};

#endif // PILA_HPP