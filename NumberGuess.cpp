#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    std::srand(static_cast<unsigned int>(std::time(nullptr))); // Seed for random number
    int secretNumber = std::rand() % 100 + 1; // Random number between 1 and 100
    int guess;

    std::cout << "=== Number Guessing Game ===" << std::endl;
    std::cout << "Guess the number between 1 and 100:\n";

    while (true) {
        std::cout << "Enter your guess: ";
        std::cin >> guess;

        if (guess < 1 || guess > 100) {
            std::cout << "Please enter a number within range (1-100).\n";
            continue;
        }

        if (guess < secretNumber) {
            std::cout << "Too low! Try again.\n";
        } else if (guess > secretNumber) {
            std::cout << "Too high! Try again.\n";
        } else {
            std::cout << "Congratulations! You guessed the correct number: " << secretNumber << std::endl;
            break;
        }
    }

    return 0;
}
