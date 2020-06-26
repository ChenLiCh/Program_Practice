#include "Tree.h"

template<class T>
Tree<T>::Tree(): root(NULL), current(NULL) {

}

template<class T>
Tree<T>::Tree(Node<T> *r, Node<T> *c): root(r), current(c) {

}

template<class T>
Tree<T>::~Tree() {
    cout << "一顆 binary tree 解構..." << endl << endl;
}

template<class T>
void Tree<T>::Set_Current(Node<T>* node) {
    current = node;
}

template<class T>
Node<T>* Tree<T>::Get_Root() {
    return root;
}

template<class T>
Node<T>* Tree<T>::Get_Current() {
    return current;
}

template<class T>
void Tree<T>::Insert_Left_Child(Node<T> *node, T data) {
    if (node->Get_Left_Child() != NULL) {
        cout << "已經有 left child..." << endl << endl;
        return;
    }
    Node<T> *new_Left_Child = new Node<T>(data);
    node->Set_Left_Child(new_Left_Child);
    new_Left_Child->Set_Parent(node);
}

template<class T>
void Tree<T>::Insert_Right_Child(Node<T> *node, T data) {
    if (node->Get_Right_Child() != NULL) {
        cout << "已經有 left child..." << endl << endl;
        return;
    }
    Node<T> *new_Right_Child = new Node<T>(data);
    node->Set_Right_Child(new_Right_Child);
    new_Right_Child->Set_Parent(node);
}

template<class T>
void Tree<T>::Delete_Left_Child(Node<T> *node) {
    
}

template<class T>
void Tree<T>::Delete_Right_Child(Node<T> *node) {
    
}

template<class T>
void Tree<T>::Find_Position(Node<T> *node, T data) {
    if (node == NULL) return;
    if (node->Get_Data() == data) {
        current = node;
        return;
    }
    Find_Position(node->Get_Left_Child(), data);
    Find_Position(node->Get_Right_Child(), data);
}

template<class T>
bool Tree<T>::Is_Empty() {
    return root == NULL;
}

template<class T>
void Tree<T>::Pre_Order_Traversal(Node<T> *node) {
    if (node == NULL) return;
    cout << node->Get_Data() << " ";
    Pre_Order_Traversal(node->Get_Left_Child());
    Pre_Order_Traversal(node->Get_Right_Child());
}

template<class T>
void Tree<T>::In_Order_Traversal(Node<T> *node) {
    if (node == NULL) return;
    In_Order_Traversal(node->Get_Left_Child());
    cout << node->Get_Data() << " ";
    In_Order_Traversal(node->Get_Right_Child());
}

template<class T>
void Tree<T>::Post_Order_Traversal(Node<T> *node) {
    if (node == NULL) return;
    Post_Order_Traversal(node->Get_Left_Child());
    Post_Order_Traversal(node->Get_Right_Child());
    cout << node->Get_Data() << " ";
}