#include <iostream>

int main(){
    setlocale(LC_ALL,"rus");
    int a;
    std::cout << "Введите возраст: ";
    std::cin >> a;
    if (a<18){
        std::cout << "Вы юноша";
    }
    else if(a<60){
        std::cout << "Вы еще не старый!";
    }
    else{
        std::cout << "Вы старый!";
    }
    return 0;
}