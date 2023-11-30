#include "PedidoControl.hpp"

PedidoControl::PedidoControl()
{
    this->ID = 0;
    this->num_seguimiento = 0;
}

string PedidoControl::generarDNI()
{
    char letras[] = "TRWAGMYFPDXBNJZSQVHLCKE" ;
    int numDNI = 0, aux = 1E7;
    for(int i = 0; i < 8; i++) {
        int num = rand() % 10;
        DNI[i] = '0' + num;
        numDNI = numDNI + num * aux;
        aux /= 10;
    }
    
    this->DNI[8] = letras[numDNI % 23];
    this->DNI[9] = '\0';
    return string(DNI);
}

void PedidoControl::generarArrayID()
{
    // Crear un vector con números del 1 al 49
    for (int i = 1; i <= 49; ++i) {
        vectorIDestandar.push_back(i);
    }
    // Crear un vector con números del 51 al 99
    for (int i = 51; i <= 99; ++i) {
        vectorIDurgente.push_back(i);
    }
}

int PedidoControl::asignarID(bool prioridad)
{
    //vector<int> vectorID = (prioridad == 0) ? vectorIDestandar : vectorIDurgente;
    
    if (vectorIDestandar.size() > 0 && prioridad == 0) {
        // Elegir un número aleatorio y eliminarlo del vector
        indiceAleatorio = rand() % vectorIDestandar.size();
        numeroSelecionado = vectorIDestandar[indiceAleatorio];
        vectorIDestandar.erase(vectorIDestandar.begin() + indiceAleatorio);

        return numeroSelecionado;
    } else {
        // Elegir un número aleatorio y eliminarlo del vector
        indiceAleatorio = rand() % vectorIDurgente.size();
        numeroSelecionado = vectorIDurgente[indiceAleatorio];
        vectorIDurgente.erase(vectorIDurgente.begin() + indiceAleatorio);

        return numeroSelecionado;
    }
    return 0;
}

void PedidoControl::generarArraySeguimiento()
{
    // Crear un vector con números del 1 al 49
    for (int i = 1; i <= 499; ++i) {
        vectorSeguimientoEstandar.push_back(i);
    }
    
    // Crear un vector con números del 51 al 99
    for (int i = 501; i <= 999; ++i) {
        vectorSeguimientoUrgente.push_back(i);
    }
}

int PedidoControl::asignarNumSeguimiento(bool prioridad)
{
    
    if (vectorSeguimientoEstandar.size() > 0 && prioridad == 0) {
        // Elegir un número aleatorio y eliminarlo del vector
        indiceAleatorio = rand() % vectorSeguimientoEstandar.size();
        numeroSelecionado = vectorSeguimientoEstandar[indiceAleatorio];
        vectorSeguimientoEstandar.erase(vectorSeguimientoEstandar.begin() + indiceAleatorio);

        return numeroSelecionado;
    } else {
         // Elegir un número aleatorio y eliminarlo del vector
        indiceAleatorio = rand() % vectorSeguimientoUrgente.size();
        numeroSelecionado = vectorSeguimientoUrgente[indiceAleatorio];
        vectorSeguimientoUrgente.erase(vectorSeguimientoUrgente.begin() + indiceAleatorio);

        return numeroSelecionado;
    }
    return 0;
}

PedidoControl::~PedidoControl()
{
}

