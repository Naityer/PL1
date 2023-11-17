#include <iostream>
#include <vector>
#include <cstdlib> 

using namespace std;

#ifndef PEDIDOCONTROL_HPP
#define PEDIDOCONTROL_HPP

class PedidoControl
{
public:
    PedidoControl();
    ~PedidoControl();

//ATRIBUTOS
    bool prioridad;
    int ID {0};
    int num_seguimiento{0};
    char DNI[10];
    
    vector<int> vectorIDestandar;
    vector<int> vectorIDurgente;
    vector<int> vectorSeguimientoEstandar;
    vector<int> vectorSeguimientoUrgente;
    
private:
    
//METODOS
    char* generarDNI();
    void generarArrayID();
    void generarArraySeguimiento();
    int asignarNumSeguimiento(bool prioridad);
    int asignarID(bool prioridad);
    friend class Gestor;
};

#endif // PEDIDOCONTROL_HPP
