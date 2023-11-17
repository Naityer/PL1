#include "NodoLista.hpp"

#ifndef LISTA_HPP
#define LISTA_HPP

class Lista
{
public:
    Lista (); 
    ~Lista ();
    
    void insertarNodo(Paquete* p) ;
    bool listaVacia();
    
    // GETTES
    int getLongitud();
    Paquete* getPrimero();
    Paquete* getUltimo();
    
    // SETTES
    void setLogitud(int v);
    
    Paquete* mostrarLista();
    
private:
    pnodoLista cabeza, actual, final;
    Paquete* ultimo;
    Paquete* primero;
    int longitud;
    
    // METODOS
    void esUltimo(Paquete* p);
    void esPrimero(Paquete* p);
    void esCabeza();
};



#endif // LISTA_HPP
