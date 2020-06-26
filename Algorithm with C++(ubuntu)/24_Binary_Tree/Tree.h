#ifndef TREE_H
#define TREE_H
#include <iostream>
#include <cstdlib>
#include "Node.h"

using namespace std;

template<class T>
class Tree {
    public:
        Tree();
        Tree(Node<T>*, Node<T>*);
        ~Tree();
        
        void Set_Current(Node<T>*);
        Node<T> *Get_Root();
        Node<T> *Get_Current();

        void Insert_Left_Child(Node<T>*, T);
        void Insert_Right_Child(Node<T>*, T);
        void Delete_Left_Child(Node<T>*);
        void Delete_Right_Child(Node<T>*);

        void Find_Position(Node<T>*, T);
        bool Is_Empty();

        void Pre_Order_Traversal(Node<T>*);
        void In_Order_Traversal(Node<T>*);
        void Post_Order_Traversal(Node<T>*);
    private:
        Node<T> *root;
        Node<T> *current;
};
#endif