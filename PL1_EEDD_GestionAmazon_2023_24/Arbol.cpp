#include "Arbol.hpp"

Arbol::Arbol() { 
    raiz = nullptr;
}

void Arbol::insertar(Paquete* p) { 
    raiz = insertar(raiz, p); 
}

pnodoAbb Arbol::insertar(pnodoAbb nodo, Paquete* p)
{
    if (!nodo) {
        cout << "NODO RAIZ " << p->getID() << endl;
        return new NodoArbol(p);
    } else if (p->getPrioridad() == 0) {
        // Intentar insertar en el lado derecho si está vacío
        if (p->getNum_seguimiento() >= nodo->paquete->getNum_seguimiento()) {
            nodo->der = insertar(nodo->der, p);
            cout << "Elemento insertado DER: " << p->getID() << endl;
            return nodo;
        } else {
            // Insertar en el lado izquierdo si el derecho no está disponible
            nodo->izq = insertar(nodo->izq, p);
            cout << "Elemento insertado IZQ: " << p->getID() << endl;
            return nodo;
        }
    } else {
        // Intentar insertar en el lado izquierdo si está vacío
        if (p->getNum_seguimiento() >= nodo->paquete->getNum_seguimiento()) {
            nodo->izq = insertar(nodo->izq, p);
            cout << "Elemento insertado IZQ: " << p->getID() << endl;
            return nodo;
        } else {
            // Insertar en el lado derecho si el izquierdo no está disponible
            nodo->der = insertar(nodo->der, p);
            cout << "Elemento insertado DER: " << p->getID() << endl;
            return nodo;
        }
    }
}


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
