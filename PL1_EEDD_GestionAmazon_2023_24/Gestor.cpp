#include "Gestor.hpp"
//#include "Pila.hpp" en Gestor.hpp
//include "Paquete.hpp" en NodoPila

Gestor::Gestor() 
{
    pila = new Pila();
    estacionA = new Cola();
    estacionB = new Cola();
    estacionC = new Cola();
    estacionD = new Cola();
    listaEstandar = new Lista();
    listaUrgente = new Lista();
}

// INTERFAZ

void Gestor::genera12Pedidos() 
{
    
    if(pila->getLongitud() < 48) {
        for(auto i = 1; i <= 12; i++) {
            Paquete *p = new Paquete();
            pila->insertar(p);
        }
    } else {
        cout << "\nPILA LLENA !!! - Canditdad paquetes MAX = " <<  pila->getLongitud() << endl;
    }
}

// ZONA PILAS

void Gestor::muestraPedidos()
{
    pila->mostrar();
    cout << "CANTIDAD PEDIDO = " << pila->getLongitud() << endl;
}

void Gestor::borraPedidosPila() 
{
    pila->~Pila();
    pila->setLongitud(0);
}


// ZONA COLAS

void Gestor::encolarPedidos()
{
    Paquete* paquete;
    
    cout << "Encolando " << pila->getLongitud() << " pedidos... " << endl;
    cout << "===================================================" << endl;
    
    while(pila->getLongitud() > 0)
    {
        
        paquete = pila->extraer();
        paquete->setID();
        
        // 0 - PEDIDO ESTANDAR
        if (paquete->getID() == 0) {
            cout << "COLAS LLENAS !!! paquete CLIENTE: " << paquete->getDNI() << " ha sido eliminado" << endl;
            paquete->~Paquete();
        }
        else if(estacionA->getLongitud() <= estacionB->getLongitud() && paquete->getPrioridad() == 0 && paquete->getCountEstandar() <= 49) {
            cout << "Paquete ESTANDAR ID: " << paquete->getID() << " asginado a la Estacion A " << endl; 
            estacionA->insertar(paquete);
        } 
        else if(estacionA->getLongitud() > estacionB->getLongitud() && paquete->getPrioridad() == 0 && paquete->getCountEstandar() <= 49) {
            cout << "Paquete ESTANDAR ID: " << paquete->getID() << " asginado a la Estacion B " << endl; 
            estacionB->insertar(paquete);
        } 
        // 1 - PEDIDO URGENTE
        else if(estacionC->getLongitud() <= estacionD->getLongitud() && paquete->getPrioridad() == 1 && paquete->getCountUrgente() >= 51 && paquete->getCountUrgente() <= 99) {
            cout << "Paquete URGENTE ID: " << paquete->getID() << " asginado a la Estacion C " << endl; 
            estacionC->insertar(paquete);
        } else if (estacionC->getLongitud() > estacionD->getLongitud() && paquete->getPrioridad() == 1 && paquete->getCountUrgente() >= 51 && paquete->getCountUrgente() <= 99) {
            cout << "Paquete URGENTE ID: " << paquete->getID() << " asginado a la Estacion D " << endl;
            estacionD->insertar(paquete);
        } 
    }
}

void Gestor::muestraPedidosSalasAyB()
{
    cout << "\nESTACION-A " << "NUMERO PAQUETES = " <<estacionA->getLongitud() << endl;
    estacionA->mostrar();
    cout << "\nESTACION-B " << "NUMERO PAQUETES = " <<estacionB->getLongitud() << endl;
    estacionB->mostrar();
}

void Gestor::muestraPedidosSalasCyD()
{
    cout << "\nESTACION-C " << "NUMERO PAQUETES = " <<estacionC->getLongitud() << endl;
    estacionC->mostrar();
    cout << "\nESTACION-D " << "NUMERO PAQUETES = " <<estacionD->getLongitud() << endl;
    estacionD->mostrar();
}

void Gestor::borraPedidosColas()
{
    estacionA->~Cola();
    estacionA->setLongitud(0);
    estacionB->~Cola();
    estacionB->setLongitud(0);
    estacionC->~Cola();
    estacionC->setLongitud(0);
    estacionD->~Cola();
    estacionD->setLongitud(0);
}

//ZONA LISTAS

