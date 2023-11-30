#include "Cola.hpp"

Cola::Cola()
{
    primero = ultimo = NULL;
    longitud = 0;
}

void Cola::insertar(Paquete* p)
{
    pnodoCola nuevo;
    nuevo = new NodoCola(p);
    
    if(ultimo) {
        ultimo->siguiente = nuevo;
    }
    ultimo = nuevo;
    
    if(!primero) {
        primero = nuevo;
    }
    longitud++;
}

Paquete* Cola::eliminar()
{
    pnodoCola nodo;
    Paquete* p;
    nodo = primero;
    if(!nodo)
        primero = NULL;  
    primero = nodo->siguiente;
    p = nodo->paquete;
    delete nodo;
    if(!primero)
        primero = NULL;
    longitud--;
    return p;
}

void Cola::mostrar()
{
    pnodoCola aux = primero;
    cout << "==========================================================================================================" << endl;
    while(aux) {
        aux->paquete->mostrar();
        aux = aux->siguiente;
    }
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


