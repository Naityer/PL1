#include "Paquete.hpp"

Paquete::Paquete()
{
    this->prioridad = (rand() % 2);  // 0 = Estandar ; 1 = Urgente
    this->ID = 0;
    this->num_seguimiento = 0;
}

//FUNCIONES DE PAQUETES ==============================================================================================

void Paquete::mostrar()
{
     // Utilización de la operación ternaria para la asignación condicional
    string asignacion = (prioridad == 0) ? "estandar" : "urgente";
    
    if (ID != 0) {
        // PEDIDO CON ID
        cout << left << setw(20) << "El pedido a nombre del titular con DNI " << this->DNI << " es de caracter " << asignacion << ", su ID es: " << this->ID << endl;
        
    } else if (num_seguimiento != 0) {
        // PEDIDO CON NUMERO DE SEGUIMIENTO
        cout << left << setw(20) << "El pedido a nombre del titular con DNI " << this->DNI << " es de caracter " << asignacion << ", su ID es: " << this->ID << " y su numero de seguimiento es: " << endl;
        
    } else {
        // PEDIDO SIN ID NI NUMERO DE SEGUIMIENTO
        cout << left << setw(20) << "El pedido a nombre del titular con DNI " << this->DNI << " es de caracter " << asignacion << endl;
    }
    cout << endl;
}

// SETTER ===================================================================================================

void Paquete::setID(int IDgenerado){
    this->ID = IDgenerado;
}

void Paquete::setNum_seguimiento(int seguimientoGenerado)
{
    this->num_seguimiento = seguimientoGenerado;
}

void Paquete::setDNI(string DNIgenerado){
    strcpy(DNI, DNIgenerado.c_str());
}


// GETTER getPrioridad;  getID {"None"}; getNum_seguimiento{0};  getDNI[10]; ================================

bool Paquete::getPrioridad()
{
    return this->prioridad;
} 
   
int Paquete::getID()
{
    return this->ID;
}

int Paquete::getNum_seguimiento()
{
    return num_seguimiento;
}

char* Paquete::getDNI()
{
    return DNI;
}

Paquete::~Paquete()
{
    
}

