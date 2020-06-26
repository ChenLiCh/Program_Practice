#include "Binary_Search_Tree.h"

Binary_Search_Tree::Binary_Search_Tree(): root(NULL), current(NULL) {

}

Binary_Search_Tree::~Binary_Search_Tree() {
    cout << "A BST is destruct..." << endl << endl;
}

Node* Binary_Search_Tree::Get_Root() {
    return root;
}

// �j�M
Node* Binary_Search_Tree::Search(int key) {
    current = root;
    while(current != NULL && key != current->Get_Key()) {
        if (key < current->Get_Key()) current = current->Get_Left();
        else if (key > current->Get_Key()) current = current->Get_Right();
    }
    return current;
}


// �s�W node
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

    Update_Height(new_Node->Get_Parent());
    Inspect_Balance(new_Node->Get_Parent(), (new_Node->Get_Key()));
}

// LVR ���Ǩ��X
void Binary_Search_Tree::Inorder(Node *node) {
    if (node == NULL) return;
    Inorder(node->Get_Left());
    cout << node->Get_Data() << " " << "(" <<node->Get_Key() << ")" << " ";
    Inorder(node->Get_Right());
}

// Level ���X
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

// -----private member function-----

// �^�� root ���̥��䪺 node
Node* Binary_Search_Tree::Left_Most(Node *node) {
    if (node == NULL) return NULL;
    if (node->Get_Left() != NULL) return Left_Most(node->Get_Left());
    return node;
}

// �^�� current_Node ���U�@�� node (�H inorder ���X) (�k�l��̤p�� node)
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

int Binary_Search_Tree::Get_Max(int a, int b) {
    return (a > b)? a : b;
}

int Binary_Search_Tree::Get_Height (Node *node) {
    if (node == NULL) return 0;
    else return node->Get_Height();
}

void Binary_Search_Tree::Update_Height(Node *node) {
    while (node != NULL) {
        node->Set_Height(1 + Get_Max(Get_Height(node->Get_Left()), Get_Height(node->Get_Right())));
        node = node->Get_Parent();
    }
}

int Binary_Search_Tree::Get_Balance_Factor(Node *node) {
    if (node == NULL) return 0;
    return Get_Height(node->Get_Left()) - Get_Height(node->Get_Right());
}

void Binary_Search_Tree::Inspect_Balance(Node *node, int key) {
    int factor = 0;
    
    while(node != NULL) {
        factor = Get_Balance_Factor(node);

        // Left Left
        if (factor > 1 && key < node->Get_Left()->Get_Key()) {
            Right_Rotate(node);
        }
        // Right Right
        else if (factor < -1 && key > node->Get_Right()->Get_Key()) {
            Left_Rotate(node);
        }
        // Left Right
        else if (factor > 1 && key > node->Get_Left()->Get_Key()) {
            Left_Rotate(node->Get_Left());
            Right_Rotate(node);
        }
        // Right Left
        else if (factor < -1 && key < node->Get_Right()->Get_Key()) {
            Right_Rotate(node->Get_Right());
            Left_Rotate(node);
        }
        node = node->Get_Parent();
    }
}

// ����
void Binary_Search_Tree::Left_Rotate (Node *A) {
    Node *B = A->Get_Right();
    Node *b = B->Get_Left();

    // Rotation

    // �վ� A �� parent �� (left child || right child)�A�N����VB
    if (A->Get_Parent() != NULL) {
        if (A->Get_Key() > A->Get_Parent()->Get_Key()) A->Get_Parent()->Set_Right(B);
        else A->Get_Parent()->Set_Left(B);
    }

    // �վ� B �� parrent, left child (right child �������ܡA���Χ��)
    B->Set_Parent(A->Get_Parent()); 
    B->Set_Left(A);

    // �վ� A �� parrent, right child (left child �������ܡA���Χ��)
    A->Set_Parent(B);
    A->Set_Right(b);

    // �վ㰪��
    A->Set_Height(1 + Get_Max(Get_Height(A->Get_Left()), Get_Height(A->Get_Right())));
    B->Set_Height(1 + Get_Max(Get_Height(B->Get_Left()), Get_Height(B->Get_Right())));

    if (B->Get_Parent() == NULL) root = B;
}

// �k��
void Binary_Search_Tree::Right_Rotate(Node *A) {
    Node *B = A->Get_Left();
    Node *b = B->Get_Right();

    // Rotation

    // �վ� A �� parent �� (left child || right child)�A�N����VB
    if (A->Get_Parent()) {
        if (A->Get_Key() > A->Get_Parent()->Get_Key()) A->Get_Parent()->Set_Right(B);
        else A->Get_Parent()->Set_Left(B);
    } 

    // �վ� B �� parrent, right child (right child �������ܡA���Χ��)
    B->Set_Parent(A->Get_Parent());
    B->Set_Right(A);

    // �վ� A �� parrent, right child (left child �������ܡA���Χ��)
    A->Set_Parent(B);
    A->Set_Left(b);

    // �վ㰪��
    A->Set_Height(1 + Get_Max(Get_Height(A->Get_Left()), Get_Height(A->Get_Right())));
    B->Set_Height(1 + Get_Max(Get_Height(B->Get_Left()), Get_Height(B->Get_Right())));

    if (B->Get_Parent() == NULL) root = B;
}