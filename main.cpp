#include <iostream>
#include "include/handleProblem1.h"
#include "include/inputValidation.h"

// Function to display the main menu
void displayMainMenu();

enum MenuOption {
    EXIT = 0,
    PRIME_FACTORIZATION
};

int main() {
    int option;

    std::cout << "Data Structures and Algorithms Project" << std::endl;
    std::cout << "Pirvu Constantin Bogdan, 1331b" << std::endl;

    do {
        displayMainMenu();
        option = handleUserInput<int>("Choose an option: ",
            [](const int x) { return x >= 0 && x <= 2; },
            "Invalid option! Please enter a number between 0 and 2!\nChoose an option: ");

        switch (option) {
            case PRIME_FACTORIZATION: {
                handleProblem1();
            }
            break;

            case 2: {
                std::cout << "Still working on it!" << std::endl;
            }
            break;

            case EXIT:
                std::cout << "Exiting program." << std::endl;
                break;

            default:
                std::cout << "Invalid option!" << std::endl;
                break;
        }
    } while (option != EXIT);
    return 0;
}

/**
 * @brief Displays the main menu options to the user.
 */
void displayMainMenu() {
    std::cout << std::endl << "Main Menu" << std::endl;
    std::cout << "1. Prime factorization" << std::endl;
    std::cout << "2. Problem 2" << std::endl;
    std::cout << "0. Exit" << std::endl;
}