#include <iostream>

int main(){
    setlocale(LC_ALL,"rus");
    int a;
    std::cout << "Введите число: ";
    std::cin >> a;
    if (a%3==0){
        std::cout << "Число делится на 3";
    }
    else{
        std::cout << "Число не делится на 3";
    }
    if (a%5==0){
        std::cout << " и делится на 5";
    }
    else{
        std::cout << " и не делится на 5";
    }
    return 0;
}