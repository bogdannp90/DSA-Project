//
// Created by Bogdan on 11/30/2024.
//

#include "my_stack.h"
#include <iostream>

void my_stack::push(const int value) {
    my_stack *new_node = new my_stack(value, this->next);
    this->next = new_node;
}

void my_stack::pop() {
    if (this->next == nullptr) {
        std::cout << "Stack is empty!" << std::endl;
        return;
    }
    const my_stack *temp = this->next;
    this->next = this->next->next;
    delete temp;
}

void my_stack::print() const {
    const my_stack *temp = this->next;
    while (temp->next != nullptr) {
        std::cout << temp->value << " * ";
        temp = temp->next;
    }
    std::cout << temp->value;
    std::cout << std::endl;
}

void my_stack::print_in_exponential_form() const {
    const my_stack *temp = this->next;
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
