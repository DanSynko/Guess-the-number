//#define NOMINMAX
#include <iostream>
#include <random>
#include <limits>

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
    std::cout << CPU_num << std::endl;
    std::cout << "Введите любое число в заданом диапазоне и узнайте, отгадали ли вы.\n" << std::endl;
    int attempts = 1;
    bool in_program = true;
    while (in_program) {
        std::cin >> user_num;
        if (std::cin.fail()) {
            do {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Ошибка: введен символ вместо числа. Попробуйте еще раз" << std::endl;
                std::cin >> user_num;
            } while (std::cin.fail());
        }
        else {
            continue;
        }
        if (user_num != CPU_num) {
            if (CPU_num < 25) {
                std::cout << "Подсказка: загаданное число меньше 25" << std::endl;
                attempts++;
            }
            else {
                std::cout << "Подсказка: загаданное число больше 25" << std::endl;
                attempts++;
            }
        }
        else {
            std::cout << "Вы угадали! Компьютером было задано такое число: " << CPU_num << "\n";
            std::cout << "Количество потраченных попыток: " << attempts << "\n" << std::endl;
            std::cout << "Желаете сыграть еще раз?(1 - да, 0 - нет)" << "\n" << std::endl;
            int choice;
            std::cin >> choice;
            do {
                if (choice == 0) {
                    in_program = false;
                }
                else if (choice == 1) {
                    break;
                }
                else {
                    do {
                        std::cin.clear();
                        std::cout << "Такой команды нет. Попробуйте еще раз." << std::endl;
                        std::cin >> choice;
                    } while (std::cin.fail());
                }
            } while (choice != 1 && choice != 0);
        }
        if (in_program) {
            continue;
        }
        else {
            break;
        }
    }
    return 0;
}