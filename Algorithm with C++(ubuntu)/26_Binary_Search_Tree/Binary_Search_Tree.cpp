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

// Case1： 欲刪除的 node 沒有 child
// Case2： 欲刪除的 node 有一個 child (可能是 left or right)
// Case3： 欲刪除的 node 有兩個 child

void Binary_Search_Tree::Delete(int k) {
    
    // 先看 node 是否存在
    Node *delete_Node = Search(k);
    if (delete_Node == NULL) {
        cout << "The node doesn't exist..." << endl << endl;
        return;
    }

    Node *real_Delete_Node = NULL;          // 真正要被刪除的 node
    Node *child_Of_Real_Delete_Node = NULL; // 要被刪除的 node 的 child

    // 將 real_Delete_Node 設成 delete_node 的 Successor
    // 經過這組 if-else, real_Delete_Node 調整成至多只有一個child
    // 全部調整成 Case1 或 Case2 來處理
    if (delete_Node->Get_Left() == NULL || delete_Node->Get_Right() == NULL)
        real_Delete_Node = delete_Node;
    else
        real_Delete_Node = Sucessor(delete_Node);
    
    // --------------------------------------------------------------------------------------------

    // 將 child_Of_Real_Delete_Node 設成 real_Delete_Node 的 child
    // 可能是有效記憶體，也有可能是NULL
    if (real_Delete_Node->Get_Left() != NULL)
        child_Of_Real_Delete_Node = real_Delete_Node->Get_Left();
    else
        child_Of_Real_Delete_Node = real_Delete_Node->Get_Right();
    
    // --------------------------------------------------------------------------------------------

    // 在 real_Delete_Node 被刪除之前, 這個步驟把 child_Of_Real_Delete_Node 接回 BST
    if (child_Of_Real_Delete_Node != NULL)
        child_Of_Real_Delete_Node->Set_Parent(real_Delete_Node->Get_Parent());

    // --------------------------------------------------------------------------------------------

    // 把 real_Delete_Node 的 parent 和 child_Of_Real_Delete_Node 連接
    
    if (real_Delete_Node->Get_Parent() == NULL)                               // real_Delete_Node 是 root
        root = child_Of_Real_Delete_Node;
    else if (real_Delete_Node == real_Delete_Node->Get_Parent()->Get_Left())  // 若 real_Delete_Node 原本是其 parent 之 left child
        real_Delete_Node->Get_Parent()->Set_Left(child_Of_Real_Delete_Node);  // 便把 child_Of_Real_Delete_Node 接在 real_Delete_Node 的 parent 的 left child, 取代 real_Delete_Node
    else if (real_Delete_Node == real_Delete_Node->Get_Parent()->Get_Right()) // 若 real_Delete_Node 原本是其 parent 之 right child
        real_Delete_Node->Get_Parent()->Set_Right(child_Of_Real_Delete_Node); // 便把 child_Of_Real_Delete_Node 接在 real_Delete_Node 的 parent 的 right child, 取代 real_Delete_Node

    // --------------------------------------------------------------------------------------------

    // 針對 Case3
    // 若 real_Delete_Node 是 delete_node 的替身, 最後要再將 real_Delete_Node 的資料
    // 放到 delete_node 的記憶體位置, 並將 real_Delete_Node 的記憶體位置釋放
    if (real_Delete_Node != delete_Node) {
        delete_Node->Set_Data(real_Delete_Node->Get_Data());
        delete_Node->Set_Key(real_Delete_Node->Get_Key());
    }

    delete real_Delete_Node;
}

// --

// 回傳 root 的左子樹的最左邊的 node
Node* Binary_Search_Tree::Left_Most(Node *node) {
    if (node == NULL) return NULL;
    if (node->Get_Left() != NULL) return Left_Most(node->Get_Left());
    return node;
}

// 回傳 current_Node 的下一個 node (以 inorder 巡訪)
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