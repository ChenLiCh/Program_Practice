#include "Stack.h"

template <class T>
Stack<T>::Stack(): top(NULL) {

}

template <class T>
Stack<T>::~Stack() {
    cout << "�@�� Stack �Ѻc..." << endl << endl;
}

template <class T>
void Stack<T>::Push(T d) {
    Node<T> *new_Node = new Node<T>(d);
    new_Node->Set_Next(top);
    top = new_Node;
}

template <class T>
void Stack<T>::Pop() {
    if (Is_Empty()) cout << "Stack ���šA�L�k pop..." << endl << endl;
    else {
        cout << "top = " << top->Get_Data() << ", " << top->Get_Data() << " �Q pop..." << endl << endl;
        Node<T> *temp = top;
        top = top->Get_Next();
        delete temp;
    }
}

template <class T>
void Stack<T>::Peek() {
    if (Is_Empty()) cout << "Stack ���šA�L�k peek..." << endl << endl;
    else {
        cout << "top = " << top->Get_Data() << endl << endl;
    }
}

template <class T>
bool Stack<T>::Is_Empty() {
    return !top;
}