#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

int main() {

    cout << "½Ð¿é¤J¦r¦ê¡G ";
    string str = "";
    cin >> str;

    int times = 1, i = 0;
    for (i = 0; i < str.length() - 1; i++) {
        if (str[i] == str[i+1]) times++;
        else {
            cout << times << str[i] << " ";
            times = 1;
        }
    }
    cout << times << str[i] << " ";
    system("pause");
    return 0;
}