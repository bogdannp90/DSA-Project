#include "myStack.h"
#include <iostream>

// Function to add a new element to the stack
void myStack::push(const int value) {
    auto *new_node = new myStack(value, this->next);
    this->next = new_node;
}

// Function to remove the top element from the stack
void myStack::pop() {
    if (this->next == nullptr) {
        std::cout << "Stack is empty!" << std::endl;
        return;
    }
    const myStack *temp = this->next;
    this->next = this->next->next;
    delete temp;
}

// Function to print the prime factors stored in the stack
void myStack::print() const {
    const myStack *temp = this->next;
    while (temp->next != nullptr) {
        std::cout << temp->value << " * ";
        temp = temp->next;
    }
    std::cout << temp->value;
    std::cout << std::endl;
}

// Function to print the prime factors in exponential form
void myStack::printInExponentialForm() const {
    const myStack *temp = this->next;
    while (temp != nullptr) {
        int exponent = 1;
        while (temp->next != nullptr and (temp->next)->value == temp->value) {
            temp = temp->next;
            exponent++;
        }
        std::cout << temp->value << "^" << exponent;
        if (temp->next != nullptr)
            std::cout << " * ";
        temp = temp->next;
    }
    std::cout << std::endl;
}