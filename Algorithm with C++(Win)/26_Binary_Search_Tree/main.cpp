#include <iostream>
#include <cstdlib>
#include "Binary_Search_Tree.cpp"
using namespace std;

int main() {

    Binary_Search_Tree bst;

    bst.Insert("龜仙人", 8);
    bst.Insert("悟空", 1000);
    bst.Insert("克林", 2);
    bst.Insert("比克", 513);

    cout << "Inorder Traversal:\n";
    bst.Inorder(bst.Get_Root());
    
    cout << endl << endl;
    cout << "Level-order Traversal:\n";
    bst.Levelorder();
    cout << endl << endl;

    bst.Delete(8);         // 刪除龜仙人(8), 確認比克(513)會成為新的root

    cout << "Level-order Traversal:\n";
    bst.Levelorder();
    cout << endl << endl;

    Node *node = bst.Search(1000);
    if(node != NULL){
        cout << "There is " << node->Get_Data() << "(" << node->Get_Key() << ")" << endl;
    }
    else {
        cout << "no element with Key(1000)" << endl;
    }

    node = bst.Search(8);
    if(node != NULL){
        cout << "There is " << node->Get_Data() << "(" << node->Get_Key() << ")" << endl;
    }
    else {
        cout << "no element with Key(8)" << endl;
    }
    system("pause");
    return 0;
}