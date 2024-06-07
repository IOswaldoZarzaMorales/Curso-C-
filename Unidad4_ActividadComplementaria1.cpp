#include <iostream>

int mcd(int x, int y) {
    if (y == 0)
        return x;
    else
        return mcd(y, x % y);
}

int main() {
    int num1, num2;
    
    std::cout << "Introduce el primer número: ";
    std::cin >> num1;
    std::cout << "Introduce el segundo número: ";
    std::cin >> num2;
    
    int resultado = mcd(num1, num2);
    
    std::cout << "El Máximo Común Divisor (MCD) de " << num1 << " y " << num2 << " es: " << resultado << std::endl;
    
    return 0;
}
