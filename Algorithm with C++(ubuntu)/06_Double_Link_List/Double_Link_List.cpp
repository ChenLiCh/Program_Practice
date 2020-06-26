#include "Double_Link_List.h"

template <class T>
Double_Link_List<T>::Double_Link_List(): head(NULL), tail(NULL), current(NULL), count(0) {

}

template <class T>
Double_Link_List<T>::~Double_Link_List() {
    cout << "一個 Double Link List 解構..." << endl;
}

template <class T>
void Double_Link_List<T>::Set_Head(Node<T> *h) {
    head = h;
}

template <class T>
void Double_Link_List<T>::Set_Tail(Node<T> *t) {
    tail = t;
}

template <class T>
void Double_Link_List<T>::Set_Current(Node<T> *c) {
    current = c;
}

template <class T>
Node<T>* Double_Link_List<T>::Get_Head() {
    return head;
}

template <class T>
Node<T>* Double_Link_List<T>::Get_Tail() {
    return tail;
}

template <class T>
Node<T>* Double_Link_List<T>::Get_Current() {
    return current;
}

template <class T>
void Double_Link_List<T>::Insert_At_Head(Node<T> *node) {
    node->Set_Next(head);
    head->Set_Previous(node);
    head = node;
}

template <class T>
void Double_Link_List<T>::Insert_At_Tail(Node<T> *node) {
    tail->Set_Next(node);
    node->Set_Previous(tail);
    tail = node;
}

template <class T>
void Double_Link_List<T>::Insert_After(const T data, Node<T> *node) {
    current = head;
    while(current != NULL) {
        if (current->Get_Data() == data) break;
        current = current->Get_Next();
    }
    if (current == NULL) {
        cout << "找不到指定節點，無法插入" << endl << endl;
        delete node;
    }
    else {
        node->Set_Next(current->Get_Next());
        current->Get_Next()->Set_Previous(node);
        current->Set_Next(node);
        node->Set_Previous(current);
    }
}

template <class T>
void Double_Link_List<T>::Delete_Head() {
    if (head == NULL) {
        cout << "double link list中沒有結點，無法刪除" << endl << endl;
        return;
    } 
    current = head->Get_Next();
    if (current != NULL) {
        head->Set_Next(NULL);
        current->Set_Previous(NULL);
    }
    delete head;
    head = current;
}

template <class T>
void Double_Link_List<T>::Delete_Tail() {
    if (tail == NULL) {
        cout << "double link list 中沒有節點，無法刪除" << endl << endl;
        return;
    }
    current = tail->Get_Previous();
    if (current != NULL) {
        current->Set_Next(NULL);
        tail->Set_Previous(NULL);
    }
    delete tail;
    tail = current;
}

template <class T>
void Double_Link_List<T>::Delete_THe_Node(const T data) {
    current = head;
    while(current != NULL) {
        if (current->Get_Data() == data) break;
        current = current->Get_Next();
    }
    if (current == NULL) cout << "找不到指定節點，無法刪除" << endl << endl;
    else if (current == head) Delete_Head();
    else if (current == tail) Delete_Tail();
    else {
        current->Get_Previous()->Set_Next(current->Get_Next());
        current->Get_Next()->Set_Previous(current->Get_Previous());
        current->Set_Previous(NULL);
        current->Set_Next(NULL);
        delete current;
    }
}

template <class T>
void Double_Link_List<T>::Delete_All() {
    if (Is_Empty()) {
        cout << "double link list 中沒有節點，無法刪除" << endl << endl;
        return;
    }
    current = head;
    while(current != NULL) {
        Delete_Head();
    }
    cout << "double link list 中有多少節點？ " << Get_Count()  << endl << endl;
}

template <class T>
bool Double_Link_List<T>::Is_Empty() {
    return !Get_Count();
}

template <class T>
int Double_Link_List<T>::Get_Count() {
    count = 0;
    current = head;
    if (current == NULL) return 0;
    while (current != NULL) {
        count++;
        current = current->Get_Next();
    }
    return count;
}

template <class T>
void Double_Link_List<T>::Traverse() {
    current = head;
    if (current != NULL) cout << "NULL <---> ";
    while(current != NULL) {
        cout << current->Get_Data() << " <---> ";
        current = current->Get_Next();
    }
    cout << "NULL" << endl << endl;
}