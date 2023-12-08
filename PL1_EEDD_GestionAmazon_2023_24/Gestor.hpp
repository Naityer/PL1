#include <iostream>
#include "Pila.hpp"
#include "Cola.hpp"
#include "Lista.hpp"
#include "Arbol.hpp"

#ifndef GESTOR_HPP
#define GESTOR_HPP

class Gestor
{
public:
    Gestor();
    
    //INTERFAZ PARTE 1
    void genera12Pedidos(); // Option A
    void muestraPedidos();  // Option B
    void borraPedidosPila(); // Option C
    void encolarPedidos(); // Option D
    void muestraPedidosSalasAyB(); // Option E
    void muestraPedidosSalasCyD(); // Option F
    void borraPedidosColas(); // Option G
    void enlistarPedidos(); // Option H
    void borrarPedidosListas(); // Option I
    void muestraPedidosEstandar(); // Option J
    void muestraPedidosUrgentes(); // Option K
    void buscarPedidos(); // Option L
    void reiniciar(); // Option M
    
    //ARBOLES
    void crear_dibujar_ABB();
    void mostrarEstandarOrdenados();
    void mostrarUrgentesOrdenados();
    void pedidosInorden_ABB();
    void buscar_ABB();
    void contarPedidosImpares_ABB();
    void pedidosNodoHoja_ABB();
    void eliminarPedido_ABB();
    ~Gestor();
    
    int PedidosEnPila();
    int PedidosEnEstacionA();
    int PedidosEnEstacionB();
    int PedidosEnEstacionC();
    int PedidosEnEstacionD();
    int PedidosEnListaEstandar();
    int PedidosEnListaUrgentes();
//    PedidosEnArbol()
    
private: 
    
    //ESTRUTURAS PARTE 1
    PedidoControl* pedidoControl;
    Pila* pila;
    Cola* estacionA;
    Cola* estacionB;
    Cola* estacionC;
    Cola* estacionD;
    Lista* listaEstandar;
    Lista* listaUrgente;
    Arbol* arbol;

};

#endif // GESTOR_HPP

