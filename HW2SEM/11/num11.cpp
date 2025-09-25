#include <iostream>

int main(){
    setlocale(LC_ALL,"rus");
    for (int i = 32; i <= 126; i++){
        std::cout << i << " - " << (char)i << std::endl;
    }
    return 0;
}