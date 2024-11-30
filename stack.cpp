//
// Created by Bogdan on 11/30/2024.
//

#include "stack.h"
#include <iostream>

void stack::push(const int value) {
    stack *new_node = new stack(value, this->next);
    this->next = new_node;
}

void stack::pop() {
    if (this->next == nullptr) {
        std::cout << "Stack is empty!" << std::endl;
        return;
    }
    const stack *temp = this->next;
    this->next = this->next->next;
    delete temp;
}

void stack::print() const {
    const stack *temp = this->next;
    while (temp->next != nullptr) {
        std::cout << temp->value << " * ";
        temp = temp->next;
    }
    std::cout << temp->value;
    std::cout << std::endl;
}

void stack::print_in_exponential_form() const {
    const stack *temp = this->next;
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
