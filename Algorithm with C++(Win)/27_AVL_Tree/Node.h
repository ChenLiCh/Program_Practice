#ifndef NODE_H
#define NODE_H
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

class Node {
    public:
        Node();
        Node(string, int);
        ~Node();
        
        void Set_Left(Node*);
        void Set_Right(Node*);
        void Set_Parent(Node*);
        void Set_Data(string);
        void Set_Key(int);
        void Set_Height(int);

        Node *Get_Left();
        Node *Get_Right();
        Node *Get_Parent();
        string Get_Data();
        int Get_Key();
        int Get_Height();
    private:
        Node *left;
        Node *right;
        Node *parent;
        string data;
        int key;
        int height;
};
#endif