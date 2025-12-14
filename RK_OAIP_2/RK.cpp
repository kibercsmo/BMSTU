#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <memory>
#include <cctype>
#include <algorithm>
#include <iomanip>

class FoodItem{
protected:
    std::string name;
    std::string date;
    float weight;
    std::vector<std::string> suppliers;
public:
    FoodItem(std::string name, std::string date, float weight, std::string suply){
        this->name = name;
        this->date = date;
        this->weight = weight;
        std::stringstream ss(suply);
        std::string segment;
        while (std::getline (ss, segment, '|')){
            this->suppliers.push_back(segment);
        };
    };

    virtual void display(){
        std::cout << "Название: "      << name   << " ";
        std::cout << "Срок годности: " << date   << " ";
        std::cout << "Вес: "           << weight << " ";
        std::cout << "Поставщики: ";
        for (const auto& suply : suppliers){
            std::cout << suply << " ";
        }
        std::cout << std::endl;
    }

    void setname(std::string name){this->name = name;}
    void setdate(std::string date){this->date = date;}
    void setweight(int weight){this->weight = weight;}
    void setsuppliers(std::vector<std::string> suppliers){this->suppliers = suppliers;}
    virtual void settype(std::string type){}
    virtual void setcallorie(int calorie){}
    virtual void setfat(int fat){}
    virtual void setprotein(int protein){}
    
    std::string getname(){return name;}
    std::string getdate(){return date;}
    float getweight(){return weight;}
    std::vector<std::string> getsuppliers(){return suppliers;}
    virtual std::string gettype(){return  "None";};
    virtual float getcallorie(){return 0;};
    virtual std::string getposition(){return "None";};
    virtual float getfat(){return 0;};
    virtual float getprotein(){return 0;};

    ~FoodItem(){
        std::cout << "Удаление прошло успешно!" << std::endl;
    }
};

class Vegetable : public FoodItem{
protected:
    std::string type = "";
    std::string cal_buff = "";
    float calorie = 0;
public:
    Vegetable(std::string name, std::string date, float weight, std::string info, std::string suply): FoodItem(name,date,weight,suply){
        for (char i : info){
            if (std::isalpha(i)){
                this->type += i;
            }
            else if(i != '-'){
                this->cal_buff += i;
            }
        };
        calorie = stof(cal_buff);
    }
    void display() override{
        std::cout << "Название: "      << name    << " ";
        std::cout << "Срок годности: " << date    << " ";
        std::cout << "Вес: "           << weight  << " ";
        std::cout << "Тип: "           << type    << " ";
        std::cout << "Каллораж: "      << calorie << " ";
        std::cout << "Поставщики: ";
        for (const auto& suply : suppliers){
            std::cout << suply << " ";
        }
        std::cout << std::endl;
    }
    std::string gettype() override{return type;};
    float getcallorie() override{return calorie;};
    std::string getposition() override{return "Vegetable";};

    void settype(std::string type) override {this->type = type;}
    void setcallorie(int calorie) override {this->calorie = calorie;}
};

class DairyProduct : public FoodItem{
protected:    
    float fat;
    std::string fat_buff = "";
    float protein;
    std::string protein_buff = "";
public:
    DairyProduct(std::string name, std::string date, float weight, std::string info, std::string suply): FoodItem(name,date,weight,suply){
    for (char i : info){
        if(i != '-'){
            fat_buff += i;
        }
        else{
            info.erase(0, fat_buff.length()+1);
        }
    };
    fat = stof(fat_buff);
    for (char i : info){
        if(!std::isalpha(i)){
            protein_buff += i;
        }
    };
    protein = stof(protein_buff);
    }
    void display() override{
        std::cout << "Название: "      << name    << " ";
        std::cout << "Срок годности: " << date    << " ";
        std::cout << "Вес: "           << weight  << " ";
        std::cout << "Жир: "           << fat     << " ";
        std::cout << "Белок: "         << protein << " ";
        std::cout << "Поставщики: ";
        for (const auto& suply : suppliers){
            std::cout << suply << " ";
        }
        std::cout << std::endl;
    }
    float getfat() override {return fat;};
    float getprotein() override {return protein;};
    std::string getposition() override {return "Dairy";};

