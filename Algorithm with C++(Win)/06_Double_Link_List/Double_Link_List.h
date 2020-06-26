#ifndef DOUBLE_LINK_LIST_H
#define DOUBLE_LINK_LIST_H
#include <iostream>
#include <cstdlib>
#include "Node.h"

using namespace std;

template <class T>
class Double_Link_List {

    public:
        Double_Link_List();
        ~Double_Link_List();
        void Set_Head(Node<T> *);
        void Set_Tail(Node<T> *);
        void Set_Current(Node<T> *);
        Node<T> *Get_Head();
        Node<T> *Get_Tail();
        Node<T> *Get_Current();
        void Insert_At_Head(Node<T> *);
        void Insert_At_Tail(Node<T> *);
        void Insert_After(const T, Node<T> *);
        void Delete_Head();
        void Delete_Tail();
        void Delete_THe_Node(const T);
        void Delete_All();
        bool Is_Empty();
        int Get_Count();
        void Traverse();
    private:
        Node<T> *head, *tail, *current;
        int count;
};
#endif