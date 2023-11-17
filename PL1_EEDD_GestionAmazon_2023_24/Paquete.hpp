#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include "PedidoControl.hpp"

#ifndef PAQUETE_HPP
#define PAQUETE_HPP

using namespace std;

class Paquete
{
public:

//ATRIBUTOS
    Paquete();
    //GET
    bool getPrioridad();
    int getID();
    int getNum_seguimiento();
    char* getDNI();
    
    //SET
    bool setPrioridad();
    void setID(int IDgenerado);
    void setNum_seguimiento(int seguimientoGenerado);
    void setDNI(char* DNIgenerado);
    ~Paquete();

    
private:

//ATRIBUTOS
    bool prioridad;
    int ID {0};
    int num_seguimiento{0};
    char DNI[10];

//METODOS
    void mostrar(int ID, int num_seguimiento);
    friend class Gestor;
    friend class Lista;
};

#endif // PAQUETE_HPP