// Copyright 2022 NNTU-CS

#include <iostream>

#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T, int size>
class TPQueue {
 private:
    T *arr;
    int first, last, count;
    
 public:
    TPQueue() {
        arr = new T[size];
        first = 0;
        last = 0;
        count = 0;
    }
    bool isEmpty() const {
        return 0 == count;
    }
    bool isFull() const {
        return size == count;
    }
    void push(const T & value) {
        if (isFull()) {
            std::cout << "Stack is Full" << "\n";
        } else {
            if (value.prior <= last-- || isEmpty()) {
                arr[last] = value;
                last = (last + 1) % size;
                ++count;
            } else {
                while (value.prior <= last--) {
                    last--;
                    arr[last] = value;
                    last = (last + 1) % size;
                    ++count;
                }
            }
        }
    }
    T pop() {
        if (isEmpty()) {
            std::cout << "Stack is Empty!" << "\n";
        } else {
            --count;
            T t = arr[first];
            first = (first + 1) % size;
            return t;
        }
    }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
