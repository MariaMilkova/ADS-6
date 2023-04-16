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
    void push(const T& value) {
        if (isFull()) {
            throw std::string("Full");
        } else {
            if (isEmpty() || value.prior <= arr[(last - 1) % size].prior) {
                arr[last] = value;
                last = (last + 1) % size;
                ++count;
            } else {
                int flag = first;
                while (value.prior <= arr[flag].prior && flag != last) {
                    flag = (flag + 1) % size;
                }
                for (int i = last; i != flag; i = (size + i - 1) % size) {
                    arr[i] = arr[(size + i - 1) % size];
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
