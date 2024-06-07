#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> generarNumerosAleatorios(int cantidad) {
    vector<int> numerosDisponibles;
    for (int i = 1; i <= 100; ++i) {
        numerosDisponibles.push_back(i);
    }

    vector<int> numerosGenerados;
    srand(time(0)); // Semilla para la generación de números aleatorios
    for (int i = 0; i < cantidad; ++i) {
        int indice = rand() % numerosDisponibles.size();
        numerosGenerados.push_back(numerosDisponibles[indice]);
        numerosDisponibles.erase(numerosDisponibles.begin() + indice);
    }
    sort(numerosGenerados.begin(), numerosGenerados.end()); // Ordenar los números generados
    return numerosGenerados;
}

vector<int> encontrarGap(const vector<int>& numerosGenerados) {
    vector<int> gap;
    int numeroEsperado = 1;
    for (int numero : numerosGenerados) {
        while (numero != numeroEsperado) {
            gap.push_back(numeroEsperado++);
        }
        numeroEsperado++;
    }
    while (numeroEsperado <= 100) {
        gap.push_back(numeroEsperado++);
    }
    return gap;
}

int main() {
    vector<int> numerosGenerados = generarNumerosAleatorios(80);
    vector<int> gap = encontrarGap(numerosGenerados);

    cout << "Conjunto de 80 números generados aleatoriamente:\n";
    for (int numero : numerosGenerados) {
        cout << numero << " ";
    }
    cout << "\n\n";

    cout << "Lista de números faltantes:\n";
    for (int numero : gap) {
        cout << numero << " ";
    }
    cout << endl;

    return 0;
}
