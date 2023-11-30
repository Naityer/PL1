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
    int indiceAleatorio;
    int numeroSelecionado;
    bool prioridad;
    int ID;
    int num_seguimiento;
    char DNI[10];
    
    vector<int> vectorIDestandar;
    vector<int> vectorIDurgente;
    vector<int> vectorSeguimientoEstandar;
    vector<int> vectorSeguimientoUrgente;
    
private:
    
//METODOS
    string generarDNI();
    void generarArrayID();
    void generarArraySeguimiento();
    int asignarNumSeguimiento(bool prioridad);
    int asignarID(bool prioridad);
    
    friend class Gestor;
};

#endif // PEDIDOCONTROL_HPP
