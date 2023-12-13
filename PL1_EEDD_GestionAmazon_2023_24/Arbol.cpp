#include "Arbol.hpp"

Arbol::Arbol() { 
    raiz = nullptr;
    cantidad = 0;
}

void Arbol::insertar(Paquete* p) { 
    raiz = insertar(raiz, p); 
    cantidad++;
}

pnodoAbb Arbol::insertar(pnodoAbb nodo, Paquete* p)
{
    if(!nodo)
        return new NodoArbol(p);
    if (p->num_seguimiento == nodo->paquete->num_seguimiento)
    {
        cout << "El nodo con el mismo valor ya existe, no se inserta nuevamente" << endl;
        return nodo;
    }    
    
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

// METODOS DE BUSQUEDA 

int Arbol::buscarAvazando(pnodoAbb nodo, TipoBusqueda tipo) {
    
    if (nodo == nullptr) {
        return 0;
    }

    switch (tipo) {
        case MENOR_SEGUIMIENTO:
            return minNumSeguimiento(nodo->izq);
        case MAYOR_SEGUIMIENTO:
            return maxNumSeguimiento(nodo->izq);
        case MENOR_ID_URGENTE:
            return menorIDUrgente(nodo->der);
        case MAYOR_ID_URGENTE:
            return mayorIDUrgente(nodo->der);
        default:
            cout << "PAQUETE NO ENCONTRADO" << std::endl;
            return 0;
    }
}

//===============================================================================================================

int Arbol::minNumSeguimiento(pnodoAbb nodo) {
    if (nodo == nullptr) {
        return 0;
    }

    int valorIzquierda = minNumSeguimiento(nodo->izq);

    return (valorIzquierda < nodo->paquete->num_seguimiento && valorIzquierda != 0) ?
           valorIzquierda : nodo->paquete->num_seguimiento;
}

int Arbol::maxNumSeguimiento(pnodoAbb nodo) {
    if (nodo == nullptr) {
        return 0;
    }

    int valorDerecha = maxNumSeguimiento(nodo->der);

    return (valorDerecha >= nodo->paquete->num_seguimiento && valorDerecha < 500) ?
           valorDerecha : nodo->paquete->num_seguimiento;
}

int Arbol::menorIDUrgente(pnodoAbb nodo) {
    if (nodo == nullptr) {
        return INT_MAX;
    }

    int menorIzquierdo = min({nodo->paquete->getID(), menorIDUrgente(nodo->izq), menorIDUrgente(nodo->der)});

    return menorIzquierdo;
}

int Arbol::mayorIDUrgente(pnodoAbb nodo) {
    if (nodo == nullptr) {
        return INT_MIN;
    }

    int mayorDerecho = max({nodo->paquete->getID(), mayorIDUrgente(nodo->izq), mayorIDUrgente(nodo->der)});

    return mayorDerecho;
}

// METODO DE CONSULTAS EN EL ARBOL 

bool Arbol::esImpar(int numero) {
    return numero % 2 != 0;
}

int Arbol::contarImpares(pnodoAbb nodo) {
    
    if (nodo == nullptr) {
        return 0;
    }

    int imparesIzquierda = contarImpares(nodo->izq);
    int imparesDerecha = contarImpares(nodo->der);

    return esImpar(nodo->paquete->num_seguimiento) + imparesIzquierda + imparesDerecha;
}

vector<Paquete*> Arbol::obtenerPaquetesEnHojas(pnodoAbb nodo) {
    
    vector<Paquete*> paquetes;
    
    if (nodo == nullptr) {
        return paquetes;
    }

    // Un nodo hoja no tiene ningun nodo hijo
    if (nodo->izq == nullptr && nodo->der == nullptr) {
        paquetes.push_back(nodo->paquete);
    }
    // Recorrer de manera eficiente los nodos hoja en el subárbol izquierdo y derecho
    auto paquetesIzquierda = obtenerPaquetesEnHojas(nodo->izq);
    auto paquetesDerecha = obtenerPaquetesEnHojas(nodo->der);

     // Combinar los paquetes de ambas ramas
    paquetes.insert(paquetes.end(), paquetesIzquierda.begin(), paquetesIzquierda.end());
    paquetes.insert(paquetes.end(), paquetesDerecha.begin(), paquetesDerecha.end());
    
    return paquetes;
}

int Arbol::maximo(pnodoAbb nodo) {
    if (nodo == nullptr) {
        throw runtime_error("Árbol vacío"); // Lanza una excepción en caso de árbol vacío
    }

    int elementoAEliminar;

    if (nodo->der == nullptr) {
        elementoAEliminar = nodo->paquete->num_seguimiento;
    } else {
        elementoAEliminar = maximo(nodo->der);
    }

    return elementoAEliminar;
}

pnodoAbb Arbol::borrarElemento(int elementoAEliminar, pnodoAbb nodo) {
    
    if (nodo != nullptr) {
        if (elementoAEliminar == nodo->paquete->num_seguimiento) {
            return borrarNodo(nodo);
        } else if (elementoAEliminar < nodo->paquete->num_seguimiento) {
            nodo->izq = borrarElemento(elementoAEliminar, nodo->izq);
        } else {
            nodo->der = borrarElemento(elementoAEliminar, nodo->der);
        }
    }
    return nodo;
}

pnodoAbb Arbol::borrarNodo(pnodoAbb nodo) {
    
    if (nodo->izq == nullptr) {
        pnodoAbb nuevo = nodo->der;
        nodo->der = nullptr;
        delete nodo;
        return nuevo;
    } else if (nodo->der == nullptr) {
        pnodoAbb nuevo = nodo->izq;
        nodo->izq = nullptr;
        delete nodo;
        return nuevo;
    } else {
        int elementoAEliminar = maximo(nodo->izq);
        nodo->paquete->num_seguimiento = elementoAEliminar;
        nodo->izq = borrarElemento(elementoAEliminar, nodo->izq);
        return nodo;
    }
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
