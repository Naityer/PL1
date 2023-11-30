#include "NodoArbol.hpp"

NodoArbol::NodoArbol(Paquete* paquete)
{
    this->paquete = paquete;
    this->izq = nullptr;
    this->der = nullptr;
}

NodoArbol::~NodoArbol() {}
