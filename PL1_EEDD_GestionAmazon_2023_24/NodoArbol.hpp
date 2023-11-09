#include "NodoArbol.hpp"

NodoArbol::NodoArbol(Paquete *dato, NodoArbol *p)
{

    this->dato = dato;
    this->izq = nullptr;
    this->der = nullptr;
    this->padre = p;
}

NodoArbol::~NodoArbol()
{
}
