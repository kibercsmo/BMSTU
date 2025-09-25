#include <iostream>

int main(){
    setlocale(LC_ALL,"rus");
    double a;
    std::cout << "Градусы цельсия: ";
    std::cin >> a;
    std::cout << "Градусы фаренгейта: " << (a * 9 / 5) + 32;
    return 0;
}