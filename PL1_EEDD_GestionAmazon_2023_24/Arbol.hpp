#ifndef ARBOL_HPP
#define ARBOL_HPP

#include "NodoArbol.hpp"

using namespace std;

enum TipoBusqueda {
    MENOR_SEGUIMIENTO,
    MAYOR_SEGUIMIENTO,
    MENOR_ID_URGENTE,
    MAYOR_ID_URGENTE
};

class Arbol
{
public:
    Arbol();
    void insertar(Paquete* p);
    void pintar();
    void dibujar();
    ~Arbol();

private:
    pnodoAbb raiz;
    
    // METODOS
    pnodoAbb insertar(pnodoAbb, Paquete* p);
    void pintar(pnodoAbb);
    int altura(pnodoAbb);
    void dibujarNodo(vector<string>& output, vector<string>& linkAbove, pnodoAbb nodo, int nivel, int minPos, char linkChar);
    
    bool esVacio(pnodoAbb);
    int buscar(pnodoAbb nodo, TipoBusqueda tipo);
    int buscarAvazando(pnodoAbb nodo, TipoBusqueda tipo);
    
    list<Paquete> inorden(pnodoAbb nodo, list<Paquete>& NumSeg_set, string tipoMostrar);
    int postorden(pnodoAbb nodo);
    int minNumSeguimiento(pnodoAbb arbol);
    int maxNumSeguimiento(pnodoAbb arbol);
    
    friend class Gestor;
};

#endif // ARBOL_HPP
