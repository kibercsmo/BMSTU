#include <iostream>

int main(){
    setlocale(LC_ALL,"rus");
    int a;
    std::cout << "Введите число: ";
    std::cin >> a;
    for (int i = 1; i < a+1; i++){
        std::cout << i*i << std::endl;
    }
    return 0;
}