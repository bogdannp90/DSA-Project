//
// Created by Bogdan on 11/30/2024.
//

#ifndef STACK_H
#define STACK_H


class my_stack {
    int value;
    my_stack *next;

public:
    my_stack() = default;

    my_stack(const int value, my_stack *next) : value(value), next(next) {
    }

    ~my_stack() = default;

    void push(int value); // Adds a new element to the stack
    void pop(); // Removes the top element
    void print() const; // Prints the prime factors
    void print_in_exponential_form() const; // Prints the prime factors in exponential form
};


#endif //STACK_H
