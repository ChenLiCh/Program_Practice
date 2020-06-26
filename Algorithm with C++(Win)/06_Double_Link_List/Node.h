#ifndef NODE_H
#define NODE_H
#include <iostream>
#include <cstdlib>

using namespace std;

template <class T> 
class Node {
    public:
        Node();
        Node(T value);
        ~Node();
        void Set_Previous(Node<T> *pre);
        void Set_Next(Node<T> *n);
        void Set_Data(T value);
        Node<T> *Get_Previous();
        Node<T> *Get_Next();
        T Get_Data();
    private:
        T data;
        Node<T> *previous, *next;
};
#endif