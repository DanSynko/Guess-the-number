// OOP-version of project
#include <iostream>
#include <random>
#include <limits>
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

class Game {
private:
    int rand_num;
public:
    Game() {
        std::random_device seed;
        std::mt19937 engine(seed());
        std::uniform_int_distribution<int> dist(1, 50);
        rand_num = dist(engine);
    }
    int get_rand_num() {
        return rand_num;
    }
};
class Player {
private:
    int user_num;
public:
};

int main()
{
    Game computer;
    Player player;

    return 0;
}