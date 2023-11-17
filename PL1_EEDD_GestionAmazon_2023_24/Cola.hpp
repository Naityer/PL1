#include <NodoCola.hpp>

#ifndef COLA_HPP
#define COLA_HPP

class Cola
{
public:
    Cola();
    ~Cola();
    
    void insertar(Paquete* p);
    Paquete* eliminar();
    Paquete* mostrar();
    Paquete* verPrimero();
    
    int getLongitud();
    void setLongitud(int v);

private:
    pnodoCola primero, ultimo;
    int longitud;
};

#endif // COLA_HPP