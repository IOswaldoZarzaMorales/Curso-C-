#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(0)); // Inicializar la semilla para generar números aleatorios

    char eleccion;
    do {
        cout << "Juego de Chicos y Grandes" << endl;
        cout << "Elige entre Chicos (C) o Grandes (G): ";
        cin >> eleccion;

        if (eleccion != 'C' && eleccion != 'G') {
            cout << "Eleccion no valida. Eligelige entre 'C' o 'G'." << endl;
            continue;
        }

        int dado1 = rand() % 6 + 1; 
        int dado2 = rand() % 6 + 1; 

        int suma = dado1 + dado2;
        cout << "La suma de los dados es: " << suma << endl;

        if (suma < 7 && eleccion == 'C') {
            cout << "Ganaste eligiendo Chicos." << endl;
        } else if (suma > 7 && eleccion == 'G') {
            cout << "Ganaste eligiendo Grandes." << endl;
        } else {
            cout << "La casa gana esta ronda." << endl;
        }

        char continuar;
        cout << "¿Quieres jugar de nuevo? (S/N): ";
        cin >> continuar;
        if (continuar != 'S' && continuar != 's') {
            break;
        }
    } while (true);

    cout << "Gracias por jugar." << endl;

    return 0;
}
