#ifndef BINARY_SEARCH_TREE
#define BINARY_SEARCH_TREE
#include <iostream>
#include <cstdlib>
#include <queue>
#include "Node.cpp"
using namespace std;

class Binary_Search_Tree {
    public:
        Binary_Search_Tree();
        ~Binary_Search_Tree();

        Node *Get_Root();
        Node *Search(int);
        void Insert(string, int);
        void Inorder(Node*);
        void Levelorder();
        void Delete(int);
    private:
        Node *root;
        Node *current;
        Node *Left_Most(Node*);
        Node *Sucessor(Node*);
};
#endif