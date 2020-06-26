#include "Node.h"

template <class T>
Node<T>::Node(): data(NULL), next(NULL) {

}

template <class T>
Node<T>::Node(T d): data(d), next(NULL) {

}

template <class T>
Node<T>::~Node() {
    cout << "一個節點解構..." << endl << endl;
}

template <class T>
void Node<T>::Set_Next(Node<T> *n) {
    next = n;
}

template <class T>
Node<T>* Node<T>::Get_Next() {
    return next;
}

template <class T>
T Node<T>::Get_Data() {
    return data;
}