#include "Lista.hpp"

Lista::Lista()
{
    longitud = 0;
    primero = actual = final = NULL;
}

void Lista::insertarNodo(Paquete* p, char c) {
    
    pnodoLista aux;
    char tipoInsercion;
    tipoInsercion = c;
 
    if(listaVacia()) {
        aux = new NodoLista (p, NULL, NULL);
        final = primero = aux;
        
    } else if (tipoInsercion == 'f') {
        aux= new NodoLista (p, NULL, NULL);
        aux->anterior = final;
        final->siguiente=aux;
        final=aux;
    }  
    else if (tipoInsercion == 'p') { //Inserción por el principio
        aux = new NodoLista (p, NULL, NULL);
        aux->siguiente = primero;
        primero->anterior = aux;
        primero = aux;
    }
    this->longitud++;
}

void Lista::buscarElemento(char c) {
    
    char tipoBorrado; 
    tipoBorrado = c;
    pnodoLista aux = NULL;
    
    
    // Títulos de las columnas
    cout << left << setw(20) << "TIPO_PRIORIDAD" << setw(20) << "ID_PAQUETE" << setw(20) << "NUM_SEGUIMIENTO" << setw(20) << "DNI_CLIENTE" << endl;
    cout << left << setw(20) << "______________" << setw(20) << "__________" << setw(20) << "_______________" << setw(20) << "___________" << endl;
    
    if(tipoBorrado == 'f') { //Eliminación por el final
        if(primero == final) { //Sólo hay elemento
            aux = final;
            primero = final = NULL; 
            aux=NULL;
        } else {
            aux = final; 
            final = final->anterior;
            aux->anterior=NULL;
            final->siguiente=NULL; 
        }
        
        // Datos de la fila
        cout << left << setw(20) << aux->paquete->getPrioridad() << setw(20) << aux->paquete->getID() << setw(20) << aux->paquete->getNum_seguimiento() << setw(20) << aux->paquete->getDNI() << endl;
        // Separacion de columnas
        cout << left << setw(20) << "______________" << setw(20) << "__________" << setw(20) << "_______________" << setw(20) << "___________" << endl;
        
    } else if(tipoBorrado =='p') {//Eliminación por el Principio
        pnodoLista aux = NULL;
        if(primero == final) {//Sólo hay elemento
            aux = primero;
            primero = final = NULL; 
            aux = NULL;
        } else {
        aux = primero; 
        primero = primero->siguiente; 
        aux->siguiente = NULL;
        primero->anterior = NULL; 
        }
        // Datos de la fila
        cout << left << setw(20) << aux->paquete->getPrioridad() << setw(20) << aux->paquete->getID() << setw(20) << aux->paquete->getNum_seguimiento() << setw(20) << aux->paquete->getDNI() << endl;
        // Separacion de columnas
        cout << left << setw(20) << "______________" << setw(20) << "__________" << setw(20) << "_______________" << setw(20) << "___________" << endl;
    }
}

bool Lista::listaVacia()
{
    return primero == NULL;
}

void Lista::recorrerLista(bool orden)
{
    pnodoLista aux;
    
    // Títulos de las columnas
    cout << left << setw(20) << "ID_PAQUETE" << setw(20) << "NUM_SEGUIMIENTO" << setw(20) << "DNI_CLIENTE" << endl;
    cout << left << setw(20) << "__________" << setw(20) << "_______________" << setw(20) << "___________" << endl;
    
    if (orden == true) { 
        esPrimero();
        aux = primero;
        while(aux) {
            cout << left << setw(20) << aux->paquete->getID() << setw(20) << aux->paquete->getNum_seguimiento() << setw(20) << aux->paquete->getDNI() << endl;
            // Separacion de columnas
            cout << left << setw(20) << "__________" << setw(20) << "_______________" << setw(20) << "___________" << endl; 
            aux = aux->siguiente;
        }

    } else {
        esUltimo();
        aux = final; 
        while(aux) {
            cout << left << setw(20) << aux->paquete->getID() << setw(20) << aux->paquete->getNum_seguimiento() << setw(20) << aux->paquete->getDNI() << endl;
            // Separacion de columnas
            cout << left << setw(20) << "__________" << setw(20) << "_______________" << setw(20) << "___________" << endl; 
            aux = aux->anterior;
        }
    }
    
    cout << endl;
}

void Lista::esPrimero()
{
    actual = primero;
}

void Lista::esUltimo()
{
    actual = final;
}

//GETTER

int Lista::getLongitud()
{
    return longitud;
}

void Lista::setLogitud(int v)
{
    this->longitud = v;
}

Lista::~Lista()
{
    pnodoLista aux;
    esPrimero();
    while (primero) {
        aux = primero;
        primero = primero->siguiente;
        delete aux;
    }
    
    primero = NULL;
    actual = NULL;
    final = NULL;
}