    void setfat(int fat) override{this->fat = fat;}
    void setprotein(int protein) override{this->protein = protein;}
};

int main(){
    float sum = 0;
    short choose;
    std::fstream file;
    std::vector<std::unique_ptr<FoodItem>> items;
    
    std::string buff1;
    std::string buff2;
    std::vector<std::string> buffl;

    start:
    std::cout << "Выберите действие"                       << std::endl;
    std::cout << "1. Загрузка данных из файла"             << std::endl;
    std::cout << "2. Вывод всех объектов"                  << std::endl;
    std::cout << "3. Поиск"                                << std::endl;
    std::cout << "4. Сортировка"                           << std::endl;
    std::cout << "5. Добавить новый объект"                << std::endl;
    std::cout << "6. Редактировать объект"                 << std::endl;
    std::cout << "7. Удаление объекта"                     << std::endl;
    std::cout << "8. Сохранение текущего состояния в файл" << std::endl;
    std::cout << "9. Посчитать суммарную массу"            << std::endl;
    std::cout << "10. Удаление просрочки"                  << std::endl;
    std::cout << "0. Выход"                                << std::endl;
    std::cin >> choose;

    switch (choose)
    {
    default:
        return 0;
        break;
    case 1:
        file.open("warehouse.txt");
        while (std::getline(file, buff1)){
            std::stringstream ss(buff1);
             while (std::getline (ss, buff2, ';')){
                buffl.push_back(buff2);
            };
            if(buff1.substr(0,5) == "Dairy"){
                items.emplace_back(std::make_unique<DairyProduct>(buffl[1],buffl[2],stof(buffl[3]),buffl[4],buffl[5]));
            }
            else{
                items.emplace_back(std::make_unique<Vegetable>(buffl[1],buffl[2],stof(buffl[3]),buffl[4],buffl[5]));
            };
            buff1 = "";
            buff2 = ""; 
            buffl = {};
        };
        file.close();
        goto start;
        break;
    case 2:
        for (auto& i : items){
            i -> display();
        };
        goto start;
        break; 
    case 3:

        std::cout << "Поиск по: "        << std::endl;
        std::cout << "1. Позиции"        << std::endl;
        std::cout << "2. Имени"          << std::endl;
        std::cout << "3. Сроку годности" << std::endl;
        std::cout << "4. Весу"           << std::endl;
        std::cout << "5. Поставщикам"   << std::endl;
        std::cout << "6. Жирности"       << std::endl;
        std::cout << "7. Белкам"         << std::endl;
        std::cout << "8. Типу"           << std::endl;
        std::cout << "9. Каллорийности"  << std::endl;
        std::cout << "0. Выход"          << std::endl;
        std::cin >> choose;
        switch (choose){
            default:
                goto start;
                break;
            case 1:                std::cout << "Введите позицию" << std::endl;
                std::cin >> buff1;
                for (auto& i : items){
                    if (i -> getposition() == buff1){
                        i -> display();
                    }
                };
                goto start;
                break;
            case 2:
                std::cout << "Введите имя" << std::endl;
                std::cin >> buff1;
                for (auto& i : items){
                    if (i -> getname() == buff1){
                        i -> display();
                    }
                };
                goto start;
                break;
            case 3:
                std::cout << "Введите срок годности (YYYY-MM-DD)" << std::endl;
                std::cin >> buff1;
                for (auto& i : items){
                    if (i -> getdate() == buff1){
                        i -> display();
                    }
                };
                goto start;
                break;
            case 4:
                std::cout << "Введите вес" << std::endl;
                std::cin >> buff1;
                for (auto& i : items){
                    if (i -> getweight() == stof(buff1)){
                        i -> display();
                    }
                };
                goto start;
                break;
            case 5:
                std::cout << "Введите поставщика" << std::endl;
                std::cin >> buff1;
                for (auto& i : items){
                    for (std::string j : i -> getsuppliers()){
                        if(j == buff1){
                            i -> display();
                        }
                    }
                };
                goto start;
                break;
            case 6:
                std::cout << "Введите процент жира" << std::endl;
                std::cin >> buff1;
                for (auto& i : items){
                    if (i -> getposition() == "Dairy" && i -> getfat() == stof(buff1)){
                        i -> display();
                    }
                };
                goto start;
                break;
            case 7:
                std::cout << "Введите колличество белка" << std::endl;
                std::cin >> buff1;
                for (auto& i : items){
                    if (i -> getposition() == "Dairy" && i -> getprotein() == stof(buff1)){
                        i -> display();
                    }
                };
                goto start;
                break;
            case 8:
                std::cout << "Введите тип" << std::endl;
                std::cin >> buff1;
                for (auto& i : items){
                    if (i -> getposition() == "Vegetable" && i -> gettype() == buff1){
                        i -> display();
                    }
                };
                goto start;
                break;
            case 9:
                std::cout << "Введите каллорийность" << std::endl;
                std::cin >> buff1;
                for (auto& i : items){
                    if (i -> getposition() == "Vegetable" && i -> getcallorie() == stof(buff1)){
                        i -> display();
                    }
                };
                goto start;
                break;
        };
    case 4:
        std::cout << "Сортировать по: " << std::endl;
        std::cout << "1. Возрастанию "  << std::endl;
        std::cout << "2. Убыванию "     << std::endl;
        std::cout << "0. Выход"         << std::endl;
        std::cin >> choose;
        switch(choose){
            default:
                goto start;
                break;
            case 1:
                std::cout << "Сортировать: "        << std::endl;
                std::cout << "1. Срок годности"     << std::endl;
                std::cout << "2. Вес"               << std::endl;
                std::cout << "3. Жирность"          << std::endl;
                std::cout << "4. Белки"             << std::endl;
                std::cout << "5. Каллорийность"     << std::endl;
                std::cout << "0. Выход"             << std::endl;
                std::cin >> choose;
                switch (choose){
                    default:
                        goto start;
                        break;
                    case 1:
                        std::sort(items.begin(), items.end(), [](const std::unique_ptr<FoodItem>& a, const std::unique_ptr<FoodItem>& b) {return a->getdate() < b->getdate();});
                        goto start;
                        break;
                    case 2:
                        std::sort(items.begin(), items.end(), [](const std::unique_ptr<FoodItem>& a, const std::unique_ptr<FoodItem>& b) {return a->getweight() < b->getweight();});
                        goto start;
                        break;
                    case 3:
                        std::sort(items.begin(), items.end(), [](const std::unique_ptr<FoodItem>& a, const std::unique_ptr<FoodItem>& b) {return a->getfat() < b->getfat();});
                        goto start;
                        break;
                    case 4:
                        std::sort(items.begin(), items.end(), [](const std::unique_ptr<FoodItem>& a, const std::unique_ptr<FoodItem>& b) {return a->getprotein() < b->getprotein();});
                        goto start;
                        break;
                    case 5:
                        std::sort(items.begin(), items.end(), [](const std::unique_ptr<FoodItem>& a, const std::unique_ptr<FoodItem>& b) {return a->getcallorie() < b->getcallorie();});
                        goto start;
                        break;
                };
            case 2:
                std::cout << "Сортировать: "        << std::endl;
                std::cout << "1. Срок годности"     << std::endl;
                std::cout << "2. Вес"               << std::endl;
                std::cout << "3. Жирность"          << std::endl;
                std::cout << "4. Белки"             << std::endl;
                std::cout << "5. Каллорийность"     << std::endl;
                std::cout << "0. Выход"             << std::endl;
                std::cin >> choose;
                switch (choose){
                    default:
                        goto start;
                        break;
                    case 1:
                        std::sort(items.begin(), items.end(), [](const std::unique_ptr<FoodItem>& a, const std::unique_ptr<FoodItem>& b) {return a->getdate() > b->getdate();});
                        goto start;
                        break;
                    case 2:
                        std::sort(items.begin(), items.end(), [](const std::unique_ptr<FoodItem>& a, const std::unique_ptr<FoodItem>& b) {return a->getweight() > b->getweight();});
                        goto start;
                        break;
                    case 3:
                        std::sort(items.begin(), items.end(), [](const std::unique_ptr<FoodItem>& a, const std::unique_ptr<FoodItem>& b) {return a->getfat() > b->getfat();});
                        goto start;
                        break;
                    case 4:
                        std::sort(items.begin(), items.end(), [](const std::unique_ptr<FoodItem>& a, const std::unique_ptr<FoodItem>& b) {return a->getprotein() > b->getprotein();});
                        goto start;
                        break;
                    case 5:
                        std::sort(items.begin(), items.end(), [](const std::unique_ptr<FoodItem>& a, const std::unique_ptr<FoodItem>& b) {return a->getcallorie() > b->getcallorie();});
                        goto start;
                        break;
                };
        };
    case 5: {
        std::cout << "Введите значения в формате: " << std::endl;
        std::cout << "Position;Name;ExpDate;Weight;Parameter;Suply1|Syply2...|SuplyN" << std::endl;
        std::cin >> buff1;
        std::stringstream ss(buff1);
        while (std::getline (ss, buff2, ';')){
            buffl.push_back(buff2);
        }
        if(buff1.substr(0,5) == "Dairy"){
                items.emplace_back(std::make_unique<DairyProduct>(buffl[1],buffl[2],stof(buffl[3]),buffl[4],buffl[5]));
        }
        else{
                items.emplace_back(std::make_unique<Vegetable>(buffl[1],buffl[2],stof(buffl[3]),buffl[4],buffl[5]));
        }
        goto start;
        break;
    }
    case 6:
        for (auto& i : items){
            std::cout << "Выбранный элемент: " << std::endl;
            i -> display();
            std::cout << "Поменять: "           << std::endl;
            std::cout << "1. Имя "              << std::endl;
            std::cout << "2. Срок годности "    << std::endl;
            std::cout << "3. Вес"               << std::endl;
            std::cout << "4. Жирность"          << std::endl;
            std::cout << "5. Колличество белка" << std::endl;
            std::cout << "6. Тип"               << std::endl;
            std::cout << "7. Каллорийность"     << std::endl;
            std::cout << "8. Поставщиков"       << std::endl;
            std::cout << "---------------------"<< std::endl;
            std::cout << "9. Следующий элемент "<< std::endl;
            std::cout << "0. Выход"             << std::endl;
            std::cin >> choose;
            switch (choose)
            {
            default:
                goto start;
                break;
            case 1:
                std::cout << "Заменить имя на: " << std::endl;
                std::cin >> buff1;
                i -> setname(buff1);
                goto start;
                break;
            case 2:
                std::cout << "Заменить срок годности на: " << std::endl;
                std::cin >> buff1;
                i -> setdate(buff1);
                goto start;
                break;
            case 3:
                std::cout << "Заменить вес на: " << std::endl;
                std::cin >> buff1;
                i -> setweight(stof(buff1));
                goto start;
                break;
            case 4:
                if (i -> getposition() == "Dairy"){
                    std::cout << "Заменить жирность на: " << std::endl;
                    std::cin >> buff1;
                    i -> setfat(stof(buff1));
                }
                else{
                    std::cout << "Выбранный товар не имеет данного параметра" << std::endl;
                }
                goto start;
                break;
            case 5:
                if (i -> getposition() == "Dairy"){
                    std::cout << "Заменить колличество белка на: " << std::endl;
                    std::cin >> buff1;
                    i -> setprotein(stof(buff1));
                }
                else{
                    std::cout << "Выбранный товар не имеет данного параметра" << std::endl;
                }
                goto start;
                break;
            case 6:
                if (i -> getposition() == "Vegetable"){
                    std::cout << "Заменить тип на: " << std::endl;
                    std::cin >> buff1;
                    i -> settype(buff1);
                }
                else{
                    std::cout << "Выбранный товар не имеет данного параметра" << std::endl;
                }
                goto start;
                break;
            case 7:
                if (i -> getposition() == "Vegetable"){
                    std::cout << "Заменить каллорийность на: " << std::endl;
                    std::cin >> buff1;
                    i -> setcallorie(stof(buff1));
                }
                else{
                    std::cout << "Выбранный товар не имеет данного параметра" << std::endl;
                }
                goto start;
                break;
            case 8:
                buffl = i -> getsuppliers();
                std::cout << "Поставщики: ";
                for (std::string j : buffl){
                    std::cout << j << " "; 
                }
                std::cout << std::endl;
                std::cout << "Выберите: "               << std::endl;
                std::cout << "1. Добавить поставщика: " << std::endl;
                std::cout << "2. Удалить поставщика: "  << std::endl;
                std::cout << "0. Выход"                 << std::endl;
                std::cin >> choose;
                switch (choose)
                {
                default:
                    goto start;
                    break;
                case 1:
                    std::cout << "Название поставщика: " << std::endl;
                    std::cin >> buff1;
                    buffl.push_back(buff1);
                    i -> setsuppliers(buffl);
                    goto start;
                    break;
                case 2:
                    std::cout << "Название поставщика: " << std::endl;
                    std::cin >> buff1;
                    for (int j = 0; j < buffl.size(); j++){
                        if (buffl[j] == buff1){
                            buffl.erase(buffl.begin() + j);
                        }
                    };
                    i -> setsuppliers(buffl);
                    goto start;
                    break;
                }
            case 9:
                break;
            }
        }
        goto start;
        break;
    case 7:
        for(auto& i: items){
            std::cout << "Выбранный элемент: " << std::endl;
            i -> display();
            std::cout << "Выберите действие: " << std::endl;
            std::cout << "1. Удалить "         << std::endl;
            std::cout << "2. Следующий элемент"<< std::endl;
            std::cout << "--------------------"<< std::endl;
            std::cout << "0. Выйти"            << std::endl;
            std::cin >> choose;
            switch (choose)
            {
            default:
                goto start;
                break;
            case 1:
                for(int j = 0;j < items.size();j++){
                    if (items[j] == i){
                        items.erase(items.begin() + j);
                        goto start;
                        break;
                    }
                }
                goto start;
                break;
            case 2:
                break;
            }
        }
        goto start;
        break;
    case 8:{
        std::ofstream outfile("warehouse.txt");
        outfile.close();
        file.open("warehouse.txt");
        for(auto& i : items){
            file << i -> getposition() << ";";
            file << i -> getname() << ";";
            file << i -> getdate() << ";";
            file << i -> getweight() << ";";
            if (i -> getposition() == "Dairy"){
                buff1 = std::to_string(i -> getfat()) + "-Protein" + std::to_string(i -> getprotein());
            }
            else{
                buff1 = i -> gettype() + "-" + std::to_string(i -> getcallorie());
            }
            file << buff1 << ";";
            buff1 = "";
            for(std::string j: i -> getsuppliers()){
                buff1 += j;
                buff1 += "|";
            }   
            buff1.pop_back();
            file << buff1 << std::endl;
        }
        file.close();
        goto start;
        break;
    }
    case 9:
        std::cout << "Суммарная масса: " << std::endl;
        std::cout << "------------------" << std::endl;
        for (auto& i : items){
            if (i -> getposition() == "Dairy"){
                sum += i -> getweight();
            }
        }
        std::cout << "Молочной продукции: " << sum << std::endl;
        sum = 0;
        for (auto& i : items){
            if (i -> getposition() == "Vegetable"){
                sum += i -> getweight();
            }
        }
        std::cout << "Овощной продукции: " << sum << std::endl;
        sum = 0;
        goto start;
        break;
    case 10:
        std::cout << "Введите сегодняшнюю дату (YYYY-MM-DD): ";
        std::cin >> buff1;
        for (int i = 0; i < items.size();i++){
            if(items[i] -> getdate() < buff1){
                items.erase(items.begin() + i);
            }
        }
        goto start;
        break;
    }    
}