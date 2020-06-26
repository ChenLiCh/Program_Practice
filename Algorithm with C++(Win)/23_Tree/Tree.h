#ifndef TREE_H
#define TREE_H
#include <iostream>
#include <cstdlib>
#include "Node.cpp"

using namespace std;

template <class T>
class Tree {
    public:
        Tree();
        Tree(Node<T> *root);
        ~Tree();
        void Set_Root(Node<T>*);
        void Set_Current(Node<T>*);
        Node<T> *Get_Root();
        Node<T> *Get_Current();
        void Insert_Child(Node<T>*);
        bool Is_Empty();
    private:
        Node<T> *root;
        Node<T> *current;
};

#endif