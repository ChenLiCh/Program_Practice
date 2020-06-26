#ifndef NODE_H
#define NODE_H
#include <iostream>
#include <cstdlib>

using namespace std;

template<class T>
class Node {
    public:
        Node();
        Node(const T);
        ~Node();
        
        void Set_Data(const T);
        void Set_Parent(Node<T>*);
        void Set_Left_Child(Node<T>*);
        void Set_Right_Child(Node<T>*);

        T Get_Data();
        Node<T> *Get_Parent();
        Node<T> *Get_Left_Child();
        Node<T> *Get_Right_Child();
    private:
        T data;
        Node<T> *parent;
        Node<T> *left_Child;
        Node<T> *right_Child;
};
#endif