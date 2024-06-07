#include <iostream>
#include <vector>
#include <cmath> // para pow()

using namespace std;

double calcularVAN(double inversionInicial, const vector<double>& flujosNetos, double tasaDescuento) {
    double van = -inversionInicial; 
    int n = flujosNetos.size();
    
    for (int t = 0; t < n; ++t) {
        van += flujosNetos[t] / pow(1 + tasaDescuento, t + 1);
    }
    
    return van;
}

int main() {
    double inversionInicial;
    double tasaDescuento;
    int numPeriodos;
    
    cout << "Ingrese la inversión inicial (Io): ";
    cin >> inversionInicial;
    
    cout << "Ingrese la tasa de descuento (k) en formato decimal (ejemplo 0.05 para 5%): ";
    cin >> tasaDescuento;
    
    cout << "Ingrese el número de periodos (n): ";
    cin >> numPeriodos;
    
    vector<double> flujosNetos(numPeriodos);
    for (int i = 0; i < numPeriodos; ++i) {
        cout << "Ingrese el flujo de efectivo para el periodo " << i + 1 << " (F" << i + 1 << "): ";
        cin >> flujosNetos[i];
    }
    
    double van = calcularVAN(inversionInicial, flujosNetos, tasaDescuento);
    
    cout << "El Valor Presente Neto (VAN) es: " << van << endl;
    
    return 0;
}
