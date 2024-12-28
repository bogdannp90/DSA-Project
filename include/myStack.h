#ifndef STACK_H
#define STACK_H

/**
 * @class myStack
 * @brief A simple stack class to store integer values.
 */
class myStack {
    int value; ///< The value stored in the stack node.
    myStack *next; ///< Pointer to the next node in the stack.

public:
    /**
     * @brief Default constructor for myStack.
     */
    myStack() = default;

    /**
     * @brief Parameterized constructor for myStack.
     * @param value The value to be stored in the stack node.
     * @param next Pointer to the next node in the stack.
     */
    myStack(const int value, myStack *next) : value(value), next(next) {
    }

    /**
     * @brief Default destructor for myStack.
     */
    ~myStack() = default;

    /**
     * @brief Adds a new element to the stack.
     * @param value The value to be added to the stack.
     */
    void push(int value);

    /**
     * @brief Removes the top element from the stack.
     */
    void pop();

    /**
     * @brief Prints the prime factors stored in the stack.
     */
    void print() const;

    /**
     * @brief Prints the prime factors in exponential form.
     */
    void printInExponentialForm() const;
};

#endif //STACK_H