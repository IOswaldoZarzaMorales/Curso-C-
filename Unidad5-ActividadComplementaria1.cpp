#include <iostream>
#include <vector>

using namespace std;

void generarSubconjuntos(int inicio, int fin, vector<int>& conjunto, vector<int>& actual) {
    if (inicio == fin) {
        if (!actual.empty()) {
            for (int i : actual) {
                cout << i << " ";
            }
            cout << endl;
        }
        return;
    }

    generarSubconjuntos(inicio + 1, fin, conjunto, actual);

    actual.push_back(conjunto[inicio]);
    generarSubconjuntos(inicio + 1, fin, conjunto, actual);
    actual.pop_back();
}

void generarSubconjuntos(int n) {
    vector<int> conjunto(n);
    vector<int> actual;
    for (int i = 0; i < n; ++i) {
        conjunto[i] = i + 1;
    }

    generarSubconjuntos(0, n, conjunto, actual);
}

int main() {
    int n;
    cout << "Ingrese el valor de n: ";
    cin >> n;

    cout << "Los subconjuntos no vacíos del conjunto {1, 2, ..., " << n << "} son:\n";
    generarSubconjuntos(n);

    return 0;
}
