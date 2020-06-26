#include "Node.h"

template <class T>
Node<T>::Node(): previous(NULL), next(NULL) {

}

template <class T>
Node<T>::Node(T value): data(value), previous(NULL), next(NULL) {

}

template <class T>
Node<T>::~Node() {
    cout << "一個物件解構..." <<endl;
}

template <class T>
void Node<T>::Set_Previous(Node<T> *pre) {
    previous = pre;
}

template <class T>
void Node<T>::Set_Next(Node<T> *n) {
    next = n;
}


template <class T>
void Node<T>::Set_Data(T value) {
    data = value;
}

template <class T>
Node<T>* Node<T>::Get_Previous() {
    return previous;
}

template <class T>
Node<T>* Node<T>::Get_Next() {
    return next;
}

template <class T>
T Node<T>::Get_Data() {
    return data;
}