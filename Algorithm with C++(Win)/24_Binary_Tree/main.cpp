#include <iostream>
#include <cstdlib>
#include "Node.cpp"
#include "Tree.cpp"

using namespace std;

int main() {


    // �s�W�@�����@�� Node ����
    Node<int> *new_Node = new Node<int>(1);
    Tree<int> *new_Tree = new Tree<int>(new_Node, new_Node);

    // �s�W�@�� left child
    new_Tree->Insert_Left_Child(new_Tree->Get_Root(), 2);

    // �s�W�@�� right child
    new_Tree->Insert_Right_Child(new_Tree->Get_Root(), 3);

    new_Tree->Set_Current(new_Tree->Get_Root());
    new_Tree->Pre_Order_Traversal(new_Tree->Get_Current());
    cout << endl << endl;

    new_Tree->Set_Current(new_Tree->Get_Root());
    new_Tree->In_Order_Traversal(new_Tree->Get_Current());
    cout << endl << endl;

    new_Tree->Set_Current(new_Tree->Get_Root());
    new_Tree->Post_Order_Traversal(new_Tree->Get_Current());
    cout << endl << endl;
    
    new_Tree->Set_Current(new_Tree->Get_Root());
    new_Tree->Find_Position(new_Tree->Get_Current(), 2);
    new_Tree->Insert_Left_Child(new_Tree->Get_Current(), 4);
    new_Tree->Insert_Right_Child(new_Tree->Get_Current(), 5);

    new_Tree->Set_Current(new_Tree->Get_Root());
    new_Tree->Pre_Order_Traversal(new_Tree->Get_Current());
    cout << endl << endl;
    
    system("pause");
    return 0;
}
