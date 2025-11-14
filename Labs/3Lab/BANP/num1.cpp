#include <iostream>
#include <string>
#include <fstream>
#include <vector>
// Это самый ужасный код что я делал...

int main(){
    short chose;
    int num;
    std::string line, fline, buff;
    std::fstream File;

    std::vector<std::string>mass;
    std::vector<int>imass;

    std::cout << "1. Создать файл с нуля" <<std::endl;
    std::cout << "2. Добавление в конец"  <<std::endl;
    std::cout << "3. Поиск"               <<std::endl;
    std::cout << "4. Вывод по приоритету" <<std::endl;
    std::cout << "5. Сортировка"          <<std::endl;
    std::cout << "0. Выход из программы"  <<std::endl;
    std::cout << "Выберите действие: ";
    std::cin >> chose;
    switch (chose){
        default:
            //Выход из програмыы
            return 0;
        break;
        case 1:

            //Создание файла 
            File.open("tasks.txt");
            if (File.is_open()){
                std::cout << "Error: file exists";
                File.close();
                break;
            }
            else{
                std::ofstream File("tasks.txt");
                File.close();
            }

        case 2:

            //Добавление строк
            File.open("tasks.txt");
            std::cout << "Enter task: Name|Priority|Term(DD:MM:YY);" << std::endl;
            std::cin.ignore();
            std::getline(std::cin, line);
            while (!line.empty()){
                File << line << std::endl;
                std::getline(std::cin, line);
            }
            File.close();

        break;
        case 3:

            //Поиск строк с названием
            File.open("tasks.txt");
            std::cout << "Task name: ";
            std::cin.ignore();
            std::getline(std::cin, line);
            while (File >> fline){
                if(fline.substr(0,line.size()) == line && fline[line.size()] == '|'){
                    std::cout << fline << std::endl;
                }
            }
            File.close();

        break;
        case 4:

            //Поиск по приоритету (сделал больше или равно, потому что это логичнее)
            File.open("tasks.txt");
            std::cout << "Priority: ";
            std::cin >> num;
            while (File >> fline){
                buff = "";
                for (char i: fline){
                    if (int(i) > 47 && int(i) < 58){
                        buff += i;
                    }
                }
                buff = buff.substr(0,buff.size()-6);
                if (std::stoi(buff) >= num){
                    std::cout << fline << buff << std::endl;
                }
            }
            File.close();

        break;
        case 5:

            //Сортировка
            File.open("tasks.txt");
            std::cout << "Сортировать по:" << std::endl;
            std::cout << "1. Приоритету" << std::endl;
            std::cout << "2. Дате" << std::endl;
            std::cin >> chose;

            //Выборка данных
            switch (chose)
            {
            case 1:
                // Сохраняем 2 вектора с целыми строками и приоритетом
                while (File >> fline){
                    buff = "";
                    for (char i: fline){
                        if (int(i) > 47 && int(i) < 58){ 
                        buff += i;
                        }
                    }
                    buff = (buff.substr(0,buff.size()-6));
                    mass.push_back(fline);
                    imass.push_back(stoi(buff));
                }
            break;
            case 2:
                // Сохраняем 2 вектора с целыми строками и датами в формате YYMMDD
                while (File >> fline){
                    mass.push_back(fline);
                    imass.push_back(stoi(fline.substr(fline.size()-3,2)+fline.substr(fline.size()-6,2)+fline.substr(fline.size()-9,2)));
                }
            break;
            }
            // Процесс сортировки
            sort:
                for (int i=0;i<imass.size()-1;i++){
                    if(imass[i]<imass[i+1]){

                        num = imass[i+1];
                        imass[i+1] = imass[i];
                        imass[i] = num;
                        buff = mass[i+1];
                        mass[i+1] = mass[i];
                        mass[i] = buff;
                        goto sort;
                    }
                }

            // Заного загружаем в файл отсортированные строки
            std::ofstream File("tasks.txt");
            for (std::string i: mass){
                File << i << std::endl;
            }
            File.close();
        break;
        return 0;
    }
}