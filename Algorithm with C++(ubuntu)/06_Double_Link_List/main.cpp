#include <iostream>
#include <cstdlib>
#include "Node.cpp"
#include "Double_Link_List.cpp"

using namespace std;

int main () {

    // 新增一個節點
    Node<int> *new_Node = new Node<int>(0);
    // 新增一個 double link list
    Double_Link_List<int> *list = new Double_Link_List<int>();
    list->Set_Head(new_Node);
    list->Set_Tail(new_Node);
    list->Set_Current(new_Node);

    // 新增很多節點
    new_Node = new Node<int>(5);
    list->Insert_At_Tail(new_Node);

    new_Node = new Node<int>(10);
    list->Insert_At_Tail(new_Node);

    new_Node = new Node<int>(15);
    list->Insert_At_Tail(new_Node);

    cout << "在 tail 新增節點" << endl;
    list->Traverse();

    // 在 head 前新增節點
    new_Node = new Node<int>(-1);
    list->Insert_At_Head(new_Node);

    new_Node = new Node<int>(-2);
    list->Insert_At_Head(new_Node);

    new_Node = new Node<int>(-3);
    list->Insert_At_Head(new_Node);
    
    cout << "在 head 新增節點" << endl;
    list->Traverse();

    // 在 特定節點後面加入節點
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

    cout << "在特定節點後面新增節點" << endl;
    list->Traverse();

    // 刪除 head 節點
    cout << "刪除 head 節點" << endl;
    list->Delete_Head();
    list->Traverse();

    // 刪除 tail 節點
    cout << "刪除 tail 節點" << endl;
    list->Delete_Tail();
    list->Traverse();

    // 刪除指定節點
    cout << "刪除指定節點" << endl;
    list->Delete_THe_Node(99);
    list->Traverse();

    cout << "刪除指定節點" << endl;
    list->Delete_THe_Node(0);
    list->Traverse();

    // 刪除全部
    cout << "刪除全部節點" << endl;
    list->Delete_All();
    list->Traverse();

    system("pause");
    return 0;
}