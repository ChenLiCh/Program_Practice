#ifndef STACK_H
#define STACK_H
#include <iostream>
#include <cstdlib>
#include "Node.h"

using namespace std;

template <class T>
class Stack {
    public:
        Stack();
        ~Stack();
        void Push(T);
        void Pop();
        void Peek();
        bool Is_Empty();
    private:
        Node<T> *top;
};
#endif