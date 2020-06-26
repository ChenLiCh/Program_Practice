#ifndef NODE_H
#define NODE_H
#include <iostream>
#include <cstdlib>

using namespace std;

template <class T>
class Node {
    public:
        Node();
        Node(T);
        ~Node();
        void Set_Next(Node<T> *);
        Node<T> *Get_Next();
        T Get_Data();
    private:
        T data;
        Node<T> *next;
};
#endif