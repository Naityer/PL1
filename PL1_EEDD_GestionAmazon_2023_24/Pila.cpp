#include "Pila.hpp"

Pila::Pila()
{
    ultimo = NULL;
    longitud = 0;
}

void Pila::insertar(Paquete* p)
{
    pnodoPila nuevo;
    nuevo = new NodoPila(p, ultimo);
    ultimo = nuevo;
    longitud++;
}

Paquete* Pila::extraer()
{
    pnodoPila nodo;
    Paquete* p;
    if(!ultimo)
        return 0;
        
    nodo = ultimo;
    ultimo = nodo->siguiente;
    p = nodo->paquete;
    longitud--;
    delete nodo;
    return p;
}

Paquete* Pila:: cima()
{
    //pnodoPila nodo;
    if (!ultimo)
        return NULL;
    return ultimo->paquete;
}

int Pila::getLongitud()
{
    return this->longitud;
}

void Pila::setLongitud(int v) {
    this->longitud = v;
}

Pila::~Pila()
{
    pnodoPila aux;
    while(ultimo) {
        aux = ultimo;
        ultimo = ultimo->siguiente;
        delete aux;
    }
}

