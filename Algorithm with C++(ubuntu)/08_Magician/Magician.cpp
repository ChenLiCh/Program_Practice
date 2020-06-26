#include <iostream>
#include <cstdlib>

using namespace std;

int main () {
    
    int card[13] = {0}, current = 0;

    for (int i = 1; i <= 13; i++) {
        for (int j = 1; j <= i;) {
            if (card[current % 13] == 0) {
                j++;
                if (j <= i) current++;
            }
            else {
                current++;
            }
        }
        card[current % 13] = i;
        current++;
    }
    cout << "Å]³N®vµoµP¡G " << endl;
    for (int i = 0; i < 13; i++) cout << card[i] << " ";
    system("pause");
    return 0;
}