#include "Node.h"

template<class T>
Node<T>::Node(): parent(NULL), left_Child(NULL), right_Child(NULL) {

}

template<class T>
Node<T>::Node(const T value): data(value), parent(NULL), left_Child(NULL), right_Child(NULL) {

}

template<class T>
Node<T>::~Node() {
    cout << "¤@­Ó Node ¸Ñºc..." <<endl << endl;
}

template<class T>
void Node<T>::Set_Data(const T value) {
    data = value;
}

template<class T>
void Node<T>::Set_Parent(Node<T>* p) {
    parent = p;
}

template<class T>
void Node<T>::Set_Left_Child(Node<T>* lc) {
    left_Child = lc;
}

template<class T>
void Node<T>::Set_Right_Child(Node<T>* rc) {
    right_Child = rc;
}

template<class T>
T Node<T>::Get_Data() {
    return data;
}

template<class T>
Node<T>* Node<T>::Get_Parent() {
    return parent;
}

template<class T>
Node<T>* Node<T>::Get_Left_Child() {
    return left_Child;
}

template<class T>
Node<T>* Node<T>::Get_Right_Child() {
    return right_Child;
}