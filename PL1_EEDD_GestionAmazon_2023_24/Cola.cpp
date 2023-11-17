#include "Cola.hpp"

Cola::Cola()
{
    primero = NULL;
    ultimo = NULL;
    longitud = 0;
}

void Cola::insertar(Paquete* p)
{
    pnodoCola nuevo;
    nuevo = new NodoCola(p);
    
    if(ultimo)
        ultimo->siguiente = nuevo;
    ultimo = nuevo;
    
    if(!primero)
        primero = nuevo;
    longitud++;
}

Paquete* Cola::eliminar()
{
    pnodoCola nodo;
    Paquete* p;
    nodo = primero;
    if(!nodo)
        return NULL;
    primero = nodo->siguiente;
    p = nodo->paquete;
    delete nodo;
    if(!primero)
        ultimo = NULL;
    longitud--;
    return p;
}

Paquete* Cola::mostrar()
{
    // La funcion MOSTRAR no extrae ni imprime como tal. Simplemente nos permite recorrec de forma dinamica la pila para
    // poder hacer las asignacions de los paquetes y posteriormente mostrarlos
    
    pnodoCola nodo;
    Paquete* p;
    nodo = primero;
    if(!nodo)
        return NULL;
    primero = nodo->siguiente;
    p = nodo->paquete;
    if(!primero)
        ultimo = NULL;
    return p;
}

Paquete* Cola::verPrimero()
{
    return primero->paquete;
}

int Cola::getLongitud()
{
    return longitud;
}

void Cola::setLongitud(int v) 
{
    this->longitud = v;
}

Cola::~Cola()
{
    while(primero)
        eliminar();
}


