#include <iostream>;

int main(){
	setlocale(LC_ALL, "rus");
	int a;
	std::cout << "������� ������?" << std::endl;
	std::cin >> a;
	std::cout << std::endl;
	while(a>=0){
		std::cout << "������� ������?" << std::endl;
		std::cin >> a;
		std::cout << std::endl;
	}
	return 0;
}