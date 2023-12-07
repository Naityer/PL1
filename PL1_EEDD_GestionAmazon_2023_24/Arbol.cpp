#include "Arbol.hpp"

Arbol::Arbol() { 
    raiz = nullptr;
}

void Arbol::insertar(Paquete* p) { 
    raiz = insertar(raiz, p); 
}

pnodoAbb Arbol::insertar(pnodoAbb nodo, Paquete* p)
{
    if(!nodo)
        return new NodoArbol(p);
    if(p->num_seguimiento <= nodo->paquete->num_seguimiento)
        nodo->izq = insertar(nodo->izq, p);
    else
        nodo->der = insertar(nodo->der, p);
    return nodo;
}

// METODOS DE MOSTRAR EL ARBOL

list<Paquete> Arbol::inorden(pnodoAbb nodo, std::list<Paquete>& Paquete_list, std::string tipoMostrar) {
    
    if (!nodo) {
        return Paquete_list;
    }
    // Recorrer la parte izquierda
    inorden(nodo->izq, Paquete_list, tipoMostrar);

    if (nodo->paquete->num_seguimiento != 500 &&
        ((tipoMostrar == "estandar" && nodo->paquete->prioridad == 0) ||
        (tipoMostrar == "urgente" && nodo->paquete->prioridad == 1) ||
        tipoMostrar == "todosPedidos")) {
            
            Paquete_list.push_back(*nodo->paquete);  // Assuming Paquete is a pointer
    }

    // Recorrer la parte derecha
    inorden(nodo->der, Paquete_list, tipoMostrar);
    
    return Paquete_list;
}

int Arbol::minNumSeguimiento(pnodoAbb arbol) {
    
    if (arbol == nullptr) {
        // Árbol vacío, devuelve un valor apropiado (puede ser -1)
        return 0;
    }

    // Recorre en postorden 
    int valorIzquierda = minNumSeguimiento(arbol->izq);

    // Si el valor del nodo izquierdo es mayor o igual, detén la búsqueda
    if ((valorIzquierda <= arbol->paquete->num_seguimiento) && valorIzquierda != 0) {
        return valorIzquierda;
    }
    // Retorna el valor actual del nodo
    return arbol->paquete->num_seguimiento;
}

int Arbol::maxNumSeguimiento(pnodoAbb arbol) {
    
    if (arbol == nullptr) {
        // Árbol vacío, devuelve un valor apropiado (puede ser -1)
        return 0;
    }

    // Recorre en postorden el subárbol derecho
    int valorDerecha = maxNumSeguimiento(arbol->der);

    // Si el valor del nodo derecho es menor, actualiza el resultado
    if ((valorDerecha >= arbol->paquete->num_seguimiento) && valorDerecha < 500) {
        return valorDerecha;
    }

    // Retorna el valor actual del nodo
    return arbol->paquete->num_seguimiento;
}


// METODOS DE BUSQUEDA

int Arbol::buscar(pnodoAbb nodo, TipoBusqueda tipo) {
    
    if (nodo == nullptr) {
        // Árbol vacío
        return 0;
    }
    
    switch (tipo) {
        case MENOR_SEGUIMIENTO:
            // Recorre en postorden 
            return minNumSeguimiento(nodo->izq);
            
            break;
        case MAYOR_SEGUIMIENTO:
            // Recorre en postorden
            return maxNumSeguimiento(nodo->izq);
            
            break;
        case MENOR_ID_URGENTE:
            // Implementa la lógica para este caso si es necesario
            break;
        case MAYOR_ID_URGENTE:
            // Implementa la lógica para este caso si es necesario
            break;
        default:
            cout << "PAQUETE NO ENCONTRADO" << endl;
            // Cambiar 0 al valor deseado de retorno para el caso por defecto
            return 0;
    }

    return 0;
}

