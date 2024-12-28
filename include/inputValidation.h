#ifndef INPUTVALIDATION_H
#define INPUTVALIDATION_H

#include <iostream>
#include <functional>

/**
 * @brief Handles user input with validation.
 *
 * @tparam T The type of input to handle.
 * @param message The message to display to the user.
 * @param condition The condition to validate the input.
 * @param error_message The error message to display if the input is invalid.
 * @return T The validated user input.
 */
template <typename T>
T handleUserInput(const std::string &message, std::function<bool(T)> condition, const std::string &error_message) {
    T input;
    std::cout << message;
    while (!(std::cin >> input) || !condition(input)) {
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cout << error_message;
    }
    return input;
}

#endif //INPUTVALIDATION_H