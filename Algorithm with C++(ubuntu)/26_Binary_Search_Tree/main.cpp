#include <iostream>
#include <cstdlib>
#include "Binary_Search_Tree.cpp"
using namespace std;

int main() {

    Binary_Search_Tree bst;

    bst.Insert("�t�P�H", 8);
    bst.Insert("����", 1000);
    bst.Insert("�J�L", 2);
    bst.Insert("��J", 513);

    cout << "Inorder Traversal:\n";
    bst.Inorder(bst.Get_Root());
    
    cout << endl << endl;
    cout << "Level-order Traversal:\n";
    bst.Levelorder();
    cout << endl << endl;

    bst.Delete(8);         // �R���t�P�H(8), �T�{��J(513)�|�����s��root

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