int Arbol::buscarAvazando(pnodoAbb nodo, TipoBusqueda tipo) {
    if (nodo == nullptr) {
        // Árbol vacío, devuelve un valor apropiado (puede ser -1)
        return 0;
    }

    int valorIzquierda = buscarAvazando(nodo->izq, tipo) != 0 ? buscarAvazando(nodo->izq, tipo) : 0;
    int valorDerecha = buscarAvazando(nodo->der, tipo) != 0 ? buscarAvazando(nodo->der, tipo) : 0;

    switch (tipo) {
        case MENOR_SEGUIMIENTO:
            if ((valorIzquierda <= nodo->paquete->num_seguimiento) && valorIzquierda != 0) {
                return valorIzquierda;
            }
            break;
        case MAYOR_SEGUIMIENTO:
            if ((valorDerecha >= nodo->paquete->num_seguimiento) && valorDerecha < 500) {
                return valorDerecha;
            }
            break;
        case MENOR_ID_URGENTE:
            // Implementa la lógica para este caso si es necesario
            break;
        case MAYOR_ID_URGENTE:
            // Implementa la lógica para este caso si es necesario
            break;
        default:
            std::cout << "PAQUETE NO ENCONTRADO" << std::endl;
            // Cambiar 0 al valor deseado de retorno para el caso por defecto
            return 0;
    }

    return nodo->paquete->num_seguimiento;
}

//  METODOS PARA DIBUJAR EL ARBOL 

void Arbol::pintar()
{
    pintar(raiz);
    cout << '\n';
}

void Arbol::pintar(pnodoAbb nodo)
{
    if(!nodo)
        return;
    pintar(nodo->izq);
    cout << nodo->paquete << " ";
    pintar(nodo->der);
}

int Arbol::altura(pnodoAbb nodo)
{
    if(!nodo)
        return 0;
    return 1 + max(altura(nodo->izq), altura(nodo->der));
}

void Arbol::dibujarNodo(vector<string>& output, vector<string>& linkAbove, pnodoAbb nodo, int nivel, int p,
                        char linkChar)
{
    if(!nodo)
        return;

    int h = output.size();
    string SP = " ";

    if(p < 0) {
        string extra(-p, ' ');
        for(string& s : output)
            if(!s.empty())
                s = extra + s;
        for(string& s : linkAbove)
            if(!s.empty())
                s = extra + s;
    }
    if(nivel < h - 1)
        p = max(p, (int)output[nivel + 1].size());
    if(nivel > 0)
        p = max(p, (int)output[nivel - 1].size());
    p = max(p, (int)output[nivel].size());

    if(nodo->izq) {
        int numeroQueQuieroImprimirEnElArbol = nodo->izq->paquete->getNum_seguimiento(); // En vez de este valor, tenéis que coger el número de la habitación del paciente.
        string izqpaquete = SP + to_string(numeroQueQuieroImprimirEnElArbol) + SP;
        dibujarNodo(output, linkAbove, nodo->izq, nivel + 1, p - izqpaquete.size(), 'L');
        p = max(p, (int)output[nivel + 1].size());
    }

    int space = p - output[nivel].size();
    if(space > 0)
        output[nivel] += string(space, ' ');
    int numeroQueQuieroImprimirEnElArbol = nodo->paquete->getNum_seguimiento(); // En vez de este valor, tenéis que coger el número de la habitación del paciente.
    string nodopaquete = SP + to_string(numeroQueQuieroImprimirEnElArbol) + SP;
    output[nivel] += nodopaquete;

    space = p + SP.size() - linkAbove[nivel].size();
    if(space > 0)
        linkAbove[nivel] += string(space, ' ');
    linkAbove[nivel] += linkChar;

    if(nodo->der)
        dibujarNodo(output, linkAbove, nodo->der, nivel + 1, output[nivel].size(), 'R');
}

void Arbol::dibujar()
{
    int h = altura(raiz);
    vector<string> output(h), linkAbove(h);
    dibujarNodo(output, linkAbove, raiz, 0, 5, ' ');

    for(int i = 1; i < h; i++) {
        for(auto j = 0; j < linkAbove[i].size(); j++) {
            if(linkAbove[i][j] != ' ') {
                int size = output[i - 1].size();
                if(size < j + 1)
                    output[i - 1] += string(j + 1 - size, ' ');
                int jj = j;
                if(linkAbove[i][j] == 'L') {
                    while(output[i - 1][jj] == ' ')
                        jj++;
                    for(int k = j + 1; k < jj - 1; k++)
                        output[i - 1][k] = '_';
                } else if(linkAbove[i][j] == 'R') {
                    while(output[i - 1][jj] == ' ')
                        jj--;
                    for(int k = j - 1; k > jj + 1; k--)
                        output[i - 1][k] = '_';
                }
                linkAbove[i][j] = '|';
            }
        }
    }

    cout << '\n' << '\n';
    for(int i = 0; i < h; i++) {
        if(i)
            cout << linkAbove[i] << '\n';
        cout << output[i] << '\n';
    }
    cout << '\n' << '\n';
}

Arbol::~Arbol() {}
