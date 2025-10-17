#include <iostream> // Ввод <---> Вывод
#include <vector> // Для удобства в массивах
#include <string> // Для нормальных строк

int exit(std::vector<std::string>m){
    for (int i=0;i<std::size(m);i++){
        std::cout << "[" << m[i] << "]";
    }
    std::cout << std::endl;
    return 0;
}

int pair(std::string n,std::string m){
    for (int i=0;i<std::size(n)-1;i++){
        for(int j=0;j<std::size(m)-1;j++){
            if (n[i] == m[j] && n[i+1] == m[j+1]){
                std::cout << m << " " << n << " - " << n[i] << n[i+1] << std::endl;
                return 0;
            }
        }
    }
    return 0;
}

int main(){
    std::string inp = "";
    std::cout << "Введите строку из 10 слов: ";
    std::getline(std::cin, inp); //Получаем строку из 10 слов
    std::cout << std::endl << "Вы ввели: " << inp << std::endl; 

    // Делим на отдельные слова и заносим их в вектор
    std::vector<std::string> m(10,"");
    short c = 0;
    for (int i=0;i<std::size(inp);i++){
        if ((int)inp[i] == 32){
            c++;
        }
        else{
            m[c] += inp[i];
        }
    }
    std::cout << "Поделённое на слова: ";
    exit(m);

    // Считаем колво слов начинающихся на a(A)
    c = 0;
    for (int i=0;i<10;i++){
        if (m[i][0] == 'a' || m[i][0] == 'A'){
            c++;
        }
    }
    std::cout << "Число слов начинающихся на a(A): " << c << std::endl;

    // Находим длинну самого короткого слова
    c = std::size(m[0]);
    for (int i=1;i<10;i++){
        if (c > std::size(m[i])){
            c = std::size(m[i]);
        }
    }
    std::cout << "Длинна наименьшего слова: " << c << std::endl;

    // Заменяем все заглавные буквы на строчные
    for (int i=0;i<10;i++){
        for(int j=0;j<std::size(m[i]);j++){
            if ((int)m[i][j]>=65 && (int)m[i][j]<=90){
                m[i][j] += 32;
            }
        }
    }
    std::cout << "Меняем все заглавные буквы на строчные: ";
    exit(m);

    // Считаем колличество слов с одинаковым началом и концом
    c = 0;
    for (int i=0;i<10;i++){
        for (int j=i+1;j<10;j++){
            if(m[i][0]==m[j][0] && m[i][std::size(m[i])-1]==m[j][std::size(m[j])-1]){
                c++;
            }
        }
    }
    std::cout << "Колличество пар с одинаковым началом и концом: " << c << std::endl;

    // *Ищем самую короткую общую строку между двумя словами (через отсутствие логики)
    std::cout << "Наименьшая общая часть: " << std::endl;
    for (int I=0;I<10;I++){
        for (int J=I+1;J<10;J++){
            pair(m[I],m[J]);
            c++;
        }
    }
    return 0;
}