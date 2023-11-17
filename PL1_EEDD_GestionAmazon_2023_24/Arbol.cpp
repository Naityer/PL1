//#include "Arbol.hpp"
//
//Arbol::Arbol()
//{
//}
//
//Arbol::~Arbol()
//{
//}
//
//#include "Arbol.hpp"
//
//Arbol::Arbol()
//{
//    raiz = NULL;
//    num = 0;
//}
//int Arbol::altura()
//{
//    altura(raiz);
//}
//int Arbol::altura(pnodoAbb a)
//{
//    if(a == NULL) {
//        return 0;
//    } else if(a->izq == NULL && a->der == NULL) {
//        return 1;
//    } else {
//        return 1 + max(altura(a->izq), altura(a->der));
//    }
//}
//int Arbol::getNum()
//{
//    return num;
//}
//void Arbol::setNum(int x)
//{
//    num = x;
//}
//void Arbol::menorApendicitis()
//{
//    menorApendicitis(raiz->izq);
//}
//void Arbol::menorApendicitis(pnodoAbb a)
//{
//    if(a == NULL) {
//        cout << "\nArbol vacio ";
//    }
//    if(a->izq == NULL) {
//        cout << "\nPaciente con apendicitis de la habitacion cuyo numero es el menor:\n \t";
//        a->dato->mostrar();
//    } else {
//        menorApendicitis(a->izq);
//    }
//}
//void Arbol::menorHernias()
//{
//    menorHernias(raiz->der);
//}
//void Arbol::menorHernias(pnodoAbb a)
//{
//    if(a == NULL) {
//        cout << "\nArbol vacio ";
//    }
//    if(a->izq == NULL) {
//        cout << "\nPaciente con hernias de la habitacion cuyo numero es el menor:\n \t";
//        a->dato->mostrar();
//    } else {
//        menorHernias(a->izq);
//    }
//}
//void Arbol::mayorApendicitis()
//{
//    mayorApendicitis(raiz->izq);
//}
//void Arbol::mayorApendicitis(pnodoAbb a)
//{
//    if(a == NULL) {
//        cout << "\nArbol vacio ";
//    }
//    if(a->der == NULL) {
//        cout << "\nPaciente con apendicitis de la habitacion cuyo numero es el mayor:\n \t";
//        a->dato->mostrar();
//    } else {
//        mayorApendicitis(a->der);
//    }
//}
//void Arbol::mayorHernias()
//{
//    mayorHernias(raiz->der);
//}
//void Arbol::mayorHernias(pnodoAbb a)
//{
//    if(a == NULL) {
//        cout << "\nArbol vacio ";
//    }
//    if(a->der == NULL) {
//        cout << "\nPaciente con hernias de la habitacion cuyo numero es el mayor:\n \t";
//        a->dato->mostrar();
//    } else {
//        mayorHernias(a->izq);
//    }
//}
//
//void Arbol::inorden()
//{
//    inorden(raiz);
//}
//void Arbol::inorden(pnodoAbb a)
//{
//    if(a == NULL) {
//        return;
//    } else {
//        inorden(a->izq);
//        a->dato->mostrar();
//        inorden(a->der);
//    }
//}
//int Arbol::contarImpares()
//{
//    int contador = 0;
//    contarImpares(raiz, contador);
//    return contador;
//}
//void Arbol::contarImpares(pnodoAbb a, int& contador)
//{
//    if(a == NULL) {
//        return;
//    } else {
//        if(a->dato->getNHabitacion() % 2 == 0) {
//
//        } else {
//            contador++;
//        }
//        contarImpares(a->izq, contador);
//        contarImpares(a->der, contador);
//    }
//}
//
//void Arbol::inordenizq()
//{
//    inorden(raiz->izq);
//}
//void Arbol::inordender()
//{
//    inorden(raiz->der);
//}
//void Arbol::mostrarIzq()
//{
//    int cont = 0;
//    mostrar(raiz->izq, cont);
//}
//void Arbol::mostrarDer()
//{
//    int cont = 0;
//    mostrar(raiz->der, cont);
//}
//void Arbol::mostrarHojas()
//{
//    mostrarHojas(raiz);
//}
//void Arbol::mostrarHojas(pnodoAbb a)
//{
//    if(a == NULL) {
//        return;
//    } else {
//        if(a->der == NULL && a->izq == NULL) {
//            a->dato->mostrar();
//        }
//        mostrarHojas(a->izq);
//        mostrarHojas(a->der);
//    }
//}
//pnodoAbb Arbol::minimo(pnodoAbb a)
//{
//    if(a == NULL) {
//        return NULL;
//    } else if(a->izq) {
//        return minimo(a->izq);
//    } else {
//        return a;
//    }
//}
//
//Paciente* Arbol::buscarValor(int x)
//{
//    return buscarValor(raiz, x);
//}
//
//Paciente* Arbol::buscarValor(pnodoAbb a, int x)
//{
//    if(a == NULL) {
//        return NULL;
//    } else if(x < a->dato->getNHabitacion()) {
//        buscarValor(a->izq, x);
//    } else if(x > a->dato->getNHabitacion()) {
//        buscarValor(a->der, x);
//    } else if(x == a->dato->getNHabitacion()) {
//        return a->dato;
//    }
//}
//
//void Arbol::mostrarArbol()
//{
//    int cont = 0;
//    mostrar(raiz, cont);
//}
//void Arbol::mostrar(pnodoAbb a, int cont)
//{
//    if(a == NULL) {
//        return;
//    } else {
//        mostrar(a->der, cont + 1);
//        for(int i = 0; i < cont; i++) {
//            cout << "     ";
//        }
//        cout << a->dato->getNHabitacion() << endl;
//        mostrar(a->izq, cont + 1);
//    }
//}
//
//void Arbol::insertar(Paciente* x)
//{
//
//    insertar(raiz, x, NULL);
//}
//
//pnodoAbb Arbol::insertar(pnodoAbb& a, Paciente* x, pnodoAbb p)
//{
//    if(a == NULL) {
//        pnodoAbb nuevo = new NodoArbol(x, p);
//        a = nuevo;
//        cout << "HOLA";
//
//    } else {
//        if(x->getNHabitacion() < a->dato->getNHabitacion()) {
//
//            insertar(a->izq, x, a);
//
//        } else {
//            insertar(a->der, x, a);
//        }
//    }
//}
//void Arbol::eliminar(Paciente * p){
//    eliminar(raiz,p);
//}
//void Arbol::eliminar(pnodoAbb a, Paciente* p)
//{
//
//    if(a == NULL) {
//        return;
//    } else if(p->getNHabitacion() < a->dato->getNHabitacion()) {
//        eliminar(a->izq, p);
//    } else if(p->getNHabitacion() > a->dato->getNHabitacion()) {
//        eliminar(a->der, p);
//    } else {
//        eliminarNodo(a);
//    }
//}
//
//void Arbol::eliminarNodo(pnodoAbb a)
//{
//
//    if(a->izq && a->der) {
//        pnodoAbb b = minimo(a->der);
//        a->dato = b->dato;
//        eliminarNodo(b);
//    } else if(a->izq) {
//        reemplazarNodo(a, a->izq);
//        a->izq = nullptr;
//        a->der = nullptr;
//        a->padre = nullptr;
//        delete a;
//    } else if(a->der) {
//        reemplazarNodo(a, a->der);
//    } else {
//        reemplazarNodo(a, NULL);
//        a->izq = nullptr;
//        a->der = nullptr;
//        a->padre = nullptr;
//        delete a;
//    }
//}
//void Arbol::reemplazarNodo(pnodoAbb a, pnodoAbb b)
//{
//    if(a->padre) {
//        if(a->dato->getNHabitacion() == a->padre->izq->dato->getNHabitacion()) {
//            a->padre->izq = b;
//        } else if(a->dato->getNHabitacion() == a->padre->der->dato->getNHabitacion()) {
//            a->padre->der = b;
//        }
//        if(b) {
//            b->padre = a->padre;
//        }
//    }
//}
//void Arbol::dibujar()
//{
//    int h = altura(raiz);
//    vector<string> output(h), linkAbove(h);
//    dibujarNodo(output, linkAbove, raiz, 0, 5, ' ');
//    for(int i = 1; i < h; i++) {
//        for(int j = 0; j < linkAbove[i].size(); j++) {
//            if(linkAbove[i][j] != ' ') {
//                int size = output[i - 1].size();
//                if(size < j + 1)
//                    output[i - 1] += string(j + 1 - size, ' ');
//                int jj = j;
//                if(linkAbove[i][j] == 'L') {
//                    while(output[i - 1][jj] == ' ')
//                        jj++;
//                    for(int k = j + 1; k < jj - 1; k++)
//                        output[i - 1][k] = '_';
//                } else if(linkAbove[i][j] == 'R') {
//                    while(output[i - 1][jj] == ' ')
//                        jj--;
//                    for(int k = j - 1; k > jj + 1; k--)
//                        output[i - 1][k] = '_';
//                }
//                linkAbove[i][j] = '|';
//            }
//        }
//    }
//    cout << '\n' << '\n';
//    for(int i = 0; i < h; i++) {
//        if(i)
//            cout << linkAbove[i] << '\n';
//        cout << output[i] << '\n';
//    }
//    cout << '\n' << '\n';
//}
//void Arbol::dibujarNodo(vector<string>& output,
//    vector<string>& linkAbove,
//    pnodoAbb nodo,
//    int nivel,
//    int p,
//    char linkChar)
//{
//
//    if(!nodo)
//        return;
//    int h = output.size();
//    string SP = " ";
//    if(p < 0) {
//        string extra(-p, ' ');
//        for(string& s : output)
//            if(!s.empty())
//                s = extra + s;
//        for(string& s : linkAbove)
//            if(!s.empty())
//                s = extra + s;
//    }
//    if(nivel < h - 1)
//        p = max(p, (int)output[nivel + 1].size());
//    if(nivel > 0)
//        p = max(p, (int)output[nivel - 1].size());
//    p = max(p, (int)output[nivel].size());
//    if(nodo->izq) {
//        int numeroQueQuieroImprimirEnElArbol = nodo->izq->dato->getNHabitacion();
//        string izqdato = SP + to_string(numeroQueQuieroImprimirEnElArbol) + SP;
//        dibujarNodo(output, linkAbove, nodo->izq, nivel + 1, p - izqdato.size(), 'L');
//        p = max(p, (int)output[nivel + 1].size());
//    }
//    int space = p - output[nivel].size();
//    if(space > 0)
//        output[nivel] += string(space, ' ');
//    int numeroQueQuieroImprimirEnElArbol = nodo->dato->getNHabitacion();
//    string nododato = SP + to_string(numeroQueQuieroImprimirEnElArbol) + SP;
//    output[nivel] += nododato;
//    space = p + SP.size() - linkAbove[nivel].size();
//    if(space > 0)
//        linkAbove[nivel] += string(space, ' ');
//    linkAbove[nivel] += linkChar;
//    if(nodo->der)
//        dibujarNodo(output, linkAbove, nodo->der, nivel + 1, output[nivel].size(), 'R');
//}
//Arbol::~Arbol()
//{
//}
