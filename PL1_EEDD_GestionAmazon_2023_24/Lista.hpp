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
    
private:
    pnodoLista principio, cabeza, actual, final;
    Paquete* ultimo;
    Paquete* primero;
    int longitud;
    
    // METODOS
    void mostrarLista(bool vista);
    void esUltimo(Paquete* p);
    void esPrimero(Paquete* p);
    void esCabeza();
    Paquete* eliminar(bool modoEliminacion);
    
    friend class Gestor;
};



#endif // LISTA_HPP
