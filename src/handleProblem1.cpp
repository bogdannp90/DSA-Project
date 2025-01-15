#include <iostream>
#include "myStack.h"
#include "inputValidation.h"

// Function to check if a number is prime
bool isPrime(const int n) {
    if (n < 2) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (int d = 3; d * d <= n; d += 2)
        if (n % d == 0) return false;
    return true;
}

// Function to perform prime factorization on a given number
myStack primeFactorization(int n) {
    auto *head = new myStack();
    if (n < 2) {
        head->push(n);
        return *head;
    }
    for (int d = 2; d <= n; d++) {
        if (isPrime(d)) {
            while (n % d == 0) {
                head->push(d);
                n /= d;
            }
        }
    }
    return *head;
}

// Function to handle the prime factorization problem
void handleProblem1() {
    int option;
    std::cout << "\nPrime factorization of a number" << std::endl;
    do {
        // Get a positive number from the user
        const int number = handleUserInput<int>("Enter a number: ",
                                    [](int x) { return x > 0; },
                                    "Invalid input! Please enter a positive number: ");
        // Perform prime factorization
        myStack factors = primeFactorization(number);
        // Print the prime factors
        std::cout << "The prime factorization of " << number << " is: ";
        factors.print();
        // Print the prime factors in exponential form
        std::cout << "The prime factorization of " << number << " in exponential form is: ";
        factors.printInExponentialForm();

        // Ask the user if they want to calculate another factorization
        std::cout << "\n1. Calculate another factorization" << std::endl;
        std::cout << "0. Back to main menu" << std::endl;
        option = handleUserInput<int>("Choose an option: ",
            [](int x) { return x >= 0 && x <= 1; },
            "Invalid option! Please enter 0 or 1: ");
    } while (option == 1);
}