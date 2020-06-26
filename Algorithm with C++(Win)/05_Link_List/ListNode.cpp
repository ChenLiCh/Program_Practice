#include "ListNode.h"

template <class T>
ListNode<T>::ListNode(): link(NULL) {

}

template <class T>
ListNode<T>::ListNode(T value): link(NULL), data(value) {

}

template <class T>
ListNode<T>::~ListNode() {
    cout << "�@�Ӫ���Ѻc..." <<endl;
}

template <class T>
void ListNode<T>::SetLink(ListNode<T> *next) {
    link = next;
}

template <class T>
void ListNode<T>::SetData(T value) {
    data = value;
}

template <class T>
ListNode<T>* ListNode<T>::GetLink() {
    return link;
}

template <class T>
T& ListNode<T>::GetData() {
    return data;
}
