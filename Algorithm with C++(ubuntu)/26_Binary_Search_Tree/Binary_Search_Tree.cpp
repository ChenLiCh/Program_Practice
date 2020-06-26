#include "Binary_Search_Tree.h"

Binary_Search_Tree::Binary_Search_Tree(): root(NULL), current(NULL) {

}

Binary_Search_Tree::~Binary_Search_Tree() {
    cout << "A BST is destruct..." << endl << endl;
}

Node* Binary_Search_Tree::Get_Root() {
    return root;
}

Node* Binary_Search_Tree::Search(int key) {
    current = root;
    while(current != NULL && key != current->Get_Key()) {
        if (key < current->Get_Key()) current = current->Get_Left();
        else if (key > current->Get_Key()) current = current->Get_Right();
    }
    return current;
}

void Binary_Search_Tree::Insert(string d, int k) {
    current = root;
    Node *previous = NULL;
    Node *new_Node = new Node(d, k);

    while(current != NULL) {
        previous = current;
        if (new_Node->Get_Key() < current->Get_Key()) current = current->Get_Left();
        else if (new_Node->Get_Key() > current->Get_Key()) current = current->Get_Right();
        else if (new_Node->Get_Key() == current->Get_Key()) {
            cout << "A node has same key value..." << endl << endl;
            return;
        }
    }

    new_Node->Set_Parent(previous);

    if (previous == NULL) root = new_Node;
    else if (new_Node->Get_Key() < previous->Get_Key()) previous->Set_Left(new_Node);
    else if (new_Node->Get_Key() > previous->Get_Key()) previous->Set_Right(new_Node);
}

void Binary_Search_Tree::Inorder(Node *node) {
    if (node == NULL) return;
    Inorder(node->Get_Left());
    cout << node->Get_Data() << " " << "(" <<node->Get_Key() << ")" << " ";
    Inorder(node->Get_Right());
}

void Binary_Search_Tree::Levelorder() {
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        current = q.front();
        cout << current->Get_Data() << " " << "(" << current->Get_Key() << ")" << " ";
        q.pop();

        if (current->Get_Left() != NULL) q.push(current->Get_Left());
        if (current->Get_Right() != NULL) q.push(current->Get_Right());
    }
}

// Case1�G ���R���� node �S�� child
// Case2�G ���R���� node ���@�� child (�i��O left or right)
// Case3�G ���R���� node ����� child

void Binary_Search_Tree::Delete(int k) {
    
    // ���� node �O�_�s�b
    Node *delete_Node = Search(k);
    if (delete_Node == NULL) {
        cout << "The node doesn't exist..." << endl << endl;
        return;
    }

    Node *real_Delete_Node = NULL;          // �u���n�Q�R���� node
    Node *child_Of_Real_Delete_Node = NULL; // �n�Q�R���� node �� child

    // �N real_Delete_Node �]�� delete_node �� Successor
    // �g�L�o�� if-else, real_Delete_Node �վ㦨�ܦh�u���@��child
    // �����վ㦨 Case1 �� Case2 �ӳB�z
    if (delete_Node->Get_Left() == NULL || delete_Node->Get_Right() == NULL)
        real_Delete_Node = delete_Node;
    else
        real_Delete_Node = Sucessor(delete_Node);
    
    // --------------------------------------------------------------------------------------------

    // �N child_Of_Real_Delete_Node �]�� real_Delete_Node �� child
    // �i��O���İO����A�]���i��ONULL
    if (real_Delete_Node->Get_Left() != NULL)
        child_Of_Real_Delete_Node = real_Delete_Node->Get_Left();
    else
        child_Of_Real_Delete_Node = real_Delete_Node->Get_Right();
    
    // --------------------------------------------------------------------------------------------

    // �b real_Delete_Node �Q�R�����e, �o�ӨB�J�� child_Of_Real_Delete_Node ���^ BST
    if (child_Of_Real_Delete_Node != NULL)
        child_Of_Real_Delete_Node->Set_Parent(real_Delete_Node->Get_Parent());

    // --------------------------------------------------------------------------------------------

    // �� real_Delete_Node �� parent �M child_Of_Real_Delete_Node �s��
    
    if (real_Delete_Node->Get_Parent() == NULL)                               // real_Delete_Node �O root
        root = child_Of_Real_Delete_Node;
    else if (real_Delete_Node == real_Delete_Node->Get_Parent()->Get_Left())  // �Y real_Delete_Node �쥻�O�� parent �� left child
        real_Delete_Node->Get_Parent()->Set_Left(child_Of_Real_Delete_Node);  // �K�� child_Of_Real_Delete_Node ���b real_Delete_Node �� parent �� left child, ���N real_Delete_Node
    else if (real_Delete_Node == real_Delete_Node->Get_Parent()->Get_Right()) // �Y real_Delete_Node �쥻�O�� parent �� right child
        real_Delete_Node->Get_Parent()->Set_Right(child_Of_Real_Delete_Node); // �K�� child_Of_Real_Delete_Node ���b real_Delete_Node �� parent �� right child, ���N real_Delete_Node

    // --------------------------------------------------------------------------------------------

    // �w�� Case3
    // �Y real_Delete_Node �O delete_node ������, �̫�n�A�N real_Delete_Node �����
    // ��� delete_node ���O�����m, �ñN real_Delete_Node ���O�����m����
    if (real_Delete_Node != delete_Node) {
        delete_Node->Set_Data(real_Delete_Node->Get_Data());
        delete_Node->Set_Key(real_Delete_Node->Get_Key());
    }

    delete real_Delete_Node;
}

// --

// �^�� root �����l�𪺳̥��䪺 node
Node* Binary_Search_Tree::Left_Most(Node *node) {
    if (node == NULL) return NULL;
    if (node->Get_Left() != NULL) return Left_Most(node->Get_Left());
    return node;
}

// �^�� current_Node ���U�@�� node (�H inorder ���X)
Node* Binary_Search_Tree::Sucessor(Node *current_Node) {
    if (current_Node->Get_Right() != NULL) {
        return Left_Most(current_Node->Get_Right());
    }

    Node *sucessor = current_Node->Get_Parent();

    while(sucessor != NULL && current_Node == sucessor->Get_Right()) {
        current_Node = sucessor;
        sucessor = sucessor->Get_Parent();
    }

    return sucessor;
}

//-