#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    srand(time(0));

    const int totalNumeros = 100;
    const int rangoInicio = 1;
    const int rangoFin = 20;
    int numeros[totalNumeros];
    for (int i = 0; i < totalNumeros; ++i) {
        numeros[i] = rand() % (rangoFin - rangoInicio + 1) + rangoInicio;
    }

    sort(numeros, numeros + totalNumeros);

    map<int, int> frecuencias;
    for (int i = 0; i < totalNumeros; ++i) {
        frecuencias[numeros[i]]++;
    }

    cout << "Numeros aleatorios en orden de menor a mayor:" << endl;
    for (int i = 0; i < totalNumeros; ++i) {
        cout << numeros[i] << " ";
    }
    cout << endl;

    cout << "Frecuencia de cada numero:" << endl;
    for (auto it = frecuencias.begin(); it != frecuencias.end(); ++it) {
        cout << "Numero " << it->first << ": " << it->second << " veces" << endl;
    }

    return 0;
}
