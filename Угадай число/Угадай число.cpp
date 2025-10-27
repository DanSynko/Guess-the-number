#include <iostream>
#include <random>

int main()
{
    setlocale(LC_ALL, "RU");

    std::random_device seed; 
    std::mt19937 engine(seed());
    std::uniform_int_distribution<int> dist(1, 50);
    int CPU_num = dist(engine);
    int user_num;
    std::cout << "Компьютером было загадано число от 1 до 50. ";
    // для отладки
    //std::cout << CPU_num << std::endl;
    std::cout << "Введите любое число в заданом диапазоне и узнайте, отгадали ли вы.\n" << std::endl;
    while (true){
        std::cin >> user_num;
        if (user_num != CPU_num) {
            if (CPU_num < 25) {
                std::cout << "Подсказка: загаданное число меньше 25" << std::endl;
            }
            else {
                std::cout << "Подсказка: загаданное число больше 25" << std::endl;
            }
        }
        else {
            std::cout << "Вы угадали! Компьютером было задано такое число: " << CPU_num << "\n";
            break;
        }
    }
    return 0;
}