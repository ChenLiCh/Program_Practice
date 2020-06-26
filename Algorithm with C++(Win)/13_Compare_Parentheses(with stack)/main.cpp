#include <iostream>
#include <cstdlib>
#include <string>
#include "Node.cpp"
#include "Stack.cpp"

using namespace std;

int main() {

    while (1) {
        cout << "Input parentheses" << endl << endl;
        string str = "";
        cin >> str;

        bool has_Printed = false;
        Stack<char> parentheses = Stack<char>();
        for (int i = 0; i < str.length(); i++) {
            if (str[i] == '(') {
                parentheses.Push('(');
            }
            else if (str[i] == ')') {
                if (parentheses.Is_Empty()) {
                    cout << "Wrong" << endl << endl;
                    has_Printed = true;
                    break;
                }
                else parentheses.Pop();
            }
        }

        if (!has_Printed) {
            if (parentheses.Is_Empty()) cout << "Correct" << endl << endl;
            else cout << "Wrong" << endl << endl;
        }
    }
    
    system("pause");
    return 0;
}