void Gestor::enlistarPedidos()
{
    Paquete* enlistarA;
    Paquete* enlistarB;
    Paquete* enlistarC;
    Paquete* enlistarD;
    int cantidadListados = 0;
    
    while(estacionA->getLongitud() > 0 || estacionB->getLongitud() > 0 || estacionC->getLongitud() > 0 || estacionD->getLongitud() > 0)
    {
        if(estacionA->getLongitud() > 0) {
            cout << "\nCantidad estacionA = " << estacionA->getLongitud() << endl;
            cout << "Paquete ESTANDAR (estacionA) " << enlistarA << " enlistado" << endl;
            enlistarA = estacionA->eliminar(); // ESTANDAR
            enlistarA->setNum_seguimiento(0);
            listaEstandar->insertarNodo(enlistarA, 'p');
        
        } else if (estacionB->getLongitud() > 0) {
            cout << "\nCantidad estacionB = " << estacionB->getLongitud() << endl;
            cout << "Paquete ESTANDAR (estacionB) " << enlistarB << " enlistado" << endl;
            enlistarB = estacionB->eliminar(); // ESTANDAR
            enlistarB->setNum_seguimiento(0);
            listaEstandar->insertarNodo(enlistarB, 'p');  
            
        } else if (estacionC->getLongitud() > 0) {
            cout << "\nCantidad estacionC = " << estacionC->getLongitud() << endl;
            cout << "Paquete URGENTE (estacionC) " << enlistarA << " enlistado" << endl;
            enlistarC = estacionC->eliminar(); // URGENTE
            enlistarC->setNum_seguimiento(1);
            listaUrgente->insertarNodo(enlistarC, 'p');    
            
        } else {
            cout << "\nCantidad estacionD = " << estacionD->getLongitud() << endl;
            cout << "Paquete URGENTE (estacionD) " << enlistarA << " enlistado" << endl;
            enlistarD = estacionD->eliminar(); // URGENTE
            enlistarD->setNum_seguimiento(1);
            listaUrgente->insertarNodo(enlistarD, 'p');
            
        }
        cantidadListados++;
    }
    
    // RESET COUNTERS
//    enlistarA->setCountEstandar(0);
//    enlistarB->setCountEstandar(0);
//    enlistarC->setCountUrgente(51);
//    enlistarD->setCountUrgente(51);
    
    cout << "\n=============================== " << endl;
    cout << "\nLista ESTANDAR = " << listaEstandar->getLongitud() << endl;
    cout << "Lista URGENTE = " << listaUrgente->getLongitud() << endl;
    cout << "\nNUMERO PAQUETES LISTADOS = " << cantidadListados << endl;
}

void Gestor::borrarPedidosListas()
{
    listaEstandar->~Lista();
    listaUrgente->~Lista();
}

void Gestor::muestraPedidosEstandar()
{
    cout << "\nPOSTEMPAQUETADO AREA ESTANDAR " << " NUMERO PAQUETES = " << listaEstandar->getLongitud() << endl;
    cout << "\n======================================================================================= " << endl;
    listaEstandar->recorrerLista(true);
}

void Gestor::muestraPedidosUrgentes()
{
    cout << "\nPOSTEMPAQUETADO AREA URGENTE " << " NUMERO PAQUETES = " << listaUrgente->getLongitud();
    cout << "\n=======================================================================================" << endl;
    listaUrgente->recorrerLista(true);
}

void Gestor::buscarPedidos()
{
//    listaEstandar->recorrerLista(true);
    listaEstandar->buscarElemento('p');
//    listaUrgente->recorrerLista(false);
    listaUrgente->buscarElemento('f');
}

// INTERFAZ 

int Gestor::PedidosEnPila()
{
    int pedidos = pila->getLongitud();
    return pedidos;
}

int Gestor::PedidosEnEstacionA()
{
    int pedidos = estacionA->getLongitud();
    return pedidos;
}

int Gestor::PedidosEnEstacionB()
{
    int pedidos = estacionB->getLongitud();
    return pedidos;
}

int Gestor::PedidosEnEstacionC()
{
    int pedidos = estacionC->getLongitud();
    return pedidos;
}

int Gestor::PedidosEnEstacionD()
{
    int pedidos = estacionD->getLongitud();
    return pedidos;
}

int Gestor::PedidosEnListaEstandar()
{
    int pedidos = listaEstandar->getLongitud();
    return pedidos;
}

int Gestor::PedidosEnListaUrgentes()
{
    int pedidos = listaUrgente->getLongitud();
    return pedidos;
}

void Gestor::reiniciar()
{
    borraPedidosPila();
    borraPedidosColas();
    borrarPedidosListas();
}

Gestor::~Gestor()
{
}

