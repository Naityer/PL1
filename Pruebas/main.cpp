#include <iostream>
#include <vector>

using namespace std;

int main() {
    
    for (auto i=0; i < 5; ++i) {
        vector<int> vectorSeguimiento = (prioridad == 0) ? vectorSeguimientoEstandar : vectorSeguimientoUrgente;
    
        if (vectorSeguimiento.size() > 0) {
            // Elegir un número aleatorio y eliminarlo del vector
            int tamanoInicial = vectorSeguimiento.size();
            int indiceAleatorio = rand() % tamanoInicial;
            int numeroSelecionado = vectorSeguimiento[indiceAleatorio];
            vectorSeguimiento.erase(vectorSeguimiento.begin() + indiceAleatorio);

            // Mostrar el número seleccionado y el arreglo resultante
            cout << "NUMERO SEGUIMIENTO seleccionado aleatoriamente: " << numeroSelecionado << endl;

            return numeroSelecionado;
        }
    }
    return 0;
}
