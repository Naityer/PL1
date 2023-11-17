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

Paquete* Pila::mostrar()
{
    
    // La funcion MOSTRAR no extrae ni imprime como tal. Simplemente nos permite recorrec de forma dinamica la pila para
    // poder hacer las asignacions de los paquetes y posteriormente mostrarlos
    pnodoPila nodo;
    Paquete* p;
    if(!ultimo)
        return 0;
        
    nodo = ultimo;
    ultimo = nodo->siguiente;
    p = nodo->paquete;
    return p;
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

