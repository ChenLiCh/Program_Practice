#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

int main() {

    while (1) {
        cout << "½Ð¿é¤J¬A¸¹¡G " << endl << endl;
        string str = "";
        cin >> str;

        int score = 0;
        for (int i = 0; i < str.length(); i++) {
            if (str[i] == '(') score++;
            else if (str[i] == ')') {
                score--;
                if (score < 0) break;
            }
        }

        if (score == 0) cout << "Correct" << endl << endl;
        else cout << "Wrong" << endl << endl;
    }

    system("pause");
    return 0;
}