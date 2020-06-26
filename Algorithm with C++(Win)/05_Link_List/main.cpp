#include <iostream>
#include <cstdlib>
#include "ListNode.cpp"

using namespace std;

template <class T>
void Traverse(ListNode<T> *);

int main() {

    ListNode<int> *head = new ListNode<int>(100);
    head->SetLink(NULL);
    ListNode<int> *tail = new ListNode<int>(25);
    tail->SetLink(NULL);
    head->SetLink(tail);
    ListNode<int> *traverse_Node = NULL;

    // �L�X��llink list
    cout << "��l link list" << endl;
    traverse_Node = head;
    Traverse(traverse_Node);

    // �b head ��m���J
    cout << endl << "�b head ��m���J" << endl;
    ListNode<int> *new_Head = new ListNode<int>(1);
    new_Head->SetLink(head);
    head = new_Head;
    Traverse(head);

    // �b tail ��m���J
    cout << endl << "�b tail ��m���J" << endl;
    ListNode<int> *new_Tail = new ListNode<int>(999);
    tail->SetLink(new_Tail);
    tail = new_Tail;
    Traverse(head);

    // �b head �M tail ��m���~���a�贡�J
    cout << endl << "�b head �M tail ��m���~���a�贡�J" << endl;
    int num = 25;
    traverse_Node = head;
    while(traverse_Node->GetLink() != NULL) {
        if (traverse_Node->GetData() == num) break;
        else traverse_Node = traverse_Node->GetLink();
    }

    ListNode<int> *new_Node = new ListNode<int>(60);
    new_Node->SetLink(NULL);
    new_Node->SetLink(traverse_Node->GetLink());
    traverse_Node->SetLink(new_Node);
    Traverse(head);

    // �b head ��m�R��
    cout << endl <<"�R�� head" << endl;
    ListNode<int> *delete_Head = head;
    head = head->GetLink();
    delete delete_Head;
    Traverse(head);

    // �b tail ��m�R��
    cout << endl <<"�R�� tail" << endl;
    ListNode<int> *delete_Tail = tail;
    traverse_Node = head;
    while(traverse_Node->GetLink() != delete_Tail) {
        traverse_Node = traverse_Node->GetLink();
    }
    tail = traverse_Node;
    tail->SetLink(NULL);
    delete delete_Tail;
    Traverse(head);

    // �b head �M tail ��m���~���a��R��
    cout << endl <<"�b head �M tail ��m���~���a��R��" << endl;
    traverse_Node = head->GetLink();
    ListNode<int> *traverse_Node_previous = head;
    while (traverse_Node->GetData() != num && traverse_Node->GetLink() != NULL) {
        traverse_Node = traverse_Node->GetLink();
        traverse_Node_previous = traverse_Node_previous->GetLink();
    }
    ListNode<int> *delete_Node = traverse_Node;
    traverse_Node_previous->SetLink(traverse_Node->GetLink());
    delete_Node->SetLink(NULL);
    delete delete_Node;
    Traverse(head);

    // ����O��
    cout << endl << "����O����" << endl;
    delete head;
    delete tail;
    delete traverse_Node;
    delete traverse_Node_previous;

    system("pause");
    return 0;
}

template <class T>
void Traverse(ListNode<T> *traverse_Node) {
    
    while (traverse_Node->GetLink() != NULL) {
        cout << traverse_Node->GetData() << " ---> ";
        traverse_Node = traverse_Node->GetLink();
    }
    cout << traverse_Node->GetData() << endl;
}