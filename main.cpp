#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main() {
    srand(time(0));
    int numeros[100] = {};
    
    for (int i = 0; i < 100; i++) {
        numeros[i] = (rand() % 1000) + 1;
    }
      
    for (int i = 0; i < 100; i++) {
        cout << "Consecutivo " << i << " valor " << numeros[i] << endl;
    }
    
    cout << "Termina programa " << endl;
    
    return 0;
}