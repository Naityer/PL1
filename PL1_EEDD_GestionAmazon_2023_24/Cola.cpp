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

void Cola::mostrar()
{
    pnodoCola aux = primero;
    cout << "===================================" << endl;
    cout << endl;
    
    // Títulos de las columnas
    cout << left << setw(20) << "TIPO_PRIORIDAD" << setw(20) << "ID_PAQUETE" << setw(20) << "NUM_SEGUIMIENTO" << setw(20) << "DNI_CLIENTE" << endl;
    cout << left << setw(20) << "______________" << setw(20) << "__________" << setw(20) << "_______________" << setw(20) << "___________" << endl;
    
    while(aux) {
        // Datos de la fila
        cout << left << setw(20) << aux->paquete->getPrioridad() << setw(20) << aux->paquete->getID() << setw(20) << aux->paquete->getNum_seguimiento() << setw(20) << aux->paquete->getDNI() << endl;
        // Separacion de columnas
        cout << left << setw(20) << "______________" << setw(20) << "__________" << setw(20) << "_______________" << setw(20) << "___________" << endl;  
        aux = aux->siguiente;
    }
    cout << endl;
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


