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
    arbol = new Arbol();
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
            string DNIgenerado = pedidoControl->generarDNI();
            p->setDNI(DNIgenerado);
            pila->insertar(p);
        }
    } else {
        cout << "\nPILA LLENA !!! - Canditdad paquetes MAX = " <<  pila->getLongitud() << endl;
    }
}

//ZONA ARBOLES 

void Gestor::crear_dibujar_ABB()
{
    Paquete* p;
    Paquete* paqueteFicticio = new Paquete();
    paqueteFicticio->setNum_seguimiento(500);
    arbol->insertar(paqueteFicticio);
    
    while(listaEstandar->getLongitud() > 0) {
        p = listaEstandar->eliminar(true);
        arbol->insertar(p);
        cout << "ID extraido de la lista (ESTANDAR) : " << p->getID() << endl;
    }
    
    while(listaUrgente->getLongitud() > 0) {
        arbol->insertar(listaUrgente->eliminar(true));
        cout << "ID extraido de la lista (URGENTE) : " << p->getID() << endl;
    }
    
    arbol->dibujar();
}

void Gestor::mostrarEstandarOrdenados()
{
    list<Paquete> Paquete_list;
    Paquete_list = arbol->inorden(arbol->raiz, Paquete_list, "estandar");
    
    cout << "Contenido ARBOL --> PEDIDOS ESTANDAR: " << endl;
    for (auto paquete : Paquete_list) {
        paquete.mostrar();
    }
    
    cout << endl;
}

void Gestor::mostrarUrgentesOrdenados()
{
    list<Paquete> Paquete_list;
    Paquete_list = arbol->inorden(arbol->raiz, Paquete_list, "urgente");
    
    cout << "Contenido ARBOL --> PEDIDO URGENTE: " << endl;
    for (auto paquete : Paquete_list) {
        paquete.mostrar();
    }
    cout << endl;
}

void Gestor::pedidosInorden_ABB()
{
    list<Paquete> Paquete_list;
    Paquete_list = arbol->inorden(arbol->raiz, Paquete_list, "todosPedidos");
    
    cout << "Contenido ARBOL --> TODOS LOS PEDIDOS: " << endl;
    for (auto paquete : Paquete_list) {
        paquete.mostrar();
    }
    cout << endl;
}

void Gestor::buscar_ABB()
{
//    int valMin = arbol->postorden(arbol->raiz);
//    cout << "Valor minimo es = " << valMin << endl;
    arbol->dibujar();
    
    int valMinSeg = arbol->buscarAvazando(arbol->raiz, MENOR_SEGUIMIENTO);
    cout << "El pedido estandar cuyo numero de seguimiento es el menor: " << valMinSeg << endl;
    
    int valMaxSeg = arbol->buscarAvazando(arbol->raiz, MAYOR_SEGUIMIENTO);
    cout << "El pedido estandar cuyo numero de seguimiento es el mayor: " << valMaxSeg << endl;
    
    int valMenorID = arbol->buscarAvazando(arbol->raiz, MENOR_ID_URGENTE);
    cout << "El pedido urgente cuyo numero de ID es el menor: " << valMenorID << endl;
    int valMayorID = arbol->buscarAvazando(arbol->raiz, MAYOR_ID_URGENTE);
    cout << "El pedido urgente cuyo numero de ID es el mayor: " << valMayorID << endl;
}

void Gestor::contarPedidosImpares_ABB()
{
    arbol->dibujar();
    cout << "Numero de pedidos impares: " << arbol->contarImpares(arbol->raiz) << endl;
}

void Gestor::pedidosNodoHoja_ABB()
{
    vector <Paquete*> paquetesEnNodoHoja = arbol->obtenerPaquetesEnHojas(arbol->raiz);
    
    arbol->dibujar();
    cout << "CANTIDAD NODOS HOJAS: " << paquetesEnNodoHoja.size() << endl;
    for (auto paquete : paquetesEnNodoHoja) {
        paquete->mostrar();
    }
    cout << endl;
}

void Gestor::eliminarPedido_ABB()
{
    arbol->dibujar();
    int elementoAEliminar;
    cout << "Eliminar paquete con num seguimiento: ";
    cin >> elementoAEliminar;

    // Llamar a la función para borrar el elemento
    arbol->borrarElemento(elementoAEliminar, arbol->raiz);
    arbol->dibujar();
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
    listaEstandar->mostrarLista(true);
}

void Gestor::muestraPedidosUrgentes()
{
   listaUrgente->mostrarLista(true);
}

void Gestor::buscarPedidos()
{
    if(listaEstandar->getLongitud() + listaUrgente->getLongitud() > 0) {
        Paquete* p;
        p = listaEstandar->getUltimo();
        p->mostrar();
        
        p = listaUrgente->getPrimero();
        p->mostrar();
    
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

