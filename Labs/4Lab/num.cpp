#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <memory>

template <typename T1, typename T2>
class Pair {
public:
    T1 first;
    T2 second;
    Pair(T1 f, T2 s) : first(f), second(s) {}
};

class Book {
protected:

    std::string title;
    std::string author;
    std::string genre;
    int availableCopies;

public:
    Book(std::string t, std::string a, std::string g, int count = 1)
        : title(t), author(a), genre(g), availableCopies(count) {}

    virtual void displayInfo() const {
        std::cout << "Книга: " + title + " | Автор: " + author + " | Жанр: " + genre + " | В наличии: " << availableCopies << std::endl;
    }

    std::string getAuthor() const { return author; }
    std::string getTitle()  const { return title;  }
    std::string getGenre()  const { return genre;  }
    
    void setGenre(std::string newGenre) { genre = newGenre; }
};

class Fiction : public Book {
public:

    Fiction(std::string t, std::string a, int count = 1) : Book(t, a, "Фикция", count) {}

    void displayInfo() const override {
        std::cout << "[Фикция]";
        Book::displayInfo();
    }

};

class NonFiction : public Book {
public:

    NonFiction(std::string t, std::string a, int count = 1) : Book(t, a, "Не фикция", count) {}

    void displayInfo() const override {
        std::cout << "[Не фикция] ";
        Book::displayInfo();
    }

};

class Library {
private:

    std::vector<std::unique_ptr<Book>> books;

    void logToFile(const std::string& message) {
        std::ofstream out("output.txt", std::ios::app);
        if (out.is_open()) {
            out << message << std::endl;
        }
    }

public:

    void addBook() {

        std::string t, a;
        int type, count;

        std::cout << "1. Фикция "    << std::endl;
        std::cout << "2. Не фикция" << std::endl;

        std::cin >> type;
        std::cin.ignore();

        std::cout << "Название: "  ; std::getline(std::cin, t);
        std::cout << "Автор: "     ; std::getline(std::cin, a);
        std::cout << "Количество: "; std::cin >> count;

        if (type == 1) books.push_back(std::make_unique<Fiction>(t, a, count));
        else books.push_back(std::make_unique<NonFiction>(t, a, count));

        logToFile("Добавлена книга: " + t + " в колличестве " + std::to_string(count) + "Шт");
    }

    void searchBook() {

        std::string t;

        std::cout << "Введите название для поиска: ";
        std::cin.ignore();
        std::getline(std::cin, t);

        bool found = false;
        for (const auto& b : books) {
            if (b->getTitle() == t) {

                b->displayInfo();
                found = true;
            }
        }

        if (!found) std::cout << "Книга не найдена" << std::endl;

        logToFile("Поиск книги: " + t + (found ? " (Найдено)" : " (Не найдено)"));
    }

    void sortBooksByAuthor() {
        std::sort(books.begin(), books.end(), [](const std::unique_ptr<Book>& a, const std::unique_ptr<Book>& b) {
            return a->getAuthor() < b->getAuthor();
        });
        std::cout << "Каталог отсортирован по автору" << std::endl;
        logToFile("Выполнена сортировка по автору.");
    }

    void modifyBookGenre() {

        std::string t, newG;

        std::cout << "Введите название книги: ";
        std::cin.ignore();
        std::getline(std::cin, t);

        for (auto& b : books) {
            if (b->getTitle() == t) {

                std::cout << "Новый жанр: ";
                std::getline(std::cin, newG);
                b->setGenre(newG);

                std::cout << "Данные обновлены." << std::endl
                logToFile("Изменен жанр книги " + t + " на " + newG);
                return;
            }
        }
        std::cout << "Книга не найдена" << std::endl;
    }

    void displayAll() {
        for (const auto& b : books) b->displayInfo();
    }
};

int main() {
    Library myLib;
    short choice;

    while (true) {

        std::cout << "1. Добавить книгу" << std::endl;
        std::cout << "2. Поиск книги"    << std::endl;
        std::cout << "3. Сортировать"    << std::endl;
        std::cout << "4. Изменить жанр"  << std::endl;
        std::cout << "5. Показать все"   << std::endl;
        std::cout << "0. Выход"          << std::endl;
        
        std::cin >> choice;

        if (choice == 0) break;

        switch (choice) {
            case 1: myLib.addBook(); break;
            case 2: myLib.searchBook(); break;
            case 3: myLib.sortBooksByAuthor(); break;
            case 4: myLib.modifyBookGenre(); break;
            case 5: myLib.displayAll(); break;
            default: break;
        }
    }

    return 0;
}