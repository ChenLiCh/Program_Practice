#include "Node.h"

Node::Node(): left(NULL), right(NULL), parent(NULL), data(""), key(0), height(0) {

}

Node::Node(string d, int k): left(NULL), right(NULL), parent(NULL), data(d), key(k), height(1) {

}

Node::~Node() {
    cout << "One Node is destruct..." << endl << endl;
}

void Node::Set_Left(Node *l) {
    left = l;
}

void Node::Set_Right(Node *r) {
    right = r;
}

void Node::Set_Parent(Node *p) {
    parent = p;
}

void Node::Set_Data(string d) {
    data = d;
}

void Node::Set_Key(int k) {
    key = k;
}

void Node::Set_Height(int h) {
    height = h;
}

Node* Node::Get_Left() {
    return left;
}

Node* Node::Get_Right() {
    return right;
}

Node* Node::Get_Parent() {
    return parent;
}

string Node::Get_Data() {
    return data;
}

int Node::Get_Key() {
    return key;
}

int Node::Get_Height() {
    return height;
}