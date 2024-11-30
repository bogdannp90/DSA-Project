#include <iostream>

#include "my_stack.h"

using namespace std;

bool is_prime(const int n) {
    if (n < 2) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (int d = 3; d * d <= n; d += 2)
        if (n % d == 0) return false;
    return true;
}

my_stack prime_factorization(int n) // Outputs a stack with the prime factors of n
{
    my_stack *head = new my_stack();
    for (int d = 2; d <= n; d++)
        if (is_prime(d)) {
            while (n % d == 0) {
                head->push(d);
                n /= d;
            }
        }
    return *head;
}

int main() {
    int op;
    do {
        cout << "\nDATA STRUCTURES AND ALGORITHMS PROJECT\n\n";
        cout << "1. Prime factorization of a number" << endl;
        cout << "2." << endl;
        cout << "0. Exit" << endl;
        cout << "Choose an option: ";
        cin >> op;
        switch (op) {
            case 1: {
                int op1;
                int n;
                cout << "\nPrime factorization of a number" << endl;
                do {
                    cout << "\nEnter a number: ";
                    cin >> n;
                    my_stack factors = prime_factorization(n);
                    cout << "The prime factorization of " << n << " is: ";
                    factors.print();
                    cout << "The prime factorization of " << n << " in exponential form is: ";
                    factors.print_in_exponential_form();

                    cout << "\n1. Calculate another factorization" << endl;
                    cout << "0. Back" << endl;
                    cout << "Choose an option: ";
                    cin >> op1;
                } while (op1 == 1);
            }
            break;

            case 2: {
                // Problem 2
            }
            break;

            case 0:
                cout << "Exiting program..." << endl;
                break;

            default:
                cout << "Invalid option!" << endl;
                break;
        }
    } while (op != 0);
    return 0;
}
