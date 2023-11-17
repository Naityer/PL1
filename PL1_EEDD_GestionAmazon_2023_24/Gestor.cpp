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
    pedidoControl = new PedidoControl();
    pedidoControl->generarArrayID();
    pedidoControl->generarArraySeguimiento();
}

// INTERFAZ

void Gestor::genera12Pedidos() 
{
    if(pila->getLongitud() < 48) {
        for(auto i = 1; i <= 12; i++) {
            Paquete *p = new Paquete();
            char* DNIgenerado = pedidoControl->generarDNI();
            p->setDNI(DNIgenerado);
            pila->insertar(p);
        }
    } else {
        cout << "\nPILA LLENA !!! - Canditdad paquetes MAX = " <<  pila->getLongitud() << endl;
    }
}

// ZONA PILAS

void Gestor::muestraPedidos()
{
    Paquete* p;
    for (auto i=1; i<=pila->getLongitud(); ++i) {
        p = pila->mostrar();
        cout << "P." << i << "-";
        p->mostrar(p->getID(), p->getNum_seguimiento());
    }
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
        // POR CADA PAQUETE GENERAMOS UN ID y se lo asginamos
        paquete = pila->extraer();
        int IDgenerado = pedidoControl->asignarID(paquete->getPrioridad());
        paquete->setID(IDgenerado);
        
        //cout << "TAMANO DE ARRAY ID estandar : " << pedidoControl->vectorIDestandar.size() << endl;
        //cout << "TAMANO DE ARRAY ID urgente : " << pedidoControl->vectorIDurgente.size() << endl;
        
        if (pedidoControl->vectorIDestandar.size() == 0) {
            cout << "COLAS LLENAS ESTANDAR !!! paquete CLIENTE: " << paquete->getDNI() << " ha sido eliminado" << endl;
            paquete->~Paquete();
        }
        // 0 - PEDIDO ESTANDAR
        else if(estacionA->getLongitud() <= estacionB->getLongitud() && paquete->getPrioridad() == 0) {
            cout << "Paquete ESTANDAR ID: " << paquete->getID() << " asginado a la Estacion A " << endl; 
            estacionA->insertar(paquete);
        } 
        else if(estacionA->getLongitud() > estacionB->getLongitud() && paquete->getPrioridad() == 0) {
            cout << "Paquete ESTANDAR ID: " << paquete->getID() << " asginado a la Estacion B " << endl; 
            estacionB->insertar(paquete);
        } 
        // 1 - PEDIDO URGENTE
        else if(estacionC->getLongitud() <= estacionD->getLongitud() && paquete->getPrioridad() == 1) {
            cout << "Paquete URGENTE ID: " << paquete->getID() << " asginado a la Estacion C " << endl; 
            estacionC->insertar(paquete);
        } else if (estacionC->getLongitud() > estacionD->getLongitud() && paquete->getPrioridad() == 1) {
            cout << "Paquete URGENTE ID: " << paquete->getID() << " asginado a la Estacion D " << endl;
            estacionD->insertar(paquete);
        } 
    }
}

void Gestor::muestraPedidosSalasAyB()
{
    Paquete* p;
    
    cout << "\nESTACION-A " << "NUMERO PAQUETES = " <<estacionA->getLongitud() << endl;
    for (auto i= 1; i <= estacionA->getLongitud(); ++i) {
        p = estacionA->mostrar();
        p->mostrar(p->getID(), p->getNum_seguimiento());
    }
    
    cout << "\nESTACION-B " << "NUMERO PAQUETES = " <<estacionB->getLongitud() << endl;
    for (auto i= 1; i <= estacionB->getLongitud(); ++i) {
        p = estacionB->mostrar();
        p->mostrar(p->getID(), p->getNum_seguimiento());
    }
}

void Gestor::muestraPedidosSalasCyD()
{
    Paquete* p;
    
    cout << "\nESTACION-C " << "NUMERO PAQUETES = " <<estacionC->getLongitud() << endl;
    for (auto i= 1; i <= estacionC->getLongitud(); ++i) {
        p = estacionC->mostrar();
        p->mostrar(p->getID(), p->getNum_seguimiento());
    }
    
    cout << "\nESTACION-D " << "NUMERO PAQUETES = " <<estacionD->getLongitud() << endl;
    for (auto i= 1; i <= estacionD->getLongitud(); ++i) {
        p = estacionD->mostrar();
        p->mostrar(p->getID(), p->getNum_seguimiento());
    }
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
    
    while(estacionA->getLongitud() + estacionB->getLongitud() + estacionC->getLongitud() + estacionD->getLongitud() > 0)
    {
        if (estacionA->getLongitud() > 0) {
            // ENLISTAR ESTACION A
            cout << "\nCantidad estacionA = " << estacionA->getLongitud() << endl;
            cout << "Paquete ESTANDAR (estacionA) " << enlistarA << " enlistado" << endl;
            enlistarA = estacionA->eliminar(); // ESTANDAR
            enlistarA->setNum_seguimiento(pedidoControl->asignarNumSeguimiento(enlistarA->getPrioridad()));
            listaEstandar->insertarNodo(enlistarA);
        
        } else if(estacionB->getLongitud() > 0) {
            // ENLISTAR ESTACION B
            cout << "\nCantidad estacionB = " << estacionB->getLongitud() << endl;
            cout << "Paquete ESTANDAR (estacionB) " << enlistarB << " enlistado" << endl;
            enlistarB = estacionB->eliminar(); // ESTANDAR
            enlistarB->setNum_seguimiento(pedidoControl->asignarNumSeguimiento(enlistarB->getPrioridad()));
            listaEstandar->insertarNodo(enlistarB);  
        
        } else if (estacionC->getLongitud() > 0) {
            // ENLISTAR ESTACION C
            cout << "\nCantidad estacionC = " << estacionC->getLongitud() << endl;
            cout << "Paquete URGENTE (estacionC) " << enlistarA << " enlistado" << endl;
            enlistarC = estacionC->eliminar(); // URGENTE
            enlistarC->setNum_seguimiento(pedidoControl->asignarNumSeguimiento(enlistarC->getPrioridad()));
            listaUrgente->insertarNodo(enlistarC);    
        
        } else {
            // ENLISTAR ESTACION D
            cout << "\nCantidad estacionD = " << estacionD->getLongitud() << endl;
            cout << "Paquete URGENTE (estacionD) " << enlistarA << " enlistado" << endl;
            enlistarD = estacionD->eliminar(); // URGENTE
            enlistarD->setNum_seguimiento(pedidoControl->asignarNumSeguimiento(enlistarD->getPrioridad()));
            listaUrgente->insertarNodo(enlistarD);
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
    Paquete* p;
    for (auto i=1; i<= listaEstandar->getLongitud() ; ++i) {
        p = listaEstandar->mostrarLista();
        p->mostrar(p->getID(), p->num_seguimiento);
    }
}

void Gestor::muestraPedidosUrgentes()
{
    Paquete* p;
    for (auto i=1; i<= listaUrgente->getLongitud() ; ++i) {
        p = listaUrgente->mostrarLista();
        p->mostrar(p->getID(), p->num_seguimiento);
    }
}

void Gestor::buscarPedidos()
{
    if(listaEstandar->getLongitud() + listaUrgente->getLongitud() > 0) {
        Paquete* p;
        p = listaEstandar->getUltimo();
        p->mostrar(p->getID(), p->getNum_seguimiento());
        
        p = listaUrgente->getPrimero();
        p->mostrar(p->getID(), p->getNum_seguimiento());
    
    }
}

// INTERFAZ SUPERIOR

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

