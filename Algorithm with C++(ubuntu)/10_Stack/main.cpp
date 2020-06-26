#include <iostream>
#include <cstdlib>
#include "Stack.cpp"
#include "Node.cpp"

using namespace std;

int main() {

    Stack<int> *new_Stack = new Stack<int>();

    new_Stack->Push(5);
    new_Stack->Peek();
    new_Stack->Push(10);
    new_Stack->Peek();
    new_Stack->Push(15);
    new_Stack->Peek();

    while (!new_Stack->Is_Empty()) {
        cout << "========== Stack 為空嗎？ " << new_Stack->Is_Empty() << endl << endl;
        new_Stack->Peek();
        new_Stack->Pop();
    }

    cout << "========== Stack 為空嗎？ " << new_Stack->Is_Empty() << endl << endl;
    new_Stack->Peek();
    new_Stack->Pop();

    delete new_Stack;
    
    system("pause");
    return 0;
}