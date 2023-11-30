#include "Lista.hpp"

Lista::Lista()
{
    longitud = 0;
    principio = cabeza = actual = final = NULL;
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
        principio = cabeza = aux;
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
    
    // Después de la inserción, enlazar los últimos paquetes al anterior
    if (final->anterior != NULL) {
        final->anterior->siguiente = final;
    }
    
    this->longitud++;
}

void Lista::mostrarLista(bool vista)
{
    pnodoLista aux = (vista) ? cabeza : final;
    cout << "El contenido de la LISTA es: \n" << endl;
    cout << "==========================================================================================================" << endl;
    
    while (aux) {
        aux->paquete->mostrar();
        aux = (vista) ? aux->siguiente : aux->anterior;
    }
}

Paquete* Lista::eliminar(bool modoEliminacion) {
    
    if (listaVacia()) {
        cout << "La lista está vacía. No se puede eliminar ningún nodo." << endl;
        return nullptr;
    }

    Paquete* paqueteEliminado;
    pnodoLista aux;

    if (modoEliminacion) {  // Modo eliminación normal (desde el principio)
        aux = cabeza;
        if (cabeza == final) {  // Solo hay un elemento en la lista
            cabeza = final = nullptr;
        } else {
            cabeza = cabeza->siguiente;
            cabeza->anterior = nullptr;
        }
    } else {  // Modo eliminación en sentido contrario (desde el final)
        aux = final;
        if (cabeza == final) {  // Solo hay un elemento en la lista
            cabeza = final = nullptr;
        } else {
            final = final->anterior;
            final->siguiente = nullptr;
        }
    }

    paqueteEliminado = aux->paquete;
    delete aux;

    this->longitud--;

    return paqueteEliminado;
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

