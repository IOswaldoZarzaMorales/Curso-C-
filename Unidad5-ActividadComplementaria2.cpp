#include <iostream>
#include <vector>

using namespace std;

void generateMagicSquare(int n) {
    vector<vector<int>> magicSquare(n, vector<int>(n, 0));

    int i = n / 2;
    int j = n - 1;

    
    for (int num = 1; num <= n * n; ) {
        if (i == -1 && j == n) { 
            j = n - 2;
            i = 0;
        } else {
            
            if (j == n) {
                j = 0;
            }

            
            if (i < 0) {
                i = n - 1;
            }
        }

        if (magicSquare[i][j] != 0) { 
            j -= 2;
            i++;
            continue;
        } else {
            
            magicSquare[i][j] = num++;
        }

        j++; 
        i--; 
    }

 
    cout << "El cuadrado mágico de orden " << n << " es:" << endl;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            cout << magicSquare[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Ingrese el valor de n (debe ser impar y estar entre 3 y 10): ";
    cin >> n;

    if (n % 2 == 0 || n <= 3 || n >= 10) {
        cout << "El valor de n debe ser un número impar entre 3 y 10." << endl;
        return 1;
    }

    generateMagicSquare(n);

    return 0;
}
