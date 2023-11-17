#include "Lista.hpp"

Lista::Lista()
{
    longitud = 0;
    cabeza = actual = final = NULL;
}

void Lista::insertarNodo(Paquete* p) {
    
    pnodoLista aux;
    if (listaVacia()) {
    aux = new NodoLista(p, NULL, NULL);
    final = cabeza = aux;
    cout << "NODO ANADIDO: " << aux->paquete->getID();
    } else if (final->paquete->getID() <= p->getID()) { // Inserción por el final
        aux = new NodoLista(p, NULL, final);
        final->siguiente = aux;
        final = aux;
        esUltimo(aux->paquete);
    } else if (cabeza->paquete->getID() > p->getID()) { // Inserción por el principio
        aux = new NodoLista(p, cabeza, NULL);
        cabeza->anterior = aux;
        cabeza = aux;
        esPrimero(aux->paquete);
    } else { // Inserción en medio de la lista
        pnodoLista actual = cabeza->siguiente;
        while (actual->paquete->getID() < p->getID()) {
            actual = actual->siguiente;
        }
        aux = new NodoLista(p, actual, actual->anterior);
        actual->anterior->siguiente = aux;
        actual->anterior = aux;
    }
    
    this->longitud++;
}

Paquete* Lista::mostrarLista()
{
    pnodoLista aux;
    Paquete* p;
    esCabeza();
    aux = cabeza;
    p = aux->paquete;
    cabeza = aux->siguiente;
    return p;
}

bool Lista::listaVacia()
{
    return cabeza == NULL;
}

void Lista::esCabeza()
{
    actual = cabeza;
}

void Lista::esUltimo(Paquete* p)
{
    this->ultimo = p;
}

void Lista::esPrimero(Paquete* p) 
{
    this->primero = p;
}

//GETTER

int Lista::getLongitud()
{
    return longitud;
}

void Lista::setLogitud(int v)
{
    this->longitud = v;
}

Paquete* Lista::getPrimero()
{
    return primero;
}

Paquete* Lista::getUltimo()
{
    return ultimo;
}

Lista::~Lista()
{
    pnodoLista aux;
    while (cabeza) {
        aux = cabeza;
        cabeza = cabeza->siguiente;
        longitud--;
        delete aux;
    }
    
    cabeza = NULL;
    actual = NULL;
    final = NULL;
}

