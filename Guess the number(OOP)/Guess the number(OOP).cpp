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
            std::cout << "Error: A character was entered instead of a number. Try again." << std::endl;
            std::cin >> a;
        } while (std::cin.fail());
    }
}

class Game {
private:
    int rand_num;
    int player_num;
    int attempts = 0;
    void rand_num_generator() {
        std::random_device seed;
        std::mt19937 engine(seed());
        std::uniform_int_distribution<int> dist(1, 50);
        rand_num = dist(engine);
    }
    void numbers_compare() {
        if (player_num != rand_num) {
            do {
                if (rand_num < player_num) {
                    std::cout << "Hint: the guessed number is less than " << player_num << std::endl;
                }
                else if (rand_num > player_num) {
                    std::cout << "Hint: the guessed number is more than " << player_num << std::endl;
                }
                attempts++;
                error_check(player_num);
            } while (player_num != rand_num);
        }
    }
public:
    void run() {
        while (true) {
            rand_num_generator();
            std::cout << "The computer has guessed a number between 0 and 50." << std::endl;
            // for debuging
            std::cout << rand_num << std::endl;
            std::cout << "Enter a number within the specified range to see if you guessed correctly.\n" << std::endl;
            error_check(player_num);
            numbers_compare();
            std::cout << "You guessed it! The number set by the computer was: " << rand_num << "\n";
            std::cout << "Attempts count for this game: " << attempts << "\n" << std::endl;
            std::cout << "Do you want to play again?(1 - yes, 0 - no)" << "\n" << std::endl;
            int player_choice;
            error_check(player_choice);
            if (player_choice != 1 && player_choice != 0) {
                do {
                    std::cout << "There is no such command. Try again." << std::endl;
                    error_check(player_choice);
                } while (player_choice != 1 && player_choice != 0);
            }
            if (player_choice == 1) {
                continue;
            }
            else if (player_choice == 0) {
                break;
            }
        }
    }
};

int main()
{
    Game game;
    game.run();

    return 0;
}