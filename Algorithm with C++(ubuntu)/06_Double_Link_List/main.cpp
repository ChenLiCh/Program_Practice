#include <iostream>
#include <cstdlib>
#include "Node.cpp"
#include "Double_Link_List.cpp"

using namespace std;

int main () {

    // �s�W�@�Ӹ`�I
    Node<int> *new_Node = new Node<int>(0);
    // �s�W�@�� double link list
    Double_Link_List<int> *list = new Double_Link_List<int>();
    list->Set_Head(new_Node);
    list->Set_Tail(new_Node);
    list->Set_Current(new_Node);

    // �s�W�ܦh�`�I
    new_Node = new Node<int>(5);
    list->Insert_At_Tail(new_Node);

    new_Node = new Node<int>(10);
    list->Insert_At_Tail(new_Node);

    new_Node = new Node<int>(15);
    list->Insert_At_Tail(new_Node);

    cout << "�b tail �s�W�`�I" << endl;
    list->Traverse();

    // �b head �e�s�W�`�I
    new_Node = new Node<int>(-1);
    list->Insert_At_Head(new_Node);

    new_Node = new Node<int>(-2);
    list->Insert_At_Head(new_Node);

    new_Node = new Node<int>(-3);
    list->Insert_At_Head(new_Node);
    
    cout << "�b head �s�W�`�I" << endl;
    list->Traverse();

    // �b �S�w�`�I�᭱�[�J�`�I
    new_Node = new Node<int>(11);
    list->Insert_After(-3, new_Node);

    new_Node = new Node<int>(22);
    list->Insert_After(10, new_Node);

    new_Node = new Node<int>(33);
    list->Insert_After(-1, new_Node);

    new_Node = new Node<int>(44);
    list->Insert_After(5, new_Node);

    new_Node = new Node<int>(55);
    list->Insert_After(-2, new_Node);

    new_Node = new Node<int>(99);
    list->Insert_After(100, new_Node);

    cout << "�b�S�w�`�I�᭱�s�W�`�I" << endl;
    list->Traverse();

    // �R�� head �`�I
    cout << "�R�� head �`�I" << endl;
    list->Delete_Head();
    list->Traverse();

    // �R�� tail �`�I
    cout << "�R�� tail �`�I" << endl;
    list->Delete_Tail();
    list->Traverse();

    // �R�����w�`�I
    cout << "�R�����w�`�I" << endl;
    list->Delete_THe_Node(99);
    list->Traverse();

    cout << "�R�����w�`�I" << endl;
    list->Delete_THe_Node(0);
    list->Traverse();

    // �R������
    cout << "�R�������`�I" << endl;
    list->Delete_All();
    list->Traverse();

    system("pause");
    return 0;
}