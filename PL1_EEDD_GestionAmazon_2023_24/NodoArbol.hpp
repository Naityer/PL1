#ifndef NODOARBOL_HPP
#define NODOARBOL_HPP

#include <iostream>
#include "Paquete.hpp"
#include <vector>
#include <cstdlib> 

class NodoArbol
{
public:
    NodoArbol(Paquete* p);
    ~NodoArbol();

private:
    Paquete* paquete; // Aquí se almacenan enteros pero en vuestra práctica se deben almacenar paquete
    NodoArbol* izq;
    NodoArbol* der;

    friend class Arbol;
};
typedef NodoArbol* pnodoAbb;
#endif // NODOARBOL_HPP
