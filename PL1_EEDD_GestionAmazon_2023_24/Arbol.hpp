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
    int cantidad;
    
    // METODOS PARA DIBUJAR EL ARBOL
    pnodoAbb insertar(pnodoAbb, Paquete* p);
    void pintar(pnodoAbb);
    int altura(pnodoAbb);
    void dibujarNodo(vector<string>& output, vector<string>& linkAbove, pnodoAbb nodo, int nivel, int minPos, char linkChar);
    
    // METODOS PARA MOSTRAR EL ARBOL
    list<Paquete> inorden(pnodoAbb nodo, list<Paquete>& NumSeg_set, string tipoMostrar);
   
    // METODOS DE BUSQUEDA 
    int buscarAvazando(pnodoAbb nodo, TipoBusqueda tipo);
    int minNumSeguimiento(pnodoAbb nodo);
    int maxNumSeguimiento(pnodoAbb nodo);
    int menorIDUrgente(pnodoAbb nodo);
    int mayorIDUrgente(pnodoAbb nodo);
    
    // METODOS DE CONSULTA DE EL ARBOL
    bool esImpar(int numero);
    int contarImpares(pnodoAbb nodo);
    
    vector<Paquete*> obtenerPaquetesEnHojas(pnodoAbb nodo);
    
    int maximo(pnodoAbb nodo);
    pnodoAbb borrarElemento(int elementoAEliminar, pnodoAbb nodo);
    pnodoAbb borrarNodo(pnodoAbb nodo);
    
    friend class Gestor;
};

#endif // ARBOL_HPP
