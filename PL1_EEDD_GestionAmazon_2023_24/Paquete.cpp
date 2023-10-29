#include "Paquete.hpp"

Paquete::Paquete()
{
    this->prioridad = (rand() % 2);  // 0 = Estandar ; 1 = Urgente
    this->generarDNI();
}

//CONTADORES ESTATICOS - PAQUETES ====================================================================================
int Paquete::countEstandarID = 0;
int Paquete::countUrgenteID = 50;

//FUNCIONES DE PAQUETES ==============================================================================================

void Paquete::generarDNI()
{
    char letras[] = "TRWAGMYFPDXBNJZSQVHLCKE" ;
    int numDNI = 0, aux = 1E7;
    for(int i = 0; i < 8; i++) {
        int num = rand() % 10;
        this->DNI[i] = '0' + num;
        numDNI = numDNI + num * aux;
        aux /= 10;
    }
    
    this->DNI[8] = letras[numDNI % 23];
    this->DNI[9] = '\0';
}

void Paquete::generarNumSeguimiento(bool prioridad)
{
    if(prioridad == 0) {
        int valor = rand() % 500;
        if(isRepetido(valor)) {
            generarNumSeguimiento(0);
        } else {
            this->num_seguimiento = valor;
            seguimientoDuplicados.push_back(num_seguimiento);
        }
    } else {
        int valor = rand() % 500 + 499;
        if(isRepetido(valor)) {
            generarNumSeguimiento(1);
        } else {
            this->num_seguimiento = valor;
            seguimientoDuplicados.push_back(num_seguimiento);
        }
    }
}

void Paquete::asignarID()
{
    // 0 - PRIORIDAD ESTANDAR
    if(countEstandarID >= 0 && countEstandarID < 49 && this->prioridad == 0) {
            countEstandarID++;
            this->ID = countEstandarID;
    
    // 1 - PRIORIDAD URGENTE
    } else if (countUrgenteID >= 50 && countUrgenteID < 99 && this->prioridad == 1) {
        countUrgenteID++;
        this->ID = countUrgenteID;
    } 
}

bool Paquete::isRepetido(int num_seguimiento) {
    
    int key = num_seguimiento;
    if (find(seguimientoDuplicados.begin(), seguimientoDuplicados.end(), key) != seguimientoDuplicados.end()) {
        cout << key << " REPETIDO cambiando num_segumiento ";
        return true;
    }
    else {
        cout << "NUM_SEGUIMIENTO disponible -> " << key;
    }
    return 0;
}

// SETTER ===================================================================================================

void Paquete::setID(){
     this->asignarID();
}

void Paquete::setNum_seguimiento(bool prioridad)
{
    this->generarNumSeguimiento(prioridad);
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

int Paquete::getCountEstandar()
{
    return countEstandarID;
}

void Paquete::setCountEstandar(int v) {
    this->countEstandarID = v;
}

int Paquete::getCountUrgente()
{
    return countUrgenteID;
}

void Paquete::setCountUrgente(int v) {
    this->countUrgenteID = v;
}

Paquete::~Paquete()
{
    
}

