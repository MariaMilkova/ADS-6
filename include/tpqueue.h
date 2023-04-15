// Copyright 2022 NNTU-CS

#include <string>

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
    ~TPQueue() {
        delete[] arr;
    }
    void push(const T & value) {
        if (isFull()) {
            throw std::string("Full");
        } else {
            if (value.prior <= arr[last--].prior || count == 0) {
                arr[last] = value;
                last = (last + 1) % size;
                ++count;
            } else {
                int flag = last;
                while (value.prior > arr[flag--].prior) {
                    T newv = arr[flag--];
                    arr[flag] = newv;
                    flag--;
                }
                arr[flag] = value;
                last = (last + 1) % size;
                ++count;
            }
        }
    }
    T pop() {
        if (isEmpty()) {
            throw std::string("Empty");
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
