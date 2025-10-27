#include <iostream>
#include <random>
#include <limits>
int random_num_generator(){
    std::random_device seed; 
    std::mt19937 engine(seed());
    std::uniform_int_distribution<int> dist(1, 50);
    int rand_num = dist(engine);
    return rand_num; 
}
void error_check(int& a) {
    std::cin >> a;
    if (std::cin.fail()) {
        do {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Ошибка: введён символ вместо числа. Попробуйте еще раз." << std::endl;
            std::cin >> a;
        } while (std::cin.fail());
    }
}


int main()
{
    setlocale(LC_ALL, "RU");

    int attempts = 0;
    
    while (true) {
        int CPU_num = random_num_generator();
        attempts = 0;
        int user_num;
        std::cout << "Компьютером было загадано число от 1 до 50. ";
        // для отладки
        std::cout << CPU_num << std::endl;
        std::cout << "Введите любое число в заданом диапазоне и узнайте, отгадали ли вы.\n" << std::endl;
        error_check(user_num);
        if (user_num != CPU_num) {
            do {
                if (CPU_num < user_num) {
                    std::cout << "Подсказка: загаданное число меньше " << user_num << std::endl;
                }
                else if (CPU_num > user_num) {
                    std::cout << "Подсказка: загаданное число больше " << user_num << std::endl;
                }
                attempts++;
                error_check(user_num);
            } while (user_num != CPU_num);
        }
        std::cout << "Вы угадали! Компьютером было задано такое число: " << CPU_num << "\n";
        std::cout << "Счётчик попыток за игру: " << attempts << "\n" << std::endl;
        std::cout << "Желаете сыграть еще раз?(1 - да, 0 - нет)" << "\n" << std::endl;
        int choice;
        error_check(choice);
        if (choice != 1 && choice != 0) {
            do {
                std::cout << "Такой команды нет. Попробуйте еще раз." << std::endl;
                error_check(choice);
            } while (choice != 1 && choice != 0);
        }
        if (choice == 1) {
            continue;
        }
        else if (choice == 0) {
            break;
        }
    }
    return 0;
}
