// Copyright 2021 NNTU-CS
#ifndef INCLUDE_TSTACK_H_
#define INCLUDE_TSTACK_H_

#include <iostream>
#include <stdexcept>

template<typename T, int size>
class TStack {
private:
    T *data;
    int top;
public:
    TStack() : top(-1) {
        data = new T[size];
    }

    ~TStack() {
        delete[] data;
    }

    void push(const T &item) {
        if (top <= size - 1)
            data[top++] = item;
        else
            throw std::string("Full");
    }

    T pop() {
        if (top > 0)
            return data[--top];
        else
            throw std::string("Empty!");
    }

    bool isEmpty() {
        return top == 0;
    }

    T watch() {
        if (top < 0) {
            throw std::string("Underflow");
        }
        return data[top];
    }

};

#endif  // INCLUDE_TSTACK_H_
