#ifndef HANDLEPROBLEM1_H
#define HANDLEPROBLEM1_H

#include "myStack.h"

/**
 * @brief Checks if a number is prime.
 *
 * @param n The number to check.
 * @return true if the number is prime, false otherwise.
 */
bool isPrime(int n);

/**
 * @brief Performs prime factorization on a given number.
 *
 * @param n The number to factorize.
 * @return myStack A stack containing the prime factors of the number.
 */
myStack primeFactorization(int n);

/**
 * @brief Handles the prime factorization problem.
 */
void handleProblem1();

#endif //HANDLEPROBLEM1_H